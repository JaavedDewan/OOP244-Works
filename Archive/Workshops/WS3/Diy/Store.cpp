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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Store.h"

using namespace sdds;

void Store::setStore(const char* sName, int no)
{
    // Check if the store name is a null pointer or an empty string, or if the number of toys is less than or equal to 0
    if (sName == nullptr || sName[0] == '\0' || no <= 0)
    {
        // Set the store as an empty object
        setEmpty();
    }
    else
    {
        // Set the number of toys
        m_noOfToys = no;
        // Reset the number of additional toys to 0
        m_addToys = 0;
        // Copy the store name to m_sName
        strncpy(m_sName, sName, MAX_SNAME);
        // Ensure that m_sName is a valid C-string
        m_sName[MAX_SNAME - 1] = '\0';
    }
}



void Store::setToys(const char* tname, int sku, double price, int age)
{
    // Check if the number of toys already added to the store is equal to or greater than the maximum number of toys the store can hold
    if (m_addToys >= m_noOfToys)
    {
        // Return without adding a new toy
        return;
    }
    // Add a new toy
    m_toy[m_addToys++].addToys(tname, sku, price, age);
}



void Store::display() const
{
    // Check if the store is an invalid object
    if (m_sName[0] == '\0')
    {
        // Display "Invalid Store"
        std::cout << "Invalid Store" << endl;
    }
    else
    {
        // Display the store information
        cout << setfill('*') << setw(60) << "*" << endl;
        cout << m_sName << endl;
        cout << setfill('*') << setw(60) << "*" << endl;
        cout << "list of the toys" << endl;
        cout << setfill(' ') << setw(30) << "SKU";
        cout << setw(10) << "Age";
        cout << setw(11) << "Price";
        cout << setw(10) << "Sale" << endl;
        // Display the information about each toy
        for (int i = 0; i < m_addToys; i++)
        {
            cout << "Toy[" << i + 1 << "] :";
            m_toy[i].display();
        }
    }
}


void Store::find(int sku)
{
    // loop through all the toys in the store
    for (int i = 0; i < m_addToys; i++)
    {
        // if the SKU of the toy matches the input sku
        if (m_toy[i].getSKU() == sku)
        {
            // mark the toy as on sale
            m_toy[i].isSale(true);
            // calculate the sale price of the toy
            m_toy[i].calSale();
        }
    }
}

void Store::setEmpty()
{
    // set the store name to an empty string
    m_sName[0] = '\0';
    // set the number of toys in the store to 0
    m_noOfToys = 0;
    // set the number of toys added to the store to 0
    m_addToys = 0;
}
