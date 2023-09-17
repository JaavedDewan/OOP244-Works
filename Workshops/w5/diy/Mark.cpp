/*
*****************************************************************************
Workshop - #5 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/18/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Mark.h"

namespace sdds {

	Mark::Mark() {
		m_mark = 0;     // Initialize mark to 0
		m_gpa = 0.0;    // Initialize GPA to 0.0
		m_grade = 'F';  // Initialize grade to 'F'
	}

	Mark::Mark(int mark) {
		if (mark >= 0 && mark <= 100) {
			m_mark = mark;  // Set mark value within valid range
			if (mark < 50) {
				m_gpa = 0.0;    // Set GPA to 0.0 for marks below 50
				m_grade = 'F';  // Set grade to 'F' for marks below 50
			}
			else if (mark < 60) {
				m_gpa = 1.0;    // Set GPA to 1.0 for marks between 50 and 59
				m_grade = 'D';  // Set grade to 'D' for marks between 50 and 59
			}
			else if (mark < 70) {
				m_gpa = 2.0;    // Set GPA to 2.0 for marks between 60 and 69
				m_grade = 'C';  // Set grade to 'C' for marks between 60 and 69
			}
			else if (mark < 80) {
				m_gpa = 3.0;    // Set GPA to 3.0 for marks between 70 and 79
				m_grade = 'B';  // Set grade to 'B' for marks between 70 and 79
			}
			else {
				m_gpa = 4.0;    // Set GPA to 4.0 for marks 80 and above
				m_grade = 'A';  // Set grade to 'A' for marks 80 and above
			}
		}
		else {
			m_mark = mark;      // Set mark value even if it's invalid
			m_gpa = 0.0;        // Set GPA to 0.0 for invalid marks
			m_grade = 'X';      // Set grade to 'X' for invalid marks
		}
	}

	Mark::operator int() const {
		int num;  // Variable to store the converted mark value
		if (m_mark >= 0 && m_mark <= 100) {
			num = m_mark;  // Convert mark to int if it's within valid range
		}
		else {
			num = 0;       // Convert mark to 0 if it's invalid
		}
		return num;       // Return the converted mark value
	}

	Mark::operator double() const {
		double gpa;       // Variable to store the converted GPA value
		if (m_mark >= 0 && m_mark < 50) {
			gpa = 0.0;    // Convert mark to 0.0 if it's below 50
		}
		else if (m_mark < 60) {
			gpa = 1.0;    // Convert mark to 1.0 if it's between 50 and 59
		}
		else if (m_mark < 70) {
			gpa = 2.0;    // Convert mark to 2.0 if it's between 60 and 69
		}
		else if (m_mark < 80) {
			gpa = 3.0;    // Convert mark to 3.0 if it's between 70 and 79
		}
		else if (m_mark <= 100) {
			gpa = 4.0;    // Convert mark to 4.0 if it's 80 or above
		}
		else {
			gpa = 0.0;    // Convert mark to 0.0 if it's invalid
		}
		return gpa;       // Return the converted GPA value
	}

	Mark::operator char() const {
		char letter;   // Variable to store the converted grade letter
		if (m_mark < 50) {
			letter = 'F';   // Convert mark to 'F' if it's below 50
		}
		else if (m_mark < 60) {
			letter = 'D';   // Convert mark to 'D' if it's between 50 and 59
		}
		else if (m_mark < 70) {
			letter = 'C';   // Convert mark to 'C' if it's between 60 and 69
		}
		else if (m_mark < 80) {
			letter = 'B';   // Convert mark to 'B' if it's between 70 and 79
		}
		else if (m_mark <= 100) {
			letter = 'A';   // Convert mark to 'A' if it's 80 or above
		}
		else {
			letter = 'X';   // Convert mark to 'X' if it's invalid
		}
		return letter;      // Return the converted grade letter
	}

	Mark& Mark::operator=(int mark) {
		m_mark = mark;      // Assign the provided mark value
		return *this;       // Return the modified object
	}

	Mark& Mark::operator+=(const Mark& other) {
		m_mark += other.m_mark;     // Add the mark value of the other object to the current object's mark value
		return *this;               // Return the modified object (by reference)
	}

	int operator+=(int& value, const Mark& mark) {
		if (mark.m_mark >= 0 && mark.m_mark <= 100) {
			value += mark.m_mark;   // Add the mark value to the provided value if it's within the valid range
		}
		return value;               // Return the modified value
	}



}