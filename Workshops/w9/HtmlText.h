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
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include "Text.h"

namespace sdds {
    class HtmlText : public Text {
        char* m_title;

    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& other); // Copy Constructor
        HtmlText& operator=(const HtmlText& other); // Copy Assignment Operator
        ~HtmlText(); // Destructor

        virtual void write(std::ostream& os) const override;
    };
}

#endif // !SDDS_HTMLTEXT_H__
