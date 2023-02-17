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
#include "SoccerTeam.h"

using namespace sdds;
using namespace std;


SoccerTeam::SoccerTeam() {
    setEmpty();
}

SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
    if (tname == nullptr || fines < 0 || foul < 0 || strlen(tname) == 0) {
        setEmpty();
    }
    else {
        setName(tname);
        setFine(fines, foul);
    }
}



void SoccerTeam::setTeam(const SoccerTeam& team) {
    setName(team.m_teamName);
    m_noFouls = team.m_noFouls;
    m_fines = team.m_fines;
    m_golas = team.m_golas;
}

void SoccerTeam::setName(const char* tname) {
    if (tname == nullptr) {
        setEmpty();
    }
    else {
        strncpy(m_teamName, tname, 40);
        m_teamName[40] = '\0';
    }
}

void SoccerTeam::setFine(double fines, int foul)
{
    if (fines >= 0 && foul >= 0)
    {
        m_fines = fines;
        m_noFouls = foul;
    }
    else
    {
        setEmpty();
    }
}


void SoccerTeam::setEmpty() {
    m_teamName[0] = '\0';
    m_noFouls = -1;
    m_fines = -1.0;
    m_golas = 0;
}

bool SoccerTeam::isEmpty() const {
    return m_teamName[0] == '\0' && m_fines < 0 && m_noFouls < 0;
}

void SoccerTeam::calFines() {
    m_fines *= 1.2;
}

int SoccerTeam::fouls() const {
    return m_noFouls;
}

ostream& SoccerTeam::display() const {
    if (isEmpty()) {
        cout << "Invalid Team";
    }
    else {
        cout << left << setw(30) << m_teamName;
        cout << right << setw(6) << fixed << setprecision(2) << m_fines;
        cout << setw(6) << m_noFouls << setw(10);
        if (m_golas > 0) {
            cout << m_golas << "w" << endl;
        }
        else {
            cout << m_golas << endl;
        }
    }
    return cout;
}
