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
    driver.WhenSelectColaAndNotEnoughCoinsThenDisplayPrice();
    driver.WhenSelectCandyandNotEnoughCoinsThenDisplayPrice();
    driver.WhenSelectChipsAndNotEnoughCoinsThenDisplayPrice();
    driver.WhenInsertPennyandCheckDisplayTwiceThenChangesfromInvalidtoTotal();
    driver.WhenInsertExactCorrectAmountForChipsThenResetToZeroAndPrintInsertCoin();
    driver.WhenInsertExactCorrectAmountForCandyThenResetToZeroAndPrintInsertCoin();
    driver.WhenInsertExactCorrectAmountForColaThenResetToZeroAndPrintInsertCoin();
    
    
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
    acceptCoins.WhenOneDollarInsertedAndCandySelectedThenMakeChangeForThirtyFiveCents();
    acceptCoins.WhenOneDollarInsertedAndColaSelectedThenMakeChangeFor0Cents();
    acceptCoins.WhenOneDollarAndPennyInsertedAndChipsSelectedThenMakeChangeForFiftyOneCents();
    acceptCoins.WhenNoMoneyIsInsertedAndColaSelectedThenMakeChangeForZeroCents();
    
    //RETURN COINS
    acceptCoins.WhenHitReturnCoinThenCoinSlotIsEmptyAndCoinReturnIsFull();
    acceptCoins.WhenHitReturnCoinAfterInsertingDollarAndPennyThenDisplaysInsertCoin();
    
    //SOLD OUT
    driver.WhenSelectItemForColaThenDispenseOneCola();
    
    //EXACT CHANGE
    
    
    return 0;
}
