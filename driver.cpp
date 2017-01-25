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
    
    string input;
    
/*********** USER INPUT ****************/
    while(input != "q") { //allow user to input multiple conversions
        printf("enter: ");
        cin >> input;
        calc(input); //produce correct flag output
    }
    
    return 0;
}
