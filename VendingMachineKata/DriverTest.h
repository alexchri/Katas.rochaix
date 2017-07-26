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

class DriverTest {
    
public:
    void WhenSelectCandyandNotEnoughCoinsThenDisplayPrice() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.select("Candy");
        assert("PRICE: 0.65" == vendingMachine.checkDisplay());
    }
    
    void WhenSelectChipsAndNotEnoughCoinsThenDisplayPrice() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Dime");
        vendingMachine.select("Chips");
        assert("PRICE: 0.5" == vendingMachine.checkDisplay());
    }
    
    void WhenSelectColaAndNotEnoughCoinsThenDisplayPrice() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Dime");
        vendingMachine.insert("Quarter");
        vendingMachine.select("Cola");
        assert("PRICE: 1" == vendingMachine.checkDisplay());
    }
    
    void WhenInsertPennyandCheckDisplayTwiceThenChangesfromInvalidtoTotal() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Penny");
        assert("INVALID COIN" == vendingMachine.checkDisplay());
        assert("0.25" == vendingMachine.checkDisplay());
    }
    
    void WhenInsertExactCorrectAmountForChipsThenResetToZeroAndPrintInsertCoin() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.select("Chips");
        assert("THANK YOU" == vendingMachine.checkDisplay());
        assert("INSERT COIN" == vendingMachine.checkDisplay());
    }
    
    void WhenInsertExactCorrectAmountForCandyThenResetToZeroAndPrintInsertCoin() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Dime");
        vendingMachine.insert("Nickel");
        vendingMachine.select("Candy");
        assert("THANK YOU" == vendingMachine.checkDisplay());
        assert("INSERT COIN" == vendingMachine.checkDisplay());
    }
    
    void WhenInsertExactCorrectAmountForColaThenResetToZeroAndPrintInsertCoin() {
        Driver vendingMachine;
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.insert("Quarter");
        vendingMachine.select("Cola");
        assert("THANK YOU" == vendingMachine.checkDisplay());
        assert("INSERT COIN" == vendingMachine.checkDisplay());
    }
    
    void WhenSelectItemForColaThenDispenseOneCola() {
        Machine machine;
        machine.stockWithSnack();
        assert(4 == machine.dispenseItemAndReturnNumLeft("Cola"));
    }

};

#endif /* Header_h */
