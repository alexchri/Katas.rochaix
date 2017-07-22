//
//  Header.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#ifndef Header_h
#define Header_h

#include <string>
#include <sstream>

class ReadInsertedCoins {
    double runningTotal = 0;
    std::stringstream display;
public:
    void insertCoin(std::string coins);
    std::string printDisplay();
    double readTotal();
};

#endif /* Header_h */
