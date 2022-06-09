#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

using namespace std;

int contain(int arr[],int num){
    int i;
    for(i=0; i<20; i++){
        if(arr[i] == num){return 1;}
    }
    return 0;
}


Leauge::Leauge(){
    vector<Team> team_v;
    int ids[20];
    size_t i;
    for(i=0; i<20; i++){
        ids[i] = -1;
    }
    i=0;
    while(team_v.size() != 20 && team_v.size()<21){
        Team tmp;
        if(!contain(ids,tmp.getID())){
            ids[i] = tmp.getID();
            team_v.push_back(tmp);
        }
    }
    this->team_list = team_v;
}






