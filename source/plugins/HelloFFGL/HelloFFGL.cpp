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

#define  LayerSelect1 20
#define  LayerSelect2 21
#define  LayerSelect3 22
#define  LayerSelect4 23
#define  LayerSelect5 24
#define  LayerSelect6 25
#define  LayerSelect7 26
#define  LayerSelect8 27

#define  OpacityFader1 28
#define  OpacityFader2 29
#define  OpacityFader3 30
#define  OpacityFader4 31
#define  OpacityFader5 32
#define  OpacityFader6 33
#define  OpacityFader7 34
#define  OpacityFader8 35

#define BankSelectUp 36
#define BankSelectDown 37


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





    ////////////////////////////////////////////////////////////////////////////////////////////////////

    SetParamInfo( LayerSelect1, "LayerSelect1", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect2, "LayerSelect2", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect3, "LayerSelect3", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect4, "LayerSelect4", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect5, "LayerSelect5", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect6, "LayerSelect6", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect7, "LayerSelect7", FF_TYPE_BOOLEAN, 0.f);
    SetParamInfo( LayerSelect8, "LayerSelect8", FF_TYPE_BOOLEAN, 0.f); // layer selection

	////////////////////////////////////////////////////////////////////////////////////////////////////

    SetParamInfo( OpacityFader1, "OpacityFader1", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader2, "OpacityFader2", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader3, "OpacityFader3", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader4, "OpacityFader4", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader5, "OpacityFader5", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader6, "OpacityFader6", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader7, "OpacityFader7", FF_TYPE_STANDARD, 0.f);
    SetParamInfo( OpacityFader8, "OpacityFader8", FF_TYPE_STANDARD, 0.f); // opacity faders

	////////////////////////////////////////////////////////////////////////////////////////////////////

	SetParamInfo(BankSelectUp, "BankSelectUp", FF_TYPE_EVENT, 0.f);
	SetParamInfo(BankSelectDown, "BankSelectDown", FF_TYPE_EVENT, 0.f); // BankSelect


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
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // layer dials, FX dial for each layer
            
            
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

            ////////////////////////////////////////////////////////////////////////////////////////////////////    // groupmode

        case GroupModeA:
            a09 = value;
            break;
        case GroupModeB:
            a10 = value;
            break;
        case GroupModeC:
            a11 = value;
            break;

            ////////////////////////////////////////////////////////////////////////////////////////////////////    // multi dial, LIB dial for macro's

        case MultiDial:
            a12 = value;
            break;

            ////////////////////////////////////////////////////////////////////////////////////////////////////    // bypass dials, for each layer

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

            ////////////////////////////////////////////////////////////////////////////////////////////////////    // groupSelect, group selection per layer





            ////////////////////////////////////////////////////////////////////////////////////////////////////    // layer selection

        case LayerSelect1:
            a45 = value;
            break;
        case LayerSelect2:
            a46 = value;
            break;
        case LayerSelect3:
            a47 = value;
            break;
        case LayerSelect4:
            a48 = value;
            break;
        case LayerSelect5:
            a49 = value;
            break;
        case LayerSelect6:
            a50 = value;
            break;
        case LayerSelect7:
            a51 = value;
            break;
        case LayerSelect8:
            a52 = value;
            break;

            ////////////////////////////////////////////////////////////////////////////////////////////////////    // opacity faders
            
        case OpacityFader1:
            a53 = value;
            break;
        case OpacityFader2:
            a54 = value;
            break;
        case OpacityFader3:
            a55 = value;
            break;
        case OpacityFader4:
            a56 = value;
            break;
        case OpacityFader5:
            a57 = value;
            break;
        case OpacityFader6:
            a58 = value;
            break;
        case OpacityFader7:
            a59 = value;
            break;
        case OpacityFader8:
            a60 = value;
            break;


		case BankSelectDown:
			a61 = value;
			break;
		case BankSelectUp:
			a62 = value;
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
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // layer dials, FX dial for each layer
            
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
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // groupmode
            
        case GroupModeA:
            return a09 ;
            break;
        case GroupModeB:
            return a10 ;
            break;
        case GroupModeC:
            return a11 ;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // multi dial, LIB dial for macro's
            
        case MultiDial:
            return a12 ;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // bypass dials, for each layer
            
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
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // groupSelect, group selection per layer



            ////////////////////////////////////////////////////////////////////////////////////////////////////    // layer selection

        case LayerSelect1:
            return a45 ;
            break;
        case LayerSelect2:
            return a46 ;
            break;
        case LayerSelect3:
            return a47 ;
            break;
        case LayerSelect4:
            return a48 ;
            break;
        case LayerSelect5:
            return a49 ;
            break;
        case LayerSelect6:
            return a50 ;
            break;
        case LayerSelect7:
            return a51 ;
            break;
        case LayerSelect8:
            return a52 ;
            break;
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////    // opacity faders
            
        case OpacityFader1:
            return a53 ;
            break;
        case OpacityFader2:
            return a54 ;
            break;
        case OpacityFader3:
            return a55 ;
            break;
        case OpacityFader4:
            return a56 ;
            break;
        case OpacityFader5:
            return a57 ;
            break;
        case OpacityFader6:
            return a58 ;
            break;
        case OpacityFader7:
            return a59 ;
            break;
        case OpacityFader8:
            return a60 ;
            break;
            
	}
}
