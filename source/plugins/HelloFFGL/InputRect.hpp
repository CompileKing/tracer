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
#include "GetPath.hpp"
#include <string>

using namespace std;


class InputRect
{
private:
    
    
    

    
public:
    
    
    InputRect();
    ~InputRect();
     
    
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
    

};










#endif /* InputRect_hpp */
