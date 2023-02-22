/*
*****************************************************************************
<assessment name example: Workshop - #4 (Part-2)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 02/15/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#include "NameTag.h"

using namespace std;
namespace sdds {
    // Set the name of the NameTag
    void NameTag::setName(const char* Cstr) {
        if (Cstr == nullptr) {
            m_name = nullptr;
        }
        else {
            delete[] m_name;
            m_name = new char[41];
            strncpy(m_name, Cstr, 40);
            m_name[40] = '\0';// ensure string is null terminated
        }
    }
    // Default constructor
    NameTag::NameTag() : m_name(nullptr), m_ext(0) {}
    // Constructor that sets the name
    NameTag::NameTag(const char* name) : NameTag() {
        setName(name);
    }
    // Constructor that sets the name and extension
    NameTag::NameTag(const char* name, int ext) : NameTag(name) {
        if (ext < 10000 || ext > 99999) {
            m_ext = -1;// invalid extension
        }
        else {
            m_ext = ext;
        }
    }
    // Copy constructor
    NameTag::NameTag(const NameTag& source) : NameTag(source.m_name, source.m_ext) {}
    // Assignment operator
    NameTag& NameTag::operator=(const NameTag& source) {
        if (this != &source) {
            setName(source.m_name);
            if (source.m_ext < 10000 || source.m_ext > 99999) {
                m_ext = -1;// invalid extension
            }
            else {
                m_ext = source.m_ext;
            }
            if (source.m_ext == 0) {
                m_ext = 0;// set to zero if source has no extension
            }
        }
        return *this;
    }


    NameTag::~NameTag() {
        delete[] m_name;
        m_name = nullptr;
    }

    // Read in a NameTag from the console
    NameTag& NameTag::read() {
        // Read in the name
        char name[41];
        std::cout << "Please enter the name: ";
        std::cin.getline(name, 41, '\n');
        // Handle input errors
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any remaining input
        }
        setName(name); // Set the name of the NameTag

        // Ask if the user wants to enter an extension
        char answer;
        std::cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        do {
            std::cin >> answer;
            // Handle invalid input
            if (answer == 'Y' || answer == 'y') {
                // Read in the extension
                int ext;
                std::cout << "Please enter a 5 digit phone extension: ";
                do {
                    std::cin >> ext;
                    // Handle invalid input
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Bad integer value, try again: ";
                    }
                    else if (ext < 10000 || ext > 99999) {
                        std::cout << "Invalid value [10000<=value<=99999]: ";
                    }
                    else {
                        m_ext = ext;
                        break;
                    }
                } while (true);
            }
            else if (answer == 'N' || answer == 'n') {
                m_ext = 0;
            }
            else {
                std::cout << "Only (Y) or (N) are acceptable, try again: ";
            }
            std::cin.ignore(1000, '\n'); // Ignore any remaining input
        } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

        return *this; // Return a reference to the current object
    }



    void NameTag::print() {
        // Check if the NameTag is empty or invalid
        if (m_name == nullptr || m_ext == -1) {
            cout << "EMPTY NAMETAG!" << endl;
            return;
        }

        int nameLen = strlen(m_name);
        if (nameLen > 40) {
            nameLen = 40;
        }

        int ext = m_ext;
        // Check if the extension is not provided
        if (ext == 0) {
            // Print a NAMETAG without an extension
            cout << "+------------------------------------------+" << endl;
            cout << "|                                          |" << endl;
            cout << "| " << setw(41) << left << m_name << "|" << endl;
            cout << "|                                          |" << endl;
            cout << "| Extension: N/A                           |" << endl;
            cout << "|                                          |" << endl;
            cout << "+------------------------------------------+" << endl;
            return;
        }

        // Print a NAMETAG with an extension
        cout << "+----------------------+" << endl;
        cout << "|                      |" << endl;
        cout << "| " << setw(21) << left << m_name << "|" << endl;
        cout << "|                      |" << endl;
        cout << "| Extension: " << setw(9) << left << ext << " |" << endl;
        cout << "|                      |" << endl;
        cout << "+----------------------+" << endl;
        return;
    }


    }