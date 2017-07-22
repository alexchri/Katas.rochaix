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
};


#endif /* Header_h */
