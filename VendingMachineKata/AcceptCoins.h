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
class CoinCounter {
    struct CoinSlot {
        size_t numQuarters;
        size_t numDimes;
        size_t numNickels;
    } coinSlot;
    struct ChangeAvailable {
        size_t numQuarters;
        size_t numDimes;
        size_t numNickels;
    } changeAvailable;
    struct CoinReturn {
        size_t numQuarters;
        size_t numDimes;
        size_t numNickels;
        size_t numPennies;
    } coinReturn;
public:
    //default
    CoinCounter();
    //setter
    void stockWithChange(int numOfEachCoin);
    //getters
    double getRunningTotal();
    double getChangeMade();
    //acting functions
    void insertQuarter();
    void insertDime();
    void insertNickel();
    void insertPenny();
    void acceptCoins();
    void makeChangeFor(double amount);
    void cancelAndReturnCoins();
};

class ReadInsertedCoins {
    CoinCounter machine;
    std::stringstream display;
public:
    ReadInsertedCoins();
    
    //setter
    void stockWithCoin();
    void insertCoin(std::string coins);
    void transaction(double price);
    void returnCoins();
    
    //getter
    std::string printDisplay();
    double readTotal();
    double rejectedCoins();
};

#endif /* Header_h */
