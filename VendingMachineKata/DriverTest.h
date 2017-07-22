//
//  DriverTest.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef DriverTest_h
#define DriverTest_h

#include <cassert>

#include "Driver.h"
#include "AcceptCoins.h"
#include "SelectProduct.h"

class DriverTest {
    
public:
    void WhenSelectProductandNotEnoughCoinsThenDisplayPrice() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.select("Candy");
        assert("PRICE: 0.65" == vendingMachine.display());
    }
};

#endif /* Header_h */
