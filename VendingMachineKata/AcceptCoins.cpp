//
//  AcceptCoins.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#include <cmath>

#include "AcceptCoins.h"

CoinCounter::CoinCounter() {
    //coin slot
    coinSlot.numQuarters = 0;
    coinSlot.numDimes = 0;
    coinSlot.numNickels = 0;
    //coins available for change from machine
    changeAvailable.numQuarters = 0;
    changeAvailable.numDimes = 0;
    changeAvailable.numNickels = 0;
    //coin return
    coinReturn.numQuarters = 0;
    coinReturn.numDimes = 0;
    coinReturn.numNickels = 0;
    coinReturn.numPennies = 0;
}

void CoinCounter::stockWithChange(int numOfEachCoin) {
    //default of 5 coins
    changeAvailable.numQuarters += numOfEachCoin;
    changeAvailable.numDimes += numOfEachCoin;
    changeAvailable.numNickels += numOfEachCoin;
}

void CoinCounter::insertQuarter() {
    ++coinSlot.numQuarters;
}

void CoinCounter::insertDime() {
    ++coinSlot.numDimes;
}

void CoinCounter::insertNickel() {
    ++coinSlot.numNickels;
}

void CoinCounter::insertPenny() {
    ++coinReturn.numPennies;
}

double CoinCounter::getRunningTotal() {
    return 0.25*coinSlot.numQuarters + 0.10*coinSlot.numDimes
        + 0.05*coinSlot.numNickels;
}

double CoinCounter::getChangeMade() {
    return 0.25*coinReturn.numQuarters + 0.10*coinReturn.numDimes
        + 0.05*coinReturn.numNickels + 0.01*coinReturn.numPennies;
}

void CoinCounter::acceptCoins() {
    //accept coins
    changeAvailable.numQuarters += coinSlot.numQuarters;
    changeAvailable.numDimes += coinSlot.numDimes;
    changeAvailable.numNickels += coinSlot.numNickels;
    //reset
    coinSlot.numQuarters = coinSlot.numDimes = coinSlot.numNickels = 0;
}

void CoinCounter::makeChangeFor(double amount) {
    //make change for <amount>
    //converted to integer comparison for ease
    int total = int(ceil(100 * amount));
    
    size_t Q = changeAvailable.numQuarters;
    for(; (Q > 0) && (total - 25 >= 0);--Q) {
        ++coinReturn.numQuarters;
        --changeAvailable.numQuarters;
        total -= 25;
    }
    size_t D = changeAvailable.numDimes;
    for(; (D > 0) && (total - 10 >= 0);--D) {
        ++coinReturn.numDimes;
        --changeAvailable.numDimes;
        total -= 10;
    }
    size_t N = changeAvailable.numNickels;
    for(; (N > 0) && (amount - 10 >= 0);--N) {
        ++coinReturn.numNickels;
        --changeAvailable.numNickels;
        total = 5;
    }
}

void CoinCounter::cancelAndReturnCoins() {
    //implementation later!
}

ReadInsertedCoins::ReadInsertedCoins() {
    display << std::fixed << std::setprecision(2);
    display << "INSERT COIN";
    CoinCounter();
}

void ReadInsertedCoins::stockWithCoin() {
    machine.stockWithChange(5);
}

void ReadInsertedCoins::insertCoin(std::string coins) {
    //minimal code required to pass test
    
    display.str("");
    display.clear();
    
    if(coins == "Quarter") {
        machine.insertQuarter();
    }
    else if(coins == "Dime") {
        machine.insertDime();
    }
    else if(coins == "Nickel") {
        machine.insertNickel();
    }
    else {
        display << "INVALID COIN";
        machine.insertPenny();
        return;
    }
    
    display << machine.getRunningTotal();
}

void ReadInsertedCoins::transaction(double price) {
    double changeToMake = machine.getRunningTotal() - price;
    //machine swallows coins
    machine.acceptCoins();
    machine.makeChangeFor(changeToMake);
}

double ReadInsertedCoins::readTotal() {
    //getter class function
    int roundToCent = (int)(100 * machine.getRunningTotal());
    return (double)roundToCent/100;
}

double ReadInsertedCoins::rejectedCoins() {
    int roundToCent = (int)(100 * machine.getChangeMade());
    return (double)roundToCent/100;
}

void ReadInsertedCoins::returnCoins() {
    //implementation later!
}

std::string ReadInsertedCoins::printDisplay() {
    std::string temp = display.str();
    display.str("");
    display.clear();
    
    if(machine.getRunningTotal() == 0)
        display << "INSERT COIN";
    else
        display << machine.getRunningTotal();
    
    if(temp == "INVALID COIN")
        return "INVALID COIN";
    
    return display.str();
}
