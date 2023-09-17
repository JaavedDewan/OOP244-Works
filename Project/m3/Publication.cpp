/*
*****************************************************************************
Project - Milestone 3
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/28/23
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
    void Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << m_shelfId << " | ";
            os.width(SDDS_TITLE_WIDTH);
            os.setf(std::ios::left);
            os.fill('.');
            os << m_title;
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
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
            if (m_membership == 0) {
                os << "N/A";
            }
            else {
                os << m_membership;
            }
            os << "\t" << m_date;
        }
    }
    void Publication::read(std::istream& istr) {
        // Clear all the attributes and set default values
        delete[] m_title;
        m_title = nullptr;
        m_membership = 0;
        m_libRef = -1;

        int length;

        // Check if it's a console IO object
        if (conIO(istr)) {
            std::cout << "Shelf No: ";
            // Read the shelf number up to its limit (SDDS_SHELF_ID_LEN)
            istr.get(m_shelfId, static_cast<std::streamsize>(SDDS_SHELF_ID_LEN) + 2);
            length = strlen(m_shelfId);
            // Check if the number is exactly the length it's supposed to be
            if (length != SDDS_SHELF_ID_LEN) {
                std::cout << "Title: Date: ";
                istr.setstate(std::ios::failbit);
                return;
            }

            // Read the title
            std::cout << "Title: ";
            char titleInput[SDDS_TITLE_WIDTH + 1];
            istr.ignore();
            istr.getline(titleInput, static_cast<std::streamsize>(SDDS_TITLE_WIDTH) + 1);
            m_title = new char[strlen(titleInput) + 1];
            strcpy(m_title, titleInput);

            // Read the date
            std::cout << "Date: ";
            istr >> m_date;
            if (m_date.errCode() != 0) {
                istr.setstate(std::ios::failbit);
            }
        }
        else {
            // Read the libRef number
            istr >> m_libRef;
            istr.ignore();

            // Read the shelf number
            istr.getline(m_shelfId, sizeof(m_shelfId), '\t');

            // Read the title
            char titleInput[SDDS_TITLE_WIDTH + 1];
            istr.getline(titleInput, static_cast<std::streamsize>(SDDS_TITLE_WIDTH) + 1, '\t');
            m_title = new char[strlen(titleInput) + 1];
            strcpy(m_title, titleInput);

            // Read the membership
            istr >> m_membership;
            istr.ignore();

            // Read the date
            istr >> m_date;
            if (m_date.errCode() != 0) {
                istr.setstate(std::ios::failbit);
                return;
            }
        }
    }

    Publication::operator bool() const {
        return (m_title != nullptr && m_shelfId[0] != '\0');
    }
}
