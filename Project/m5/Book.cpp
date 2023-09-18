/*
*****************************************************************************
Project - Milestone 4
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 08/02/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include "Lib.h"
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds {
	// Copy constructor: creates a deep copy of the book
	Book::Book(const Book& other) : Publication(other) {
		if (other.m_author) {
			m_author = new char[strlen(other.m_author) + 1];
			strcpy(m_author, other.m_author);
		}
		else {
			m_author = nullptr;
		}
	}

	// Copy assignment operator: assigns values from one book to another
	Book& Book::operator=(const Book& other) {
		if (this != &other) {
			// First, copy the base class members
			Publication::operator=(other);

			// Deallocate the current m_author (if any)
			delete[] m_author;

			// Perform deep copy of the m_author from other
			if (other.m_author) {
				m_author = new char[strlen(other.m_author) + 1];
				strcpy(m_author, other.m_author);
			}
			else {
				m_author = nullptr;
			}
		}
		return *this;
	}
	
	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	char Book::type() const{
		return 'B'; // 'B' to identify this object as a "Book object"
	}
	ostream& Book::write(std::ostream& os) const {
		// Truncate the author's name to SDDS_AUTHOR_WIDTH characters
		char reducedAuthor[SDDS_AUTHOR_WIDTH + 1];
		strncpy(reducedAuthor, m_author, SDDS_AUTHOR_WIDTH);
		reducedAuthor[SDDS_AUTHOR_WIDTH] = '\0'; // Ensure null-termination
		//char temp[SDDS_AUTHOR_WIDTH + 1] = {};
		Publication::write(os);
		if (Publication::conIO(os)) {
			os << " " << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ')
				<< reducedAuthor; // Display author's name with fixed width
			os << " |";
		}
		else {
			os << '\t';

			//if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
			//	for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
			//		temp[i] = m_author[i];
			//	}
			//	temp[SDDS_AUTHOR_WIDTH] = '\0';
			//	os << temp;
			//}
			//else {
				os << m_author;
			//}
		}
		return os;
	}
	std::istream& Book::read(std::istream& is) {
		// Call the base class's read function to read common attributes
		Publication::read(is);

		// Delete existing memory for m_author if not nullptr
		if (m_author != nullptr) {
			delete[] m_author;
			m_author = nullptr;
		}

		char author[256]{};

		// Check if it's a console IO object
		if (Publication::conIO(is)) {
			is.ignore(1); // Ignore the delimiter
			cout << "Author: ";
			is.get(author, 256); // Read the author's name
		}
		else {
			is.ignore(1); // Ignore the delimiter
			is.get(author, 256); // Read the author's name
		}

		// If the read operation was successful
		if (is) {
			// Truncate the author's name to SDDS_AUTHOR_WIDTH characters
			//char reducedAuthor[SDDS_AUTHOR_WIDTH + 1];
			//strncpy(reducedAuthor, author, SDDS_AUTHOR_WIDTH);
			//reducedAuthor[SDDS_AUTHOR_WIDTH] = '\0'; // Ensure null-termination

			// Allocate memory for m_author and copy the truncated author's name
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}

		return is;
	}


	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}
	Book::operator bool() const {
		// Check if the author's name exists and is not empty
		bool hasAuthor = (m_author && m_author[0] != '\0');

		// Check if the base class's operator bool() returns true
		bool publicationValid = Publication::operator bool();

		// Return true if both conditions are met
		return (hasAuthor && publicationValid);
	}
}