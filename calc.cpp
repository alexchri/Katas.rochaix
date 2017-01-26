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
    cout << "Welcome to Roman Numeral calculator!\n\nValid inputs include:\n\t<numeral> for Roman Numeral to number\n\t<number> for Number to Roman Numeral\n\t'q' at any time to quit the program.\n\t'test', then '*.txt' to run input from test file (*.txt)\n\t'help' at any time to return to this message.\nValid range for calculator:\n\t0 to 3999\n\n";
}
bool valid_rom(const string& rom) {
    if((int)rom.size() == 1) {
        return true;
    }
    char prev = rom[0];
    for(int i = 1; i < (int)rom.size(); ++i) {
        if(rom[i] == 'I'){
            
        }
        else if(rom[i] == 'X') {
            
        }
        else if(rom[i] == 'C') {
            
        }
        else if(rom[i] == 'M') {
            
        }
        else if(rom[i] == 'V') {
            
        }
        else if(rom[i] == 'L') {
            
        }
        else if(rom[i] == 'D') {
            
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
    
    if(isdigit(input[0])) { val = 1; } //if char is a num, return value is set to 1
    else if(valid.find(input[0]) != -1) { val = 0; } //if char is roman numeral, return value is set to 0
    else { return val; } //if neither, return -1 cause invalid input

    for(int i = 1; i < (int)input.size(); ++i) { //invalid check using first char as comparator
        if(isdigit(input[i])) {
            if(val == 0) {
                return val = -1;
            }
        }
        else if(valid.find(input[i]) != -1) {
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
    
    for(int i = 0; i < (int)rom.size(); ++i) {
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
        if(num[i] == '1') {
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
        else if(num[i] == '2') {
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
        else if(num[i] == '3') {
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
        else if(num[i] == '4') {
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
        else if(num[i] == '5') {
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
        else if(num[i] == '6') {
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
        else if(num[i] == '7') {
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
        else if(num[i] == '8') {
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
        else if(num[i] == '9') {
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
        else if(num[i] == '0') {
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
    if((int)file.find(".txt") != -1) {
        //cast int because size_t vs signed
        ifstream input(file);
        if(!input.is_open()) {
            cout << "Invalid *.txt file\n\n";
            return;
        }
        cin.rdbuf(input.rdbuf()); //redirect std::cin to in.txt!
        ofstream output("out.txt");
        if(!output.is_open()) {
            cout << "Did not find out.txt file\n\n";
            return;
        }
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
