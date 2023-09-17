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
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {
        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name); // Sets the name of the item
    public:
        void setEmpty(); // Sets the item to an empty state
        void set(const char* name, double price, bool taxed); // Sets the details of the item
        void display() const; // Displays the item details
        bool isValid() const; // Checks if the item is valid (has a name and price)
        double price() const; // Returns the price of the item
        double tax() const; // Returns the tax amount for the item
    };
}


#endif // !SDDS_SUBJECT_H
