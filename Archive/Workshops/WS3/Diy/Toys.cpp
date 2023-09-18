/*
*****************************************************************************
<assessment name example: Workshop - #3 (Part-2)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 02/06/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Toys.h"
#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>

namespace sdds {
    void Toys::addToys(const char* tname, int sku, double price, int age)
    {
        // Check if all input parameters are valid
        if (tname != nullptr && tname[0] != '\0' && sku >= 0 && price >= 0 && age >= 0)
        {
            // Copy the name of the toy to the member variable
            strncpy(m_tname, tname, static_cast<size_t>(MAX_TNAME) - 1);
            // Ensure that the string is null-terminated
            m_tname[MAX_TNAME - 1] = '\0';
            // Set the SKU of the toy
            m_sku = sku;
            // Set the price of the toy
            m_price = price;
            // Set the recommended age for the toy
            m_age = age;
            // Set the on-sale status of the toy to false
            m_onSale = false;
        }
        else
        {
            // If any of the input parameters is invalid, set the toy object to an empty state
            setEmpty();
        }
    }


    void Toys::isSale(bool sale) {
        m_onSale = sale;
    }

    void Toys::calSale() {
        m_price *= 0.8;
    }

    void Toys::display() const {
        // Convert the SKU int value to a string to check its length
        std::string len_sku;
        std::stringstream length;
        length << m_sku;
        length >> len_sku;
        // Check if the toy is valid
        if (m_tname[0] != '\0' && len_sku.length() == 8 && m_price >= 0 && m_age >= 0) {
            // Align the text to the left for the toy name and align the values to the right for the rest of the data
            cout << left << setw(15) << m_tname;
            cout << right << setw(10) << m_sku;
            cout << right << setw(6) << m_age;
            cout << right << setw(12) << fixed << setprecision(2) << m_price;

            // If the toy is on sale, display "On Sale" after the price
            if (m_onSale) {
                cout << right << setw(10) << "On Sale";
            }
            else
            {
                cout << "       "; //When empty lines don't exist according to the OOP244 matrix compiler and requires 5 unnecessary spaces after the this output.
            }
            // Add a new line at the end
            cout << " " << endl; //When empty lines don't exist according to the OOP244 matrix compiler.
        }
        // If the toy is invalid, display "Invalid Toy"
        else {
            cout << "Invalid Toy" << endl;
        }

    }



    //Extra Functions I have added.


    // Function to get the SKU number of a toy object
    int Toys::getSKU() const {
        return m_sku;
    }

    // Function to reset all member variables of a toy object to default values
    void Toys::setEmpty() {
        // Set the name of the toy to an empty string
        m_tname[0] = '\0';
        // Set the SKU number to 0
        m_sku = 0;
        // Set the price of the toy to 0
        m_price = 0;
        // Set the recommended age for the toy to 0
        m_age = 0;
        // Set the "on sale" status of the toy to false
        m_onSale = false;
    }
}






