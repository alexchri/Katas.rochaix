//
//  calc.cpp
//  Roman
//
//  Created by Alexandre Rochaix on 1/24/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "calc.h"
using namespace std;

void help_message() {
    cout << "\nWelcome to Roman Numeral calculator!\nValid inputs include:\n\t<numeral> for Roman Numeral to number\n\t<number> for Number to Roman Numeral.\n\t'q' at any time to quit the program.\n\t'test', then '*.txt' to run input from test file (*.txt)\n\t'help' at any time to return to this message.\n\n";
}

int rORn(const string& input) { //returns -1 if invalid, 0 if roman, 1 if number
    int val = -1;
    string valid = "IVXLCDM";
    
    if(isdigit(input[0])) { val = 1; } //if char is a num, return value is set to 1
    else if(valid.find(input[0]) != -1) { val = 0; } //if char is roman numeral, return value is set to 0
    else { return val; } //if neither, return -1 cause invalid input

    for(int i = 1; i < (int)input.size(); ++i) { //invalid check using first char as comparator
        if(isdigit(input[i])) {
            if(val == 0) {
                return val = -1;
            }
        }
        else if(valid.find(input[0]) != -1) {
            if(val == 1) {
                return val = -1;
            }
        }
    }
    return val;
}

string calc(const string& input) {
    string answer;
    int type = rORn(input);
    if(type == -1) {
        return "Invalid input, try again\n";
    }
    else if(type == 0) { //roman numeral
        
    }
    else if(type == 1) { //number 
        
    }
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
        if(passed) {
            cout << "Pass!" << endl;
        }
        else {
            cout << "See out.txt for errors" << endl << endl;
        }
    }
    return;
}
