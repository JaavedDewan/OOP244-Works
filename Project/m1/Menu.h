/*
*****************************************************************************
Project - Milestone 1
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/10/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu; // Forward declaration of Menu class

	class MenuItem {
	private:
		char* m_content; // Dynamically allocated C-string for the content

		MenuItem(const char* content); // Private constructor
		~MenuItem(); // Private destructor
		MenuItem(const MenuItem& other) = delete; // Deleted copy constructor
		MenuItem& operator=(const MenuItem& other) = delete; // Deleted copy assignment operator
		operator bool() const; // Bool type conversion operator
		friend class Menu; // Make Menu class a friend
		void display(std::ostream& os) const; // Display the content of the MenuItem
	};

	class Menu {
	private:
		MenuItem* m_title; // Title of the Menu
		MenuItem* m_menuItems[MAX_MENU_ITEMS]; // Array of MenuItem pointers
		int m_numMenuItems; // Number of MenuItem pointers

	public:
		Menu(); // Default constructor
		Menu(const char* title); // Constructor with title
		~Menu(); // Destructor
		Menu(const Menu& other) = delete; // Deleted copy constructor
		Menu& operator=(const Menu& other) = delete; // Deleted copy assignment operator

		void displayTitle(std::ostream& os) const; // Display the title of the Menu
		void displayMenu(std::ostream& os) const; // Display the entire Menu
		unsigned int run(); // Run the Menu and get user selection
		unsigned int operator~(); // Operator~ overload to run the Menu
		Menu& operator<<(const char* menuItemContent); // Operator<< overload to add a MenuItem to the Menu
		operator int() const; // Operator int() overload to return the number of MenuItems
		operator unsigned int() const; // Operator unsigned int() overload to return the number of MenuItems
		operator bool() const; // Operator bool() overload to check if Menu has MenuItems
		friend std::ostream& operator<<(std::ostream& os, const Menu& menu); // Operator<< overload to print the Menu title
		const char* operator[](int index) const; // Operator[] overload to access MenuItem content by index
	};

}

#endif
