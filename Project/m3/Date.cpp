// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds {

    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;

   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }
   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

/*
*****************************************************************************
Project - Milestone 3
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 07/28/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

   std::istream& sdds::Date::read(std::istream& is) {
       // Clear the error code
       m_ErrorCode = NO_ERROR;

       // Read the date components (year, month, day) from the input stream
       is >> m_year;
       is.ignore(); // Ignore the separator character
       is >> m_mon;
       is.ignore(); // Ignore the separator character
       is >> m_day;

       // Check if the input stream has failed
       if (is.fail()) {
           // Set the error code to CIN_FAILED
           m_ErrorCode = CIN_FAILED;
           // Clear the input stream error flags
           is.clear();
       }
       else {
           // Validate the values entered
           if (!validate()) {
               // If validation fails, set the appropriate error code
               if (m_year < MIN_YEAR)
                   m_ErrorCode = YEAR_ERROR;
               else if (m_mon < 1 || m_mon > 12)
                   m_ErrorCode = MON_ERROR;
               else if (m_day < 1 || m_day > mdays())
                   m_ErrorCode = DAY_ERROR;
           }
       }

       // Return the istream object
       return is;
   }
   std::ostream& sdds::Date::write(std::ostream& os) const {
       // Check if the Date object is in a "bad" state
       if (bad()) {
           // Print the date status
           os << dateStatus();
       }
       else {
           // Print the date components in the specified format
           os << m_year << '/';
           os.width(2);
           os.fill('0');
           os << m_mon << '/';
           os.width(2);
           os << m_day;
           os.fill(' ');
       }

       // Return the ostream object
       return os;
   }
   bool Date::operator==(const Date& other) const {
       // Compare year, month, and day values for equality
       return (m_year == other.m_year && m_mon == other.m_mon && m_day == other.m_day);
   }

   bool Date::operator!=(const Date& other) const {
       // Use the negation of the equality operator
       return !(*this == other);
   }

   bool Date::operator>=(const Date& other) const {
       // Use the negation of the less than operator
       return !(*this < other);
   }

   bool Date::operator<=(const Date& other) const {
       // Use the negation of the greater than operator
       return !(*this > other);
   }

   bool Date::operator<(const Date& other) const {
       // Compare year, month, and day values in a hierarchical manner

       // Initially assume the calling object is not less than the other date
       bool ok = false;

       // Compare years
       if (m_year < other.m_year)
           ok = true;
       // If years are equal, compare months
       else if (m_year == other.m_year && m_mon < other.m_mon)
           ok = true;
       // If years and months are equal, compare days
       else if (m_year == other.m_year && m_mon == other.m_mon && m_day < other.m_day)
           ok = true;

       // Return the result
       return ok;
   }

   bool Date::operator>(const Date& other) const {
       // Reversing the comparison using the less than operator
       return (other < *this);
   }

   int Date::operator-(const Date& other) const {
       // Calculate the difference in days between two dates
       return daysSince0001_1_1() - other.daysSince0001_1_1();
   }

   Date::operator bool() const {
       // Convert the date validity to a boolean value
       return !bad();
   }


   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }


}
