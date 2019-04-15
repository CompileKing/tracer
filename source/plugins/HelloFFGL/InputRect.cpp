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
    pugi::xml_document doc;
    pugi::xml_parse_result
    result =
        doc.load_file("/Users/Shimla/Documents/Resolume Arena 6/Presets/Advanced Output/testScreen.xml");
    
    compResX = doc.child("XmlState").child("ScreenSetup").child("CurrentCompositionTextureSize").attribute("width").as_int();
    compResY = doc.child("XmlState").child("ScreenSetup").child("CurrentCompositionTextureSize").attribute("height").as_int();
    
    if (result)
    {
        for (pugi::xml_node tool: doc.child("XmlState").child("ScreenSetup").child("screens").child("Screen").child("layers").children("Slice"))
        {
            // run through all the v children of those slices
            for (pugi::xml_node value: tool.child("InputRect").children("v"))
            {
                // fill the x array everytime an x attribute hits with it's double

                xArray[vIndex] =  value.attribute("x").as_double() / compResX;
                yArray[vIndex] =  value.attribute("y").as_double() / compResY;
                
                vIndex++;
            }
            sIndex++;
        }
    }
}




