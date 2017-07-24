//
//  Driver.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef Driver_hpp
#define Driver_hpp

#include "ItemsAndMachine.h"
#include "AcceptCoins.h"


#include <stdio.h>

class Driver {
    Machine machine;
    std::string display;
    ReadInsertedCoins coinSlot;
public:
    Driver();
    void insert(std::string coin);
    void select(std::string item);
    void coinReturn();
    std::string checkDisplay();
};
#endif /* Driver_hpp */
