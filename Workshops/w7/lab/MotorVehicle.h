/*
*****************************************************************************
Workshop - #7 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/12/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_MOTORVEHICLE_H_
#define SDDS_MOTORVEHICLE_H_
#include <iostream>
namespace sdds {
	class MotorVehicle {
		char m_licenseplate[9];
		char m_address[64];
		int m_year;
	public:
		MotorVehicle(const char* license, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);

	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& is, MotorVehicle& vehicle);
}
#endif