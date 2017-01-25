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
    return "\nWelcome to Roman Numeral calculator!\nValid inputs include:\n\t<numeral> for Roman Numeral to number\n\t<number> for Number to Roman Numeral.\n\t'q' at any time to quit the program.\n\t'test', then '*.txt' to run input from test file (*.txt)\n\t'help' at any time to return to this message.\n\n";
}

string calc(const string& input) {
    string answer;
    
    return answer;
}

void test(const string& file) {
    string in;
    string out;
    string value;
    int line = 1;
    bool passed = true;
    streambuf *b = cout.rdbuf();
    streambuf *a = cin.rdbuf();
    if((int)file.find(".txt") != -1) {
        //cast int because size_t vs signed
        ifstream input(file);
        cin.rdbuf(input.rdbuf()); //redirect std::cin to in.txt!
        ofstream output("out.txt");
        cout.rdbuf(output.rdbuf()); //redirect std::cout to out.txt!
        //freopen(file.c_str(), "r", stdin);
        //freopen("out.txt", "w", stdout);
        while(cin >> in) {
            cin >> value;
            out = calc(in);
            if(out != value) {
                passed = false;
                cout << "line " << line << ": " << out << endl;
            }
            ++line;
        }
        if(passed) {
            cout << "Pass!";
        }
        cin.rdbuf(a);
        cout.rdbuf(b);
        cout << endl;
    }
    return;
}
