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
#include "Bus.h"
namespace sdds {
    //Constructor
    Bus::Bus(int seats, int passengers) {
        if (seats % 2 == 0 && seats >= 10 && seats <= 40 && passengers >= 0 && passengers <= seats) {
            m_seats = seats;
            m_passengers = passengers;
        }
        else {
            setEmpty();
        }
    }

    //Check if Empty Function
    bool Bus::isEmpty() const {
        return m_passengers == 0;
    }
    //Check if Full Function
    bool Bus::isFull() const {
        return m_passengers == m_seats;
    }

    //Empty Function
    void Bus::setEmpty() {
        m_seats = 0;
        m_passengers = 0;
    }

    //Output Conditions
    ostream& Bus::display(ostream& ostr) const{
        if (m_seats % 2 == 0 && m_seats >= 10 && m_seats <= 40 && m_passengers >= 0 && m_passengers <= m_seats) {
            drawBus(m_seats, m_passengers, ostr);
        }
        else {
            ostr << "Out of service!" << endl;
        }
        return ostr;
    }
    //Output Function
    ostream& Bus::drawBus(int seats, int noOfPassengers, ostream& ostr)const {
        int i, p;
        double c = noOfPassengers * BUS_TICKET_PRICE;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " " << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " " << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-" << "O---'" << endl;
        ostr << "Total Fare Price: " << setprecision(2) << fixed << c << endl;
        return ostr;
    }
    //Read function.
    istream& Bus::read(istream& istr) {
        int seats, passengers;
        char comma;
        istr >> seats >> comma >> passengers;
        if (istr.fail()) {
            setEmpty(); // If the input stream has failed, mark the egg carton as "broken"
        }
        else {
        
            if (seats % 2 == 0 && seats >= 10 && seats <= 40 && passengers >= 0 && passengers <= seats) {
                m_seats = seats;
                m_passengers = passengers;
            }
            else {
                setEmpty();
            }
        }
        return istr;
    }
    //Boolean conversion
    Bus::operator bool() const {
        if (m_seats > 0) {
            return true;
        }
        else {
        
            return false;
        }
    }
    //Intger conversion
    Bus::operator int() const {
        if (m_seats % 2 == 0 && m_seats >= 10 && m_seats <= 40)
        {
            return m_passengers;
        }
        else 
        {
            return -1;
        }
    }
    //Double conversion
    Bus::operator double() const {
        if (m_seats % 2 == 0 && m_seats >= 10 && m_seats <= 40)
        {
            return m_passengers * BUS_TICKET_PRICE;
        }
        else
        {
            return -1.0;
        }
    }

    //Pre fix: Checks if the bus is empty.
    bool Bus::operator--() {
        if (isEmpty()) {
            return false;
        }
        else {
            --m_passengers;
            return true;
        }
    }
    //Pre Fix: Checks if the bus is full.
    bool Bus::operator++() {
        if (isFull()) {
            return false;
        }
        else {
            ++m_passengers;
            return true;
        }
    }
    //Post fix
    bool Bus::operator--(int) {
        return operator--();
    }
    //Post fix
    bool Bus::operator++(int) {
        return operator++();
    }


    //Sets the number of passengers of a bus by assigning it to the integer value and If the number of passengers exceeds the number of seats, the bus will be out of service.
    Bus& Bus::operator=(int value) {
        if (value > m_seats) {
            setEmpty();
        }
        else {
            m_passengers = value;
        }
        return *this;
    }

    //Adds the integer value to the number of passengers if the bus is in service. If the number of passengers exceeds the number of seats, the bus will go out of service.
    Bus& Bus::operator+=(int value) {
        if (!isEmpty()) {
            int newPassengers = m_passengers + value;
            if (newPassengers > m_seats) {
                setEmpty();
            }
            else {
                m_passengers = newPassengers;
            }
        }
        return *this;
    }

    //Adds passengers from one bus to another up to its filled capacity.
    Bus& Bus::operator+=(Bus& right) {
        if (*this && m_seats > 0) {
            int emptySeats = m_seats - m_passengers;
            if (emptySeats > 0)
            {
                int transferAmount = min(emptySeats, right.m_passengers);
                m_passengers += transferAmount;
                right.m_passengers -= transferAmount;
            }
        }
        return *this;
    }

    //Checks to see if the passengers of two valid buses are the same.
    bool Bus::operator==(const Bus& right) const {
        if (*this && m_seats > 0 && m_passengers == right.m_passengers) {
            return true;
        }
        return false;
    }
    //Helper function for binary. Returns the total sum of passengers.
    int operator+(int left, const Bus& right) {
        if (!right.isOut()) {
            return left + right.getPassengers();
        }
        else {
            return left;
        }
    }

    // Checks if the bus is out of service.
    bool Bus::isOut() const
    {
    return 0;
    }

    // Returns the number of passenger in the bus.
    int Bus::getPassengers() const 
    {
        return m_passengers;
    }
    // Writes the contents of the bus seats to an output stream.
    ostream& operator<<(ostream& ostr, const Bus& right) 
    {
        right.display(ostr);
        return ostr;
    }

    // Reads the contents of the bust seats from an input stream.
    istream& operator>>(istream& istr, Bus& right) {
        right.read(istr);
        return istr;
    }
}
