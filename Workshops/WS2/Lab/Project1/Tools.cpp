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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;


namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }


    // To Do: read functions (4 overloaded read functions)


    // Reads a string from the currently opened file and stores it in the given name variable
// Returns the number of items successfully read

    int read(char* name)
    {
        int read = 0;
        read = fscanf(fp, "%60[^\n]\n", name);
        return read;
    }

    // Reads an integer from the currently opened file and stores it in the given intMembers variable
// Returns the number of items successfully read


    int read(int& intMembers)
    {
        int read = 0;
        read = fscanf(fp, "%d,", &intMembers);
        return read;
    }
    
    // Reads a double from the currently opened file and stores it in the given hours variable
// Returns the number of items successfully read

    int read(double& hours)
    {
        int read = 0;
        read = fscanf(fp, "%lf,", &hours);
        return read;
    }

    // Reads a single character from the currently opened file and stores it in the given weekName variable
// Returns the number of items successfully read

    int read(char& weekName)
    {
        int read = 0;
        read = fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &weekName);
        return read;
    }

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }

    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}