//
//  SimplexAlgorithm.hpp
//  Simple Simplex Modeling Tool
//
//  Created by Ege Demirbaş on 5.10.2019.
//  Copyright © 2019 Ege Demirbaş. All rights reserved.
//

#ifndef SimplexAlgorithm_hpp
#define SimplexAlgorithm_hpp
//#include "StandardForm.hpp"
#include <stdio.h>
using namespace std;

class ModelCalculationClass //:public ModellingClass
{
    public:
    void SimplexAlgorithm(double ObjFuncCoeff[], int NumberOfVariables, double ContsCoeff[], int NumberOfVariables2, double SlackVarr[], int SlackVarrSize, double ArtificalVarr[], int SlackVarrSize2, double RHSVarr[], int NumberOfConst);
  
};
#endif /* SimplexAlgorithm_hpp */
