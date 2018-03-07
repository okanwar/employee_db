/*
 * TODO: ADD YOUR TOP-LEVEL COMMENT HERE
 *
 * And, remove all my comments to you...I should not see any TODO's in your
 * submitted code.
 */

#include <stdio.h>      // the C standard I/O library
#include <stdlib.h>     // the C standard library
#include <string.h>     // the C string library
#include "readfile.h"   // my file reading routines
 
// TODO: #define any constant values here:
#define MAXFILENAME  128
#define MAXNAME       64

struct Employee {
	// TODO: Add fields do your employee struct
};

// The following line allows us to use "Employee" rather than 
// "struct Employee" throughout this code.
typedef struct Employee Employee;

// forward declaration of functions
void getFilenameFromCommandLine(char filename[], int argc, char *argv[]);
void readAndPrintFile(char *filename);

// TODO: add forward declaration of your functions here

int main (int argc, char *argv[]) {

	// TODO: add more local variables here
	char filename[MAXFILENAME];


	// this initializes the filename string from the command line arguments
	getFilenameFromCommandLine(filename, argc, argv);

	// TODO: remove the call to this function from your code:
	//       It is just an example of how to use the readfile 
	//       functions to read in values from the  DB file
	readAndPrintFile(filename);


	// TODO: fill in the body of main


	printf("\ngood bye\n");
	return 0;
}

// TODO: ADD YOUR FUNCTION _DEFINITONS_ BELOW THIS LINE


/**
 * This is a function to test the readfile library on a DB input file: you will
 * not really call this in your program, but use it as an example of how to use
 * the readfile library functions.
 * @param filename the filename to open and read
 */
void readAndPrintFile(char *filename) {
	printf("filename '%s'\n", filename);

	int ret = openFile(filename);  // try to open the DB file
	if (ret == -1) {
		printf("bad error: can't open %s\n", filename);
		exit(1);
	}

	int id, salary;
	char fname[MAXNAME], lname[MAXNAME];

	while (ret != -1) {    
		ret = readInt(&id);         // read the first line of values from file
		if (ret) { break; }
		ret = readString(fname);
		if (ret) { break; }
		ret = readString(lname);
		if (ret) { break; }
		ret = readInt(&salary);
		if (ret == 0) { // stuff was read in okay
			printf("%d %s %s %d\n", id, fname, lname, salary);

		}
	}

	closeFile();  // when all done close the file
}

/**
 *  DO NOT MODIFY THIS FUNCTION. It works "as is".
 *
 *  This function gets the filename passed in as a command line option
 *  and copies it into the filename parameter. It exits with an error 
 *  message if the command line is badly formed.
 *  @param filename the string to fill with the passed filename
 *  @param argc, argv the command line parameters from main 
 *               (number and strings array)
 */
void getFilenameFromCommandLine(char filename[], int argc, char *argv[]) {

	if (argc != 2) {
		printf("Usage: %s database_file\n", argv[0]);
		// exit function: quits the program immediately...some errors are not 
		// recoverable by the program, so exiting with an error message is 
		// reasonable error handling option in this case
		exit(1);   
	}
	if (strlen(argv[1]) >= MAXFILENAME) { 
		printf("Filename, %s, is too long, cp to shorter name and try again\n",
				filename);
		exit(1);
	}
	strcpy(filename, argv[1]);
}
