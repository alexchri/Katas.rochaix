//
//  Driver.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "Driver.h"

#include <sstream>

void Driver::insert(std::string coin) {
    coinSlot.insertCoin(coin);
    display = coinSlot.printDisplay();
}

void Driver::select(std::string item) {
    if(item == "Cola") {
        
    }
    else if(item == "Chips") {
        
    }
    else if(item == "Candy") {
        if(coinSlot.readTotal() >= 0.65)
            display = "THANK YOU";
        else
            display = "PRICE: 0.65";
    }
}

void Driver::coinReturn() {
    //for later functionality
}

std::string Driver::checkDisplay() {
    if(display == "INVALID COIN") {
        std::stringstream read;
        read << coinSlot.readTotal();
        display = read.str();
        return "INVALID COIN";
    }
    return display;
}
