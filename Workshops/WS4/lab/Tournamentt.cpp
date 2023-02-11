/*
*****************************************************************************
<assessment name example: Workshop - #4 (Part-1)>
Full Name : Jaaved Dewan
Student ID#: 126045178
Email : jdewan@myseneca.ca or jilred15@gmail.com
Section : NAA
Completed on: 02/10/23
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Tournament.h"
using namespace sdds;



Tournament::Tournament() {
    setEmpty();
}

Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
    setTournament(name, noOfteam, soccer);
}

Tournament::~Tournament() {
    delete[] m_name;
    m_name = nullptr;
    delete[] m_soccer;
    m_soccer = nullptr;
}

void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
    if (name == nullptr || strlen(name) == 0 || noOfteam <= 0 || soccer == nullptr) {
        setEmpty();
        return;
    }
    else {
        m_num = noOfteam;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);

        m_soccer = new SoccerTeam[m_num];
        for (int i = 0; i < m_num; i++) {
            m_soccer[i] = soccer[i];
        }
    }
}


void Tournament::setEmpty() {
    m_num = 0;
    m_name = nullptr;
    m_soccer = nullptr;
}

bool Tournament::isEmpty() const {
    return m_num == 0 || m_name == nullptr || m_soccer == nullptr;
}

//Tournament& Tournament::match(const SoccerTeam* ls) {
//    for (int i = 0; i < m_num; i++) {
//        for (int j = i + 1; j < m_num; j++) {
//
//            if (m_soccer[i].m_noFouls < m_soccer[j].m_noFouls) {
//                m_soccer[i].m_golas += 1;
//                m_soccer[j].calFines();
//                m_soccer[j].m_noFouls *= 2;
//            }
//            if (m_soccer[j].m_noFouls = MAX_FOUL)
//            {
//                m_soccer[j].m_noFouls = -1;
//            }
//        }
//    }
//
//    return *this;
//}


std::ostream& Tournament::display() const {
    if (isEmpty()) {
        std::cout << "Invalid Tournament" << std::endl;
    }
    else {
        std::cout << "Tournament name: " << m_name << std::endl;
        std::cout << "list of the teams" << std::endl;
        std::cout << std::right << std::setw(45) << "Fines" << std::setw(10) << "Fouls" << std::setw(10) << "Goals" << std::endl;
        for (int i = 0; i < m_num; i++) {
            m_soccer[i].display();
        }
    }
    return std::cout;
}

