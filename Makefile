# *******************************
# Makefile mission control

CXX = g++
CXXFLAGS = -Wall -g

# *******************************
# Targets

main : VendingMachineMainFile.o
	$(CXX) $(CXXFLAGS) -o VendingMachineMainFile VendingMachineMainFile.o

test : VendingMachineTestSuite.o
	$(CXX) $(CXXFLAGS) -o VendingMachineTestSuite VendingMachineTestSuite.o

clean : 
	rm -f *o VendingMachineMainFile VendingMachineTestSuite

# *******************************
# Dependencies

VendingMachineTestSuite.o : VendingMachineTestSuite.cpp
	$(CXX) $(CXXFLAGS) -c VendingMachineTestSuite.cpp

VendingMachineMainFile.o : VendingMachineMainFile.cpp VendingMachineMainFile.h
	$(CXX) $(CXXFLAGS) -c VendingMachineMainFile.cpp
