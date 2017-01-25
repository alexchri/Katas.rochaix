Welcome to Alex Rochaix’s Github account!

PROJECT/Roman Numerals:
	Roman Kata by Alex Rochaix [C++, 2017]
	This project is entirely functional on the command line.

valid inputs:
	$<numeral>	//takes Roman Numeral input, outputs Number value
	$<number>	//takes Number input, outputs Roman Numeral value
	$help		//provides instructions for use, and description
	$test *.txt	//uses *.txt file as input, writes test results to out.txt
	$q		//exit program (allows multiple inputs!)

Make commands:
	make release 	//runs with -O3 flag (make run essentially!)
	make -R -r	//builds -o files and .exe, treats all warnings as errors
	make clean 	//removes object files (*.o) and executable	

Files included:
	//driver files
		driver.cpp		//main file
		calc.cpp , calc.h	//functions file, header file

	//test files		
		test.txt		//test input file	

	//Makefile
		Makefile

Notes:
	-test command will take any .txt file, provided formatted correctly
	-tests are formatted <input> <correct> in *.txt file
	-“test” will write “line #: <output>” for every incorrect to out.txt
	-if all tests pass, “test” will write “Pass!” to out.txt

Dependencies in makefile:
	driver.o: driver.cpp calc.h
	calc.o: calc.cpp calc.h
