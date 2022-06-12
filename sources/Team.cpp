#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"


using namespace std;


/**
 * @brief Defult Constructor For Team object,
 *        Creating New Random Team with a Random Rate: Using 'random_team_rate()' and 'random_team_index()'.
 */
Team::Team(): rate(random_team_rate()) ,total_Earned_score(0),
                total_Absorbed_score(0), points(0),active_win_streak(0),active_lose_streak(0),max_win_streak(0),max_lose_streak(0){
    size_t index = (size_t) random_team_index();
    this->name = team_names.at(index);
    this->ID = (int) index;
}

// Argumented Constractor.
Team::Team(std::string Name, double Rate): name(std::move(Name)), ID(-1), points(0),
            total_Earned_score(0),total_Absorbed_score(0),active_win_streak(0),active_lose_streak(0),max_win_streak(0),max_lose_streak(0){
    if(rate > 1 || rate < 0){
        throw std::invalid_argument("Rate Must Be In Range [0,1]!.");
    }
    this->rate = Rate;
}

// Copy Constractor.
Team::Team(const Team &other_team): 
            name(std::move(other_team.getName())), rate(other_team.getRate()),ID(other_team.getID()),points(other_team.points),
            total_Absorbed_score(other_team.getAbsorbed_Score()), total_Earned_score(other_team.getErned_Score()),
            active_win_streak(other_team.active_win_streak),active_lose_streak(other_team.active_lose_streak),
            max_win_streak(other_team.max_win_streak),max_lose_streak(other_team.active_lose_streak) {}



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


/**
 * @brief Function to pass the Game Info fromGame class to Team class,
 * 
 * @param num - return code 0 if the Team won, 1 if the team lose. 
 */
void Team::raisePoint(int num){
    if(num == 0){
        this->points += 1;
        
        this->active_win_streak += 1;
        if(this->active_win_streak > this->max_win_streak){
            this->max_win_streak = this->active_win_streak;
        }
        if(this->active_lose_streak > 0){
            this->active_lose_streak = 0;
        }
    }else if(num == 1){
        this->active_lose_streak += 1;
        if(this->active_lose_streak > this->max_lose_streak){
            this->max_lose_streak = this->active_lose_streak;
        }
        if(this->active_win_streak > 0){
            this->active_win_streak = 0;
        }
    }else{
        throw invalid_argument("WIN/LOSE CODE IS 0 OR 1.");
    }
}