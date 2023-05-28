/*
*****************************************************************************
Workshop - #2 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/28/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Population.h"
#include "File.h"
using namespace std;
namespace sdds {

	int totalPopulation;
	int noOfAreas;

	Area* area;

	void sort() {
		int i, j;
		Area temp;
		for (i = noOfAreas - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				// Compare the population of the current area with the population of the next area
				if (area[j].m_population > area[j + 1].m_population) {
					// Swap the positions of the current area and the next area
					temp = area[j];
					area[j] = area[j + 1];
					area[j + 1] = temp;
				}
			}
		}
	}


	bool load(Area& area) {
		bool ok = false;
		char postalCode[4]; // Temporary array to store postal code


		if (read(postalCode) && read(area.m_population)) {
			// If all reads are successful, proceed with the following steps
			int nameLength = strLen(postalCode); // Get the length of the postal code
			area.m_postalCode = new char[nameLength + 1];// Allocate memory for the area code (+1 for null termination)
			strCpy(area.m_postalCode, postalCode);// Copy the postal code into the newly allocated memory
			ok = true;// Set ok to true since the loading was successful

			// Add m_population to totalPopulation
			totalPopulation += area.m_population;
		}

		return ok;
	}

	bool load(const char* filename) {
		bool ok = false;

		if (openFile(filename)) {
			// If the file is successfully opened, proceed with the following steps

			noOfAreas = noOfRecords(); // Get the number of records (area) in the file

			area = new Area[noOfAreas]; // Allocate a dynamic array of Area objects

			for (int i = 0; i < noOfAreas; i++) {
				// Iterate over each record and load it into the corresponding Area object

				if (!load(area[i])) {
					// If loading fails for any record, display an error message, deallocate memory, and set ok to false
					cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
					delete[] area;
					area = nullptr;
					noOfAreas = 0;
					ok = false;
				}
				else {
					ok = true; // Set ok to true if all records are successfully loaded
				}
			}
		}

		closeFile(); // Close the file
		return ok; // Return the status of the loading process
	}

	void display(Area& area) {
		// Display the information of a single postal code and population

		cout << area.m_postalCode << ":  " << area.m_population << endl;
	}

	void display() {
		// Display the employee salary report

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sort(); // Sort the area array by area code number.

		for (int i = 0; i < noOfAreas; i++) {
			// Iterate over the sorted array and print each area's information

			const Area& emp = area[i]; // Reference to the current area

			cout << i + 1 << "- " << emp.m_postalCode << ":  " << emp.m_population << endl;
			// Display the area code and population
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPopulation << endl;
	}

	void deallocateMemory() {
		if (area != nullptr) {
			for (int i = 0; i < noOfAreas; i++) {
				// Deallocate the memory for the postal code of each area
				delete[] area[i].m_postalCode;
				area[i].m_postalCode = nullptr;
			}
			// Deallocate the memory for the area array
			delete[] area;
			area = nullptr;
		}
		// Reset the number of areas and total population to 0
		noOfAreas = 0;
		totalPopulation = 0;
	}

}