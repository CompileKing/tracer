#pragma once

//we need to include this file so we can access the functions that are used to create and run an FFGL plugin
#include "FFGLPluginSDK.h"

//we create a class called FFLPlugin, that inherits from CFreeFramePlugin
//this will let us access the functions that we use to create an FFGL plugin
//get texture and parameter data from Resolume,
//and draw pixels in Resolume's output
class FFGLPlugin : public CFreeFrameGLPlugin
{
public:
	FFGLPlugin();
	~FFGLPlugin();

	//these are all FFGL functions that are used to communicate with Resolume
	//what they do is explained in the cpp file
	FFResult ProcessOpenGL(ProcessOpenGLStruct* pGL) override;
	FFResult SetFloatParameter(unsigned int index, float value) override;
	float GetFloatParameter( unsigned int index ) override;


	//this is a float that will be set by Resolume, and we can use it to change stuff in our plugin
	//we're going to link the value of this float to the value of the slider in Resolume
	float a01;
    float a02;
    float a03;
    float a04;
    float a05;
    float a06;
    float a07;
    float a08;
    float a09;
    float a10;
    float a11;
    float a12;
    float a13;
    float a14;
    float a15;
    float a16;
    float a17;
    float a18;
    float a19;
    float a20;
    float a21;
    float a22;
    float a23;
    float a24;
    float a25;
    float a26;
    float a27;
    float a28;
    float a29;
    float a30;
    float a31;
    float a32;
    float a33;
    float a34;
    float a35;
    float a36;
    float a37;
    float a38;
    float a39;
    float a40;
    float a41;
    float a42;
    float a43;
    float a44;
    float a45;
    float a46;
    float a47;
    float a48;
    float a49;
    float a50;
    float a51;
    float a52;
    float a53;
    float a54;
    float a55;
    float a56;
    float a57;
    float a58;
    float a59;
    float a60;
    float a61;
    float a62;
    float a63;
    float a64;


	//this is boiler plate code that takes care of all the behind the scenes stuff used in creating a plugin
	//in other words, we don't want to mess with this
	static FFResult __stdcall CreateInstance(CFreeFrameGLPlugin **ppOutInstance)
	{
		*ppOutInstance = new FFGLPlugin();
		if (*ppOutInstance != NULL)
			return FF_SUCCESS;
		return FF_FAIL;
	}
};
