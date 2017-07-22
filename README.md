# Katas.rochaix
Coding Exercises. See inside for project names!

UPDATES:
Roman Project: retired 
Vending Machine Project: active

************************************
STYLE GUIDE for Vending Machine Kata:
************************************

First official commit for this project begins on 22JUL2017.

NOTE: -please ignore "cleaning" commits - those were used to clean up the repository after a mistake.

Make Commands:
	make - defaults to make build
	make build - compile code
	make test - run test files
	make clean - clean object files and executables

Commit comment format: 
	"STAGE: <TDD stage> FILE: <filename> LINE: <line #>"

TDD stages are defined as follows (based on video from Pillar Technology):
	WriteFailingTest
	WritePassingCode
	Refactor

File Names format (based on Kata description from Pillar Technology):

    (Implementation files)
    main.cpp - driver for kata
    AcceptCoins.cpp - includes .h file of same name
    SelectProduct.cpp - includes .h file of same name
    MakeChange.cpp - includes .h file of same name
    ReturnCoins.cpp - includes .h file of same name
    SoldOut.cpp - includes .h file of same name
    ExactChangeOnly.cpp - includes .h file of same name
    
    (Test files)
    VendingMachineTestSuite.cpp - driver for test suite
    AcceptCoinsTest.h - class function tests, tested by test suite driver
    SelectProductTest.h - class function tests, tested by test suite driver
    MakeChangeTest.h - class function tests, tested by test suite driver
    ReturnCoinsTest.h - class function tests, tested by test suite driver
    SoldOutTest.h - class function tests, tested by test suite driver
    ExactChangeOnlyTest.h - class function tests, tested by test suite driver
