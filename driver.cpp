//
//  driver.cpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//
#include "calc.h"
using namespace std;

int main() {
    
    string input;
    
/*********** USER INPUT ****************/
    while(input != "q") { //allow user to input multiple conversions
        cin >> input;
        if(input == "help") {
            printf("%s", help_message().c_str());
        }
        if(input == "test") {
            cin >> input;
            test(input);
            break; //exit program if test command is run
        }
        printf("%s", calc(input).c_str()); //produce correct flag output
    }
    
    return 0;
}
