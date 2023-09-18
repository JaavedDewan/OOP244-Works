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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

const int MAX_NO_ITEMS = 2000;


namespace sdds {

    const int MAX_SKU_LEN = 7;
    const int MAX_NAME_LEN = 20;
    const int MAX_NO_ITEMS = 2000;
    const double TAX = 0.13;

    class Item {
        char m_sku[7];
        char m_name[21];
        double m_price;
        bool m_taxed;
        int m_quantity;
    public:
        Item();
        Item(const char* sku, const char* name, double price, bool taxed = true);
        Item(const Item& other);
        virtual ~Item();
        Item& operator=(const Item& other);
        void sku(const char* sku);
        void name(const char* name);
        void price(double price);
        void taxed(bool taxed);
        void quantity(int quantity);
        const char* sku() const;
        const char* name() const;
        double price() const;
        bool taxed() const;
        int quantity() const;
        double cost() const;
        bool isEmpty() const;
        bool operator==(const char* sku) const;
        int operator+=(int quantity);
        int operator-=(int quantity);
    };

    double operator+=(double& d, const Item& item);
    std::ostream& operator<<(std::ostream& os, const Item& item);
    std::istream& operator>>(std::istream& is, Item& item);
}

#endif // !SDDS_UTILS_H


