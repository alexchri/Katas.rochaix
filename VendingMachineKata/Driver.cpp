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

Driver::Driver() {
    machine.stockWithSnack();
    coinSlot.stockWithCoin(5);
}

void Driver::insert(std::string coin) {
    coinSlot.insertCoin(coin);
    display = coinSlot.printDisplay();
}

void Driver::select(std::string item) {
    SnackItem snack = machine.findItem(item);
    
    if(machine.returnNumLeft(snack.getName()) == 0) {
        display = "SOLD OUT";
        return;
    }
    
    if(coinSlot.readTotal() >= snack.getPrice()) {
        display = "THANK YOU";
        coinSlot.transaction(snack.getPrice());
        machine.dispenseItem(snack.getName());
    }
    else {
        std::stringstream read;
        read << "PRICE: " << snack.getPrice();
        display = read.str();
    }
}

void Driver::coinReturn() {
    coinSlot.returnCoins();
}

std::string Driver::checkDisplay() {
    //print current and refresh display in background
    std::string refresh = display;
    display = coinSlot.printDisplay();
    return refresh;
}
