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
#ifndef SDDS_NAMETAG_H // Include guard to prevent multiple definitions of the class
#define SDDS_NAMETAG_H

namespace sdds { // Namespace declaration to avoid name collisions with other code
    class NameTag {
        char* m_name; // A pointer to a dynamically allocated array of chars to store the name
        int m_ext; // An integer to store the extension

        // Private member function to set the name
        void setName(const char* Cstr);

    public:
        // Default constructor
        NameTag();

        // Constructor with one parameter
        NameTag(const char* name);

        // Constructor with two parameters
        NameTag(const char* name, int ext);

        // Copy constructor
        NameTag(const NameTag& source);

        // Copy assignment operator
        NameTag& operator=(const NameTag& source);

        // Destructor
        ~NameTag();

        // Member function to read the name and extension from the user
        NameTag& read();

        // Member function to print the name and extension
        void print();

    };
}

#endif // End of the include guard

