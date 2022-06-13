#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"


// Defult Constractor (Build Empty Game).
Game::Game(){
    this->home_team = NULL;
    this->out_team = NULL;
    this->home_score = 0;
    this->out_score = 0;
    this->finish_stats = false;
}

// Argumented Constractor.
Game::Game(Team *home, Team *out): 
            finish_stats(false), home_score(-1), out_score(-1){
    if(*(home) == *(out)){
        throw std::invalid_argument("Same team cant play against it self.");
    }
    this->home_team = home;
    this->out_team = out;
}

// Copy Constractor.
Game::Game(const Game &game):
            home_team(game.home_team), out_team(game.out_team), finish_stats(game.finish_stats),
            home_score(-1), out_score(-1){}


/**
 * @brief Set Home team.
 * 
 * @param h_team pointer to the Team we want to add.
 */
void Game::setHomeTeam(Team *h_team){
    if(this->finish_stats || home_team != NULL){
        throw std::invalid_argument("Game is inittialized allready!");
    }
    this->home_team = h_team;
    this->home_score = 0;
}


/**
 * @brief Set Out Team.
 * 
 * @param o_team pointer to the Team we want to add.
 */
void Game::setOutTeam(Team *o_team){
    if(this->finish_stats || this->out_team != NULL){
        throw std::invalid_argument("Game is inittialized allready!");
    }
    this->out_team = o_team;
    this->out_score = 0;
}

/**
 * @brief function for creating a match and  get a winner of the match,
 *        The Function will get to Random numbers in [0,1], divide them by 3, and add them to the teams rate. 
 *        So the team with the higher Rate will have an adventage, But still can lose.
 * @return int - 0 if the Home team won, 1 if the Out team has lost.
 */
int Game::winner(){
    if(this->finish_stats){
        throw std::invalid_argument("Game is Allready Over!.");
    }
    // Get two random numbers from 0 to 1 included;
    double num1 = (double) (rand()%ONE_HUNDRED_AND_ONE)/HUNDRED;
    double num2 = (double) (rand()%ONE_HUNDRED_AND_ONE)/HUNDRED;
    // Divide the numbers by 3 for lower impact. 
    num1 = num1;
    num2 = num2;    

    // Here The Team with the Higher Rate Will have advantage
    double score1 = this->getHomeTeam()->getRate() + num1;
    double score2 = this->getOutTeam()->getRate() + num2;
    
    // Setting the Scores to be in range from 50 to 100.
    score1 = score1*HUNDRED;
    score2 = score2*HUNDRED;
    if(score1 > HUNDRED){
        score1 = HUNDRED;
    }
    if(score1 < FIFTY_FIVE){
        score1 = FIFTY_FIVE;
    }
    if(score2 > HUNDRED){
        score2 = HUNDRED;
    }
    if(score2 < FIFTY){
        score2 = FIFTY;
    }
    

    // Passind the Final Scores.
    this->home_score = (int) score1;
    this->out_score = (int) score2;
    this->getHomeTeam()->setErned_Score(this->home_score);
    this->getOutTeam()->setErned_Score(this->out_score);

    this->getHomeTeam()->setAbsorbed_Score(this->out_score);
    this->getOutTeam()->setAbsorbed_Score(this->home_score);

    this->finish_stats = 1;

    // Return the Finle winner (0 If Home team won, 1 if Out team won).
    if(score1 >= score2){
        this->home_team->raisePoint(0);
        this->out_team->raisePoint(1);
        return 0;
    }else{
        this->out_team->raisePoint(0);
        this->home_team->raisePoint(1);
        return 1;
    }

    return -1;
}


/**
 * @brief Function for clearing the game data -> for reusing this game object.
 */
void Game::clear(){
    this->home_team = NULL;
    this->out_team = NULL;
    this->home_score = 0;
    this->out_score = 0;
    this->finish_stats = false;
}

