//
//  main.cpp
//  Simple Simplex Modeling Tool
//
//  Created by Ege Demirbaş on 1.10.2019.
//  Copyright © 2019 Ege Demirbaş. All rights reserved.
//
#include "StandardForm.hpp"
#include "MainControl.hpp"
#include <iostream>
using namespace std;

int main()
{
    
    cout << "=============================================================" << endl;
    cout << "STANDARD FORM CONVERSION 1)" << endl;
    cout << "LP MODELLING 2)" << endl;
    cout << "=============================================================" << endl;
    
    int Selected = 0; int UsersSelection; cin >> UsersSelection;
    
    while(Selected == 0)
    {
        //ONLY STANDARD FORM CONVERSION
        if(UsersSelection == 1)
        {
            ModellingClass getModel;
            getModel.TakeModel();
            Selected++;
        }
        //SIMPLEX MODELLING1
        else if(UsersSelection == 2)
        {
            ModellingClass getModel;
            getModel.TakeModel();
            Selected++;
        }
        //SIMPLEX + STANDARD FORM
        else
        {
            printf("TODO");
        }
        
    }
    return 0;
}
