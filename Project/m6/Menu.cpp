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
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
#include "Menu.h"
namespace sdds {


    MenuItem::MenuItem(const char* content) {
        if (content != nullptr) {
            // Dynamically allocate memory for the content
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            // If content is nullptr, set m_content to nullptr
            m_content = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        // Deallocate the dynamically allocated memory for m_content
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        // Return true if m_content is not nullptr, false otherwise
        return (m_content != nullptr);
    }


    void MenuItem::display(std::ostream& os) const {
        if (m_content != nullptr) {
            // Display the content of the MenuItem
            os << m_content;
        }
    }

    Menu::Menu() : m_title(nullptr), m_numMenuItems(0) {
        // Initialize the array of MenuItem pointers to nullptr
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::Menu(const char* title) : m_numMenuItems(0) {
        if (title != nullptr) {
            // Create a new MenuItem object for the title
            m_title = new MenuItem(title);
        }
        else {
            m_title = nullptr;
        }

        // Initialize the array of MenuItem pointers to nullptr
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_menuItems[i] = nullptr;
        }
    }

    Menu::~Menu() {
        // Deallocate memory for the title
        delete m_title;

        // Deallocate memory for each MenuItem in the array
        for (int i = 0; i < m_numMenuItems; i++) {
            delete m_menuItems[i];
        }
    }


    void Menu::displayTitle(std::ostream& os) const {
        if (m_title != nullptr) {
            // Display the content of the title MenuItem
            os << m_title->m_content << endl; //added end line
        }
    }

    void Menu::displayMenu(std::ostream& os) const {
        //if (m_title != nullptr) {
        //    // Display the title with a colon separator
        //    os << ":" << endl;
        //} 
        //removed due to updated code

        // Display each menu item with a numbered index
        for (int i = 0; i < m_numMenuItems; i++) {
            os << " " << (i + 1) << "- " << m_menuItems[i]->m_content << endl;
        }
        // Display the exit option
        os << " 0- Exit" << endl;
    }

    unsigned int Menu::run() {
        cout << *this;
        int selection;

        // Display the menu initially
        displayMenu(cout);
        cout << "> ";

        do {
            // Read the user's selection
            cin >> selection;

            if (cin.fail() || cin.peek() != '\n') {
                // Invalid input, clear the stream and ignore any remaining characters
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (selection < 0 || selection > m_numMenuItems) {
                // Invalid selection, prompt for a valid one
                cout << "Invalid Selection, try again: ";
            }

        } while (cin.fail() || cin.peek() != '\n' || selection < 0 || selection > m_numMenuItems);

        return selection;
    }






    unsigned int Menu::operator~()
    {
        // Invokes the run() function to run the menu and return the user's selection
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (static_cast<unsigned int>(m_numMenuItems) < MAX_MENU_ITEMS) {
            // Create a new MenuItem and add it to the menu
            m_menuItems[m_numMenuItems] = new MenuItem(menuItemContent);
            ++m_numMenuItems;
        }
        return *this;
    }

    Menu::operator int() const {
        // Convert the number of menu items to int and return it
        return m_numMenuItems;
    }

    Menu::operator unsigned int() const {
        // Convert the number of menu items to unsigned int and return it
        return static_cast<unsigned int>(m_numMenuItems);
    }

    Menu::operator bool() const {
        // Return true if there are one or more menu items, false otherwise
        return m_numMenuItems > 0;
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        // Display the title of the menu on the output stream
        menu.displayTitle(os);
        return os;
    }

    const char* Menu::operator[](int index) const {
        if (m_numMenuItems > 0) {
            // Normalize the index to wrap around the menu items
            int normalizedIndex = index % m_numMenuItems;
            // Return the content of the corresponding menu item
            return m_menuItems[normalizedIndex]->m_content;
        }
        return nullptr;
    }



}