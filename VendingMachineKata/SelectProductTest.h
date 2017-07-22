//
//  SelectProductTest.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef SelectProductTest_h
#define SelectProductTest_h

#include <stdio.h>
#include "SelectProduct.h"

class SelectProductTest {
    
public:
    void WhenColaIsSelectedThenDeductOneDollar() {
        DispenseProduct selectProduct;
        selectProduct.deductPrice("Cola");
        assert(1 == selectProduct.moneyEarned());
    }
    
    void WhenChipsIsSelectedThenDeductFiftyCents() {
        DispenseProduct selectProduct;
        selectProduct.deductPrice("Chips");
        assert(0.50 == selectProduct.moneyEarned());
    }
    
    void WhenCandyIsSelectedThenDeductSixtyFiveCents() {
        DispenseProduct selectProduct;
        selectProduct.deductPrice("Candy");
        assert(0.65 == selectProduct.moneyEarned());
    }
    
    void WhenMultipleItemsAreSelectedThenDeductSumofPrices() {
        DispenseProduct selectProduct;
        
        //Vend out Cola, Chips, Candy = 1.00 + 0.50 + 0.65 = 2.15
        
        selectProduct.deductPrice("Cola");
        assert(1 == selectProduct.moneyEarned());
        selectProduct.deductPrice("Chips");
        assert(1.5 == selectProduct.moneyEarned());
        selectProduct.deductPrice("Candy");
        assert(2.15 == selectProduct.moneyEarned());
    }
};


#endif /* Header_h */
