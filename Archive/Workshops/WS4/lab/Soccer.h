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

#ifndef SDDS_SOCCERTEAM_H
#define SDDS_SOCCERTEAM_H

#include <iostream>
#include <cstring>

namespace sdds {

    const int MAX_FOUL = 4; //maximum number of fouls



    struct SoccerTeam {
        char m_teamName[41];// a statically allocated Cstring with size 41.
        int m_noFouls;//number of fouls
        double m_fines;//fine amount
        int m_golas;//number of goals

        SoccerTeam();
        SoccerTeam(const char* tname, double fines, int foul);
        void setTeam(const SoccerTeam& team);
        void setName(const char* tname);
        void setFine(double fines, int foul);
        void setEmpty();
        bool isEmpty() const;
        void calFines();
        int fouls() const;
        std::ostream& display() const;
    };
}
#endif