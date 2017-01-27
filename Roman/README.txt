Welcome to Alex Rochaix’s Github account!

README Notes:
	<blah> means input value indicated here
		so <numeral> would be:
			MDC [ENTER]
		so <number> would be:
			1050 [ENTER]
	‘blah’ means a command input 
		so ‘help’ would be:
			help [ENTER]

PROJECT/Roman Numerals:
	Roman Kata by Alex Rochaix [C++, 2017]
	This project is entirely functional on the command line.
running:
	(1) make release
	(2) ./roman
	(2a) if required, use below for the updated compiler:
		$module load gcc/5.1.0 
	(3) when finished (using ‘q’), use below to remove -o and .exe:
		$make clean

valid inputs:
	$<numeral>	//takes Roman Numeral input, outputs Number value
	$<number>	//takes Number input, outputs Roman Numeral value
	$help		//provides instructions for use, and description
	$test *.txt	//uses *.txt file as input, writes test results to out.txt
	$q		//exit program (allows multiple inputs!)

Make commands:
	$make release 	//runs with -O3 flag 
	$make -R -r	//builds -o files and .exe, treats all warnings as errors
	$make clean 	//removes object files (*.o) and executable	

Files included:
	//driver files
		roman.cpp		//driver (aka main) file
		calc.cpp , calc.h	//functions file, header file

	//test files		
		test.txt		//provided test input file	

	//Makefile
		Makefile

Using the ‘test’ command:

	-test command will take any .txt file in folder, provided formatted correctly
		comments on any individual line
			//blah 
		but not
			1	I	//blah

	-tests are formatted in *.txt file on any individual line:
		<input><tabs/whitespace><correct> 

	-‘test’ will write “line #: <output>” for every incorrect to out.txt

	-if all tests pass, ‘test’ will write “Pass!” to out.txt and to console

	-if any test fails, ‘test’ will write “See out.txt for errors” to console

Dependencies in makefile:

	driver.o: driver.cpp calc.h

	calc.o: calc.cpp calc.h
