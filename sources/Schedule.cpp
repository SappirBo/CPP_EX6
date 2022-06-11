#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <array>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;

Schedule::Schedule(Leauge *pleauge){
    this->leauge_ptr = pleauge;
    this->Round = 0;
    this->home_list = {0,1,2,3,4,5,6,7,8,9};
    this->out_list = {10,11,12,13,14,15,16,17,18,19};
}

void Schedule::runRound(){
    size_t index = 0;
    // Creating Game Object that will run all games in this round. 
    Game tmp_game;
    
    // Run matches between Suitable Home / Out lists.
    for(; index<TEN; index++){
        tmp_game.clear();
        tmp_game.setHomeTeam(&(leauge_ptr->getTeams_vec()->at(home_list.at(index))));
        tmp_game.setOutTeam(&(leauge_ptr->getTeams_vec()->at(out_list.at(index))));
        tmp_game.winner();
    }
    this->Round++;
}





std::ostream& operator<<(std::ostream& _os, Schedule& sch){
    if(sch.Round == 0){
        _os << "Schedule Haven't Started!";
    }else{
        _os << "Schedule Details: \n";
        // _os << 
    }
    return _os;
}

