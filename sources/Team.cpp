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
    return num;
}