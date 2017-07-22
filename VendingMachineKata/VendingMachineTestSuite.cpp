//
//  VendingMachineTestSuite.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/19/17.
//
//
#include <iostream>

#include "AcceptCoinsTest.h"
#include "SelectProductTest.h"

int main() {
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
    SelectProductTest selectProducts;
    selectProducts.WhenColaIsSelectedThenDeductOneDollar();
    selectProducts.WhenChipsIsSelectedThenDeductFiftyCents();
    selectProducts.WhenCandyIsSelectedThenDeductSixtyFiveCents();
    selectProducts.WhenMultipleItemsAreSelectedThenDeductSumofPrices();
    
    
    //MAKE CHANGE
    
    
    //RETURN COINS
    
    
    //SOLD OUT
    
    
    //EXACT CHANGE
    
    
    return 0;
}
