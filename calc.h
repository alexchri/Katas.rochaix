//
//  calc.hpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef calc_hpp
#define calc_hpp

#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

void help_message(); //print out help message

std::string calc(const std::string& input); //process word input

void test(const std::string& file);  //test *.txt file

#endif /* calc_h */
