//
//  Items.cpp
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/23/17.
//  Copyright © 2017 Alexandre Rochaix. All rights reserved.
//

#include "ItemsAndMachine.h"

SnackItem::SnackItem() {
    name = "";
    price = 0;
}

SnackItem::SnackItem(std::string snack, double cost) : name(snack), price(cost) {
    //just a constructor
}

double SnackItem::getPrice() {
    return price;
}

std::string SnackItem::getName() {
    return name;
}

Machine::Machine() {
    //define machine[0] as error item
    machine.emplace_back(SnackItem("ERROR", 0));
}

void Machine::stockMachine() {
    //insert items list here!
    machine.emplace_back(SnackItem("Cola", 1));
    machine.emplace_back(SnackItem("Chips", 0.5));
    machine.emplace_back(SnackItem("Candy", 0.65));
}

SnackItem Machine::findItem(std::string item) {
    for(int i = 0; i < machine.size(); ++i) {
        if(machine[i].getName() == item)
            return machine[i];
    }
    //define machine[0] as error item
    return machine[0];
}
