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
    size_t num;
public:
    SnackItem();
    SnackItem(std::string snack, double cost, size_t count);
    double getPrice();
    std::string getName();
    size_t getNum();
    void dispense();
};

class Machine {
    std::vector<SnackItem> machine;
public:
    Machine();
    void stockWithSnack();
    SnackItem findItem(std::string item);
    size_t returnNumLeft(std::string item);
    void dispenseItem(std::string item);
};
#endif /* Header_h */
