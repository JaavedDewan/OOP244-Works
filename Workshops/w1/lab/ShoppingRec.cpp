/*
*****************************************************************************
Workshop - #1 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/16/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "ShoppingRec.h"
#include "Utils.h"
#include <iostream>
using namespace std;
using namespace sdds;

const int MAX_QUANTITY_VALUE = 50;

ShoppingRec sdds::getShoppingRec() {
    ShoppingRec R = {};
    cout << "Item name: ";
    readCstr(R.m_title, MAX_TITLE_LENGTH);
    cout << "Quantity: ";
    R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
    return R;
}
void sdds::displayShoppingRec(const ShoppingRec* shp) {
    cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
        " qty:(" << shp->m_quantity << ")" << endl;
}
void sdds::toggleBoughtFlag(ShoppingRec* rec) {
    rec->m_bought = !rec->m_bought;

}
bool sdds::isShoppingRecEmpty(const ShoppingRec* shp) {
    return shp->m_title[0] == 0;
}
