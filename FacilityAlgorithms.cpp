//
//  FacilityAlgorithms.cpp
//  Simple Simplex Modeling Tool
//
//  Created by Ege Demirbaş on 12.03.2020.
//  Copyright © 2020 Ege Demirbaş. All rights reserved.
//


#include "MainControl.hpp"
#include <iostream>

using namespace std;

void ModellingClass::Process_Layout()
{
    
    int ROWS;
    int COLUMNS;
    int Check;
    
    int Column_Weight[500];
    int Row_Weight[500];
    int My_Matrix[500][500];
    
    cout << "enter your machine amount\n"<< endl; cin >> ROWS;
    cout << "enter your part amount\n" << endl; cin >> COLUMNS;
    
    cout << "how many parts do you have ?:\n";
    
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            cout << "does machine " << i << " uses part " << j << "? " << endl; cin >> Check;
            if(Check == 1)
            {
                My_Matrix[i][j] = 1;
            }
            else if(Check != 1)
            {
                My_Matrix[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            Column_Weight[j] = 2^(COLUMNS - j);
            if(My_Matrix[i][j] == 1)
            {
                Row_Weight[i] += Column_Weight[j];
            }
                
        }
    }
    
    //sorting - Descending ORDER
    int temp;
    for(int i=0;i<ROWS;i++)
    {
        for(int j=i+1;j<COLUMNS;j++)
        {
            if(Row_Weight[i]<Row_Weight[j])
            {
                temp = Row_Weight[i];
                Row_Weight[i] = Row_Weight[j];
                Row_Weight[j] = temp;
            }
        }
    }
    
    for(int i=0;i<ROWS;i++)
           for(int j=i+1;j<COLUMNS;j++)
               
               cout << Row_Weight[j];
           
    
    
    
    /*
    cout << "your clustering matrix\n";
    for (int row=0; row<ROWS; row++)
    {
        for(int columns=0; columns<COLUMNS; columns++)
            {
             printf("%d ", My_Matrix[row][columns]);
            }
        printf("\n");
     }
     */
        
        
}
