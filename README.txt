Welcome to Alex Rochaix’s Github account!

PROJECT/Roman Numerals:
	This project is entirely functional on the command line.

valid commands: $<verbose form, shortcode>
	$numeral, #	//takes Roman Numeral input, outputs Number value
	$number, n	//takes Number input, outputs Roman Numeral value
	$help, h	//provides instructions for use, and description
	
Make commands:
	make release <flags>	//runs with flags and -O3 flag (make run essentially!)
	make -R -r	//builds -o files and .exe, treats all warnings as errors
	make debug	//after make -R -r, runs with debug flag
	make clean 	//removes object files (*.o) and executable 	

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

