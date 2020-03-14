//
//  main.cpp
//  Simple Simplex Modeling Tool
//
//  Created by Ege Demirbaş on 1.10.2019.
//  Copyright © 2019 Ege Demirbaş. All rights reserved.
//
#include "MainControl.hpp"
#include <iostream>
using namespace std;

int main()
{
    
    int Options;
    cout << "SELECT OPTION" << endl;
    cout <<" "<< endl;
    cout << "1- Standard Form Conversion" << endl;
    cout <<" "<< endl;
    cout << "2- Simplex Modelling" << endl;
    cout <<" "<< endl;
    cout << "3- Optimize Process Layout (Clustering Algorithm)" << endl;
    cin >> Options;
    
    switch (Options)
    {
        case 1:
            
            ModellingClass getModel;
            getModel.TakeModel();
            break;
            
        case 2:
            
            
            break;
            
        case 3:
            
            getModel.Process_Layout();
            
        default:
            
            SystemControlClass BreakSystem;
            BreakSystem.RestartProgram();
            
    }

    
    return 0;
}
