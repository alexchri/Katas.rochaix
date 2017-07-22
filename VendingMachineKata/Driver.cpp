//
//  Driver.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "Driver.h"

void Driver::insert(std::string coin) {
    coinSlot.insertCoin(coin);
}

void Driver::select(std::string item) {
    
}

void Driver::coinReturn() {
    
}

std::string Driver::display() {
    return coinSlot.printDisplay();
}
