/*
*****************************************************************************
<assessment name example: Workshop - #6 (Part-1)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 03/08/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        //Members
        double* m_collection;
        char m_filename[256]; //max 255
        unsigned int m_size;
        bool m_flagOriginal;
        bool m_flagAdded;

        //Private Functions
        void sort(double* array, unsigned int size);
        unsigned int countLines(const char* filename);
        void setEmpty();
        bool load();
        void save();
        double max() const;
        double min() const;
        double average() const;

    public:

        //Contructors
        Numbers();
        Numbers(const char* input_file);
        Numbers(const Numbers& other);
        ~Numbers();

        //Sort & Conversion
        void sort();
        operator bool() const;

        //Operators
        Numbers& operator=(const Numbers& value);
        Numbers& operator+=(double value);

        //Input & Output
        std::ostream& display(std::ostream& ostr) const;

    };

    // Input & Output Helpers
    std::ostream& operator<<(std::ostream& ostr, const Numbers& data);
    std::istream& operator>>(std::istream& istr, Numbers& data);
}
#endif // !SDDS_NUMBERS_H_

