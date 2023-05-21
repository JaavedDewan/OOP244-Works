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

#include "Utils.h"
#include <iostream>

using namespace std;
using namespace sdds;

void sdds::flushkeys() {
    while (cin.get() != '\n');
}

bool sdds::ValidYesResponse(char ch) {
    return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
}

bool sdds::yes() {
    char ch = 0;
    do {
        cin >> ch;
        flushkeys();
    } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
    return ch == 'y' || ch == 'Y';
}

void sdds::readCstr(char cstr[], int len) {
    char buf[1024] = {};
    int i;
    cin.getline(buf, 1024);
    for (i = 0; i < len && buf[i]; i++) {
        cstr[i] = buf[i];
    }
    cstr[i] = 0;
}

int sdds::readInt(int min, int max) {
    int value = 0;
    bool done = false;
    while (!done) {
        cin >> value;
        if (!cin) {
            cin.clear();
            cout << "Bad integer, try agian: ";
        }
        else {
            if (value >= min && value <= max) {
                done = true;
            }
            else {
                cout << "Value out of range (" << min << "<=value<=" << max << "): ";
            }
        }
        flushkeys();
    }
    return value;
}