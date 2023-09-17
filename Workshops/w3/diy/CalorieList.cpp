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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
    bool invalidList = false; //validity check
    void CalorieList::setEmpty() {

        // Deallocate the dynamically allocated foods array and set it to nullptr
        delete[] m_food;
        m_food = nullptr;

        // Reset the number of foods and foods added to zero
        m_noOfFood = 0;
        m_foodAdded = 0;
    }

    bool CalorieList::isValid() const {
        // Initialize the flag as true
        bool ok = true;

        // Check if the title is an empty string or the foods array is nullptr
        if (m_food == nullptr || m_noOfFood != m_foodAdded) {
            ok = false;
            invalidList = true;
        }
        // Return the overall validity flag
        return ok;
    }
    int CalorieList::totalCalories() const {
        int total = 0;

        // Iterate through each added food and accumulate the calorie amount
        for (int i = 0; i < m_foodAdded; i++) {
            total += m_food[i].calorie();
        }

        return total;
    }
    void CalorieList::Title() const {
        // Display the top separator line
        cout << "+----------------------------------------------------+" << endl;
        if (isValid() && invalidList == false) {
            cout.width(46);
            cout << left << "|  Daily Calorie Consumption                         |"; // Display the title aligned to the left within a width of 36 characters
            cout << endl;
        }
        else {
            invalidList = true;
            cout << "| Invalid Calorie Consumption list                   |"; // Display the invalid calorie message
            cout << endl;
        }

        // Display the separator line and the header for food details
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const {
        cout << "+--------------------------------+------+------------+" << endl;

        if (m_noOfFood == m_foodAdded && validList()) {
            cout << "| "; // Start of the line
            cout.width(28);
            cout.fill(' ');
            cout << right << "Total Calories for today:"; // Display "Total calorie:" aligned to the right within a width of 25 characters
            cout.width(9);
            cout.fill(' ');
            cout << right << fixed << totalCalories() << " |"; // Display the total calorie value with 2 decimal places aligned to the right within a width of 11 characters
            cout << "            |" << endl;

        }
        else {
            cout << "|    Invalid Calorie Consumption list                |"; // Display the invalid calorie message
            cout << endl;
        }

        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::display() const {
        Title(); // Display the calorie title and food header

        for (int i = 0; i < m_noOfFood; i++) {
            m_food[i].display(); // Display each food in the calorie
        }

        footer(); // Display the calorie footer with total calorie
    }
    void CalorieList::init(int size) {
        m_noOfFood = size;                // Set the number of food foods in the list
        m_foodAdded = 0;                  // Initialize the count of food foods added
        m_food = new Food[size];          // Dynamically allocate an array of Food objects
                   // Set the title and food foods to empty values
    }

    bool CalorieList::add(const char* food_name, int calories, int when) {
        bool ok = false;
        if (m_foodAdded < m_noOfFood) {
            m_food[m_foodAdded].set(food_name, calories, when); // Set the food details at the current index in the m_foods array
            m_foodAdded++; // Increment the count of foods added
            ok = true;
        }
        return ok;
    }
    void CalorieList::deallocate() { //deallocation
        delete[] m_food;
        m_food = nullptr;
        invalidList = false;
    }
    bool CalorieList::validList() const{ //checks if the list is valid.
        bool ok = true;
        if (invalidList == true) {
            ok = false;
        }
        return ok;
    }
}