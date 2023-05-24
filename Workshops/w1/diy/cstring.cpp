/*
*****************************************************************************
Workshop - #1 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/20/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "cstring.h"
using namespace sdds;

// Copies the source character string (src) into the destination (des)
void sdds::strCpy(char* des, const char* src)
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


// Copies the source character string into the destination upto "len"
// characters. The destination will be null terminated only if the number
// of the characters copied is less than "len"
void sdds::strnCpy(char* des, const char* src, int len)
{
    int i;

    // Iterate through the source string until either len characters are copied or the null character ('\0') is encountered
    for (i = 0; i < len && src[i] != '\0'; i++) {
        // Copy the current character from the source string to the destination string
        des[i] = src[i];
    }

    // If len is greater than zero and a null character was encountered in the source string before reaching len, pad the remaining characters in the destination string with null characters ('\0')
    for (; i < len; i++) {
        des[i] = '\0';
    }
}




// Compares two C-strings 
// returns 0 if they are the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
int sdds::strCmp(const char* s1, const char* s2)
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
	if (result == 0) {
		result = *s1 - *s2;
	}

	return result;
}




// returns 0 if they are the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
int sdds::strnCmp(const char* s1, const char* s2, int len)
{
	int result = 0;

	// Iterate through the strings until either len characters are compared or the null character ('\0') is encountered
	while (len > 0 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
		// Move to the next character in both strings
		s1++;
		s2++;
		len--;
	}

	// Strings match up to the null character or the specified length
	// If both strings end at the same time (null character encountered) or the specified length is reached, return 0
	// Otherwise, return the difference in length (ASCII value) between the remaining characters
	if (len == 0) {
		result = 0;
	}
	else {
		result = *s1 - *s2;
	}

	return result;
}



// returns the length of the C-string in characters
int sdds::strLen(const char* s)
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


// returns the address of first occurance of "str2" in "str1"
// returns nullptr if no match is found
const char* sdds::strStr(const char* str1, const char* str2)
{
	// str1: Pointer to the first string (const, indicating it will not be modified)
	// str2: Pointer to the second string to search for (const, indicating it will not be modified)

	const char* result = nullptr; // Initialize result to nullptr

	// Check for empty strings
	if (*str2 == '\0') {
		// Empty second string, return the original string pointer
		result = str1;
	}
	else {
		// Iterate through the first string until the null character ('\0') is encountered
		while (*str1 != '\0' && result == nullptr) {
			// Initialize pointers to track the current position in the first string and second string
			const char* ptr1 = str1;
			const char* ptr2 = str2;

			// Iterate through the first and second string characters, comparing them
			while (*ptr2 != '\0' && *ptr1 == *ptr2) {
				// Move to the next character in both the first and second string
				ptr1++;
				ptr2++;
			}

			// If the second string pointer reaches the null character, a match is found
			if (*ptr2 == '\0') {
				// Return the address of the first occurrence of the second string in the first string
				result = str1;
			}

			// Move to the next character in the first string for the next iteration
			str1++;
		}
	}

	return result;
}





// Concantinates "src" C-string to the end of "des"
void sdds::strCat(char* des, const char* src)
{
	// des: Pointer to the destination character array
	// src: Pointer to the source character array (const, indicating it will not be modified)

	// Find the end of the destination string
	char* desEnd = des;
	while (*desEnd != '\0') {
		desEnd++;
	}

	// Append the characters from the source string to the end of the destination string
	while (*src != '\0') {
		*desEnd = *src;
		desEnd++;
		src++;
	}

	// Append the null character to the end of the concatenated string
	*desEnd = '\0';
}


