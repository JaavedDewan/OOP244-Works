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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Numbers.h"

using namespace std;

namespace sdds {

//Private Functions

    //Sorting Function
   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   //Line Counter Function
   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

   //Set Empty Function
   void Numbers::setEmpty()
   {
       m_collection = nullptr;
       m_filename[0] = '\0';
       m_size = 0;
       m_flagOriginal = false;
       m_flagAdded = false;
   }

   //Read Function
   bool Numbers::load()
   {
       unsigned int i = 0, numLines = countLines(m_filename);

       // If the file contains data
       if (numLines > 0u)
       {
           // Create a dynamic array to store the data
           m_collection = new double[numLines];

           // Open the file for reading
           ifstream loadFile (m_filename);

           // Read the data from the file and store it in the array
           do
           {
               loadFile >> m_collection[i];
               if (loadFile)
               {
                   i++;
               }
           } while (loadFile);

           // If the number of lines read does not match the expected number
           if (i != numLines)
           {
               // Free the memory and reset the object
               delete[] m_collection;
               setEmpty();
           }
           else
           {
               // Otherwise, update the object's state
               m_size = numLines;
               m_flagOriginal = true;
           }
       }
       // Return true if data was loaded successfully, false otherwise
       return m_collection != nullptr;
   }

   //Save Function
   void Numbers::save()
   {
       //If there is any original data & if any new was added before
       if (m_flagOriginal && m_flagAdded)
       {
           //File is opened & saves data
           ofstream saveFile(m_filename);
           saveFile.precision(2);
           for (unsigned int i = 0; i < m_size; i++)
           {
               saveFile << fixed << setprecision(2);
               saveFile << m_collection[i] << endl;
           }
       }
   }

   //Max Function
   double Numbers::max() const
   {
       double max = m_collection[0];
       for (unsigned int i = 1; i < m_size; i++)
       {
           if (m_collection[i] > max)
           {
               max = m_collection[i];
           }
       }
       return max;
   }

   //Min Function
   double Numbers::min() const
   {
       double min = m_collection[0];
       for (unsigned int i = 1; i < m_size; i++)
       {
           if (m_collection[i] < min)
           {
               min = m_collection[i];
           }
       }
       return min;
   }

   //Average Function
   double Numbers::average() const
   {
       double total = 0.0;
       for (unsigned int i = 0; i < m_size; i++)
       {
           total += m_collection[i];
       }
       return (m_size > 0) ? (total / m_size) : 0.0;
   }

//Constructors

   //Default Constructor
   Numbers::Numbers()
   {
       setEmpty();
   }

   //One Value Constructor
   Numbers::Numbers(const char* input_file)
   {
       setEmpty();
       strncpy(m_filename, input_file, 256);
       m_filename[255] = '\0';
       load();
   }

   //Copy Constructor
   Numbers::Numbers(const Numbers& copy)
   {
       setEmpty();
       *this = copy;
   }

   //Destructor
   Numbers::~Numbers()
   {
       save();
       delete[] m_collection;
   }

//Public Functions

   //Uses sort function in public
   void Numbers::sort()
   {
       sort(m_collection, m_size);
   }

   //Helper binary that checks if there is any data
   Numbers::operator bool() const
   {
       return m_collection != nullptr;
   }

   //Copy Assignment Function
   Numbers& Numbers::operator=(const Numbers& copy)
   {
       if (this != &copy) {

           //Calls the save function to save current object
           save();

           // Delete the dynamically allocated memory used by the current object
           delete[] m_collection;

           // Set the current object to its empty state
           setEmpty();

           // Copy the values from the object being copied
           if (copy) {

               // Allocate memory for the collection
               m_collection = new double[copy.m_size];

               // Copy the collection values
               for (unsigned int i = 0; i < copy.m_size; i++) {
                   m_collection[i] = copy.m_collection[i];
               }

               // Copy the filename and size values
               std::strcpy(m_filename, copy.m_filename);
               m_size = copy.m_size;

               // Reset the original and added flags
               m_flagOriginal = false;
               m_flagAdded = false;
           }
       }
       return *this;
   }

   //Addition operator Function
   Numbers& Numbers::operator+=(double value)
   {
       //If the object is not empty, creates new array
       if (*this) {//if the Numbers object is valid
           double* temp = new double[m_size + 1]; // copy the old array into the 
           std::memcpy(temp, m_collection, m_size * sizeof(double));// copy the old array into the new one
           delete[] m_collection;
           m_collection = temp;
           temp[m_size] = value;
           m_size++;
           m_flagAdded = true;// set the flag to indicate that a value has been added
       }
       return *this;// return a reference to the current Numbers object
   }

   //Input & Output
   std::ostream& Numbers::display(std::ostream& ostr) const
   {
       //If the data is null
       if (m_collection == nullptr) {
           ostr << "Empty list";
       }
       else {
           ostr << std::fixed << std::setprecision(2);
           if (!m_flagOriginal) {
               ostr << "Copy of ";
           }
           ostr << m_filename << std::endl;

           ostr << m_collection[0];
           for (unsigned int i = 1; i < m_size; i++) {
               ostr << ", " << m_collection[i];
           }
           ostr << std::endl;

           ostr << std::setw(76) << std::setfill('-') << "" << std::endl;

           ostr << "Total of " << m_size << " number(s), Largest: " << max() << ", Smallest: " << min()
               << ", Average: " << average() << std::endl;

           ostr << std::setw(76) << std::setfill('=') << "";
       }
       return ostr;
   }

   // Input and output operator overloading
   std::ostream& operator<<(std::ostream& ostr, const Numbers& data) {
       return data.display(ostr);
   }

   std::istream& operator>>(std::istream& istr, Numbers& data) {
       double input;
       istr >> input;
       data += input;
       return istr;
   }
}