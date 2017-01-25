//
//  calc.cpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "calc.h"
using namespace std;

string help_message() {
    return "\nWelcome to Roman Numeral calculator!\nValid inputs include:\n\t$numeral for Roman Numeral to number\n\t$number for Number to Roman Numeral.\nEnter 'q' at any time to quit the program.\nEnter 'help' at any time to return to this message.\n\n";
}

void calc(const string& input) {
    if(input == "help") {
        printf("%s", help_message().c_str());
    }
    else {
        
    }
}
