/*
*****************************************************************************
Workshop - #2 (Part-1)
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NEE
Completed on: 05/23/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    // Holds the number of records (employees) in the file.
    // Should be used (after setting) to allocate the dynamic array of Employees.
    int noOfEmployees;

    // Stores the address of a dynamically-allocated array of employees.
    //   The size of the array is "noOfEmployees".
    Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument

   bool load(Employee& employee) {
      bool ok = false;
      char name[128]; // Temporary array to store the employee name


      if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {
          // If all reads are successful, proceed with the following steps

          int nameLength = strLen(name); // Get the length of the employee name
          employee.m_name = new char[nameLength + 1];// Allocate memory for the name (+1 for null termination)
          strCpy(employee.m_name, name);// Copy the name into the newly allocated memory
          ok = true;// Set ok to true since the loading was successful
      }

      return ok;
   }

   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
       bool ok = false;

       if (openFile(DATAFILE)) {
           // If the file is successfully opened, proceed with the following steps

           noOfEmployees = noOfRecords(); // Get the number of records (employees) in the file

           employees = new Employee[noOfEmployees]; // Allocate a dynamic array of Employee objects

           for (int i = 0; i < noOfEmployees; i++) {
               // Iterate over each record and load it into the corresponding Employee object

               if (!load(employees[i])) {
                   // If loading fails for any record, display an error message, deallocate memory, and set ok to false
                   cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                   delete[] employees;
                   employees = nullptr;
                   noOfEmployees = 0;
                   ok = false;
                   break;
               }
               else {
                   ok = true; // Set ok to true if all records are successfully loaded
               }
           }
       }

       closeFile(); // Close the file
       return ok; // Return the status of the loading process
   }


   // TODO: Implementation for the display functions go here
   void display(Employee& employee) {
       // Display the information of a single employee

       cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
   }

   void display() {
       // Display the employee salary report

       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort(); // Sort the employees array by employee number

       for (int i = 0; i < noOfEmployees; i++) {
           // Iterate over the sorted array and print each employee's information

           const Employee& emp = employees[i]; // Reference to the current employee

           cout << i + 1 << "- " << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
           // Display the employee number, name, and salary
       }
   }


   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       // Deallocate the memory used by the employees array

       if (employees != nullptr) {
           // Check if the employees array is not empty

           for (int i = 0; i < noOfEmployees; i++) {
               // Iterate over each employee in the array

               delete[] employees[i].m_name; // Deallocate the memory for the employee's name
               employees[i].m_name = nullptr; // Set the name pointer to null
           }

           delete[] employees; // Deallocate the memory for the employees array
           employees = nullptr; // Set the employees pointer to null
       }

       noOfEmployees = 0; // Reset the number of employees to 0
   }


}