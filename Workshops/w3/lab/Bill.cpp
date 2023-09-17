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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    void Bill::setEmpty() {
        // Set the title to an empty string
        m_title[0] = '\0';

        // Deallocate the dynamically allocated items array and set it to nullptr
        delete[] m_items;
        m_items = nullptr;

        // Reset the number of items and items added to zero
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }

    bool Bill::isValid() const {
        // Initialize the flag as true
        bool ok = true;

        // Check if the title is an empty string or the items array is nullptr
        if (m_title[0] == '\0' || m_items == nullptr) {
            ok = false;
        }

        // Iterate through each item and check if it is valid
        int i = 0;
        int noOfItems = m_noOfItems;
        while (i < m_noOfItems && ok) {
            if (!m_items[i].isValid()) {
                ok = false;
                i = noOfItems;
            }
            i++;
        }

        // Return the overall validity flag
        return ok;
    }

    double Bill::totalTax() const {
        double total = 0.0;

        // Iterate through each added item and accumulate the tax amount
        for (int i = 0; i < m_itemsAdded; i++) {
            total += m_items[i].tax();
        }

        return total;
    }

    double Bill::totalPrice() const {
        double total = 0.0;

        // Iterate through each added item and accumulate the price
        for (int i = 0; i < m_itemsAdded; i++) {
            total += m_items[i].price();
        }

        return total;
    }


    void Bill::Title() const {
        // Display the top separator line
        cout << "+--------------------------------------+" << endl;

        if (isValid()) {
            cout << "| "; // Start of the title line
            cout.width(36);
            cout << left << m_title << " |"; // Display the title aligned to the left within a width of 36 characters
            cout << endl;
        }
        else {
            cout << "| Invalid Bill                         |"; // Display the invalid bill message
            cout << endl;
        }

        // Display the separator line and the header for item details
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }


    void Bill::footer() const {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid()) {
            cout << "| "; // Start of the line
            cout.width(25);
            cout.fill(' ');
            cout << right << "Total Tax:"; // Display "Total Tax:" aligned to the right within a width of 25 characters
            cout.width(11);
            cout.fill(' ');
            cout.precision(2);
            cout << right << fixed << totalTax() << " |"; // Display the total tax value with 2 decimal places aligned to the right within a width of 11 characters
            cout << endl;

            cout << "| "; // Start of the line
            cout.width(25);
            cout.fill(' ');
            cout << right << "Total Price:"; // Display "Total Price:" aligned to the right within a width of 25 characters
            cout.width(11);
            cout.fill(' ');
            cout << totalPrice() << " |"; // Display the total price value aligned to the right within a width of 11 characters
            cout << endl;

            cout << "| "; // Start of the line
            cout.width(25);
            cout.fill(' ');
            cout << right << "Total After Tax:"; // Display "Total After Tax:" aligned to the right within a width of 25 characters
            cout.width(11);
            cout.fill(' ');
            cout << totalTax() + totalPrice() << " |"; // Display the total after-tax value aligned to the right within a width of 11 characters
            cout << endl;

        }
        else {
            cout << "| Invalid Bill                         |"; // Display the invalid bill message
            cout << endl;
        }

        cout << "+--------------------------------------+" << endl;
    }


    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty(); // If title is nullptr or noOfItems is zero or negative, set the bill to an empty state
        }
        else {
            m_noOfItems = noOfItems; // Set the number of items in the bill
            m_itemsAdded = 0; // Reset the count of items added to zero

            strnCpy(m_title, title, 36); // Copy the title string up to 36 characters into m_title
            m_title[36] = '\0'; // Ensure the m_title string is null-terminated

            m_items = new Item[m_noOfItems]; // Dynamically allocate an array of Item objects with the specified number of items
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty(); // Set each item in the array to an empty state
            }
        }
    }


    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool ok = false;
        if (m_itemsAdded < m_noOfItems && price > 0) {
            m_items[m_itemsAdded].set(item_name, price, taxed); // Set the item details at the current index in the m_items array
            m_itemsAdded++; // Increment the count of items added
            ok = true;
        }
        return ok;
    }

    void Bill::display() const {
        Title(); // Display the bill title and item header

        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display(); // Display each item in the bill
        }

        footer(); // Display the bill footer with total tax, total price, and total after tax
    }

    void Bill::deallocate() {
        delete[] m_items; // Deallocate the dynamically allocated m_items array
        m_items = nullptr; // Set the pointer to null to indicate that the memory has been deallocated
    }


}