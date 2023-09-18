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
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include <iostream>
#include "Streamable.h"
#include "Date.h"

namespace sdds {

    class Publication : public Streamable {
    private:
        char* m_title;
        char m_shelfId[5]; // 4 characters + 1 null terminator
        int m_membership;  // Changed to an integer to hold a 5-digit membership number
        int m_libRef;
        Date m_date;

    public:
        Publication();
        Publication(const Publication&);
        Publication& operator=(const Publication&);
        ~Publication();

        // Modifiers
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();

        // Queries
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        // Streamable pure virtual function implementations
        bool conIO(const std::ios& ios) const override;
        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& is) override;
        operator bool() const;
    };

}

#endif // SDDS_PUBLICATION_H_
