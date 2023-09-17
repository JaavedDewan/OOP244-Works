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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
	class Line :public LblShape {
	private:
		int m_length;
	public:
		Line():LblShape(), m_length(0){}
		Line(const char* label, int length) : LblShape(label), m_length(length) {}
		void getSpecs(istream& is) override;
		void draw(ostream& os)const override;
	};
}
#endif // !SDDS_LINE_H
