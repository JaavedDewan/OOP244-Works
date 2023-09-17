/*
*****************************************************************************
Workshop - #3 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/04/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {

    Food::Food()
    {
        m_foodName[0] = '\0'; // Initialize the array with a null character to represent an empty string
        m_mealCode = 0;
    }

    Food::Food(const char* foodName, int mealCode)
    {
        // Copy the food name to the m_foodName array
        int i = 0;
        while (foodName[i] != '\0' && i < 30)
        {
            m_foodName[i] = foodName[i];
            i++;
        }
        m_foodName[i] = '\0'; // Add a null character to terminate the string

        m_mealCode = mealCode;
    }


    void Food::setName(const char* name) {
        // Check if the name pointer is not null
        if (name != nullptr) {
            // Copy characters from name to m_itemName, up to sizeof(m_itemName) - 1 characters
            strnCpy(m_foodName, name, sizeof(m_foodName) - 1);

            // Add a null terminator at the end of m_itemName to ensure it is a null-terminated string
            m_foodName[sizeof(m_foodName) - 1] = '\0';
        }
    }

    void Food::setEmpty() {
        // Set the calorie to -1;
        m_calories = -1;

        // Set the first character of m_itemName to null character, indicating an empty string
        m_foodName[0] = '\0';
    }

    void Food::set(const char* name, int calories, int mealCode) {
        // Set the name using the setName() function
        setName(name);

        // Set the price
        m_calories = calories;

        // Set the taxed status
        m_mealCode = mealCode;
    }

    int Food::calorie() const {
        return m_calories;
    }

    int Food::mealCode() const {
        return m_mealCode;
    }

    bool Food::isValid() const {
        // Check if the item name is not an empty string, not a null pointer,
        // not equal to an empty string, and within the maximum length
        int count = 0;
        while (m_foodName[count] != '\0' && count < 30) {
            count++;
        }
        return m_foodName[0] != '\0' && m_mealCode != 0 && count <= 30;
    }





    void Food::display() const {
        if (isValid()) {
            cout << "| ";

            // Set the width to 20 characters and fill the remaining space with periods
            cout.width(30);
            cout.fill('.');
            cout << left << m_foodName << " | ";

            // Set the width to 7 characters and fill the remaining space with spaces
            cout.width(4);
            cout.fill(' ');

            // Display the price with right alignment and fixed decimal precision
            cout << right << fixed << m_calories << " | ";
            cout.unsetf(ios::fixed);
            cout.width(10);
            cout.fill(' ');
            cout << left;
            // Display "Yes" if the item is taxed, "No" otherwise
            if (m_mealCode == 1) {
                cout << "Breakfast";
            }
            else if (m_mealCode == 2) {
                cout << "Lunch";
            }
            else if (m_mealCode == 3) {
                cout << "Dinner";
            }
            else {
                cout << "Snack";
            }
            cout << " |" << endl;

        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

}