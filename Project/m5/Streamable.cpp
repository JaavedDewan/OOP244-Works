/*
*****************************************************************************
Project - Milestone 5
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 08/06/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "Streamable.h"

namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Streamable& streamable) {
        if (static_cast<bool>(streamable)) {
            streamable.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& streamable) {
        streamable.read(is);
        return is;
    }
}
