/*
*****************************************************************************
Workshop - #4 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/07/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	const double PI = 3.14159265;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty() const{
		//checks if the volume is above 0.00001
		return m_contentVolume < 0.00001; 
	}

	bool Canister::hasSameContent(const Canister& C)const {
		bool ok = false;
		//Makes sure the names are the same and are not null.
		if (m_contentName != nullptr && C.m_contentName != nullptr) { 
			//Cstring compare.
			ok = strCmp(m_contentName, C.m_contentName) == 0; 
		}
		return ok;
	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable == true) {
			delete[] m_contentName; // Delete the current content name

			// Allocate memory for the new content name (+1 for null terminator)
			m_contentName = new char[strLen(Cstr) + 1];

			// Copy the new content name into the allocated memory
			strCpy(m_contentName, Cstr);
		}
	}

	//default constructor
	Canister::Canister() {
		setToDefault();
	}

	//constructor with one argument of name
	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	//constructor of all three arguments.
	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
			m_usable = true;
		}
		else {
			m_usable = false;
		}
	}

	//destructor
	Canister::~Canister() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	//clears can to to empty.
	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	//calculates the capacity of the can.
	double Canister::capacity()const {
		double capacity = 0;
		capacity = (PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2));
		return capacity;
	}

	//returns the volume from private to public.
	double Canister::volume()const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		// Check if the name is not null.
		if (contentName == nullptr) {
			m_usable = false;
		}
		// Check if the can is empty.
		else if (isEmpty()) {
			setName(contentName);
			m_usable = true;
		}
		// Check if the contents match the name.
		else if (!hasSameContent(contentName)){
			m_usable = false;
		}
		// Return the reference to the current canister.
		return *this;
	}


	Canister& Canister::pour(Canister& C) {
		// Set the content name of the current canister to the content name of the argument canister
		setContent(C.m_contentName);

		if (C.volume() > capacity() - volume()) {
			// If the volume of the argument canister exceeds the remaining capacity in the current canister
			// Reduce the content volume of the argument canister by the excess amount
			C.m_contentVolume -= capacity() - volume();
			// Set the content volume of the current canister to its capacity
			m_contentVolume = capacity();
		}
		else {
			// If the volume of the argument canister fits within the remaining capacity of the current canister
			// Pour the entire content volume of the argument canister into the current canister
			pour(C.m_contentVolume);
			// Set the content volume of the argument canister to 0.0
			C.m_contentVolume = 0.0;
		}
		// Return a reference to the current canister
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		// Check if the canister is usable, quantity is positive, and the sum of quantity and current volume is within capacity
		if (m_usable == true && quantity > 0 && quantity + volume() <= capacity()) {
			// Add the quantity to the content volume of the canister
			m_contentVolume += quantity;
		}
		else {
			// If any of the conditions are not met, render the canister unusable
			m_usable = false;
		}
		// Return a reference to the current canister
		return *this;
	}


	//display
	std::ostream& Canister::display() const {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << std::setw(7) << capacity() << "cc ("
			<< m_height << "x" << m_diameter << ") Canister";

		if (!m_usable) {
			std::cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			std::cout << " of " << std::setw(7) << volume() << "cc   "
				<< m_contentName;
		}

		return std::cout;
	}

}