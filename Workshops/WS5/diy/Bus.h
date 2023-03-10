/*
*****************************************************************************
<assessment name example: Workshop - #5 (Part-2)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 02/22/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_

#include <iostream>
#include <iomanip>
using namespace std;

namespace sdds {
    const double BUS_TICKET_PRICE = 125.34;

    class Bus {
        int m_seats;
        int m_passengers;
        bool isEmpty() const;
        bool isFull() const;
        void setEmpty();
        ostream& drawBus(int seats, int noOfPassengers, ostream& ostr) const; //Output

    public:
        //Constructor
        Bus(int seats = 20, int passengers = 0);

        //Input and Output
        ostream& display(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);

        //Conversion
        operator bool() const;
        operator int() const;
        operator double() const;

        //Unary
        bool operator--();
        bool operator++();
        bool operator--(int);
        bool operator++(int);

        //Binary
        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);
        bool operator==(const Bus& right) const;
        //Helper
        bool isOut() const;
        int getPassengers() const;

    };
    //Binary Helper
    int operator+(int left, const Bus& right);

    //Output & Input Helper
    ostream& operator<<(std::ostream& os, const Bus& bus);
    istream& operator>>(std::istream& is, Bus& bus);
}

#endif // !SDDS_BUS_H_
