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
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {

    // Item class member functions

    Item::Item() : m_sku{ '\0' }, m_name{ '\0' }, m_price{ 0.0 }, m_taxed{ true }, m_quantity{ 0 } {}

    Item::Item(const char* sku, const char* name, double price, bool taxed) : m_price{ 0.0 }, m_quantity{ 0 } {
        this->sku(sku);
        this->name(name);
        this->price(price);
        this->taxed(taxed);
    }



    Item::Item(const Item& other) {
        *this = other;
    }

    Item::~Item() {}

    Item& Item::operator=(const Item& other) {
        if (this != &other) {
            strcpy(m_sku, other.m_sku);
            strcpy(m_name, other.m_name);
            m_price = other.m_price;
            m_taxed = other.m_taxed;
            m_quantity = other.m_quantity;
        }
        return *this;
    }

    void Item::sku(const char* sku) {
        strcpy(m_sku, sku);
    }

    void Item::name(const char* name) {
        strcpy(m_name, name);
    }

    void Item::price(double price) {
        m_price = price;
    }

    void Item::taxed(bool taxed) {
        m_taxed = taxed;
    }

    void Item::quantity(int quantity) {
        m_quantity = quantity;
    }

    const char* Item::sku() const {
        return m_sku;
    }

    const char* Item::name() const {
        return m_name;
    }

    double Item::price() const {
        return m_price;
    }

    bool Item::taxed() const {
        return m_taxed;
    }

    int Item::quantity() const {
        return m_quantity;
    }

    double Item::cost() const {
        double cost = m_price;
        if (m_taxed) {
            cost *= (1 + TAX);
        }
        return cost;
    }

    bool Item::isEmpty() const {
        return (m_sku[0] == '\0' && m_name[0] == '\0' && m_price == 0.0 && m_quantity == 0);
    }

    bool Item::operator==(const char* sku) const {
        return (strcmp(m_sku, sku) == 0);
    }

    int Item::operator+=(int quantity) {
        m_quantity += quantity;
        return m_quantity;
    }

    int Item::operator-=(int quantity) {
        m_quantity -= quantity;
        return m_quantity;
    }

    // non-member operator functions

    double operator+=(double& d, const Item& item) {
        return d += item.cost();
    }

    std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << std::setw(4) << item.sku() << "|"
            << std::setw(20) << item.name() << "|"
            << std::setw(7) << std::fixed << std::setprecision(2) << item.price() << "|";

        if (item.taxed()) {
            os << " t |";
        }
        else {
            os << "   |";
        }

        os << std::setw(4) << item.quantity() << "|"
            << std::setw(9) << std::fixed << std::setprecision(2) << item.cost() << "|";

        return os;
    }

    std::istream& operator>>(std::istream& is, Item& item) {
        char sku[7];
        char name[21];
        char taxed;
        double price;
        int quantity;

        is >> sku >> name >> price >> taxed >> quantity;

        if (is.good()) {
            item.sku(sku);
            item.name(name);
            item.price(price);
            item.taxed(taxed == 't' || taxed == 'T');
            item.quantity(quantity);
        }
        else {
            is.setstate(std::ios::failbit);
        }

        return is;
    }
}