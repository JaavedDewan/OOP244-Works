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

#ifndef SDDS_TOURNAMENT_H
#define SDDS_TOURNAMENT_H

#include <iostream>
#include <cstring>
#include "SoccerTeam.h"


namespace sdds {
    class Tournament {
    private:
        char* m_name;
        int m_num;
        SoccerTeam* m_soccer = nullptr;

    public:
        Tournament();
        Tournament(const char* name, int noOfteam, const SoccerTeam* soccer);
        ~Tournament();
        void setTournament(const char* name, int noOfteam, const SoccerTeam* soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament& match(const SoccerTeam* ls);
        std::ostream& display() const;
    };
}
#endif