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
#include <sstream>
#include "Tournament.h"
using namespace sdds;
using namespace std;


int check = 0, team1G, team2G, team1F, team2F;
double team1Fi, team2Fi;
char teamName1[41], teamName2[41];

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
            m_soccer[i].m_golas = 0;
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

Tournament& Tournament::match(const SoccerTeam* ls) {
    int team1G = 0, team2G = 0, team1F = 0, team2F = 0;
    double team1Fi = 0.0, team2Fi = 0.0;

    for (int i = 0; i < m_num; i++) {
        for (int j = i + 1; j < m_num; j++) {

            if (m_soccer[i].fouls() < m_soccer[j].fouls()) {
                m_soccer[i].m_golas += 1;

                team1G << m_soccer[i].m_golas;
                team2G << m_soccer[j].m_golas;

                m_soccer[j].calFines();
                m_soccer[j].setFine(m_soccer[j].m_fines,m_soccer[j].m_noFouls *=2);

                team1Fi = m_soccer[i].m_fines;
                team1F << m_soccer[i].m_noFouls;
                strncpy(&teamName1[41], &m_soccer[1].m_teamName[41], 1);

                team2Fi = m_soccer[j].m_fines;
                team2F << m_soccer[j].m_noFouls;
                strncpy(&teamName2[41], &m_soccer[1].m_teamName[41], 1);
            }

            if (m_soccer[j].fouls() == MAX_FOUL) {
                m_soccer[j].setFine(m_soccer[i].m_fines, -1);
                team2F = m_soccer[j].m_noFouls;
            }
        }
    };
    check = 1;
    setEmpty();
    return *this;
}


std::ostream& Tournament::display() const {
    if (isEmpty() && check == 0) {
        cout << "Invalid Tournament";
    }
    else if (isEmpty() && check == 1) {

        m_soccer[0].m_fines = team1Fi;
        m_soccer[0].m_noFouls << team1F;
        m_soccer[0].m_golas << team1G;
        strncpy(&m_soccer[1].m_teamName[41], &teamName2[41], 1);

        m_soccer[1].m_fines = team2Fi;
        m_soccer[1].m_noFouls << team2F;
        m_soccer[1].m_golas << team2G;
        strncpy(&m_soccer[1].m_teamName[41], &teamName2[41], 1);

        cout << "Tournament name: " << m_name << endl;
        cout << "list of the teams" << endl;
        cout << std::right << setw(45) << "Fines" << setw(10) << "Fouls" << setw(10) << "Goals" << endl;
        for (int i = 0; i < m_num; i++) {
            if (m_soccer[i].m_noFouls > -1) {
                cout << "Team[" << i + 1 << "] :";
                m_soccer[i].display();
            }
            else {

                m_soccer[i].m_teamName[0] = '\0';
                m_soccer[i].m_noFouls = -1;
                m_soccer[i].m_fines = -1.0;
                m_soccer[i].m_golas = 0;
                m_soccer[i].display();
            }
        }
    }
    else {
        cout << "Tournament name: " << m_name << endl;
        cout << "list of the teams" << endl;
        cout << std::right << setw(45) << "Fines" << setw(10) << "Fouls" << setw(10) << "Goals" << endl;
            for (int i = 0; i < m_num; i++) {
                if (m_soccer[i].m_golas >= 0)
                    cout << "Team[" << i + 1 << "] :";
                    m_soccer[i].display();
            }
    }
    return std::cout;
}

