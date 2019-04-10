#include "HelloFFGL.h"

#define LayerDial1   0



////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////


static CFFGLPluginInfo PluginInfo(
	FFGLPlugin::CreateInstance,			// Create method
	"0195",								// Plugin unique ID
	"AKAI1",				        	// Plugin name
	1,						   			// API major version number
	500,								// API minor version number
	1,									// Plugin major version number
	000,								// Plugin minor version number
	FF_EFFECT,							// Plugin type
	"AKAI1 CONTROLLER",		    	    // Plugin description
	"Sem Schreuder // PixelClone"		// About

);

FFGLPlugin::FFGLPlugin()
	: CFreeFrameGLPlugin()
{
    SetParamInfo( LayerDial1, "LayerDial1", FF_TYPE_STANDARD, 0.f);
    
	SetMinInputs( 1 );
	SetMaxInputs( 1 );
}

FFGLPlugin::~FFGLPlugin()
{

}


FFResult FFGLPlugin::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{

    return FF_SUCCESS;

}

/* SetFloatParameter is called by Resolume when you change a slider in the effect */
FFResult FFGLPlugin::SetFloatParameter(unsigned int index, float value)
{
	//now we use the callback to set our internal float variable, whenever the slider in Resolume is changed
	switch (index)
	{
        case LayerDial1:
            a01 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
	}

	return FF_SUCCESS;
}

/* GetFloatParameter is used by Resolume to display the value on the right side of the parameter
   For instance if you're controlling rotation of something, you can use a multiplier here to show the value in degrees */
float FFGLPlugin::GetFloatParameter( unsigned int index )
{
	switch ( index )
	{
        case LayerDial1:
            return a01; //right now, we just want to return the value of our float
            break;
	}
}
