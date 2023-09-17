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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"

namespace sdds {
	//Returns label an unmodifiable character
	const char* LblShape::label() const {
		return m_label;
	}
	//Creates a label dynamically
	LblShape::LblShape(const char* label): m_label(nullptr) {
		if (label) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	//Destructor
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;

	}
	//Creates a label from user input upto a comma
	void LblShape::getSpecs(istream& is) {
		char buffer[100];
		is.getline(buffer, 100, ',');
		if (m_label != nullptr) {
			delete[] m_label;
		}
		m_label = new char[strlen(buffer) + 1];
		strcpy(m_label, buffer);
	}
}