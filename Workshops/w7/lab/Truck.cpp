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
#include "Truck.h"
using namespace std;
namespace sdds {

    Truck::Truck(const char* licensePlate, int year, double capacity, const char* address)
        : MotorVehicle(licensePlate, year), m_capacity(capacity), m_cargo(0.0) {
        moveTo(address);   // Call the moveTo function to move the truck to the specified address
    }


    bool Truck::addCargo(double cargo) {
        bool ok = false;   // Initialize a boolean variable to track if cargo addition is successful
        if (m_cargo + cargo <= m_capacity) {   // Check if the current cargo load plus the added cargo is less than or equal to the capacity
            m_cargo += cargo;   // If valid, add the cargo to the current cargo load
            ok = true;   // Set ok to true to indicate successful cargo addition
        }
        else if (cargo < m_capacity && m_cargo != m_capacity) {
            m_cargo = m_capacity;
            ok = true;
        }
        return ok;   // Return the value of ok (true if cargo addition was successful, false otherwise)
    }


    bool Truck::unloadCargo() {
        bool ok = false;   // Initialize a boolean variable to track if cargo unloading is successful
        if (m_cargo > 0.0) {   // Check if there is any cargo to unload
            m_cargo = 0.0;   // Set the cargo load to 0 to unload the cargo
            ok = true;   // Set ok to true to indicate successful cargo unloading
        }
        return ok;   // Return the value of ok (true if cargo unloading was successful, false otherwise)
    }


    std::ostream& Truck::write(std::ostream& os) const {
        MotorVehicle::write(os);   // Call the write function of the base class to write common vehicle information
        os << " | " << m_cargo << "/" << m_capacity;   // Write truck-specific cargo information
        return os;   // Return the output stream
    }


    std::istream& Truck::read(std::istream& in) {
        MotorVehicle::read(in);   // Call the read function of the base class to read common vehicle information
        cout << "Capacity: ";
        in >> m_capacity;   // Read the capacity of the truck from the input stream
        cout << "Cargo: ";
        in >> m_cargo;   // Read the current cargo load of the truck from the input stream
        return in;   // Return the input stream
    }


    std::ostream& operator<<(std::ostream& os, const Truck& truck) {
        return truck.write(os);   // Call the write function of the Truck class to write the truck information
    }


    std::istream& operator>>(std::istream& is, Truck& truck) {
        return truck.read(is);   // Call the read function of the Truck class to read the truck information from the input stream
    }


} // namespace sdds
