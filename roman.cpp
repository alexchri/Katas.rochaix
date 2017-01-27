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
    
//(1) ADD COMMENT FUNCTIONALITY TO TEST FILE FUNCTIONALITY
//(2) FINISH VALID_ROM CHECK
    
    string input;
    cout << "Welcome to Roman Numeral calculator!\n\n";
    
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
