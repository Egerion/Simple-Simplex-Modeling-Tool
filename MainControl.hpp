//
//  MainControl.hpp
//  Simple Simplex Modeling Tool
//
//  Created by Ege Demirbaş on 1.10.2019.
//  Copyright © 2019 Ege Demirbaş. All rights reserved.
//

#ifndef MainControl_hpp
#define MainControl_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class SystemControlClass
{
    public:
    void RestartProgram();
    
};

//simplex modeling
class ModelCalculationClass
{
    public:
    void SimplexAlgorithm(double ObjFuncCoeff[], int NumberOfVariables, double ContsCoeff[], int NumberOfVariables2, double SlackVarr[], int SlackVarrSize, double ArtificalVarr[], int SlackVarrSize2, double RHSVarr[], int NumberOfConst);
  
};

//algorithms
class ModellingClass
{
    public:
    int TakeModel();
    
    public:
    void Process_Layout();
  
};
#endif /* MainControl_hpp */
