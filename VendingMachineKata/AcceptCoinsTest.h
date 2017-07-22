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
    ReadInsertedCoins readCoins;
public:
    void WhenQuarterIsInsertedThenCount25Cents() {
        //test passed!
        readCoins.insertCoin("Quarter");
        assert(0.25 == readCoins.readTotal());
    }
    
    void WhenDimeIsInsertedThenCount10Cents() {
        
    }
};

#endif /* AcceptCoins_hpp */
