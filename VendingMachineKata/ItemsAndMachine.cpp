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
    num = 0;
}

SnackItem::SnackItem(std::string snack, double cost, size_t count)
    : name(snack), price(cost), num(count) {
    //just a constructor
}

double SnackItem::getPrice() {
    return price;
}

std::string SnackItem::getName() {
    return name;
}

size_t SnackItem::getNum() {
    return num;
}

void SnackItem::dispense() {
    --num;
}

Machine::Machine() {
    //define machine[0] as error item
    machine.emplace_back(SnackItem("ERROR", 0, 0));
}

void Machine::stockWithSnack() {
    //insert items list here!
    machine.emplace_back(SnackItem("Cola", 1 , 5));
    machine.emplace_back(SnackItem("Chips", 0.5 , 5));
    machine.emplace_back(SnackItem("Candy", 0.65, 5));
}

SnackItem Machine::findItem(std::string item) {
    for(int i = 0; i < machine.size(); ++i) {
        if(machine[i].getName() == item)
            return machine[i];
    }
    //define machine[0] as error item
    return machine[0];
}

void Machine::dispenseItem(std::string item) {
    int at = 0;
    for(int i = 0; i < machine.size(); ++i) {
        if(machine[i].getName() == item)
            at = i;
    }
    if(machine[at].getNum() != 0)
        machine[at].dispense();
}

size_t Machine::ReturnNumLeft(std::string item) {
    //implementation later!
    return findItem(item).getNum();
}
