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

#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H


namespace sdds {

    const int MAX_TNAME = 31;

    class Toys {
        char m_tname[MAX_TNAME];
        int m_sku;
        double m_price;
        int m_age;
        bool m_onSale;

    public:
        void addToys(const char* tname, int sku, double price, int age);
        void isSale(bool sale);
        void calSale();
        void display()const;

        //Extra Functions

        int getSKU() const;
        void setEmpty();
    };

}  // namespace sdds

#endif

