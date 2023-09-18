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
#include "LibApp.h"
#include <fstream>
#include "Book.h"
#include "PublicationSelector.h"
#include <cstring>
#include <iomanip>
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
        ifstream infile(m_filename);
        char type{};
        
        for (int i = 0; infile; i++) {
            infile >> type;
            infile.ignore();

            if (infile) {
                if (type == 'P') {
                    PPA[i] = new Publication;
                }
                else if (type == 'B') {
                    PPA[i] = new Book;
                }
                else {
                    cout << "Entry is empty!\n";
                }
                if (PPA[i] && i < SDDS_LIBRARY_CAPACITY) {
                    infile >> *PPA[i];
                    LLRN = PPA[i]->getRef();
                    NOLP++;
                }
            }
        }
    }  // prints: "Loading Data"<NEWLINE>
    void LibApp::save() {
        cout << "Saving Data\n";
        ofstream outfile(m_filename);
        
        for (int i = 0; i < NOLP; i++) {
            if (PPA[i]->getRef() != 0) {
                outfile << *PPA[i] << endl;
            }
        }
    }   // prints: "Saving Data"<NEWLINE>
    int LibApp::search(int option, char type) {
        /*cout << "Searching for publication\n";*/

        PublicationSelector ps("Select one of the following found matches:", 15);
        cout << "Publication Title: ";
        char title[256];
        cin.ignore();
        cin.getline(title, 256);

        if (option == 1) {
            for (int i = 0; i < NOLP; i++) {
                if (strstr(*PPA[i], title) && PPA[i]->getRef() != 0 && type == PPA[i]->type()) {
                    ps << PPA[i];
                }
            }
        }
        else if (option == 2) {
            for (int i = 0; i < NOLP; i++) {
                if (strstr(*PPA[i], title) && PPA[i]->onLoan() && PPA[i]->getRef() != 0 && type == PPA[i]->type())
                    ps << PPA[i];
            }
        }
        else if (option == 3) {
            for (int i = 0; i < NOLP; i++) {
                if (strstr(*PPA[i], title) && !PPA[i]->onLoan() && PPA[i]->getRef() != 0 && type == PPA[i]->type())
                    ps << PPA[i];

            }
        }
        int ref = 0;
        if (ps) {
            ps.sort();
            ref = ps.run();
            if (ref == 0) {
                cout << "Aborted!" << endl;
            }
        }
        else {
            cout << "No matches found!" << endl;
        }
        return ref;
    }   // prints: "Searching for publication"<NEWLINE>

    void LibApp::returnPub()
    {
       

        // Print messages for returning the publication
        cout << "Return publication to the library" << endl;
        int i = m_typeMenu.run();

        char type;

        if (i == 1) {
            type = 'B';
        }
        else {
            type = 'P';
        }

        // Call the search() method to find the publication based on loan
        int ref = search(2, type);

        if (ref != 0) {
            cout << *getPub(ref) << endl;
            if (confirm("Return Publication?")) {
                Date date = getPub(ref)->checkoutDate();
                Date today;
                int days = today - date;
                days -= 15;
                if (days > 0) {
                    cout << fixed;
                    cout << setprecision(2);
                    cout << "Please pay $" << float(days) * (0.5) << " penalty for being " << days;
                    cout << " days late!" << endl;

                }
                getPub(ref)->set(0);
                cout << "Publication returned" << endl;
                // Set the m_changed flag to true since a publication was returned
                m_changed = true;
            }
        }

    }

    void LibApp::newPublication() {
        if (NOLP >= SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!\n";
            return;
        }

        cout << "Adding new publication to the library\n";

        int i = m_typeMenu.run();
        bool publicationAdded = false; // Flag to track if the publication is added
        Publication* p = nullptr;

        if (i == 0) {
            std::cout << "Aborted!\n";
        }
        else if (i == 1) {
            p = new Book;
            cin >> *p;
            if (cin.fail()) {
                cout << "\nAborted!\n";
                delete p;
            }
            else {
                publicationAdded = true;
            }
        }
        else if (i == 2) {
            p = new Publication;
            cin >> *p;
            if (cin.fail()) {
                cout << "\nAborted!\n";
                delete p;
            }
            else {
                publicationAdded = true;
            }
        }

        if (publicationAdded && confirm("Add this publication to the library?")) {
            m_changed = true;
            PPA[NOLP] = p;
            LLRN++;
            PPA[NOLP]->setRef(LLRN);
            NOLP++;
            cout << "Publication added\n";
        }
        else if (!publicationAdded) {
            //cout << "Failed to add publication!\n";
            delete p;
        }
    }



    void LibApp::removePublication()
    {
        // Print a message indicating the intention to remove a publication
        cout << "Removing publication from the library" << endl;

        int i = m_typeMenu.run();
        char type;

        if (i == 1) { 
            type = 'B'; 
        }
        else {
            type = 'P';
        }
        // Call the search() method to find the all publication
        int ref = search(1, type);

        if (ref != 0) {
            cout << *getPub(ref) << endl;
            // Ask for user confirmation before proceeding to remove the publication
            if (confirm("Remove this publication from the library?"))
            {
                // If the user confirms, set the m_changed flag to true
                m_changed = true;

                getPub(ref)->setRef(0);

                // Print a message to confirm that the publication was removed
                cout << "Publication removed" << endl;
            }
        }
    }

    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int i = m_typeMenu.run();
        char type;

        if (i == 1) {
            type = 'B';
        }
        else {
            type = 'P';
        }


        // Call the search() method to find the publications that are not on loan.
        int ref = search(3, type);

        // Ask for user confirmation before proceeding to check out the publication
        if (ref != 0)
        {
            cout << *getPub(ref) << endl;
            if (confirm("Check out publication?")) {
                // If the user confirms, set the m_changed flag to true
                m_changed = true;
                int membershipnum;
                int loop = 1;

                cout << "Enter Membership number: ";

                while (loop == 1) {
                    cin >> membershipnum;

                    if (membershipnum > 9999 && membershipnum <= 99999) {
                        loop = 0;
                    }
                    else {
                        cout << "Invalid membership number, try again: ";
                    }
                }
                getPub(ref)->set(membershipnum);

                // Print a message to confirm that the publication was checked out
                cout << "Publication checked out" << endl;
            }
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
    LibApp::LibApp(const char filename[256])
    {


        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        strcpy(m_filename, filename);
        NOLP = 0;
        LLRN = 0;

        m_typeMenu << "Book" << "Publication";

        load();
    }

    LibApp::~LibApp()
    {
        for (int i = 0; i < NOLP; i++) {
            delete PPA[i];
        }
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

    Publication* LibApp::getPub(int libRef) {
        Publication* foundPublication = nullptr; // Local pointer to store the matching publication

        for (int i = 0; i < NOLP; i++) {
            if (libRef == PPA[i]->getRef()) {
                foundPublication = PPA[i]; // Set the local pointer to the matching publication
            }
        }

        return foundPublication; // Return the local pointer (nullptr if no match found)
    }


}
