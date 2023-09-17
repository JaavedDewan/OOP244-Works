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
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds {

    MotorVehicle::MotorVehicle(const char* licensePlate, int year) {
        strnCpy(m_licenseplate, licensePlate, 8);   // Copy licensePlate to m_licenseplate (up to 8 characters)
        m_licenseplate[8] = '\0';   // Null-terminate the m_licenseplate array
        strnCpy(m_address, "Factory", 63);   // Set m_address to "Factory" (up to 63 characters)
        m_address[63] = '\0';   // Null-terminate the m_address array
        m_year = year;   // Set m_year to the provided year
    }


    void MotorVehicle::moveTo(const char* address) {
        int licenseLength = strLen(m_licenseplate);
        if (strCmp(m_address, address) != 0) {
            cout << "|" << setw(8);
            if (licenseLength < 8) {
                cout << right << m_licenseplate << "|"; // Encase license plate within || and fill empty spots with |
            }
            else {
                cout << right << m_licenseplate;   // If license plate is 8 characters or longer, use right alignment
            }
            cout << " |" << setw(20) << right << m_address << " ---> "
                << setw(20) << left << address << "|" << endl;
            strnCpy(m_address, address, 63);
            m_address[63] = '\0';
        }
    }



    std::ostream& MotorVehicle::write(std::ostream& os) const {
        os << "| " << setw(4) << m_year << " | ";
        if (strLen(m_licenseplate) < 8) {
            os << left << m_licenseplate;   // If license plate is less than 8 characters, use left alignment
        }
        else {
            os << setw(8) << right << m_licenseplate;   // If license plate is 8 characters or longer, use right alignment
        }
        os << " | " << m_address;
        return os;
    }



    std::istream& MotorVehicle::read(std::istream& in) {
        cout << "Built year: ";
        in >> m_year;   // Read the year from input
        cout << "License plate: ";
        in.ignore();
        in.getline(m_licenseplate, 9);   // Read the license plate from input (up to 8 characters)
        cout << "Current location: ";
        in.getline(m_address, 64);   // Read the address from input (up to 63 characters)
        return in;
    }


    std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
        return vehicle.write(os);   // Call the write function of the MotorVehicle object
    }


std::istream& operator>>(std::istream& is, MotorVehicle& vehicle) {
    return vehicle.read(is);   // Call the read function of the MotorVehicle object
}


}
