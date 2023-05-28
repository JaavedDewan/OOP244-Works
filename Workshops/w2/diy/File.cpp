/*
*****************************************************************************
Workshop - #2 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/28/23
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

   bool read(char* postalCode) {
       bool read = false;
       // Read the postal code from the file using the "%3s" format specifier.
       // The "%3s" specifier reads at most 3 characters (the postal code) and adds a null terminator automatically.
       if (fscanf(fptr, "%3s,", postalCode) == 1) {
           read = true;
       }
       return read;
   }

   bool read(int& population) {
       bool read = false;
       // Read the population from the file using the "%d" format specifier
       // and store it in the population parameter.
       if (fscanf(fptr, "%d,", &population) == 1) {
           read = true; // Set read to true if fscanf successfully read one item (the population).
       }
       return read;
   }
}