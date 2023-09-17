/*
*****************************************************************************
Project - Milestone 2
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/19/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include "LibApp.h"
using namespace std;
namespace sdds {
   
    bool LibApp::confirm(const char* message)
    {
        // Create a new instance of the Menu class called "newMenu"
        Menu newMenu(message);

        // Add the option "Yes" to the newMenu
        newMenu << "Yes";

        // Display the menu and get the user's choice, storing it in "menuRun"
        int menuRun = newMenu.run();

        // Initialize a boolean variable "ok" to false
        bool ok = false;

        // If the user's choice (menuRun) is non-zero (true), set "ok" to true
        if (menuRun) {
            ok = true;
        }
        // Return the value of "ok" (true if the user selected "Yes", false otherwise)
        return ok;
    }

    void LibApp::load() {
        cout << "Loading Data\n";
    }  // prints: "Loading Data"<NEWLINE>
    void LibApp::save() {
        cout << "Saving Data\n";
    }   // prints: "Saving Data"<NEWLINE>
    void LibApp::search() {
        cout << "Searching for publication\n"; 
    }   // prints: "Searching for publication"<NEWLINE>

    void LibApp::returnPub()
    {
        // Call the search() method to find the publication
        search();

        // Print messages for returning the publication
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;

        // Set the m_changed flag to true since a publication was returned
        m_changed = true;
    }

    void LibApp::newPublication()
    {
        // Print a message indicating the intention to add a new publication
        cout << "Adding new publication to library" << endl;

        // Ask for user confirmation before proceeding to add the publication
        if (confirm("Add this publication to library?"))
        {
            // If the user confirms, set the m_changed flag to true
            m_changed = true;

            // Print a message to confirm that the publication was added
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication()
    {
        // Print a message indicating the intention to remove a publication
        cout << "Removing publication from library" << endl;

        // Call the search() method to find the publication
        search();

        // Ask for user confirmation before proceeding to remove the publication
        if (confirm("Remove this publication from the library?"))
        {
            // If the user confirms, set the m_changed flag to true
            m_changed = true;

            // Print a message to confirm that the publication was removed
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub()
    {
        // Call the search() method to find the publication
        search();

        // Ask for user confirmation before proceeding to check out the publication
        if (confirm("Check out publication?"))
        {
            // If the user confirms, set the m_changed flag to true
            m_changed = true;

            // Print a message to confirm that the publication was checked out
            cout << "Publication checked out" << endl;
        }
    }

    LibApp::LibApp()
    {
        // Populate the main menu with menu items
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";

        // Populate the exit menu with menu items
        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";

        // Load the data when the LibApp object is constructed
        load();
    }





    void LibApp::run()
    {
        bool exitLoop = false;

        // Main application loop
        while (!exitLoop)
        {
            // Display the main menu and get user's choice
            int option = m_mainMenu.run();

            // Handle user's choice
            if (option == 1)
            {
                // Option 1: Add a new publication
                newPublication();
            }
            else if (option == 2)
            {
                // Option 2: Remove a publication
                removePublication();
            }
            else if (option == 3)
            {
                // Option 3: Check out a publication
                checkOutPub();
            }
            else if (option == 4)
            {
                // Option 4: Return a publication
                returnPub();
            }
            else if (option == 0)
            {
                // Option 0: Exit

                if (m_changed)
                {
                    // If there are changes, show the exit menu

                    // Display the exit menu and get user's choice
                    int opn = m_exitMenu.run();

                    if (opn == 1)
                    {
                        // Option 1 in the exit menu: Save changes and exit
                        save();
                        exitLoop = true; // Set the flag to exit the main loop
                    }
                    else if (opn == 2)
                    {
                        // Option 2 in the exit menu: Cancel and go back to the main menu
                        // Do nothing, continue with the main loop
                    }
                    else if (opn == 0)
                    {
                        // Option 0 in the exit menu: Confirm discarding changes

                        if (confirm("This will discard all the changes are you sure?"))
                            exitLoop = true; // Set the flag to exit the main loop
                    }
                }
                else
                {
                    // No changes made, exit the main loop
                    exitLoop = true;
                }
            }

            cout << endl;
        }

        // Print final messages
        cout << "-------------------------------------------\n";
        cout << "Thanks for using Seneca Library Application\n";
    }


}
