//
//  GetPath.cpp
//  TracerConsole
//
//  Created by Sem Shimla on 16/04/2019.
//  Copyright © 2019 Sem Shimla. All rights reserved.
//

#include "GetPath.hpp"


string GetPath::getAssPath()
{
    
    string  HOME = getenv("HOME") ? getenv("HOME") : ".";
    string homePath;
    string s1 = HOME;
    string s2 = "/Documents/Resolume Arena 6/Preferences/AdvancedOutput.xml";
    homePath = s1 + s2;
    
    /*
    char cstr[homePath.length()];
    
    for (int i=0;i<sizeof(cstr);i++)
    {
        cstr[i] = homePath[i];
        cout << cstr[i];
    }
    
    cstr[homePath.size()] = '\0';
     */
    
    pugi::xml_document ass;
    pugi::xml_parse_result result = ass.load_file(homePath.c_str());
    
    if (result)
    {
        // <ScreenSetup name="ScreenSetup" presetFile="testScreen">
        assPath = ass.child("ScreenSetup").attribute("presetFile").as_string();
        assPath = assPath + ".xml";
    }
    
    
    return assPath;
}
