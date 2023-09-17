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
#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include "Lib.h"
#include <cstring>
namespace sdds {

    Publication::Publication() : m_title(nullptr), m_membership(0), m_libRef(-1) {
        m_shelfId[0] = '\0';
        m_date = Date();
    }
    Publication::Publication(const Publication& other) : m_title(nullptr) {
        *this = other; // Reuse the assignment operator to copy the data
    }
    Publication& Publication::operator=(const Publication& other) {
        if (this != &other && other.m_date.errCode() == 0) {
            // Clear existing m_title
            delete[] m_title;
            m_title = nullptr;

            // Copy other attributes
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;

            // Copy m_shelfId
            strcpy(m_shelfId, other.m_shelfId);

            // Copy m_title if other has a valid title
            if (other.m_title != nullptr) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
        }
        return *this;
    }
    Publication::~Publication() {
        delete[] m_title;
    }
    void Publication::set(int member_id) {
        m_membership = member_id;
    }
    void Publication::setRef(int value) {
        m_libRef = value;
    }
    void Publication::resetDate() {
        m_date = Date(); // Set the date to the current date using the default constructor of Date
    }
    char Publication::type() const {
        return 'P'; // 'P' to identify this object as a "Publication object"
    }
    bool Publication::onLoan() const {
        return (m_membership != 0); // Returns true if the publication is checked out (membership is non-zero)
    }
    Date Publication::checkoutDate() const {
        return m_date; // Return the date attribute
    }
    bool Publication::operator==(const char* title) const {
        return (strstr(m_title, title) != nullptr); // Returns true if the argument title appears anywhere in the title of the publication, otherwise false.
    }
    Publication::operator const char* () const {
        return m_title; // Returns the title attribute
    }
    int Publication::getRef() const {
        return m_libRef; // Returns the libRef attribute
    }
    bool Publication::conIO(const std::ios& ios) const {
        return (&ios == &std::cin || &ios == &std::cout);
    }
    std::ostream& Publication::write(std::ostream& os) const {
        // Truncate the title to SDDS_TITLE_WIDTH characters
        char reducedTitle[SDDS_TITLE_WIDTH + 1];
        strncpy(reducedTitle, m_title, SDDS_TITLE_WIDTH);
        reducedTitle[SDDS_TITLE_WIDTH] = '\0'; // Ensure null-termination
        if (conIO(os)) {
            os << "| " << m_shelfId << " | ";
            os.width(SDDS_TITLE_WIDTH);
            os.setf(std::ios::left);
            os.fill('.');
            os << reducedTitle;
            os.unsetf(std::ios::left);
            os.fill(' ');
            os << " | ";
            if (m_membership == 0) {
                os << " N/A ";
            }
            else {
                os << m_membership;
            }
            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << reducedTitle << "\t";
            if (m_membership == 0) {
                os << "N/A";
            }
            else {
                os << m_membership;
            }
            os << "\t" << m_date;
        }
        return os;
    }
    std::istream& Publication::read(std::istream& is) {
        // If the m_title is not nullptr, delete the existing memory and set it to nullptr
        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }

        char title[256]{};
        m_shelfId[0] = { '\0' };
        char shelfId[SDDS_SHELF_ID_LEN + 1]{};
        m_membership = 0;
        int memship = 0;
        m_libRef = -1;
        int libref = -1;
        m_date = Date();
        Date date;

        // Check if it's a console IO object
        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(shelfId, SDDS_SHELF_ID_LEN + 1);

            // Check if the shelfId has the correct length
            if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
                is.setstate(std::ios::failbit);
            }

            std::cout << "Title: ";
            is.getline(title, 256);

            std::cout << "Date: ";
            is >> date;
        }
        else {
            // Read libRef
            is >> libref;
            is.ignore(1);

            // Read shelfId
            is.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');

            // Read title
            is.getline(title, 256, '\t');

            // Read membership
            is >> memship;
            is.ignore();

            // Read date
            is >> date;
        }

        // Check if the date is valid
        if (!date) {
            is.setstate(std::ios::failbit);
        }

        if (is) {
            // Allocate memory for m_title and copy the truncated title
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);

            // Copy the shelfId and date
            strcpy(m_shelfId, shelfId);
            m_date = date;

            // Set membership and reference number
            Publication::set(memship);
            setRef(libref);
        }

        return is;
    }


    Publication::operator bool() const {
        return (m_title != nullptr && m_shelfId[0] != '\0');
    }
}
