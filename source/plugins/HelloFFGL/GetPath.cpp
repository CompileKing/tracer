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
    
    string homePath;
    
#ifdef __APPLE__
    string  HOME = getenv("HOME") ? getenv("HOME") : ".";
    string s1 = HOME;
    string s2 = "/Documents/Resolume Arena 6/Preferences/AdvancedOutput.xml";
    homePath = s1 + s2;
    
#endif
    
    
#ifdef _WIN64
    WCHAR path[MAX_PATH + 1];
    if (SHGetSpecialFolderPathW(HWND_DESKTOP, path, CSIDL_DESKTOPDIRECTORY, FALSE))
    {
        std::wstring ws(path);
        std::string HOME(ws.begin(), ws.end());
        string s1 = HOME;
    }
#endif
    
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
