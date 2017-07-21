# *******************************
# Makefile mission control

CXX = g++
CXXFLAGS = -Wall -g

# *******************************
# Targets

all : main.o
	$(CXX) $(CXXFLAGS) -o main main.o

test : VendingMachineTestSuite.o AcceptCoins.o
	$(CXX) $(CXXFLAGS) -o VendingMachineTestSuite VendingMachineTestSuite.o AcceptCoins.o

clean : 
	rm -f *o main VendingMachineTestSuite

# *******************************
# Dependencies

VendingMachineTestSuite.o : VendingMachineTestSuite.cpp AcceptCoins.cpp AcceptCoinsTest.h AcceptCoins.h
	$(CXX) $(CXXFLAGS) -c VendingMachineTestSuite.cpp

AcceptCoins.o : AcceptCoins.cpp AcceptCoins.h
	$(CXX) $(CXXFLAGS) -c AcceptCoins.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
