# *******************************
# Makefile mission control

CXX = g++
CXXFLAGS = -Wall -g

# *******************************
# Targets

all : main.o
	$(CXX) $(CXXFLAGS) -o main main.o

test : VendingMachineTestSuite.o AcceptCoins.o SelectProduct.o
	$(CXX) $(CXXFLAGS) -o VendingMachineTestSuite VendingMachineTestSuite.o AcceptCoins.o SelectProduct.o

clean : 
	rm -f *o main VendingMachineTestSuite

# *******************************
# Dependencies

VendingMachineTestSuite.o : VendingMachineTestSuite.cpp AcceptCoins.cpp SelectProduct.cpp AcceptCoinsTest.h AcceptCoins.h SelectProduct.h SelectProductTest.h
	$(CXX) $(CXXFLAGS) -c VendingMachineTestSuite.cpp

AcceptCoins.o : AcceptCoins.cpp AcceptCoins.h
	$(CXX) $(CXXFLAGS) -c AcceptCoins.cpp
SelectProduct.o : SelectProduct.cpp SelectProduct.h
	$(CXX) $(CXXFLAGS) -c SelectProduct.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
