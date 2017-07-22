//
//  Driver.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef Driver_hpp
#define Driver_hpp

#include "AcceptCoins.h"
#include "SelectProduct.h"

#include <stdio.h>
class Driver {
    DispenseProduct vendingMachine;
    ReadInsertedCoins coinSlot;
public:
    void insert(std::string coin);
    void select(std::string item);
    void coinReturn();
    std::string display();
};
#endif /* Driver_hpp */
