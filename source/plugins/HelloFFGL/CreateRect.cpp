//
//  CreateRect.cpp
//  TracerConsole
//
//  Created by Sem Shimla on 15/04/2019.
//  Copyright © 2019 Sem Shimla. All rights reserved.
//
#include <iostream>
#include "CreateRect.hpp"
using namespace std;



void CreateRect::createArray()
{
    rect.getInputRect();
}

void CreateRect::printArray()
{
    
    
     // read the list of verticies
    
    cout << "compResX: " << rect.compResX << endl;
    cout << "compResY: " << rect.compResY << endl;
    cout << endl;
    cout << "=================================" << endl;
    cout << endl;
    
    for (int i=0;i<rect.sIndex;i++)
    {
        
        cout << "screen " << i+1 << ": " << endl;
        
        for (int j=0;j<4;j++)
        {
            cout << rect.xArrayPtr[j+(4*i)] << " ";
            cout << rect.yArrayPtr[j+(4*i)] << endl;
        }
        
        cout << endl;
        
    }
     
    
    
}
