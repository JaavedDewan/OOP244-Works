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

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
	struct Area {
		char* m_postalCode;
		int m_population;
	};
	void sort(); //Sorts population from lowest to highest.
	bool load(const char* filename); //Loads information from filename.
	bool load(Area& area); //Loads Area Struct to copy.
	void display(const Area& area); //Display Area struct.
	void display(); //General display
	void deallocateMemory(); //Memory Deallocation

}
#endif // SDDS_POPULATION_H_