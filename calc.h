//
//  calc.hpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef calc_hpp
#define calc_hpp

#include <getopt.h>
#include <iostream>
#include <stdio.h>

struct flags {
    bool r = false;
    bool n = false;
    bool h = false;
};
std::string help_message(); //print out help message
void cmndline(flags& flag, int argc, char* argv[]); //process commandline
void calc(const std::string& input); //process word input

#endif /* calc_h */
