//
//  Header.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/23/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#ifndef ItemsAndMachine_h
#define ItemsAndMachine_h

#include <string>
#include <vector>

class SnackItem {
    std::string name;
    double price;
public:
    SnackItem();
    SnackItem(std::string snack, double cost);
    double getPrice();
    std::string getName();
};

class Machine {
    std::vector<SnackItem> machine;
public:
    Machine();
    void stockWithSnack();
    SnackItem findItem(std::string item);
};
#endif /* Header_h */
