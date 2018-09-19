#include "HelloFFGL.h"

#define LayerDial1   0
#define LayerDial2   1
#define LayerDial3   2
#define LayerDial4   3
#define LayerDial5   4
#define LayerDial6   5
#define LayerDial7   6
#define LayerDial8   7

#define GroupModeA   8
#define GroupModeB   9
#define GroupModeC   10

#define MultiDial    11

#define BypassDial1  12
#define BypassDial2  13
#define BypassDial3  14
#define BypassDial4  15
#define BypassDial5  16
#define BypassDial6  17
#define BypassDial7  18
#define BypassDial8  19

#define  GroupSelect1A 20
#define  GroupSelect1B 21
#define  GroupSelect1C 22

#define  GroupSelect2A 23
#define  GroupSelect2B 24
#define  GroupSelect2C 25

#define  GroupSelect3A 26
#define  GroupSelect3B 27
#define  GroupSelect3C 28

#define  GroupSelect4A 29
#define  GroupSelect4B 30
#define  GroupSelect4C 31

#define  GroupSelect5A 32
#define  GroupSelect5B 33
#define  GroupSelect5C 34

#define  GroupSelect6A 35
#define  GroupSelect6B 36
#define  GroupSelect6C 37

#define  GroupSelect7A 38
#define  GroupSelect7B 39
#define  GroupSelect7C 40

#define  GroupSelect8A 41
#define  GroupSelect8B 42
#define  GroupSelect8C 43



////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////


static CFFGLPluginInfo PluginInfo(
	FFGLPlugin::CreateInstance,			// Create method
	"0195",								// Plugin unique ID
	"AKAI CONTROLLER",					// Plugin name
	1,						   			// API major version number												
	500,								// API minor version number
	1,									// Plugin major version number
	000,								// Plugin minor version number
	FF_EFFECT,							// Plugin type
	"AKAI CONTROLLER",		    	    // Plugin description
	"Sem Schreuder // PixelClone"		// About


);

FFGLPlugin::FFGLPlugin()
	: CFreeFrameGLPlugin()
{
	
	SetParamInfo( LayerDial1, "LayerDial1", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial2, "LayerDial2", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial3, "LayerDial3", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial4, "LayerDial4", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial5, "LayerDial5", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial6, "LayerDial6", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial7, "LayerDial7", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial8, "LayerDial8", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( LayerDial8, "LayerDial8", FF_TYPE_STANDARD, 0.f); // layer dials, FX dial for each layer
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    SetParamInfo( GroupModeA, "GroupModeA", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupModeB, "GroupModeB", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupModeC, "GroupModeC", FF_TYPE_EVENT, 0.f);  // groupmode
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    SetParamInfo( MultiDial, "MultiDial", FF_TYPE_STANDARD, 0.f);   // multi dial, LIB dial for macro's
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    SetParamInfo( BypassDial1, "BypassDial1", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial2, "BypassDial2", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial3, "BypassDial3", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial4, "BypassDial4", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial5, "BypassDial5", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial6, "BypassDial6", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial7, "BypassDial7", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( BypassDial8, "BypassDial8", FF_TYPE_BOOLEAN, 0.f); // bypass dials, for each layer
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    SetParamInfo( GroupSelect1A, "GroupSelect1A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect1B, "GroupSelect1B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect1C, "GroupSelect1C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect2A, "GroupSelect2A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect2B, "GroupSelect2B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect2C, "GroupSelect2C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect3A, "GroupSelect1A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect3B, "GroupSelect2B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect3C, "GroupSelect3C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect4A, "GroupSelect4A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect4B, "GroupSelect4B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect4C, "GroupSelect4C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect5A, "GroupSelect5A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect5B, "GroupSelect5B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect5C, "GroupSelect5C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect6A, "GroupSelect6A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect6B, "GroupSelect6B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect6C, "GroupSelect6C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect7A, "GroupSelect7A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect7B, "GroupSelect7B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect7C, "GroupSelect7C", FF_TYPE_BOOLEAN, 0.f);
    
    SetParamInfo( GroupSelect8A, "GroupSelect8A", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect8B, "GroupSelect8B", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( GroupSelect8C, "GroupSelect8C", FF_TYPE_BOOLEAN, 0.f); // groupSelect, group selection per layer
    
    
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
        case LayerDial2:
            a02 = value;
            break;
        case LayerDial3:
            a03 = value;
            break;
        case LayerDial4:
            a04 = value;
            break;
        case LayerDial5:
            a05 = value;
            break;
        case LayerDial6:
            a06 = value; 
            break;
        case LayerDial7:
            a07 = value;
            break;
        case LayerDial8:
            a08 = value;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case GroupModeA:
            a09 = value;
            break;
        case GroupModeB:
            a10 = value;
            break;
        case GroupModeC:
            a11 = value;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case MultiDial:
            a12 = value;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case BypassDial1:
            a13 = value;
            break;
        case BypassDial2:
            a14 = value;
            break;
        case BypassDial3:
            a15 = value;
            break;
        case BypassDial4:
            a16 = value;
            break;
        case BypassDial5:
            a17 = value;
            break;
        case BypassDial6:
            a18 = value;
            break;
        case BypassDial7:
            a19 = value;
            break;
        case BypassDial8:
            a20 = value;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case GroupSelect1A:
            a21 = value;
            break;
        case GroupSelect1B:
            a22 = value;
            break;
        case GroupSelect1C:
            a23 = value;
            break;
            
        case GroupSelect2A:
            a24 = value;
            break;
        case GroupSelect2B:
            a25 = value;
            break;
        case GroupSelect2C:
            a26 = value;
            break;
            
        case GroupSelect3A:
            a27 = value;
            break;
        case GroupSelect3B:
            a28 = value;
            break;
        case GroupSelect3C:
            a29 = value;
            break;
            
        case GroupSelect4A:
            a30 = value;
            break;
        case GroupSelect4B:
            a31 = value;
            break;
        case GroupSelect4C:
            a32 = value;
            break;
            
        case GroupSelect5A:
            a33 = value;
            break;
        case GroupSelect5B:
            a34 = value;
            break;
        case GroupSelect5C:
            a35 = value;
            break;
            
        case GroupSelect6A:
            a36 = value;
            break;
        case GroupSelect6B:
            a37 = value;
            break;
        case GroupSelect6C:
            a38 = value;
            break;
            
        case GroupSelect7A:
            a39 = value;
            break;
        case GroupSelect7B:
            a40 = value;
            break;
        case GroupSelect7C:
            a41 = value;
            break;
            
        case GroupSelect8A:
            a42 = value;
            break;
        case GroupSelect8B:
            a43 = value;
            break;
        case GroupSelect8C:
            a44 = value;
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
            return a02;
            break;
        case LayerDial3:
            return a03;
            break;
        case LayerDial4:
            return a04;
            break;
        case LayerDial5:
            return a05;
            break;
        case LayerDial6:
            return a06;
            break;
        case LayerDial7:
            return a07;
            break;
        case LayerDial8:
            return a08;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case GroupModeA:
            return a09 ;
            break;
        case GroupModeB:
            return a10 ;
            break;
        case GroupModeC:
            return a11 ;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case MultiDial:
            return a12 ;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case BypassDial1:
            return a13 ;
            break;
        case BypassDial2:
            return a14 ;
            break;
        case BypassDial3:
            return a15 ;
            break;
        case BypassDial4:
            return a16 ;
            break;
        case BypassDial5:
            return a17 ;
            break;
        case BypassDial6:
            return a18 ;
            break;
        case BypassDial7:
            return a19 ;
            break;
        case BypassDial8:
            return a20 ;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            
        case GroupSelect1A:
            return a21 ;
            break;
        case GroupSelect1B:
            return a22 ;
            break;
        case GroupSelect1C:
            return a23 ;
            break;
            
        case GroupSelect2A:
            return a24 ;
            break;
        case GroupSelect2B:
            return a25 ;
            break;
        case GroupSelect2C:
            return a26 ;
            break;
            
        case GroupSelect3A:
            return a27 ;
            break;
        case GroupSelect3B:
            return a28 ;
            break;
        case GroupSelect3C:
            return a29 ;
            break;
            
        case GroupSelect4A:
            return a30 ;
            break;
        case GroupSelect4B:
            return a31 ;
            break;
        case GroupSelect4C:
            return a32 ;
            break;
            
        case GroupSelect5A:
            return a33 ;
            break;
        case GroupSelect5B:
            return a34 ;
            break;
        case GroupSelect5C:
            return a35 ;
            break;
            
        case GroupSelect6A:
            return a36 ;
            break;
        case GroupSelect6B:
            return a37 ;
            break;
        case GroupSelect6C:
            return a38 ;
            break;
            
        case GroupSelect7A:
            return a39 ;
            break;
        case GroupSelect7B:
            return a40 ;
            break;
        case GroupSelect7C:
            return a41 ;
            break;
            
        case GroupSelect8A:
            return a42 ;
            break;
        case GroupSelect8B:
            return a43 ;
            break;
        case GroupSelect8C:
            return a44 ;
            break;
            
            
	}

	
}


