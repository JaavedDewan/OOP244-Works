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
#include "Shape.h"
using namespace std;
namespace sdds {

	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}
	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}
}