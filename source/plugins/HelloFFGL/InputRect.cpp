//
//  InputRect.cpp
//  TracerConsole
//
//  Created by Sem Shimla on 15/04/2019.
//  Copyright © 2019 Sem Shimla. All rights reserved.
//

#include "InputRect.hpp"




void InputRect::getInputRect()
{
    
    GetPath AssPath;
    
    
    string  HOME = getenv("HOME") ? getenv("HOME") : ".";
    string homePath;
    string s1 = HOME;
    string s2 = "/Documents/Resolume Arena 6/Presets/Advanced Output/";
    string s3 = AssPath.getAssPath();
    homePath = s1 + s2 + s3;
    
    char cstr[homePath.size() + 1];
    homePath.copy(cstr, homePath.size() + 1);
    cstr[homePath.size()] = '\0';
    
    pugi::xml_document doc;
    pugi::xml_parse_result
    result =
        doc.load_file(cstr);
    
    compResX = doc.child("XmlState").child("ScreenSetup").child("CurrentCompositionTextureSize").attribute("width").as_int();
    compResY = doc.child("XmlState").child("ScreenSetup").child("CurrentCompositionTextureSize").attribute("height").as_int();
    
    if (result)
    {
        
        for (pugi::xml_node screen: doc.child("XmlState").child("ScreenSetup").child("screens").children("Screen"))
        {
            
            if (strncmp (screen.attribute("name").as_string(),"Tracer",6)==0)
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
}




