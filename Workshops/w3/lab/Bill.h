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
#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds {
   class Bill {
      char m_title[37];  // title of the shopping list
      Item* m_items;     // pointer to the dynamically allocated array of Items
      int m_noOfItems;   // size of the dynamically allocated array of Items
      int m_itemsAdded;  // number of the Items added by the add method
      double totalTax()const;   // returns the total tax applied to the Items
      double totalPrice()const;  // returns the sum of prices of Items
      void Title()const;       // Prints the title of the shopping list
            // prints the footer contaning total tax, price and total price after tax
      void footer()const;
      void setEmpty();     // sets the Bill to an emtpy state
      bool isValid()const;  // returns true is the Bill and all of its Items are valid
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
