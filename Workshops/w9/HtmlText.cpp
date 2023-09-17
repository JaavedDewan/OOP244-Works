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
#include "cstring.h"
#include "HtmlText.h"

namespace sdds {
    // Constructor
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr) {
        if (title != nullptr) {
            int len = strLen(title) + 1;
            m_title = new char[len];
            strCpy(m_title, title);
        }
    }

    // Copy Constructor
    HtmlText::HtmlText(const HtmlText& other) : Text(other), m_title(nullptr) {
        if (other.m_title != nullptr) {
            int len = strLen(other.m_title) + 1;
            m_title = new char[len];
            strCpy(m_title, other.m_title);
        }
    }

    // Copy Assignment Operator
    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) { // Avoid self-assignment
            Text::operator=(other); // Call the base class assignment operator

            delete[] m_title;
            m_title = nullptr;

            if (other.m_title != nullptr) {
                int len = strLen(other.m_title) + 1;
                m_title = new char[len];
                strCpy(m_title, other.m_title);
            }
        }
        return *this;
    }

    // Destructor
    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    // Override the write function to convert Text to HTML
    void HtmlText::write(std::ostream& os) const {
        os << "<html><head><title>";
        if (m_title != nullptr) {
            os << m_title;
        }
        else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";

        if (m_title != nullptr) {
            os << "<h1>" << m_title << "</h1>\n";
        }

        bool multipleSpaces = false;
        // Loop through the characters in the content
        for (int i = 0; (*this)[i] != '\0'; i++) {
            const char& ch = (*this)[i];
            // Check and replace special characters
            if (ch == ' ') {
                if (multipleSpaces) {
                    os << "&nbsp;";
                }
                else {
                    multipleSpaces = true;
                    os << ' ';
                }
            }
            else if (ch == '<') {
                os << "&lt;";
                multipleSpaces = false;
            }
            else if (ch == '>') {
                os << "&gt;";
                multipleSpaces = false;
            }
            else if (ch == '\n') {
                os << "<br />\n";
                multipleSpaces = false;
            }
            else {
                multipleSpaces = false;
                os << ch;
            }
        }

        os << "</body>\n</html>";
    }
}
