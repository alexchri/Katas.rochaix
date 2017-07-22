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

class ReadInsertedCoins {
    double runningTotal = 0;
    std::string display = "";
public:
    void insertCoin(std::string coins);
    std::string printDisplay();
    double readTotal();
};

#endif /* Header_h */
