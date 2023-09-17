/*
*****************************************************************************
Project - Milestone 4
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 08/02/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
namespace sdds {
    class Streamable {
    public:
        // Pure virtual functions
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(const std::ios& ios) const = 0;
        virtual operator bool() const = 0; // Boolean conversion operator overload

        // Virtual destructor
        virtual ~Streamable() {}
    };
    // Insertion operator overload
    std::ostream& operator<<(std::ostream& os, const Streamable& streamable);

    // Extraction operator overload
    std::istream& operator>>(std::istream& is, Streamable& streamable);

}
#endif // !SDDS_STREAMABLE_H_
