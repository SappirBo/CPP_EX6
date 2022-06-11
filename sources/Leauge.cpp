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

void swap(vector<size_t> *arr, size_t i, size_t j){
    size_t tmp = arr->at(i);
    arr->at(i) = arr->at(j);
    arr->at(j) = tmp;
}

// O(1).
vector<size_t> Leauge::getSortedIndexVector(){
    vector<size_t> ans = {0,1,2,3,4,5,6,7,8,9,
                            10,11,12,13,14,15,16,17,18,19};
    size_t i,j;
    for(i=0; i<MAX_LEAUGE-1; i++){
        for(j=i; j<MAX_LEAUGE; j++){
            if(i != j){
                if(this->getTeams_vec()->at(ans.at(i)).getPoints() < this->getTeams_vec()->at(ans.at(j)).getPoints()){
                    swap(&ans,i,j);
                }else if(this->getTeams_vec()->at(ans.at(i)).getPoints() == this->getTeams_vec()->at(ans.at(j)).getPoints()){
                    if(this->getTeams_vec()->at(ans.at(i)).getErned_Score() < this->getTeams_vec()->at(ans.at(j)).getErned_Score()){
                        swap(&ans,i,j);
                    }
                }
            }
        }
    }
    return ans;
}



std::string Leauge::getStats(){
    string ans = "";
    vector<size_t> indexs = getSortedIndexVector();
    for(size_t i=0; i<MAX_LEAUGE; i++){
        string s = "";
        s += to_string(i);
        s += ". ";
        s += this->getTeams_vec()->at(indexs.at(i)).getName();
        while(s.size() < 30){
            s += " ";
        }
        s += "| Points: ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getPoints() );
        while(s.size() < TEN+1){
            s += " ";
        }
        s += "| Balls: ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getErned_Score());
        while(s.size() < TEN+1){
            s += " ";
        }
        s += "/ ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getAbsorbed_Score());

        ans += s;
        ans += "\n"; 
    }
    return ans;
}




