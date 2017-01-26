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
    help_message();
    
/*********** USER INPUT ****************/
    while(input != "q") { //allow user to input multiple conversions
        
        cin >> input;
        
        if(input == "help") {
            help_message();
        }
        else if(input == "test") {
            cin >> input;
            test(input);
        }
        else if(input == "q") {
            //do nothing
        }
        else {
            cout << endl << calc(input) << endl << endl;
        }
    }
    
    return 0;
}
