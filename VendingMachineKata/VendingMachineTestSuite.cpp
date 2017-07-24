//
//  VendingMachineTestSuite.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/19/17.
//
//
#include <iostream>

#include "DriverTest.h"
#include "ItemsAndMachine.h"
#include "AcceptCoinsTest.h"

int main() {
    //DRIVER
    DriverTest driver;
    driver.WhenSelectCandyandNotEnoughCoinsThenDisplayPrice();
    driver.WhenSelectChipsAndNotEnoughCoinsThenDisplayPrice();
    driver.WhenInsertPennyandCheckDisplayTwiceThenChangesfromInvalidtoTotal();
    driver.WhenInsertExactCorrectAmountThenResetToZeroAndPrintInsertCoin();
    driver.WhenSelectColaAndNotEnoughCoinsThenDisplayPrice();
    
    //ACCEPT COINS
    AcceptCoinsTest acceptCoins;
    acceptCoins.WhenQuarterIsInsertedThenCount25Cents();
    acceptCoins.WhenDimeIsInsertedThenCount10Cents();
    acceptCoins.WhenNickelIsInsertedThenCount5Cents();
    acceptCoins.WhenPennyIsInsertedThenDoNotCount();
    acceptCoins.WhenMultipleCoinsAreInsertedThenCountSum();
    acceptCoins.WhenNoCoinsInsertedThenDisplayInsertCoin();
    acceptCoins.WhenPennyIsInsertedThenCoinReturnisOneCent();
    acceptCoins.WhenManyPenniesAreInsertedThenCoinReturnisSumofPenniesInserted();
    
    //SELECT PRODUCT
    
    //MAKE CHANGE
    
    
    //RETURN COINS
    
    
    //SOLD OUT
    
    
    //EXACT CHANGE
    
    
    return 0;
}
