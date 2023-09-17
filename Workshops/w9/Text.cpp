/*
*****************************************************************************
Workshop - #9 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/27/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <fstream>
#include "Text.h"

namespace sdds {
    // Constructor
    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename != nullptr) {
            int len = strLen(filename) + 1;
            m_filename = new char[len];
            strCpy(m_filename, filename);
            read(); // Read the content from the file
        }
    }

    // Copy Constructor
    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        if (other.m_filename != nullptr) {
            int len = strLen(other.m_filename) + 1;
            m_filename = new char[len];
            strCpy(m_filename, other.m_filename);
            read(); // Read the content from the file
        }
    }

    // Copy Assignment Operator
    Text& Text::operator=(const Text& other) {
        if (this != &other) { // Avoid self-assignment
            if (other.m_filename != nullptr) {
                int len = strLen(other.m_filename) + 1;
                delete[] m_filename;
                m_filename = new char[len];
                strCpy(m_filename, other.m_filename);
                read(); // Read the content from the file
            }
        }
        return *this;
    }

    // Destructor
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    // Index Operator Overload (Read-only access to content
    const char& Text::operator[](int index) const {
        static char empty = '\0';
        // Check if m_content is not nullptr and index is within valid bounds. Returns empty if not
        return (m_content != nullptr && index >= 0 && index < getFileLength()) ? m_content[index] : empty;
    }


    // Private function: Get the file length
    int Text::getFileLength() const {
        int len = 0;
        std::ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    // Read the content from the file
    void Text::read() {
        delete[] m_content;
        m_content = nullptr;
        int length = getFileLength();
        if (length == 0) {
            return;
        }

        m_content = new char[length + 1];
        std::ifstream fin(m_filename);
        fin.read(m_content, length);
        m_content[length] = '\0';
    }

    // Virtual function to write the content to ostream
    void Text::write(std::ostream& os) const {
        if (m_content != nullptr) {
            os << m_content;
        }
    }

    // Insertion operator overload
    std::ostream& operator<<(std::ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}
