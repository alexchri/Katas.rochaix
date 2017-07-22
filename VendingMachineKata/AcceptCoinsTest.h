//
//  AcceptCoins.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#ifndef AcceptCoins_hpp
#define AcceptCoins_hpp

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
        //write failing test
        ReadInsertedCoins readCoins;
        readCoins.insertCoin("Nickel");
        assert(0.05 == readCoins.readTotal());
    }
};

#endif /* AcceptCoins_hpp */
