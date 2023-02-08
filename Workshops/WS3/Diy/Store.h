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

#ifndef SDDS_STORE_H
#define SDDS_STORE_H

#include "Toys.h"

namespace sdds {
    const int MAX_NUM_TOYS = 10;
    const int MAX_SNAME = 31;


        class Store {
        char m_sName[MAX_SNAME];
        int m_noOfToys;
        int m_addToys;
        Toys m_toy[MAX_NUM_TOYS];

        public:
            void setStore(const char* sName, int no);
            void setToys(const char* tname, int sku, double price, int age);
            void display()const;
            void find(int sku);
            void setEmpty();
    };

}

#endif