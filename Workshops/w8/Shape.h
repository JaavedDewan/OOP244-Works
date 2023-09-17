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
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual void draw(ostream& os) const = 0;
		virtual void getSpecs(istream& is) = 0;
		virtual ~Shape(){}
	};
	ostream& operator<<(ostream& os, const Shape& shape);
	istream& operator>>(istream& is, Shape& shape);
}
#endif