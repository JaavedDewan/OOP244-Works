/*
*****************************************************************************
Project - Milestone 5
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 08/06/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
namespace sdds {
	class Book : public Publication {
		char* m_author;
	public:
		Book() : m_author(nullptr) {}
		Book(const Book&);
		Book& operator=(const Book&);
		~Book();
		std::ostream& write(std::ostream& os) const override;
		std::istream& read(std::istream& is) override;
		operator bool() const override;
		void set(int member_id) override;
		char type() const override;
	};
}
#endif // !SDDS_BOOK_H
