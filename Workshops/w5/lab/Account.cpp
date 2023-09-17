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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const {
       return m_number != -1 && m_number > 0; // Returns true if the account number is valid
   }

   Account::operator int() const {
       return m_number; // Returns the account number
   }

   Account::operator double() const {
       return m_balance; // Returns the account balance
   }

   bool Account::operator~() const {
       return m_number == 0; // Returns true if the account is new (number is zero)
   }

   Account& Account::operator=(int number) {
       if (m_number == 0) { // Account is new
           if (number >= 10000 && number <= 99999)
               m_number = number; // Set the new account number
           else
               setEmpty(); // Set the account to an empty state
       }
       return *this;
   }

   Account& Account::operator=(Account& other) {
       if (m_number == 0 && other.m_number != -1 && other.m_balance >= 0) {
           // Left Account is new and right Account is valid
           m_number = other.m_number; // Assign the account number
           m_balance = other.m_balance; // Assign the account balance
           other.m_number = 0; // Reset the account number of the right Account
           other.m_balance = 0.0; // Reset the account balance of the right Account
       }
       return *this;
   }

   Account& Account::operator+=(double amount) {
       if (m_number != 0 && amount >= 0) {
           // Account is valid and amount is non-negative
           m_balance += amount; // Add the amount to the account balance
       }
       return *this;
   }

   Account& Account::operator-=(double amount) {
       if (m_number != 0 && amount >= 0 && m_balance >= amount) {
           // Account is valid, amount is non-negative, and enough balance
           m_balance -= amount; // Subtract the amount from the account balance
       }
       return *this;
   }

   Account& Account::operator<<(Account& other) {
       // Check if the accounts are different and both have valid numbers and non-negative balance
       if (this != &other && m_number != 0 && other.m_number != 0 && other.m_balance >= 0) {
           m_balance += other.m_balance; // Add the balance of the other account to the current account
           other.m_balance = 0.0; // Set the balance of the other account to zero
       }
       return *this;
   }

   Account& Account::operator>>(Account& other) {
       // Check if the accounts are different and the current account has a non-negative balance
       if (this != &other && m_balance >= 0) {
           other.m_balance += m_balance; // Add the balance of the current account to the other account
           m_balance = 0.0; // Set the balance of the current account to zero
       }
       return *this;
   }

   double operator+(const Account& left, const Account& right) {
       // Check if both accounts have valid numbers
       if (left.m_number != 0 && right.m_number != 0) {
           return left.m_balance + right.m_balance; // Return the sum of the balances
       }
       return 0.0; // Return zero if any of the accounts is invalid
   }

   double operator+=(double& left, const Account& right) {
       left += right.m_balance; // Add the balance of the account to the left operand (double reference)
       return left; // Return the updated value of the left operand
   }


}