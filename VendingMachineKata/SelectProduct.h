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

#endif /* SelectProduct_hpp */

class DispenseProduct {
    double revenue;
public:
    void deductPrice(std::string item);
    double moneyEarned();
};
