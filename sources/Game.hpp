#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"

class Game{
    private:
        Team *home_team;
        Team *out_team;
        bool finish_stats; // 0 for game hasn't finished, 1 for game is finished.  

    public:
        Game(Team *home, Team *out){
            this->home_team = home;
            this->out_team = out;
            this->finish_stats = false;
        }
        ~Game(){}
        
        // Get Functions for The teams, return a reffrence to the team.
        Team *getHomeTeam(){return this->home_team;}
        Team *getOutTeam(){return this->out_team;}

        /**
         * @brief function for creating a match and  get a winner of the match,
         *        The Function will get to Random numbers in [0,1], divide them by 3, and add them to the teams rate. 
         *        So the team with the higher Rate will have an adventage, But still can lose.
         * @return int - 0 if the Home team won, 1 if the Out team has lost.
         */
        int winner();

};