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
    cout << "\nValid inputs include:\n\t<numeral> for Roman Numeral to number\n\t<number> for Number to Roman Numeral\n\t'q' at any time to quit the program.\n\t'test', then '*.txt' to run input from test file (*.txt)\n\t'help' at any time to return to this message.\nValid range for calculator:\n\t0 to 3999\n\n";
}

bool valid_rom(const string& rom) { //most complicated function of the program!
    
    if((int)rom.size() == 1) {
        return true;
    }
    
    int I = 0;
    int X = 0;
    int C = 0;
    int M = 0;
    int V = 0;
    int L = 0;
    int D = 0;
    
    for(unsigned long i = 1; i < rom.size(); ++i) {
        if(rom[i-1] == 'I') { //check for no more than 3 repeats of I, correct position of I
            ++I;
            if(rom[i-1] == 'I') {
                if((rom[i] == 'L') || (rom[i] == 'C') || (rom[i] == 'D') || (rom[i] == 'M')) {
                    return false;
                }
            }
            if(I >= 3) {
                return false;
            }
        }
        if(rom[i-1] == 'X') { //check for no more than 3 repeats of X, correct position of X
            ++X;
            if(rom[i-1] == 'X') {
                if((rom[i] == 'D') || (rom[i] == 'M')) {
                    return false;
                }
            }
            if(X >= 3) {
                return false;
            }
        }
        if(rom[i-1] == 'C') { //check for no more than 3 repeats of C, correct position of C
            ++C;
            if(C >= 3) {
                return false;
            }
        }
        if(rom[i-1] == 'M') { //check for no more than 3 repeats of M, correct position of M
            ++M;
            if(M >= 3) {
                return false;
            }
        }
        if(rom[i-1] == 'V') { //check for no duplicate V, correct position of V
            ++V;
            if(rom[i-1] == 'V') {
                if((rom[i] == 'L') || (rom[i] == 'D') || (rom[i] == 'X') || (rom[i] == 'C') || (rom[i] == 'M')) {
                    return false;
                }
            }
            if(V > 1) {
                return false;
            }
        }
        if(rom[i-1] == 'L') { //check for no duplicate L, correct position of L
            ++L;
            if(L > 1) {
                return false;
            }
            if(rom[i-1] == 'L') {
                if((rom[i] == 'C') || (rom[i] == 'M') || (rom[i] == 'D')) {
                    return false;
                }
            }
        }
        if(rom[i-1] == 'D') { //check for no duplicate D, correct position of D
            ++D;
            if(rom[i-1] == 'D') {
                if(rom[i] == 'M') {
                    return false;
                }
            }
            if(D > 1) {
                return false;
            }
        }
    }
    return true;
}

bool valid_num(const string& num) {
    if((stoi(num) >= 0) && (stoi(num) < 4000)) {
        return true;
    }
    return false;
}

int rORn(const string& input, const string& valid) { //returns -1 if invalid, 0 if roman, 1 if number
    int val = -1;
    
    if(isdigit(input[0])) { //if char is a num, return value is set to 1
        val = 1;
    }
    else if((int)valid.find(input[0]) != -1) { //if char is roman numeral, return value is set to 0
        val = 0;
    }
    else { //if neither, return -1 cause invalid input
        return val;
    }

    for(unsigned long i = 1; i < input.size(); ++i) { //invalid check using first char as comparator
        if(isdigit(input[i])) {
            if(val == 0) {
                return val = -1;
            }
        }
        else if((int)valid.find(input[i]) != -1) {
            if(val == 1) {
                return val = -1;
            }
        }
    }
    return val;
}

string calc(const string& input) {
    string answer;
    string valid = "IVXLCDM";
    
    int type = rORn(input, valid);
    
    if(type == -1) {
        return "invalid";
    }
    else if(type == 0) { //roman numeral
        answer = number(input);
    }
    else if(type == 1) { //number 
        answer = roman(input);
    }
    return answer;
}

string number(const string& rom) {
    string answer;
    char prev = '_';
    int val = 0;
    if(!valid_rom(rom)) {
        return "invalid";
    }
    for(unsigned long i = 0; i < rom.size(); ++i) {
        if(rom[i] == 'I') { //1
            ++val;
            prev = rom[i];
        }
        else if(rom[i] == 'V') { //5
            if(prev == 'I') {
                val += 3; //case of IV = 4
            }
            else {
                val += 5;
            }
            prev = rom[i];
        }
        else if(rom[i] == 'X') { //10
            if(prev == 'I') {
                val += 8; //case of IX = 9
            }
            else {
                val += 10;
            }
            prev = rom[i];
        }
        else if(rom[i] == 'L') { //50
            if(prev == 'X') {
                val += 30; //case of XL = 40
            }
            else {
                val += 50;
            }
            prev = rom[i];
        }
        else if(rom[i] == 'C') { //100
            if(prev == 'X') {
                val += 80; //case of XC = 90
            }
            else {
                val += 100;
            }
            prev = rom[i];
        }
        else if(rom[i] == 'D') { //500
            if(prev == 'C') {
                val += 300; //case of CD = 400
            }
            else {
                val += 500;
            }
            prev = rom[i];
        }
        else if(rom[i] == 'M') { //1000
            if(prev == 'C') {
                val += 800; //case of CM = 900
            }
            else {
                val += 1000;
            }
            prev = rom[i];
        }
    }
    return answer = to_string(val);
}

string roman(const string& num) {
    string temp = "";
    string answer = "";
    int exp_ten = 0;
    if(!valid_num(num)) { //valid num check: between 0 and 3999
        return "invalid";
    }
    for(int i = (int)num.size() - 1; i >= 0; --i) {
        if(num[(unsigned long)i] == '1') {
            if(exp_ten == 0) {
                temp = "I"; //1
            }
            else if(exp_ten == 1) {
                temp = "X"; //10
            }
            else if(exp_ten == 2) {
                temp = "C"; //100
            }
            else if(exp_ten == 3) {
                temp = "M"; //1000
            }
        }
        else if(num[(unsigned long)i] == '2') {
            if(exp_ten == 0) {
                temp = "II"; //2
            }
            else if(exp_ten == 1) {
                temp = "XX"; //20
            }
            else if(exp_ten == 2) {
                temp = "CC"; //200
            }
            else if(exp_ten == 3) {
                temp = "MM"; //2000
            }
        }
        else if(num[(unsigned long)i] == '3') {
            if(exp_ten == 0) {
                temp = "III"; //3
            }
            else if(exp_ten == 1) {
                temp = "XXX"; //30
            }
            else if(exp_ten == 2) {
                temp = "CCC"; //300
            }
            else if(exp_ten == 3) {
                temp = "MMM"; //3000
            }
        }
        else if(num[(unsigned long)i] == '4') {
            if(exp_ten == 0) {
                temp = "IV"; //4
            }
            else if(exp_ten == 1) {
                temp = "XL"; //40
            }
            else if(exp_ten == 2) {
                temp = "CD"; //400
            }
        }
        else if(num[(unsigned long)i] == '5') {
            if(exp_ten == 0) {
                temp = "V"; //5
            }
            else if(exp_ten == 1) {
                temp = "L"; //50
            }
            else if(exp_ten == 2) {
                temp = "D"; //500
            }
        }
        else if(num[(unsigned long)i] == '6') {
            if(exp_ten == 0) {
                temp = "VI"; //6
            }
            else if(exp_ten == 1) {
                temp = "LX"; //60
            }
            else if(exp_ten == 2) {
                temp = "DC"; //600
            }
        }
        else if(num[(unsigned long)i] == '7') {
            if(exp_ten == 0) {
                temp = "VII"; //7
            }
            else if(exp_ten == 1) {
                temp = "LXX"; //70
            }
            else if(exp_ten == 2) {
                temp = "DCC"; //700
            }
        }
        else if(num[(unsigned long)i] == '8') {
            if(exp_ten == 0) {
                temp = "VIII"; //8
            }
            else if(exp_ten == 1) {
                temp = "LXXX"; //80
            }
            else if(exp_ten == 2) {
                temp = "DCCC"; //800
            }
        }
        else if(num[(unsigned long)i] == '9') {
            if(exp_ten == 0) {
                temp = "IX"; //9
            }
            else if(exp_ten == 1) {
                temp = "XC"; //90
            }
            else if(exp_ten == 2) {
                temp = "CM"; //900
            }
        }
        else if(num[(unsigned long)i] == '0') {
            //nothing
        }
        temp += answer; //insert temp in front of previous answer since going right to left
        answer = temp;
        ++exp_ten; //shift 10 by power of one to the left
    }
    return answer;
}

void test(const string& file) { //add .txt validation and user output
    string in;
    string out;
    string value;
    int line = 1;
    bool passed = true;
    streambuf *b = cout.rdbuf();
    streambuf *a = cin.rdbuf();
    if((int)file.find(".txt") != -1) { //cast int because size_t vs signed
        ifstream input(file); //open infile named 'file'
        if(!input.is_open()) {
            cout << "Invalid *.txt file\n\n";
            return;
        }
        cin.rdbuf(input.rdbuf()); //redirect cin to in.txt!
        ofstream output("out.txt"); //open outfile named 'out.txt'
        if(!output.is_open()) {
            cout << "Did not find out.txt file\n\n";
            return;
        }
        cout.rdbuf(output.rdbuf()); //redirect cout to out.txt!
        
    loop:
        while(cin >> in) {
            if(in[0] == '/') { //allow comments in *.txt file
                string junk;
                getline(cin, junk);
                ++line;
                goto loop;
            }
            cin >> value;
//**************************************************************************
            out = calc(in); //TEST THE MAIN FUNCTION OF ROMAN.CPP
//**************************************************************************
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
        
        cout << endl; //return to terminal output
        if(passed) {
            cout << "Pass!" << endl << endl;
        }
        else {
            cout << "See out.txt for errors" << endl << endl;
        }
        input.close(); //close files for good practice
        output.close();
    }
    return;
}
