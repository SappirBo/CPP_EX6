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

Schedule::Schedule(Leauge *pleauge){
    this->leauge_ptr = pleauge;
    this->Round = 0;
    this->games_list1 = {0,1,2,3,4,5,6,7,8,9};
    this->games_list2 = {10,11,12,13,14,15,16,17,18,19};
}

// void Schedule::runRound(){
//     size_t index = 0;
//     Game tmp_game;
//     for(; index<20; index++){
//         tmp_game.clear();
//         tmp_game.setHomeTeam(&(leauge_ptr->getTeams_vec().at(games_list1.at(index))));
//         tmp_game.setOutTeam(&(leauge_ptr->getTeams_vec().at(games_list2.at(index))));
        
//         tmp_game.winner();
//     }
// }
