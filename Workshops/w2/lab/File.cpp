/*
*****************************************************************************
Workshop - #2 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/23/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* name) {
        bool read = false;
        // Attempt to read the name of the employee from the file and store it in the 'name' array
        // using the format specifier "%[^\n]\n".
        // The "%[^\n]" format specifier reads a string until a newline character is encountered,
        // and "\n" consumes the newline character itself.
        // The result of fscanf will be the number of items successfully read.
        if (fscanf(fptr, "%[^\n]\n", name) == 1) {
            // If fscanf successfully read one item (the name), changes bool read to true.
            read = true;
        }
        return read;
    }

    bool read(int& employeeNumber) {
        bool read = false;
        // Read the employee number from the file using the "%d" format specifier
        // and store it in the employeeNumber parameter.
        // The trailing comma (",") is included in the format specifier to consume the comma separator in your CSV file.
        if (fscanf(fptr, "%d,", &employeeNumber) == 1) {
            read = true; // Set read to true if fscanf successfully read one item (the employee number).
        }
        return read;
    }

    bool read(double& employeeSalary) {
        bool read = false;
        // Read the employee salary from the file using the "%lf" format specifier
        // and store it in the employeeSalary parameter.
        // The trailing comma (",") is included in the format specifier to consume the comma separator in your CSV file.
        if (fscanf(fptr, "%lf,", &employeeSalary) == 1) {
            read = true; // Set read to true if fscanf successfully read one item (the employee salary).
        }
        return read;
    }
}