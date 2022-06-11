#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

using namespace std;

// Basic Contain Helper.
int contain(int arr[],int num, int size){
    int i;
    for(i=0; i<size; i++){
        if(arr[i] == num){return 1;}
    }
    return 0;
}

// Defualt Constractor.    
Leauge::Leauge(){
    int ids[20];
    size_t i;
    for(i=0; i<20; i++){
        ids[i] = -1;
    }
    i=0;
    while(this->team_list.size() != 20 && this->team_list.size()<21){
        Team tmp;
        if(!contain(ids,tmp.getID(),20)){
            ids[i] = tmp.getID();
            this->team_list.push_back(tmp);
        }
    }
}

// Argumented Constractor.
Leauge::Leauge(vector<Team> const *teams){
    // Check if the given Vector is larger then 20.
    if(teams->size() > 20){
        throw invalid_argument("Team List Must Be Equal or smaller then 20!");
    }
    // If the team vector is exacly 20
    if(teams->size() == 20){
        size_t i;
        for(i=0; i<20; i++){
            this->team_list.push_back(teams->at(i));
        }
    }
    // If we Missing some Teams in are vector, we add the missing teams.
    else{
        int missing = 20 - teams->size();
        // Push the teams we already got.
        size_t i;
        for(i=0; i<teams->size(); i++){
            this->team_list.push_back(teams->at(i));
        }
        // add the remain,
        int ids[missing];
        for(i=0; i<missing; i++){
            ids[i] = -1;
        }
        i=0;
        while(this->team_list.size() != MAX_LEAUGE){
            Team tmp;
            if(!contain(ids,tmp.getID(),missing)){
                ids[i] = tmp.getID();
                this->team_list.push_back(tmp);
                i++;
            }
        }
    }
}

// Copy Assignment Operator.
Leauge & Leauge::operator=(const Leauge &other_Leauge){
    size_t index = 0;
    for(;index < MAX_LEAUGE; index++){
        this->team_list.push_back(other_Leauge.team_list.at(index));
    }
    return *this;
}







