//
//  AcceptCoinsTest.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#ifndef AcceptCoinsTest_h
#define AcceptCoinsTest_h

#include <stdio.h>
#include <cassert>
#include "AcceptCoins.h"

class AcceptCoinsTest {
    
public:
    void WhenQuarterIsInsertedThenCount25Cents() {
        //test passed!
        ReadInsertedCoins readCoins;
        readCoins.insertCoin("Quarter");
        assert(0.25 == readCoins.readTotal());
    }
    
    void WhenDimeIsInsertedThenCount10Cents() {
        //test passed!
        ReadInsertedCoins readCoins;
        readCoins.insertCoin("Dime");
        assert(0.10 == readCoins.readTotal());
    }
    
    void WhenNickelIsInsertedThenCount5Cents() {
        //test passed!
        ReadInsertedCoins readCoins;
        readCoins.insertCoin("Nickel");
        assert(0.05 == readCoins.readTotal());
    }
    
    void WhenPennyIsInsertedThenDoNotCount() {
        //test passed!
        ReadInsertedCoins readCoins;
        readCoins.insertCoin("Penny");
        assert(0 == readCoins.readTotal());
        assert("INVALID COIN" == readCoins.printDisplay());
    }
    
    void WhenMultipleCoinsAreInsertedThenCountSum() {
        //test passed!
        
        //Quarter, Nickel, Dime, and Penny
        
        ReadInsertedCoins readCoins;
        
        readCoins.insertCoin("Quarter");
        //runningTotal = .25
        assert(0.25 == readCoins.readTotal());
        assert("0.25" == readCoins.printDisplay());
        
        readCoins.insertCoin("Dime");
        //runningTotal = .25 + .10 = .35
        assert(0.35 == readCoins.readTotal());
        assert("0.35" == readCoins.printDisplay());
        
        readCoins.insertCoin("Nickel");
        //runningTotal = .25 + .10 + .05 = .40
        assert(0.40 == readCoins.readTotal());
        assert("0.40" == readCoins.printDisplay());
        
        readCoins.insertCoin("Penny");
        //Should equal = .25 + .10 + .05 + invalid = .40
        assert(0.40 == readCoins.readTotal());
        assert("INVALID COIN" == readCoins.printDisplay());
    }
    
    void WhenNoCoinsInsertedThenDisplayInsertCoin() {
        //test passed!
        ReadInsertedCoins readCoins;
        assert("INSERT COIN" == readCoins.printDisplay());
    }
    
    void WhenPennyIsInsertedThenCoinReturnisOneCent() {
        //test passed!
        ReadInsertedCoins readCoins;
        readCoins.insertCoin("Penny");
        assert(0.01 == readCoins.rejectedCoins());
    }
    
    void WhenManyPenniesAreInsertedThenCoinReturnisSumofPenniesInserted() {
        //test passed!
        ReadInsertedCoins readCoins;
        
        //4 Pennies
        
        readCoins.insertCoin("Penny");
        readCoins.insertCoin("Penny");
        readCoins.insertCoin("Penny");
        readCoins.insertCoin("Penny");
        
        assert(0.04 == readCoins.rejectedCoins());
    }
    
    void WhenOneDollarInsertedAndCandySelectedThenMakeChangeForThirtyFiveCents() {
        ReadInsertedCoins readCoins;
        
        //insert 1 dollar
        readCoins.insertCoin("Quarter");
        readCoins.insertCoin("Quarter");
        readCoins.insertCoin("Quarter");
        readCoins.insertCoin("Quarter");
        
        //select Candy
        readCoins.transaction(0.65);
        
        //check change made
        assert(0.35 == readCoins.rejectedCoins());
        assert("INSERT COIN" == readCoins.printDisplay());
    }
};

#endif /* AcceptCoins_hpp */
