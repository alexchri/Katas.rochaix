//
//  SelectProduct.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "SelectProduct.h"

DispenseProduct::DispenseProduct() {
    revenue = 0;
}

void DispenseProduct::deductPrice(std::string item) {
    if(item == "Cola") {
        revenue += 1;
    }
    else if(item == "Chips") {
        revenue += 0.5;
    }
    else if(item == "Candy") {
        revenue += 0.65;
    }
}

double DispenseProduct::moneyEarned() {
    return revenue;
}
