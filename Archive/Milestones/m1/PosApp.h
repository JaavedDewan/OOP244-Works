/*
*****************************************************************************
<assessment name example: Project - Milestone 1>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 03/10/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

#include "Utils.h"
#include <fstream>

const int MAX_FILE_LENGTH = 100;

namespace sdds {
    class PosApp {
        char m_filename[256];
        Item* m_items[MAX_NO_ITEMS];
        int m_noOfItems;
        bool m_errorState;

        void listItems() const;
        void addItem();
        void removeItem();
        void stockItem();
        void showBill();
        void addToBill(Item& item);
        void POS();
        void saveRecs();
        void loadRecs();
        bool searchItems(const char* sku) const;
        int menu();
        void deallocateItems();
        void emptyBill();
    public:
        PosApp(const char* filename);
        PosApp(const PosApp&) = delete;
        PosApp& operator=(const PosApp&) = delete;
        ~PosApp();
        void run();
    };
}

#endif // !SDDS_POSAPP_H


