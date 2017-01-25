Welcome to Alex Rochaix’s Github account!

PROJECT/Roman Numerals:
	Roman Kata by Alex Rochaix [C++, 2017]
	This project is entirely functional on the command line.

valid inputs:
	$<numeral>	//takes Roman Numeral input, outputs Number value
	$<number>	//takes Number input, outputs Roman Numeral value
	$help		//provides instructions for use, and description
	$q		//exit program	

Make commands:
	make release 	//runs with -O3 flag (make run essentially!)
	make -R -r	//builds -o files and .exe, treats all warnings as errors
	make clean 	//removes object files (*.o) and executable
	make tests	//runs test(*).txt files 	

Files included:
	//driver files
		driver.cpp		//main file
		calc.cpp , calc.h	//functions file, header file

	//test files		
		test(rton).txt		//Roman Numeral to Number test file
		test(ntor).txt		//Number to Roman Numeral test file

	//Makefile
		Makefile

Dependencies in makefile:
	driver.o: driver.cpp calc.h
	calc.o: calc.cpp calc.h

