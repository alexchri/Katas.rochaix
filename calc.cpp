//
//  calc.cpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "calc.h"
using namespace std;

void cmndline(flags& flag, int argc, char* argv[]) {
    //turn off getopt error message
    opterr = 1;
    int c;
    int index = 0;
    static struct option longopts[] = {
        { "numeral", no_argument, nullptr, 'r' },
        { "number", no_argument, nullptr, 'n' },
        { "help", no_argument, nullptr, 'h' },
        { nullptr, 0, nullptr, '\0' }
    };
    while ((c = getopt_long(argc, argv, "rnh", longopts, &index)) != -1)
    {
        switch (c) {
            case 'r':
                flag.r = true; //numeral is on
                break;
            case 'n':
                flag.n = true; //number is on
                break;
            case 'h':
                flag.h = true; //help is on
                break;
            default:
                cerr << "Unknown option " << c << endl;
                exit(1);
        }
    }
}

void calc(const string& input, flags& flag) {
    
}
