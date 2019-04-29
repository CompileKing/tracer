#include "HelloFFGL.h"
#include <iostream>
#include <stdio.h>
#include "../../lib/ffgl/utilities/utilities.h"
#include "FFGL.h"
#include "FFGLLib.h"

using namespace std;

//here we define the word 'lineWidthParam' to equal zero
//this is handy so we don't have to remember which index each param has
#define lineWidthParam 0
#define trigger 1
#define bgToggle 2
#define maskToggle 3


////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////

static CFFGLPluginInfo PluginInfo(
    FFGLPlugin::CreateInstance,			// Create method
        "SH40",								// Plugin unique ID
        "Tracer",						    // Plugin name
        1,						   			// API major version number
        500,								// API minor version number
        1,									// Plugin major version number
        000,								// Plugin minor version number
        FF_EFFECT,							// Plugin type
        "Creates an outline on your slices",			// Plugin description
        "Sem Shimla // Pixel Clone"			// About

/*The important bits here are:
 - "Plugin unique ID". This number is used the identify the plugin internally and needs to be different for each and every FFGL plugin in existence.
 Is there a single list where you can see all the IDs that are already in use? No. Feel free to organise one.
 My plugins start with HV and then have two numbers identifying them. So HV01 is my first plugin. Resolume's plugins start with Axxx
 - "Plugin name". This is the name as its displayed in Resolume's effect list.
 - "Plugin type". Here you can let Resolume know whether the plugin is a source or effect. By putting FF_SOURCE you will create a source instead of an effect.
 - "Plugin description" and "About" are shown in the Help panel in Resolume.
 */
);

static const std::string vertexShaderCode = STRINGIFY(
                                                      void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_FrontColor = gl_Color;
}
                                                      );


static const std::string fragmentShaderCode = STRINGIFY(
                                                        uniform sampler2D inputTexture;
                                                        uniform vec3 brightness;
                                                        void main()
{
    vec4 color = texture2D(inputTexture,gl_TexCoord[0].st);
    if (color.a > 0.0) //unpremultiply
        color.rgb /= color.a;
    color.rgb = color.rgb + brightness;
    color.rgb *= color.a; //premultiply
    gl_FragColor  =  color;
}
                                                        );

FFGLPlugin::FFGLPlugin()
: CFreeFrameGLPlugin()
{
    /*This creates a parameter
     Instead of using 0 in the beginning, we use our define 'lineWidthParam'
     "Does Nothing" is the name (16 character maximum)
     FF_TYPE_STANDARD means it's a regular slider
     and 0.5f is it's default value */
    SetParamInfo( lineWidthParam, "Line Width", FF_TYPE_STANDARD, 0.1f);
    SetParamInfo( trigger, "Reload", FF_TYPE_EVENT, 0.f);
    SetParamInfo( bgToggle, "See Through", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( maskToggle, "Draw Mask", FF_TYPE_BOOLEAN, 0.f);
    
    
    
    //because we set our param to be 0.5f by default, it makes sense that our float variable also starts off at 0.5f
    aFloat = 0.1f;
    aBool = false;
    aMaskBool = false;
    
    
    
    /*This will make sure that the plugin gets recognised as an EFFECT on both OSX and Windows.
     A SOURCE has 0 inputs
     An EFFECT has 1 input
     A TRANSITION has 2 inputs
     So why is the definition there in the CreateInstance call. I don't know. Someone must have thought that was a good idea at the time */
    SetMinInputs( 1 );
    SetMaxInputs( 1 );
    
    // create the inputRect arrays
    rect.getInputRect();
}

FFGLPlugin::~FFGLPlugin()
{
    
}

FFResult FFGLPlugin::InitGL(const FFGLViewportStruct *vp)
{
    
    m_initResources = 0;
    
    
    //initialize gl shader
    m_shader.Compile(vertexShaderCode,fragmentShaderCode);
    
    //activate our shader
    m_shader.BindShader();
    
    //to assign values to parameters in the shader, we have to lookup
    //the "location" of each value.. then call one of the glUniform* methods
    //to assign a value
    m_inputTextureLocation = m_shader.FindUniform("inputTexture");
    m_BrightnessLocation = m_shader.FindUniform("brightness");
    
    //the 0 means that the 'inputTexture' in
    //the shader will use the texture bound to GL texture unit 0
    glUniform1i(m_inputTextureLocation, 0);
    
    m_shader.UnbindShader();
    
    return FF_SUCCESS;
}

FFResult FFGLPlugin::DeInitGL()
{
    m_shader.FreeGLResources();
    
    
    return FF_SUCCESS;
}

/*ProcessOpenGL is like the draw() function in processing and openframeworks.
 Everything that happens in ProcessOpenGL happens everytime the plugin renders.*/
FFResult FFGLPlugin::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{
    
    /*
    glClearColor( 0.f, 0.f, 0.f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );
     */
    
    if (pGL->numInputTextures<1)
        return FF_FAIL;
    
    if (pGL->inputTextures[0]==NULL)
        return FF_FAIL;
    
    //activate our shader
    m_shader.BindShader();
    
    FFGLTextureStruct &Texture = *(pGL->inputTextures[0]);
    
    //get the max s,t that correspond to the
    //width,height of the used portion of the allocated texture space
    FFGLTexCoords maxCoords = GetMaxGLTexCoords(Texture);
    
    //assign the Brightness
    
    /*
     glUniform3f(m_BrightnessLocation,
     -1.0f + (m_BrightnessR * 2.0f),
     -1.0f + (m_BrightnessG * 2.0f),
     -1.0f + (m_BrightnessB * 2.0f)
     );
     
     */
    
    
    
    //activate texture unit 1 and bind the input texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture.Handle);
    
    //draw the quad that will be painted by the shader/textures
    //note that we are sending texture coordinates to texture unit 1..
    //the vertex shader and fragment shader refer to this when querying for
    //texture coordinates of the inputTexture
    
    
    glBegin(GL_QUADS);
    
    //lower left
    glMultiTexCoord2f(GL_TEXTURE0, 0,0);
    glVertex2f(-1,-1);
    
    //upper left
    glMultiTexCoord2f(GL_TEXTURE0, 0, maxCoords.t);
    glVertex2f(-1,1);
    
    //upper right
    glMultiTexCoord2f(GL_TEXTURE0, maxCoords.s, maxCoords.t);
    glVertex2f(1,1);
    
    //lower right
    glMultiTexCoord2f(GL_TEXTURE0, maxCoords.s, 0);
    glVertex2f(1,-1);
    glEnd();
    
    //unbind the input texture
    glBindTexture(GL_TEXTURE_2D,0);

    m_shader.UnbindShader();
    
    
    
    
    if (aFloat > 0.1)
    {
        glLineWidth(aFloat*10);
    }

    //anti aliasing
    glEnable(GL_LINE_SMOOTH);
    
    // create verts array from input x & y array pointers
    
    
    if (!aBool)
    {
        GLfloat verts[] =
        {
            -1.f, 1.f, //top left
            1.f, 1.f, //top right
            1.f, -1.f, //bottom right
            -1.f, -1.f //bottom left
        };
        
        glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 2, GL_FLOAT, 0, verts );
        glDrawArrays( GL_TRIANGLE_FAN, 0, 4 );
    }
    
    
    
    if (aMaskBool)
    {
        for (int i=0;i<rect.sIndex;i++)
        {
            GLdouble verts[] =
            {
                rect.xArrayPtr[(4*i)],  rect.yArrayPtr[(4*i)],      //top left
                rect.xArrayPtr[(4*i+1)],rect.yArrayPtr[(4*i+1)],    //top right
                rect.xArrayPtr[(4*i+2)],rect.yArrayPtr[(4*i+2)],    //bottom right
                rect.xArrayPtr[(4*i+3)],rect.yArrayPtr[(4*i+3)],    //bottom left
            };
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            glEnableClientState( GL_VERTEX_ARRAY   );
            glVertexPointer( 2, GL_DOUBLE, 0, verts );
            glDrawArrays( GL_TRIANGLE_FAN  , 0, 4 );
        }
    }
    else
    {
        for (int i=0;i<rect.sIndex;i++)
        {
            GLdouble verts[] =
            {
                rect.xArrayPtr[(4*i)],  rect.yArrayPtr[(4*i)],      //top left
                rect.xArrayPtr[(4*i+1)],rect.yArrayPtr[(4*i+1)],    //top right
                rect.xArrayPtr[(4*i+2)],rect.yArrayPtr[(4*i+2)],    //bottom right
                rect.xArrayPtr[(4*i+3)],rect.yArrayPtr[(4*i+3)],    //bottom left
            };
            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            glEnableClientState( GL_VERTEX_ARRAY   );
            glVertexPointer( 2, GL_DOUBLE, 0, verts );
            glDrawArrays( GL_LINE_LOOP  , 0, 4 );
        }
    }
    

    
    
     
     
    
    
    

    return FF_SUCCESS;

}




/* SetFloatParameter is called by Resolume when you change a slider in the effect */
FFResult FFGLPlugin::SetFloatParameter(unsigned int index, float value)
{
    //now we use the callback to set our internal float variable, whenever the slider in Resolume is changed
    switch (index)
    {
        case lineWidthParam:
            aFloat = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case trigger:
            aTrigger = value;
            if (aTrigger)
            {
                rect.getInputRect();
            }
            break;
        case bgToggle:
            aBool = value;
            break;
        case maskToggle:
            aMaskBool = value;
        
    }
    return FF_SUCCESS;
}

/* GetFloatParameter is used by Resolume to display the value on the right side of the parameter
 For instance if you're controlling rotation of something, you can use a multiplier here to show the value in degrees */
float FFGLPlugin::GetFloatParameter( unsigned int index )
{
    
    switch ( index )
    {
        case lineWidthParam:
            return lineWidth = (aFloat * 10) + 1;
            break;
        default:
            return 0.0f; //to be safe, always return something
            break;
    }
}


