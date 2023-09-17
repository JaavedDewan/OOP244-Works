/*
*****************************************************************************
Workshop - #4 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/11/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Label::Label() {
        // Set the default frame
        strCpy(frame,"+-+|+-+|");
        // Initialize the content array
        contentLabel[0] = '\0';
    }

    Label::Label(const char* frameArg) {
        contentLabel[0] = '\0';
        strCpy(frame, frameArg);
    }

    Label::Label(const char* frameArg, const char* content) {
        strCpy(frame, frameArg);

        strnCpy(contentLabel, content, 70);
        contentLabel[70] = '\0'; // Ensure null-termination of the content string
    }

    Label::~Label() {
        //delete[] contentLabel;
    }

    void Label::readLabel() {
        cin.getline(contentLabel, 71);
    }

    std::ostream& Label::printLabel() const {
        int contentLength = strLen(contentLabel);
        int frameWidth = contentLength + 2;

        if (contentLabel[0] != '\0') {
            // Print the top line
            cout << frame[0];
            for (int i = 0; i < frameWidth; i++) {
                cout << frame[1];
            }
            cout << frame[2] << endl;

            // Print the top middle lines
                cout << frame[7];
                for (int i = 0; i < frameWidth; i++) {
                    cout << ' ';
                }
                cout << frame[3] << endl;
            

            // Print the content line
            cout << frame[7] << ' ' << contentLabel << ' ' << frame[3] << endl;

            // Print the bottom middle lines
            cout << frame[7];
            for (int i = 0; i < frameWidth; i++) {
                cout << ' ';
            }
            cout << frame[3] << endl;

            // Print the bottom line
            cout << frame[6];
            for (int i = 0; i < frameWidth; i++) {
                cout << frame[5];
            }
            cout << frame[4];
        }
        return cout;
    }
}
