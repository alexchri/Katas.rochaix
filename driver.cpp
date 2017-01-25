//
//  driver.cpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//
#include "calc.h"
using namespace std;

int main(int argc, char * argv[]) {
    flags flag;
    string input;
    
/******** PROCESS CMNDLINE *************/
    
    cmndline(flag, argc, argv);

/*********** USER INPUT ****************/
    
    while(input != "q") {
        cin >> input;
        calc(input, flag); //produce correct flag output
    }
    
    return 0;
}
