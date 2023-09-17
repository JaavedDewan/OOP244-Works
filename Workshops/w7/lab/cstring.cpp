/*
*****************************************************************************
Workshop - #7 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/12/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "cstring.h"
namespace sdds {

	int strCmp(const char* s1, const char* s2)
	{
		// s1: Pointer to the first character array (const, indicating it will not be modified)
		// s2: Pointer to the second character array (const, indicating it will not be modified)
	
		int result = 0;
	
		// Iterate through the strings until a mismatch is found or the null character ('\0') is encountered
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
			// Move to the next character in both strings
			s1++;
			s2++;
		}
	
		// If the result is still 0, it means the strings match up to the null character.
		// If both strings end at the same time (null character encountered), return 0.
		// Otherwise, return the difference in length (ASCII value) between the remaining characters.
		result = *s1 - *s2;
	
		return result;
	}

	void strnCpy(char* des, const char* src, int len)
	{
		int i;

		// iterate through the source string until either len characters are copied or the null character ('\0') is encountered
		for (i = 0; i < len && src[i] != '\0'; i++) {
			// copy the current character from the source string to the destination string
			des[i] = src[i];
		}

		// if len is greater than zero and a null character was encountered in the source string before reaching len, pad the remaining characters in the destination string with null characters ('\0')
		for (; i < len; i++) {
			des[i] = '\0';
		}
	}
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
}