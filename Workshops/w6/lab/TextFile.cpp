/*
*****************************************************************************
Workshop - #6 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/05/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setEmpty() {
       delete[] m_textLines;  // Deallocate memory for m_textLines
       m_textLines = nullptr;
       delete[] m_filename;  // Deallocate memory for m_filename
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
       delete[] m_filename;  // Deallocate previous m_filename memory

       if (!isCopy) {
           m_filename = new char[fname == nullptr ? 0 : strLen(fname) + 1];  // Allocate memory for new filename
           strCpy(m_filename, fname);  // Copy fname to m_filename
           return;
       }

       m_filename = new char[fname == nullptr ? 0 : strLen(fname) + 3];  // Allocate memory for new filename
       string copy_name = "C_";  // Create a prefix for the copy

       for (int i = 0; i < (int)strLen(fname); i++)
           copy_name += fname[i];  // Append each character of fname to copy_name

       strCpy(m_filename, copy_name.c_str());  // Copy copy_name to m_filename
   }


   void TextFile::setNoOfLines() {
       int count = 0;
       ifstream in;
       in.open(m_filename);
       string readline;
       while (getline(in, readline))
           count++;
       in.close();
       if (!count) {
           delete[] m_filename;  // Deallocate memory for m_filename
           m_filename = nullptr;
           m_noOfLines = 0;
           return;
       }
       m_noOfLines = count;
   }


   void TextFile::loadText() {
       delete[] m_textLines;  // Deallocate previous m_textLines memory if any

       if (m_filename == nullptr)
           return;  // Return if m_filename is nullptr

       m_textLines = new Line[m_noOfLines];  // Allocate memory for m_textLines

       ifstream in;
       in.open(m_filename);

       if (in.is_open()) {
           string readline;

           for (int i = 0; i < (int)m_noOfLines; i++) {
               getline(in, readline);
               m_textLines[i] = readline.c_str();  // Copy readline to m_textLines
           }
       }

       in.close();
   }

   void TextFile::saveAs(const char* fileName) const {
       if (fileName == nullptr)
           return;  // Return if fileName is nullptr

       ofstream _out;
       _out.open(fileName);

       if (_out.is_open()) {
           for (int i = 0; i < (int)m_noOfLines; i++)
               _out << m_textLines[i] << '\n';  // Write m_textLines to file
       }

       _out.close();
   }

   TextFile::TextFile(unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {
       // Empty constructor body
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {
       if (filename != nullptr) {
           setFilename(filename);  // Set the filename
           setNoOfLines();  // Set the number of lines
           loadText();  // Load the text from the file
       }
   }

   TextFile::TextFile(const TextFile& other) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(other.m_pageSize) {
       if (other.m_filename != nullptr) {
           setFilename(other.m_filename, true);  // Set the filename as a copy
           other.saveAs(m_filename);  // Save the contents of other to m_filename
           setNoOfLines();  // Set the number of lines
           loadText();  // Load the text from the file
       }
   }


   TextFile& TextFile::operator=(const TextFile& other) {
       if (this == &other)
           return *this;  // Check for self-assignment and return current object

       delete[] this->m_textLines;
       m_textLines = nullptr;  // Deallocate previous m_textLines memory

       other.saveAs(m_filename);  // Save other's content to m_filename
       setNoOfLines();  // Set the number of lines
       loadText();  // Load the text

       return *this;  // Return the current object
   }


   TextFile::~TextFile() {
       if (m_textLines != nullptr) {
           delete[] m_textLines;  // Deallocate memory for m_textLines
       }
       if (m_filename != nullptr) {
           delete[] m_filename;  // Deallocate memory for m_filename
       }
   }

   unsigned TextFile::lines() const {
       return m_noOfLines;  // Return the number of lines
   }


   std::ostream& TextFile::view(std::ostream& ostr) const {
       if (!*this)
           return ostr;  // Return the stream as-is if TextFile is in an empty state

       ostr << m_filename << endl;  // Print the filename

       ostr.width(m_filename == nullptr ? 0 : strLen(m_filename));
       ostr.fill('=');
       ostr << "" << endl;  // Print a line of '=' characters

       for (int i = 0; i < (int)m_noOfLines; i++) {
           ostr << m_textLines[i].m_value << endl;  // Print each line

           if ((i + 1) % m_pageSize == 0 && i != 0) {  // Check if it's time to pause (every m_pageSize lines)
               ostr << "Hit ENTER to continue..." << endl;
           }
       }

       return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr) {
       std::string filename;
       istr >> filename;  // Read the filename from the input stream

       delete[] m_textLines;  // Deallocate previous m_textLines memory if any
       delete[] m_filename;  // Deallocate previous m_filename memory if any
       m_textLines = nullptr;
       m_filename = nullptr;
       m_noOfLines = 0;

       if (!filename.empty()) {
           setFilename(filename.c_str());  // Set the filename
           setNoOfLines();  // Set the number of lines
           loadText();  // Load the text from the file
       }

       return istr;
   }


   const char* TextFile::operator[](unsigned index) const {
       if (m_filename == nullptr || m_noOfLines == 0) {
           return nullptr;  // Return null if TextFile is in an empty state
       }

       if (index >= m_noOfLines) {
           index %= m_noOfLines;  // Wrap around to the beginning if index exceeds the size of the array
       }

       return m_textLines[index];
   }

   TextFile::operator bool() const {
       return (m_filename != nullptr);  // Return true if TextFile has a valid filename, otherwise false
   }

   const char* TextFile::name() const {
       return m_filename;  // Return the filename
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       return text.view(ostr);  // Call the view function of TextFile and return the ostream
   }

   std::istream& operator>>(std::istream& istr, TextFile& text) {
       return text.getFile(istr);  // Call the getFile function of TextFile and return the istream
   }


}