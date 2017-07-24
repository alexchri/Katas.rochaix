//
//  Driver.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "Driver.h"

#include <sstream>
#include <utility>

void Driver::insert(std::string coin) {
    coinSlot.insertCoin(coin);
    display = coinSlot.printDisplay();
}

void Driver::select(std::string item) {
    if(item == "Cola") {
        if(coinSlot.readTotal() >= 1) {
            display = "THANK YOU";
            coinSlot.transaction(1);
        }
        else {
            display = "PRICE: 0.65";
        }
    }
    else if(item == "Chips") {
        if(coinSlot.readTotal() >= 0.5) {
            display = "THANK YOU";
            coinSlot.transaction(0.5);
        }
        else {
            display = "PRICE: 0.65";
        }
    }
    else if(item == "Candy") {
        if(coinSlot.readTotal() >= 0.65) {
            display = "THANK YOU";
            coinSlot.transaction(0.65);
        }
        else {
            display = "PRICE: 0.65";
        }
    }
}

void Driver::coinReturn() {
    //for later functionality
}

std::string Driver::checkDisplay() {
    std::string refresh = display;
    display = coinSlot.printDisplay();
    return refresh;
}
