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

#ifndef SDDS_DEPARTMENT_H_
#define SDDS_DEPARTMENT_H_
#include <cstring>
#include <iostream>

namespace sdds {
    const int MAX_TOPIC_LENGTH = 25;

    struct Project {
        char m_topic[MAX_TOPIC_LENGTH + 1];
        double m_cost;
    };

    class Department {
    private:
        char* m_departmentName;
        Project* m_projects;
        int m_numProjects;
        double m_departmentBudget;

    public:
        // Default constructor
        Department();

        // Parametrized constructor
        Department(const char* newname, Project& newproject, double change);

        // Copy constructor
        Department(const Department& obj);

        // Destructor
        ~Department();

        // Accessor functions
        Project* fetchProjects() const;
        int fetchNumProjects() const;
        double fetchBudget() const;
        char* fetchName() const;

        // Mutator functions
        void updateName(const char* newname);
        void updateBudget(double change);
        bool addProject(Project& newproject);
        void createDepartment(const char* newname,
            Project& newproject,
            double change);

        // Utility functions
        double totalexpenses();
        double remainingBudget();
        void clearDepartment();

        // Friend functions
        friend void display(const Project& project);
        friend void display(const Department& department);
    };
}
#endif // !SDDS_DEPARTMENT_H_
