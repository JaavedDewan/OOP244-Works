/*
*****************************************************************************
Workshop - #8 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/19/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <cstring>
#include "Rectangle.h"
namespace sdds {
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_width(width), m_height(height){
		if (m_height < 3 || m_width < (static_cast<int>(strlen(label)) + 2)) {
			// Set the Rectangle to an empty state if conditions are not met
			m_width = 0;
			m_height = 0;
		}
	}
    //Calls base function and reads input for width and height
	void Rectangle::getSpecs(istream& is){
		LblShape::getSpecs(is);//Call base function
        is >> m_width;
		is.ignore(1, ',');//ignores an extra comma
        is >> m_height;
        is.ignore(100, '\n');//ignores everything after; 100 characters as a placeholer
	}
	void Rectangle::draw(ostream& os)const {
        if (m_width <= 0 || m_height <= 0 || label() == nullptr) {
            // Do nothing if Rectangle is in an empty state
            return;
        }

        // First line
        os << '+';
        for (int i = 0; i < m_width - 2; ++i) {
            os << '-';
        }
        os << '+' << endl;

        // Second line
        os << '|' << label();
        for (int i = static_cast<int>(strlen(label())); i < m_width - 2; ++i) {
            os << ' ';
        }
        os << '|' << endl;

        // Next (m_height - 3) lines
        for (int i = 0; i < m_height - 3; ++i) {
            os << '|';
            for (int j = 0; j < m_width - 2; ++j) {
                os << ' ';
            }
            os << '|' << endl;
        }

        // Last line
        os << '+';
        for (int i = 0; i < m_width - 2; ++i) {
            os << '-';
        }
        os << '+';
    }
}