/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  : Jaaved Dewan
Student ID#: 126045178
Email      : jdewan@myseneca.ca
Section    : NAA
Completed on: 02/03/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {


    //fully provided for students to display details of a project
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
            Project* temp = department.fetchProjects();
            int projects = department.fetchNumProjects();
            cout << "Department " << department.fetchName() << " details:" << endl;
            cout << "Budget: " << department.fetchBudget()
                << " and the number of projects in progress is: " << projects << endl;
            cout << "Below are the details of the projects we are currently working on: " << endl;
            for (int i = 0; i < projects; i++) {
                display(temp[i]);
            }
    }

    // Default constructor
    Department::Department() {
        // Initialize the department name to nullptr
        m_departmentName = nullptr;

        // Initialize the number of projects to 0
        m_numProjects = 0;

        // Initialize the department budget to 15345.99
        m_departmentBudget = 15345.99;

        // Initialize the projects to nullptr
        m_projects = nullptr;
    }

    // Parametrized constructor
    Department::Department(const char* newname, Project& newproject, double change) {
        // Allocate memory for the department name and copy the given name to it
        m_departmentName = new char[strlen(newname) + 1];
        strcpy(m_departmentName, newname);

        // Initialize the department budget with the given change
        m_departmentBudget = 15345.99 + change;

        // Initialize the number of projects to 1
        m_numProjects = 1;

        // Allocate memory for the projects and store the given project in it
        m_projects = new Project[m_numProjects];
        m_projects[0] = newproject;
    }

    // Copy constructor
    Department::Department(const Department& obj) {
        // Allocate memory for the department name and copy the name from the given object to it
        m_departmentName = new char[strlen(obj.m_departmentName) + 1];
        strcpy(m_departmentName, obj.m_departmentName);

        // Copy the number of projects from the given object
        m_numProjects = obj.m_numProjects;

        // Copy the department budget from the given object
        m_departmentBudget = obj.m_departmentBudget;

        // Allocate memory for the projects and copy the projects from the given object
        m_projects = new Project[m_numProjects];
        for (int i = 0; i < m_numProjects; i++) {
            m_projects[i] = obj.m_projects[i];
        }
    }

    // Destructor
    Department::~Department() {
        // Deallocate the memory for the department name
        delete[] m_departmentName;
        m_departmentName = nullptr;

        // Deallocate the memory for the projects
        delete[] m_projects;
        m_projects = nullptr;
    }

    //Accessor functions
    // Returns a pointer to the projects
    Project* Department::fetchProjects() const {
        return m_projects;
    }

    // Returns the department budget
    double Department::fetchBudget() const {
        return m_departmentBudget;
    }

    // Returns the number of projects
    int Department::fetchNumProjects() const {
        return m_numProjects;
    }

    // Returns the department name
    char* Department::fetchName() const {
        return m_departmentName;
    }

    // Mutator functions
    // Updates the department name with the given name
    void Department::updateName(const char* newname) {
        // Check if the given name is valid (not null and has length greater than 0)
        if (newname && strlen(newname) > 0)
        {
            if (m_departmentName) {
                delete[] m_departmentName;
            }
            m_departmentName = new char[strlen(newname) + 1];
            strcpy(m_departmentName, newname);
        }
    }

    void Department::updateBudget(double change) {
        // Add the change to the department budget
        m_departmentBudget += change;
    }

    bool Department::addProject(Project& newproject) {
        // Check if the budget is sufficient to add the new project
        double totalCost = 0;
        // Calculate the total cost of the existing projects
        for (int i = 0; i < fetchNumProjects(); i++) {
            totalCost += fetchProjects()[i].m_cost;
        }

        if (m_departmentBudget >= totalCost + newproject.m_cost) {
            // Allocate a new array to store the projects
            Project* temp = new Project[fetchNumProjects() + 1];
            // Copy the existing projects to the new array
            for (int i = 0; i < fetchNumProjects(); i++) {
                temp[i] = fetchProjects()[i];
            }
            // Add the new project to the end of the array
            temp[fetchNumProjects()] = newproject;
            // Delete the old array to avoid memory leak
            delete[] m_projects;
            // Set the pointer to the new array
            m_projects = temp;
            // Increase the number of projects
            m_numProjects++;
            return true;
        }
        return false;
    }

    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        // Update the department name
        updateName(newname);
        // Add a new project to the department
        addProject(newproject);
        // Update the department budget
        updateBudget(change);
    }

    double Department::totalexpenses() {
        double expenses = 0.0;
        // Calculate the total expenses of all projects
        for (int i = 0; i < m_numProjects; i++) {
            expenses += m_projects[i].m_cost;
        }
        return expenses;
    }

    double Department::remainingBudget() {
        // Calculate the remaining budget by subtracting the total expenses from the budget
        return m_departmentBudget - totalexpenses();
    }

    void Department::clearDepartment() {
        // Delete the department name to avoid memory leak
        delete[] m_departmentName;
        // Delete the projects to avoid memory leak
        delete[] m_projects;
        // Set the name pointer to nullptr
        m_departmentName = nullptr;
        // Set the projects pointer to nullptr
        m_projects = nullptr;
        // Reset the number of projects
        m_numProjects = 0;
        // Reset the budget
        m_departmentBudget = 0;
    }


}