/*
*****************************************************************************
Workshop - #3 (Part-2)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/04/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds {
	class  CalorieList {
		Food* m_food;
		int m_noOfFood;
		int m_foodAdded;
		bool isValid()const; //validity if the item is valid
		bool validList()const; //validity if the entire list is valid
		int totalCalories()const; //calculates the total calories
		void footer()const; //displays results of total calories
		void Title() const; //displays title
		void setEmpty(); //empty
	public:
		// sets the CalorieList to accept the "size" number of Food Items. 
// This function is called to prepare the CalorieList for accepting food items
		void init(int size);
		// Adds Food Items using their Name, Calorie count and time of consumption up to 
		// the number set in the init() function, returns true if successful.
		bool add(const char* item_name, int calories, int when);
		// Displays the report with food information and the total calorie consumed in the day
		// as shown in the report sample
		void display()const;
		// Releases all the memory used. After this function init() can be called for another
		// report;
		void deallocate();
	};

}

#endif // !SDDS_SUBJECT_H