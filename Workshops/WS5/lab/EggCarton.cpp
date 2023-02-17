/*
*****************************************************************************
<assessment name example: Workshop - #5 (Part-1)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 02/17/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "EggCarton.h"
#include <iomanip>

using namespace std;

namespace sdds {
    // EggCarton constructor that takes in size, number of eggs, and jumboSize as parameters
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
        // Check if the size is a multiple of 6 between 6 and 36, and the number of eggs is non-negative and less than or equal to the size
        if (size % 6 != 0 || size < 6 || size > 36 || noOfEggs < 0 || noOfEggs > size) {
            // If any of the above conditions are not met, set the egg carton to be broken
            setBroken();
        }
        else {
            // If the above conditions are met, set the member variables of the egg carton to the input parameters
            m_size = size;
            m_noOfEggs = noOfEggs;
            m_jumboSize = jumboSize;
        }
    }

    // Function to set the egg carton to be broken
    void EggCarton::setBroken() {
        m_size = -1;
        m_noOfEggs = -1;
        m_jumboSize = false;
    }

    // Function to check if the egg carton is empty (i.e., has no eggs)
    bool EggCarton::isEmpty() const {
        return m_noOfEggs == 0;
    }

    // Function to check if the egg carton is full (i.e., has the maximum number of eggs)
    bool EggCarton::isFull() const {
        return m_noOfEggs == m_size;
    }

    // Function to discard all the eggs in the egg carton
    void EggCarton::discard() {
        m_noOfEggs = 0;
    }

    // Function to fill the egg carton with the maximum number of eggs
    void EggCarton::fill() {
        m_noOfEggs = m_size;
    }

    // Function to display the contents of the egg carton (or a message indicating that it is broken) to an output stream
    ostream& EggCarton::display(ostream& ostr) const {
        // Check if the egg carton is not broken
        if (*this) {
            // If the egg carton is not broken, display its contents using the displayCarton function
            displayCarton(m_size, m_noOfEggs, m_jumboSize, ostr);
        }
        else {
            // If the egg carton is broken, display a message indicating that it is broken
            ostr << "Broken Egg Carton!" << endl;
        }
        // Return the output stream
        return ostr;
    }


    // Displays the contents of an egg carton, given the size of the carton, the number of eggs in it, and whether the eggs are jumbo or not
    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
        int cartonWidth = size == 6 ? 3 : 6; // Calculate the width of each row of eggs, depending on the size of the carton
        for (int i = 0; i < size; i++) {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' '); // Print each egg, using the appropriate character (uppercase 'O' for jumbo eggs, lowercase 'o' for regular eggs)
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl; // Print a closing bracket and a newline at the end of each row of eggs
        }
        return ostr;
    }

    // Reads the contents of an egg carton from an input stream

    istream& EggCarton::read(istream& istr) {
        char jumboChar, comma1, comma2;
        int size, noOfEggs;

        istr >> jumboChar >> comma1 >> size >> comma2 >> noOfEggs; // Read in the contents of the egg carton from the input stream

        if (istr.fail()) {
            setBroken(); // If the input stream has failed, mark the egg carton as "broken"
        }
        else {
            if (jumboChar == 'j') {
                m_jumboSize = true; // If the first character read is 'j', then the eggs in the carton are jumbo
            }
            else {
                m_jumboSize = false; // Otherwise, they are regular-sized
            }
            if (size % 6 != 0 || size < 6 || size > 36 || noOfEggs < 0 || noOfEggs > size) {
                setBroken(); // If the size or number of eggs read in is invalid, mark the egg carton as "broken"
            }
            else {
                m_size = size; // Otherwise, set the size and number of eggs in the egg carton
                m_noOfEggs = noOfEggs;
            }
        }
        return istr; // Return the input stream
    }

    //Type Converter Operator overloads

    // Returns a boolean value indicating whether the egg carton is in a valid state or not
    EggCarton::operator bool() const {
        return m_size > 0; // If the size of the egg carton is greater than 0, it is considered valid
    }

    // Returns the number of eggs in the egg carton as an integer
    EggCarton::operator int() const {
        return m_size > 0 ? m_noOfEggs : -1;
    }

    //Returns the newly added weight of the eggs
    EggCarton::operator double() const {
        if (m_size <= 0) return -1.0;
        const double eggWeight = m_jumboSize ? JumboEggWieght : RegularEggWieght;
        double NeweggWeight = eggWeight / 1000;
        return m_noOfEggs * NeweggWeight;
    }


    //Unary Operator overloads

    // Prefix -- operator
    EggCarton& EggCarton::operator--() {
        if (m_size > 0 && m_noOfEggs > 0) {
            --m_noOfEggs;
        }
        return *this;
    }

    // Prefix ++ operator
    EggCarton& EggCarton::operator++() {
        if (m_size > 0) {
            ++m_noOfEggs;
            if (m_noOfEggs > m_size) {
                setBroken();
            }
        }
        return *this;
    }

    // Postfix -- operator
    EggCarton EggCarton::operator--(int) {
        EggCarton temp(*this);
        --(*this);
        return temp;
    }

    // Postfix ++ operator
    EggCarton EggCarton::operator++(int) {
        EggCarton temp(*this);
        ++(*this);
        return temp;
    }

    // Sets the number of eggs in the egg carton and checks if it is over capacity. If so, it sets the egg carton as broken.
    EggCarton& EggCarton::operator=(int value) {
        m_noOfEggs = value;
        if (m_noOfEggs > m_size) {
            setBroken();
        }
        return *this;
    }

    // Adds eggs to the egg carton and checks if the carton is already full. If it is not full, it adds the eggs and checks if it is over capacity, and if so, sets the egg carton as broken.
    EggCarton& EggCarton::operator+=(int value) {
        if (*this && !isFull()) {
            m_noOfEggs += value;
            if (m_noOfEggs > m_size) {
                setBroken();
            }
        }
        return *this;
    }

    // Adds the eggs from another egg carton to this egg carton, up to the capacity of this egg carton, and reduces the number of eggs in the other carton accordingly.
    EggCarton& EggCarton::operator+=(EggCarton& right) {
        if (*this && m_size > 0) {
            int emptySpots = m_size - m_noOfEggs;
            if (emptySpots > 0) {
                int transferAmount = min(emptySpots, right.m_noOfEggs);
                m_noOfEggs += transferAmount;
                right.m_noOfEggs -= transferAmount;
            }
        }
        return *this;
    }

    // Checks if the number of eggs in two egg cartons is approximately equal.
    bool EggCarton::operator==(const EggCarton& right) const {
        double diff = static_cast<double>(*this) - static_cast<double>(right);
        return (diff >= -0.001 && diff <= 0.001);
    }

    // Adds an integer to an egg carton and returns the total number of eggs, unless the egg carton is broken, in which case it just returns the original integer.
    int operator+(int left, const EggCarton& right) {
        if (!right.isBroken()) {
            return left + right.getNumEggs();
        }
        else {
            return left;
        }
    }

    // Checks if the egg carton is broken.
    bool EggCarton::isBroken() const {
        return -1; 
    }

    // Returns the number of eggs in the egg carton.
    int EggCarton::getNumEggs() const {
        return m_noOfEggs;
    }

    // Writes the contents of the egg carton to an output stream.
    ostream& operator<<(ostream& ostr, const EggCarton& right) {
        right.display(ostr); 
        return ostr;
    }

    // Reads the contents of the egg carton from an input stream.
    istream& operator>>(istream& istr, EggCarton& right) {
        right.read(istr); 
        return istr;
    }



}

