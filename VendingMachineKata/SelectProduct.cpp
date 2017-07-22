//
//  SelectProduct.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "SelectProduct.h"

void DispenseProduct::deductPrice(std::string item) {
    if(item == "Cola") {
        revenue = 1;
    }
    else if(item == "Chips") {
        revenue = 0.5;
    }
}

double DispenseProduct::moneyEarned() {
    return revenue;
}
