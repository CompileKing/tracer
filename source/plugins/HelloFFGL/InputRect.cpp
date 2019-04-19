//
//  InputRect.cpp
//  TracerConsole
//
//  Created by Sem Shimla on 15/04/2019.
//  Copyright © 2019 Sem Shimla. All rights reserved.
//

#include "InputRect.hpp"


InputRect::InputRect()
{
    
}

InputRect::~InputRect()
{
    
}


void InputRect::getInputRect()
{
    
    GetPath AssPath;
    
    
    string  HOME = getenv("HOME") ? getenv("HOME") : ".";
    string homePath;
    string s1 = HOME;
    string s2 = "/Documents/Resolume Arena 6/Presets/Advanced Output/";
    string s3 = AssPath.getAssPath();
    homePath = s1 + s2 + s3;
    
    char cstr[homePath.length()];
    
    for (int i=0;i<sizeof(cstr);i++)
    {
        cstr[i] = homePath[i];
        cout << cstr[i];
    }
    
    cstr[homePath.size()] = '\0';
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(cstr);
    
    compResX = doc.child("XmlState").child("ScreenSetup").child("CurrentCompositionTextureSize").attribute("width").as_int();
    compResY = doc.child("XmlState").child("ScreenSetup").child("CurrentCompositionTextureSize").attribute("height").as_int();
    
    if (result)
    {
        for (pugi::xml_node screen: doc.child("XmlState").child("ScreenSetup").child("screens").children("Screen"))
        {
            if (strncmp (screen.attribute("name").as_string(),"Tracer",6) == 0)
            {
                for (pugi::xml_node slice: screen.child("layers").children("Slice"))
                {
                    for (pugi::xml_node value: slice.child("InputRect").children("v"))
                    {
                        xArray[vIndex] =  (value.attribute("x").as_double() / compResX) * 2. - 1.;
                        yArray[vIndex] =  (value.attribute("y").as_double() / compResY) * 2. - 1.;
                        
                        vIndex++;
                    }
                    sIndex++;
                }
            }
        }
    }
    else
    {
        for (int i=0;i<4;i++)
        {
            switch (i) {
                case 0:
                    xArray[0] = -0.5;
                    yArray[0] = 0.5;
                    break;
                case 1:
                    xArray[1] = 0.5;
                    yArray[1] = 0.5;
                    break;
                case 2:
                    xArray[2] = 0.5;
                    yArray[2] = -0.5;
                    break;
                case 3:
                    xArray[3] = -0.5;
                    yArray[4] = -0.5;
                    break;
                    
                default:
                    break;
            }
        }
            
            /*
             -0.5f, 0.5f, //top left
             0.5f, 0.5f, //top right
             0.5f, -0.5f, //bottom right
             -0.5f, -0.5f //bottom left
             */
        
    }
}




