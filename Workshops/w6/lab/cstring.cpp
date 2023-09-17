/*
*****************************************************************************
Workshop - #6 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/05/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "cstring.h"
namespace sdds {

	int strLen(const char* s)
	{
		// s: Pointer to the character array (const, indicating it will not be modified)

		// Initialize a counter to keep track of the length
		int length = 0;

		// Iterate through the string until the null character ('\0') is encountered
		while (*s != '\0') {
			// Increment the length counter
			length++;

			// Move to the next character in the string
			s++;
		}

		// Return the calculated length
		return length;
	}

	void strCpy(char* des, const char* src)
	{
		// des: Pointer to the destination character array
		// src: Pointer to the source character array (const, indicating it will not be modified)

		// Iterate through the source string until the null character ('\0') is encountered
		while (*src != '\0') {
			// Copy the current character from the source string to the destination string
			*des = *src;

			// Move to the next character in both source and destination strings
			des++;
			src++;
		}

		// Append the null character ('\0') to the end of the destination string
		*des = '\0';
	}

	//void sdds::strCat(char* des, const char* src)
	//{
	//// des: Pointer to the destination character array
	//// src: Pointer to the source character array (const, indicating it will not be modified)

	//// Find the end of the destination string
	//char* desEnd = des;
	//while (*desEnd != '\0') {
	//	desEnd++;
	//}

	//// Append the characters from the source string to the end of the destination string
	//while (*src != '\0') {
	//	*desEnd = *src;
	//	desEnd++;
	//	src++;
	//}

	//// Append the null character to the end of the concatenated string
	//*desEnd = '\0';
	//}
}