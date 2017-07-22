//
//  SelectProduct.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/22/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef SelectProduct_h
#define SelectProduct_h

#include <stdio.h>
#include <string>

class DispenseProduct {
    double revenue;
public:
    DispenseProduct();
    void deductPrice(std::string item);
    double moneyEarned();
};

#endif /* SelectProduct_hpp */


