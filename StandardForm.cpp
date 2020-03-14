//
//  Standard Form.cpp
//  Simple Simplex Modeling Tool
//
//  Created by Ege Demirbaş on 1.10.2019.
//  Copyright © 2019 Ege Demirbaş. All rights reserved.
//
#include "MainControl.hpp"
#include <iostream>

using namespace std;

 int ModellingClass::TakeModel()
{

    int VarrSize, ConstSize, ArtfSize, RhsSize, VarrSize2;
    int ObjFunc[500];
    int Const[500][500];
    int RHS[500];
    int ArfVarr[500];
    int SlackVarr[500];
    
    string SignVisual[10],WhichMethod, SignType, CurrentSign;
    
    cout << "=============================================================" << endl;
    cout << "this code takes your lp model and convert it to standard form" << endl;
    cout << "=============================================================" << endl;
    cout << "do you want to maximize or minimize? (type max or min)" << endl; cin >> WhichMethod;
    cout << "how many variables do you have in objective function" << endl; cin >> VarrSize;
    cout << "how many constraints do you have ?" << endl; cin >> ConstSize;
    cout << " " << endl;
    
    VarrSize2 = VarrSize;
    
    //OBJECTIVE FUNCTION
    if((WhichMethod == "MAX" or "max") and (VarrSize > 0))
    {
        int ConstantName = 0;
        for(int t = 0; t < VarrSize; t++)
        {
            ConstantName += 1;
            cout << "enter " <<ConstantName << ". variable's coefficent:" << endl; cin >> ObjFunc[t];
        }
    }
    else
    {
        SystemControlClass BreakSystem;
        BreakSystem.RestartProgram();
    }
    
    //CONSTRAINTS
    if(ConstSize > 0)
    {
        int ConstantName = 0;
        int ConstraintName = 0;
        for(int i = 0; i < ConstSize; i ++)
        {
            ConstraintName += 1;
            cout << "=============================================================" << endl;
            cout << "enter the " << ConstraintName << "'th constraints constants"   << endl;
            cout << "=============================================================" << endl;
            
            for(int j = 0; j < VarrSize2; j++)
            {
                ConstantName += 1;
                cout << "enter" << ConstantName << "'th variables's constant:" << endl; cin >> Const[i][j];
            }
            
            cout <<"what is the sign of RHS ? (< or > or >= or <=)"<< endl; cin >> SignType;
            
            if(SignType == "<")
            {
                SlackVarr[i] = 1;
            }
            else if(SignType == ">")
            {
                SlackVarr[i] = -1;
            }
            else if((SignType == "<=") || (SignType == "=<"))
            {
                SlackVarr[i] = 1;
                ArfVarr[i] = 1;
            }
            else if((SignType == ">=") || ("=>"))
            {
                SlackVarr[i] = -1;
                ArfVarr[i] = 1;
            }
        
            cout << "what is the vaule of RHS?" << endl; cin >> RHS[i];

        }
    }
    else
    {
       SystemControlClass BreakSystem;
       BreakSystem.RestartProgram();
    }
    
    //PRINT THE RESULTS
    cout << "=============================================================" << endl;
    cout << "                 HERE IS YOUR GOD DAMN LP MODEL              " << endl;
    cout << "=============================================================" << endl;
    cout << "                                                             " << endl;
    
    //OBJECTIVE FUNCTIION
    int Index = 0;
    for(int t = 0; t < VarrSize; t++)
    {
        Index += 1;
        printf("%dX%d ", -ObjFunc[t] ,Index);
    }
    printf("= 0"); //tail of objective function
    
    cout << "                                                             " << endl;
    cout << "                                                             " << endl;

    //CONSTRAINTS
    Index = 0;
    for(int i = 0; i < ConstSize; i++)
    {
        for(int j = 0; j < VarrSize; j++)
        {
            Index +=1;
            cout << Index << "th constraint: " << Const[i][j] << "X" << Index << " +" << endl;
        }
    }
    
    



    
    
    
    
    
    
    
    
    
    /*
    //GLOBAL VARIABLES
    int NumberOfVariables, NumberOfConst, SlackVarrSize, Index;
    double ObjFuncCoeff[NumberOfVariables];
    double SlackVarr[SlackVarrSize];
    double ArtificalVarr[SlackVarrSize];
    double RHSVarr[NumberOfConst];
    double ContsCoeff[NumberOfConst][NumberOfVariables];
    
    string SignVisual[SlackVarrSize],WhichMethod, SignType, CurrentSign;
    
    //START MODELLING
    cout << "=============================================================" << endl;
    cout << "this code takes your lp model and convert it to standard form" << endl;
    cout << "=============================================================" << endl;

    //TAKE OBJECTIVE FUNCTION
    printf("do you want to maximize or minimize? (Type MAX or max)"); cin >> WhichMethod;
    printf("how many variables do you have on objective function"); cin >> NumberOfVariables;
    
    if(( WhichMethod == "MAX" || WhichMethod == "max") && (NumberOfVariables > 0))
    {
        int ConstantName = 0;
        for(int k = 0; k < NumberOfVariables; k++)
        {
            ConstantName += 1;
            printf("enter %d. variables's constant:",ConstantName); scanf("%lf", &ObjFuncCoeff[k]);
        }
    }
    else
    {
        SystemControlClass BreakSystem;
        BreakSystem.RestartProgram();
    }
    //TAKE CONSTRAINTS
    printf("how many constraints do you have ?"); cin >> NumberOfConst;
    
    if(NumberOfConst > 0)
    {
        int ConstantName = 0; //set back to zero
        int ConstraintName = 0;
        for(int j = 0; j < NumberOfConst; j++)
        {
            ConstraintName += 1;
            cout << "=============================================================" << endl;
            cout << "enter the " << ConstraintName << "'th constraints constants"   << endl;
            cout << "=============================================================" << endl;
            
            for(int i = 0; i < NumberOfVariables; i++)
            {
                ConstantName += 1;
                printf("enter %d'th variables's constant:",ConstantName); scanf("%lf", &ContsCoeff[j][i]);
            }
            //get the rhs type slack or excess?
            printf("what is the sign of RHS ? (< or > or >= or <=)"); cin >> SignType;
            
            if(SignType == "<")
            {
                SignVisual[j] = "+S1";
                SlackVarr[j] = 1;
            }
            else if(SignType == ">")
            {
                SignVisual[j] = "+E1";
                SlackVarr[j] = -1;
            }
            else if(SignType == "=")
            {
                SignVisual[j] = "+A1";
                //TODO
            }
            else if((SignType == "<=") || (SignType == "=<"))
            {
                SignVisual[j] = " +S1 +A1";
                SlackVarr[j] = 1;
                ArtificalVarr[j] =  1;
            }
            else if((SignType == ">=") || ("=>"))
            {
               SignVisual[j] = " +S1 -A1";
               SlackVarr[j] = 1;
               ArtificalVarr[j] =  1;
            }
            printf("what is the value of RHS"); cin >> RHSVarr[j];
            //take the right hand side of the constraint
        }
    }
    else
    {
        SystemControlClass BreakSystem;
        BreakSystem.RestartProgram();
    }
    
    //PRINT THE STANDARD FORM
    cout << "=============================================================" << endl;
    cout << "                 HERE IS YOUR GOD DAMN LP MODEL              " << endl;
    cout << "=============================================================" << endl;
    cout << "                                                             " << endl;
    
    //print the objective function
    printf("OBJECTIVE FUNCTION:  Z "); //head of the objective function

    Index = 0;
    for(int t = 0; t < NumberOfVariables; t++)
    {
        Index += 1;
        printf("%0.2lfX%d ", -ObjFuncCoeff[t] ,Index);
    }
    printf("= 0"); //tail of objective function
    
    cout << "                                                             " << endl;
    cout << "                                                             " << endl;
    
    //print the constraints
    Index = 0; //set back to zero
    for(int j = 0; j < NumberOfConst; j++)
    {
    cout << "                                                             " << endl;
    cout << "                                                             " << endl;
        printf("%d'th CONSTRAINT:  ", j+1);
        Index = 0;
        for(int i = 0; i < NumberOfVariables; i++)
        {
            Index += 1;
            printf("%0.2lfX%d+ ", ContsCoeff[j][i] ,Index);
        }
        
        
        printf("%s = %0.2lf", SignVisual[j].c_str(), RHSVarr[j]);
    cout << "                                                             " << endl;
    cout << "                                                             " << endl;
    }
    Index = 0;
    for(int i = 0; i < NumberOfVariables; i++)
    {
        Index += 1;
        printf("X%d + ", Index);
        if(i == NumberOfVariables -1)
        {
            Index += 1;
            printf("X%d ", Index);
        }
    }
    
    for(int i = 0; i < NumberOfConst; i++)
    {
        if (i < 0)
            break;
        printf("%s",SignVisual[i].c_str());
    }
    printf(" > 0 (non negativity)");
    
    cout << "                                                             " << endl;
    cout << "                                                             " << endl;
    */
    //START SIMPLEX CALCULATINOS
    /*
    ModelCalculationClass StartModelling;
    StartModelling.SimplexAlgorithm(ObjFuncCoeff, NumberOfVariables, ContsCoeff, NumberOfVariables, SlackVarr, SlackVarrSize, ArtificalVarr, SlackVarrSize, RHSVarr, NumberOfConst);
    */
    return 0;
}
