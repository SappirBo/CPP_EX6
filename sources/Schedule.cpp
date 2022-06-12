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
    this->out_list = {19,18,17,16,15,14,13,12,11,10};
}

void Schedule::next_game_reorder(){
    if(this->Round < MAX_LEAUGE){
        // Rearanging Home List.
        size_t index = 9;
        size_t tmp_num = this->home_list.at(index);
        for(; index > 1; index--){
            this->home_list.at(index) = this->home_list.at(index-1);
        }
        this->home_list.at(index)  = (size_t) (MAX_LEAUGE - this->Round);
        
        // Rearanging Out List.
        index = 0;
        for(; index < TEN-1; index ++){
            this->out_list.at(index) = this->out_list.at(index+1);
        }
        this->out_list.at(index)  = tmp_num;

    }else if(this->Round == MAX_LEAUGE){
        // In the mid sesson, rearanging the home / out listd such that every game will have a rmatche in the opposite Home Arena.  
        this->out_list = {0,1,2,3,4,5,6,7,8,9};
        this->home_list = {19,18,17,16,15,14,13,12,11,10};
    }
    else if(this->Round > MAX_LEAUGE && this->Round < 2*MAX_LEAUGE+1){
        // Rearanging Home List.
        size_t index = 9;
        size_t tmp_num = this->out_list.at(index);
        for(; index > 1; index--){
            this->out_list.at(index) = this->out_list.at(index-1);
        }
        this->out_list.at(index)  = (size_t) (MAX_LEAUGE - this->Round%20);
        
        // Rearanging Out List.
        index = 0;
        for(; index < TEN-1; index ++){
            this->home_list.at(index) = this->home_list.at(index+1);
        }
        this->home_list.at(index)  = tmp_num; 
    }
    else{
        // In case Someone keep pushing to the next order.
        throw invalid_argument("All Scheduale Has Done! (40 Games).");
    }
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
    this->leauge_ptr->setRound(this->getRound());
    this->next_game_reorder();
    
}




std::ostream& operator<<(std::ostream& _os, Schedule& sch){
    if(sch.Round == 0){
        _os << "Schedule Haven't Started!";
    }else{
        _os << "***** ***** ***** ***** Schedule Details: ***** ***** ***** *****\n";
        _os << "Schedule Rounds: " << sch.getRound() << " / 40 .\n";
        _os << "Full Details:\n";
        _os << sch.leauge_ptr->getStats() << "\n\n";
    }
    return _os;
}

