#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"

class Leauge{
    private:
        std::vector<Team> team_list;

    public:
        // Defualt Constractor.
        Leauge();
        // Argumented Constractor.
        Leauge(std::vector<Team> const *teams);
        // Copy Constractor.
        Leauge(const Leauge &leauge):
            team_list(leauge.team_list){}
        // Destractor.
        ~Leauge(){}

        // Copy Assignment Operator.
        Leauge & operator=(const Leauge &other_Leauge);
        
        // Move Constructor.
        Leauge (Leauge &&) = default;	
        
        // Move assignment Operator.
        Leauge& operator=(Leauge&& other) = default;

        friend std::ostream& operator<<(std::ostream& _os, Leauge& team){
            size_t index=0;
            for(;index<MAX_LEAUGE; index++){
                _os << "     " << team.team_list.at(index) << std::endl;
            }
            return _os;
        }

};
