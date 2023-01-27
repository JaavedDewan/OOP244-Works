/*
*****************************************************************************
<assessment name example: Workshop - #1 (Part-1)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 01/20/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "File.h"
using namespace std;
using namespace sdds;

FILE* fptr;

// opens the data file and returns true is successful
bool sdds::openFile(const char filename[]) {
    fptr = fopen(filename, "r");
    return fptr != NULL;
}

// closes the data file
void sdds::closeFile() {
    if (fptr) fclose(fptr);
}

// reads the title of the movie from the global fptr File pointer
// returns true if successful
bool sdds::readTitle(char title[]) {
    return fscanf(fptr, "%[^(](", title) == 1;
}

// reads the year of the movie from the global fptr File pointer
// returns true if successful
bool sdds::readYear(int* year) {
    return fscanf(fptr, "%d)", year) == 1;
}

// reads the year of the movie from the global fptr File pointer
// returns true if successful
bool sdds::readMovieRating(char rating[]) {
    return fscanf(fptr, " %[^|]|", rating) == 1;
}

// reads the duration of the movie from the global fptr File pointer
// returns true if successful
bool sdds::readDuration(int* duration) {
    return fscanf(fptr, "%d|", duration) == 1;
}

// reads the genras of the movie from the global fptr File pointer
// returns true if successful
bool sdds::readGenres(char genre[][11]) {
    char genres[256];
    int gi = 0; //genres index;
    int i = 0;// genre[i] index
    int j = 0;// genre[i][j] index
    bool res = fscanf(fptr, " %[^|]|", genres);
    if (res) { //spreading csv to array of strings
        res = false;
        while (genres[gi]) {
            if (genres[gi] != ',') {
                genre[i][j++] = genres[gi++];
                res = true;
            }
            else {
                genre[i][j] = '\0';
                i++;
                gi++;
                j = 0;
            }
        }
    }
    genre[i++][j] = '\0';
    genre[i][0] = '\0'; // NULL terminating the array of strings
    return res;
}

// reads the consumerRating of the movie from the global fptr File pointer
// returns true if successful
bool sdds::readConsumerRating(float* rating) {
    return fscanf(fptr, "%f\n", rating) == 1;
}