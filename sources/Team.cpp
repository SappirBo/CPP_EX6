#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"

/**
 * @brief Function for getting random team index. 
 * @return int - random index number [0,39]. 
 */
int random_team_index(){
    return (rand()%FORTY) ;
}

/**
 * @brief Function for getting random team rate. 
 * @return double - random index rate [0,1]. 
 */
double random_team_rate(){
    double num = rand()%ONE_HUNDRED_AND_ONE;
    num = num/HUNDRED;
    if(num <0){num = 0;}
    if(num >1){num =1;}
    return num;
}


bool operator==(const Team &team1, const Team &team2){
    // Means both teams came from same place in the Team_list.
    if(team1.getID() ==team2.getID() && team1.getID() != -1){
        return true;
    }else{
        if(team1.getName()==team2.getName() && team1.getRate()==team2.getRate()){
            return true;
        }
    }
    return false;
}