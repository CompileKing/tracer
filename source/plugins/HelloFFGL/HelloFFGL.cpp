#include "HelloFFGL.h"

//here we define the word 'LayerDial1' to equal zero
//this is handy so we don't have to remember which index each param has
#define LayerDial1 0
#define LayerDial2 1
#define LayerDial3 2
#define LayerDial4 3
#define LayerDial5 4
#define LayerDial6 5
#define LayerDial7 6
#define LayerDial8 7

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////

static CFFGLPluginInfo PluginInfo(
	FFGLPlugin::CreateInstance,			// Create method
	"0195",								// Plugin unique ID
	"AKAI CONTROLLER",						// Plugin name
	1,						   			// API major version number												
	500,								// API minor version number
	1,									// Plugin major version number
	000,								// Plugin minor version number
	FF_EFFECT,							// Plugin type
	"AKAI CONTROLLER",		    	// Plugin description
	"Sem Schreuder // PixelClone"			// About

	/*The important bits here are:
	- "Plugin unique ID". This number is used the identify the plugin internally and needs to be different for each and every FFGL plugin in existence.
	Is there a single list where you can see all the IDs that are already in use? No. Feel free to organise one. 
	My plugins start with HV and then have two numbers identifying them. So HV01 is my first plugin. Resolume's plugins start with Axxx
	- "Plugin name". This is the name as its displayed in Resolume's effect list. 
	- "Plugin type". Here you can let Resolume know whether the plugin is a source or effect. By putting FF_SOURCE you will create a source instead of an effect.
	- "Plugin description" and "About" are shown in the Help panel in Resolume.
	*/
);

FFGLPlugin::FFGLPlugin()
	: CFreeFrameGLPlugin()
{
	/*This creates a parameter
	Instead of using 0 in the beginning, we use our define 'LayerDial1'
	"Does Nothing" is the name (16 character maximum)
	FF_TYPE_STANDARD means it's a regular slider
	and 0.5f is it's default value */
	SetParamInfo( LayerDial1, "LayerDial1", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial2, "LayerDial2", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial3, "LayerDial3", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial4, "LayerDial4", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial5, "LayerDial5", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial6, "LayerDial6", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial7, "LayerDial7", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial8, "LayerDial8", FF_TYPE_STANDARD, 0.f);

	//because we set our param to be 0.5f by default, it makes sense that our float variable also starts off at 0.5f
	// a01 = 0.f;
    

	/*This will make sure that the plugin gets recognised as an EFFECT on both OSX and Windows.
	A SOURCE has 0 inputs
	An EFFECT has 1 input
	A TRANSITION has 2 inputs
	So why is the definition there in the CreateInstance call. I don't know. Someone must have thought that was a good idea at the time */
	SetMinInputs( 1 );
	SetMaxInputs( 1 );
}

FFGLPlugin::~FFGLPlugin()
{

}

/*ProcessOpenGL is like the draw() function in processing and openframeworks.
Everything that happens in ProcessOpenGL happens everytime the plugin renders.*/
FFResult FFGLPlugin::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{
	//clear the background to a nice neutral grey


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
        case LayerDial2:
            a02 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case LayerDial3:
            a03 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case LayerDial4:
            a04 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case LayerDial5:
            a05 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case LayerDial6:
            a06 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case LayerDial7:
            a07 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
            break;
        case LayerDial8:
            a08 = value; //this means we're setting our float to whatever value the first parameter has in Resolume
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
        case LayerDial2:
            return a02; //right now, we just want to return the value of our float
            break;
        case LayerDial3:
            return a03; //right now, we just want to return the value of our float
            break;
        case LayerDial4:
            return a04; //right now, we just want to return the value of our float
            break;
        case LayerDial5:
            return a05; //right now, we just want to return the value of our float
            break;
        case LayerDial6:
            return a06; //right now, we just want to return the value of our float
            break;
        case LayerDial7:
            return a07; //right now, we just want to return the value of our float
            break;
        case LayerDial8:
            return a08; //right now, we just want to return the value of our float
            break;
	

	}

	
}


