//
//  AcceptCoins.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#include "AcceptCoins.h"

void ReadInsertedCoins::insertCoin(std::string coins) {
    //minimal code required to pass test
    if(coins == "Quarter") {
        runningTotal = 0.25;
    }
    else if(coins == "Dime") {
        runningTotal = 0.10;
    }
    else if(coins == "Nickel") {
        runningTotal = 0.05;
    }
}

double ReadInsertedCoins::readTotal() {
    //getter class function
    return runningTotal;
}
