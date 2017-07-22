//
//  AcceptCoins.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#include "AcceptCoins.h"

ReadInsertedCoins::ReadInsertedCoins() {
    display << std::fixed << std::setprecision(2);
    display << "INSERT COIN";
    runningTotal = 0;
    rejectedTotal = 0;
}

void ReadInsertedCoins::insertCoin(std::string coins) {
    //minimal code required to pass test
    
    display.str("");
    display.clear();
    
    if(coins == "Quarter") {
        runningTotal += 0.25;
    }
    else if(coins == "Dime") {
        runningTotal += 0.1;
    }
    else if(coins == "Nickel") {
        runningTotal += 0.05;
    }
    else {
        display << "INVALID COIN";
        rejectedTotal += 0.01;
        return;
    }
    
    display << runningTotal;
}

double ReadInsertedCoins::readTotal() {
    //getter class function
    int roundToCent = (int)(100 * runningTotal);
    return (double)roundToCent/100;
}

double ReadInsertedCoins::rejectedCoins() {
    int roundToCent = (int)(100 * rejectedTotal);
    return (double)roundToCent/100;
}

std::string ReadInsertedCoins::printDisplay() {
    return display.str();
}
