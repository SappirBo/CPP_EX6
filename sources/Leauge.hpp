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
        Leauge();
        Leauge(std::vector<Team> t);
        ~Leauge(){}

        friend std::ostream& operator<<(std::ostream& os, Leauge& T){
            size_t i;
            for(i=0;i<20;i++){
                os << "     " << T.team_list.at(i) << std::endl;
            }
            return os;
        }

};
