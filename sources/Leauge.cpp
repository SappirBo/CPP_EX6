#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

using namespace std;

int contain(int arr[],int num, int size){
    int i;
    for(i=0; i<size; i++){
        if(arr[i] == num){return 1;}
    }
    return 0;
}


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

Leauge::Leauge(vector<Team> const *t){
    // Check if the given Vector is larger then 20.
    if(t->size() > 20){
        throw invalid_argument("Team List Must Be Equal or smaller then 20!");
    }
    // If the team vector is exacly 20
    if(t->size() == 20){
        size_t i;
        for(i=0; i<20; i++){
            this->team_list.push_back(t->at(i));
        }
    }
    // If we Missing some Teams in are vector, we add the missing teams.
    else{
        int missing = 20 - t->size();
        // Push the teams we already got.
        size_t i;
        for(i=0; i<t->size(); i++){
            this->team_list.push_back(t->at(i));
        }
        // add the remain,
        int ids[missing];
        for(i=0; i<missing; i++){
            ids[i] = -1;
        }
        i=0;
        while(this->team_list.size() != 20){
            Team tmp;
            if(!contain(ids,tmp.getID(),missing)){
                ids[i] = tmp.getID();
                this->team_list.push_back(tmp);
                i++;
            }
        }
    }
}





