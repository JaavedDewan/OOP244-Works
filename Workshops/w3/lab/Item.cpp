/*
*****************************************************************************
Workshop - #3 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/31/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

    void Item::setName(const char* name) {
        // Check if the name pointer is not null
        if (name != nullptr) {
            // Copy characters from name to m_itemName, up to sizeof(m_itemName) - 1 characters
            strnCpy(m_itemName, name, sizeof(m_itemName) - 1);

            // Add a null terminator at the end of m_itemName to ensure it is a null-terminated string
            m_itemName[sizeof(m_itemName) - 1] = '\0';
        }
    }





    void Item::setEmpty() {
        // Set the price to 0.0
        m_price = 0.0;

        // Set the first character of m_itemName to null character, indicating an empty string
        m_itemName[0] = '\0';
    }

    void Item::set(const char* name, double price, bool taxed) {
        // Set the name using the setName() function
        setName(name);

        // Set the price
        m_price = price;

        // Set the taxed status
        m_taxed = taxed;
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        const double TAX_RATE = 0.13;
        double tax = 0;

        // Calculate the tax based on the taxed status
        if (m_taxed)
            tax = m_price * TAX_RATE;
        else {
            tax = 0.0;
        }

        return tax;
    }


    bool Item::isValid() const {
        // Check if the item name is not an empty string and the price is not zero
        return m_itemName[0] != '\0' && m_price != 0.0;
    }

    void Item::display() const {
        if (isValid()) {
            cout << "| ";

            // Set the width to 20 characters and fill the remaining space with periods
            cout.width(20);
            cout.fill('.');
            cout << left << m_itemName << " | ";

            // Set the width to 7 characters and fill the remaining space with spaces
            cout.width(7);
            cout.fill(' ');

            // Set the precision to 2 decimal places
            cout.precision(2);

            // Display the price with right alignment and fixed decimal precision
            cout << right << fixed << m_price << " | ";
            cout.unsetf(ios::fixed);

            // Display "Yes" if the item is taxed, "No" otherwise
            cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }


}