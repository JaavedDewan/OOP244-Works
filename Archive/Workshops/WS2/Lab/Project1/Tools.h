/*
*****************************************************************************
						  Workshop - #2 (P1)
Full Name  : Jaaved Dewan
Student ID#: 126045178
Email      : jdewan@myseneca.ca
Section    : NAA
Completed on: 01/27/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)

	int read(char *name);

	int read(int &result);

	int read(double &timeinhours);

	int read(char &dayofweek);

	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 

