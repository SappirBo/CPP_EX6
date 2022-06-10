#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"


/**
 * @brief function for creating a match and  get a winner of the match,
 *        The Function will get to Random numbers in [0,1], divide them by 3, and add them to the teams rate. 
 *        So the team with the higher Rate will have an adventage, But still can lose.
 * @return int - 0 if the Home team won, 1 if the Out team has lost.
 */
int Game::winner(){
    // Get two random numbers from 0 to 1 included;
    double num1 = (double) (rand()%ONE_HUNDRED_AND_ONE)/HUNDRED;
    double num2 = (double) (rand()%ONE_HUNDRED_AND_ONE)/HUNDRED;
    // Divide the numbers by 3 for lower impact. 
    num1 = num1;
    num2 = num2;    

    double score1 = this->getHomeTeam()->getRate() + num1;
    double score2 = this->getOutTeam()->getRate() + num2;
    
    // Passind the Final Scores.
    this->home_score = score1;
    this->out_score = score2;
    this->finish_stats = 1;


    if(score1 >= score2){
        return 0;
    }else{
        return 1;
    }

    return -1;
}



