/*
*****************************************************************************
Workshop - #5 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 06/14/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;
      Account& operator=(int number);
      Account& operator=(Account& other);
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& other);
      Account& operator>>(Account& other);
      friend double operator+(const Account& left, const Account& right);
      friend double operator+=(double& left, const Account& right);
   };
   
   
}
#endif // SDDS_ACCOUNT_H_