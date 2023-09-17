/*
*****************************************************************************
Workshop - #5 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/18/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds {
    class Mark {
        int m_mark;       // Stores the mark value
        double m_gpa;     // Stores the GPA equivalent
        char m_grade;     // Stores the grade letter

    public:
        Mark();                                // Default constructor
        Mark(int mark);                        // Constructor with mark value
        operator int() const;                   // Conversion operator to int
        operator double() const;                // Conversion operator to double
        operator char() const;                  // Conversion operator to char
        Mark& operator=(int mark);              // Assignment operator
        Mark& operator+=(const Mark& other);             // Addition assignment operator
        friend int operator+=(int& value, const Mark& mark);   // Friend addition operator
    };



}
#endif // SDDS_MARK_H_