//
//  InputRect.hpp
//  TracerConsole
//
//  Created by Sem Shimla on 15/04/2019.
//  Copyright © 2019 Sem Shimla. All rights reserved.
//

#ifndef InputRect_hpp
#define InputRect_hpp

#include <stdio.h>
#include "../../lib/pugixml/pugixml.hpp"
#include <iostream>
#include <string>

using namespace std;


class InputRect
{
private:
    
    
    

    
public:
    
    
    string assPath;
    int compResX;
    int compResY;
    
    int vIndex = 0;
    int sIndex = 0;
    
    void getInputRect();
    
    double xArray[1000];
    double *xArrayPtr = xArray;
    
    double yArray[1000];
    double *yArrayPtr = yArray;
    
    bool isFileLoaded;
    
    bool result1;
    bool result2;


};










#endif /* InputRect_hpp */
