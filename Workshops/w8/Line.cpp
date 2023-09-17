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
#include <iostream>
#include "Line.h"
using namespace std;
namespace sdds {
	//Reads length from user input and ignores everything after the comma from the base function
	void Line::getSpecs(istream& is) {
		LblShape::getSpecs(is); //Calls base function
		is >> m_length;
		is.ignore(100, '\n');//ignores everything after; 100 characters as a placeholer
	}
	//Prints the line
	void Line::draw(ostream& os) const {
		if (m_length > 0 && LblShape::label() != nullptr) {
			os << LblShape::label() << endl; //Prints label
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	}
}