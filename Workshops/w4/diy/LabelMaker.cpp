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
#include "LabelMaker.h"
#include <iostream>
using namespace std;
namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels) {
        // Set the number of labels
        numberOfLabels = noOfLabels;
        // Create a dynamic array of labels
        labels = new Label[numberOfLabels];
    }

    void LabelMaker::readLabels() {
        cout << "Enter " << numberOfLabels << " labels:" << endl;
        for (int i = 0; i < numberOfLabels; i++) {
            cout << "Enter label number " << (i + 1) << endl;
            cout << "> ";
            // Read label content for each label
            labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels() {
        for (int i = 0; i < numberOfLabels; i++) {
            // Print each label
            labels[i].printLabel();
            cout << endl;
        }
    }

    LabelMaker::~LabelMaker() {
        // Deallocate the dynamic array of labels
        delete[] labels;
    }
}