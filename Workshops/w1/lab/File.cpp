/*
*****************************************************************************
Workshop - #1 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/16/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include <iostream>
using namespace sdds;

FILE* sfptr = nullptr;

bool sdds::openFileForRead() {
    sfptr = fopen(SHOPPING_DATA_FILE, "r");
    return sfptr != NULL;
}

bool sdds::openFileForOverwrite() {
    sfptr = fopen(SHOPPING_DATA_FILE, "w");
    return sfptr != NULL;
}

void sdds::closeFile() {
    if (sfptr) fclose(sfptr);
}

bool sdds::freadShoppingRec(ShoppingRec* rec) {
    int flag = 0;
    bool success = fscanf(sfptr, "%[^,],%d,%d\n",
        rec->m_title, &rec->m_quantity, &flag) == 3;
    rec->m_bought = !!flag;
    return success;
}

void sdds::fwriteShoppintRec(const ShoppingRec* rec) {
    fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
}