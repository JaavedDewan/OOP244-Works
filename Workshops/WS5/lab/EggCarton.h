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
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
using namespace std;

namespace sdds {
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;

    class EggCarton {
        int m_size;
        int m_noOfEggs;
        bool m_jumboSize;
        void setBroken();
        bool isEmpty() const;
        bool isFull() const;
        ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;
    public:
        //constructor
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);

        //input - output
        ostream& display(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);

        //Type Coversion Operator overloads
        operator bool() const;
        operator int() const;
        operator double() const;

        //Unary Operator overloads
        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator--(int);
        EggCarton operator++(int);

        //Binary Members Operators
        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;

        //Helper Function Assistants
        bool isBroken() const;
        int getNumEggs() const;

    };
    //Helper Functions
    int operator+(int left, const EggCarton& right);
    ostream& operator<<(ostream& ostr, const EggCarton& right);
    istream& operator>>(istream& istr, EggCarton& right);
}
#endif
