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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
namespace sdds {
   class LibApp {
       char m_filename[256];
       Publication* PPA[SDDS_LIBRARY_CAPACITY]{};
       int NOLP;
       int LLRN;
       bool m_changed = false;
       Menu m_typeMenu{"Choose the type of publication:"};
       Menu m_mainMenu{"Seneca Library Application"};
       Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       int search(int option, char type);  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication();
       void removePublication();
       void checkOutPub();
       Publication* getPub(int libRef);
   public:
       LibApp();
       LibApp(const char filename[256]);
       ~LibApp();
       void run();

   };
}
#endif // !SDDS_LIBAPP_H



