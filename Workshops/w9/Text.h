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
#include <iostream>
#include "cstring.h" 
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

namespace sdds {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength() const;

    protected:
        const char& operator[](int index) const;

    public:
        Text(const char* filename = nullptr);
        Text(const Text& other); // Copy Constructor
        Text& operator=(const Text& other); // Copy Assignment Operator
        ~Text(); // Destructor

        void read();
        virtual void write(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const sdds::Text& text);

}
#endif // !SDDS_TEXT_H__
