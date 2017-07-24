//
//  AcceptCoins.h
//  VendingMachineKata
//
//  Created by Alexandre Rochaix on 7/20/17.
//
//

#ifndef AcceptCoins_h
#define AcceptCoins_h

#include <string>
#include <sstream>
#include <iomanip>

class ReadInsertedCoins {
    double runningTotal;
    double rejectedTotal;
    std::stringstream display;
    
public:
    ReadInsertedCoins();
    
    //setter
    void insertCoin(std::string coins);
    void transaction(double price);
    
    //getter
    std::string printDisplay();
    double readTotal();
    double rejectedCoins();
};

#endif /* Header_h */
