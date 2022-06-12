#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"

/**
 * @brief This Leauge class is Hold Vector of Teams , and round counter,
 * the leage can run for 40 rounds (amount of game you need for each team will play against all other 
 * teams exacly two times: one as host and one as guest).
 */
class Leauge{
    private:
        std::vector<Team> team_list;
        int Round;

    public:
        // Defualt Constractor.
        Leauge();
        // Argumented Constractor.
        Leauge(std::vector<Team> const *teams);
        // Copy Constractor.
        Leauge(const Leauge &leauge);
        // Destractor.
        ~Leauge(){}

        // Return the amount of teams in this Leauge (Basicly it is for Testing).
        size_t size() const {return this->team_list.size();}
        
        std::string getStats();

        /**
         * @brief This is sorting function as Helper for the Get Stats.
         * This function will sort the teams by the amount of points they have, and if two teams have exacly the same score 
         * it will sort them by the earned score they gained.
         * 
         * @return vector<size_t> = vector of the INDEXS of the sorted list. 
         *                          For Example: if New York Knicks is number 1 in the ranking, but on the Leauge Vector it's index is 15,
         *                                       the returned Vector will have 15 in the 0 (first) index. AKA: ans.at(0) = 15;
         * 
         * The Time Complexity of this function is O(1), since we have constant Vector size (20 elements). 
         */
        std::vector<size_t> getSortedIndexVector();

        std::vector<Team>* getTeams_vec() {
            std::vector<Team>* list_ptr = &this->team_list;
            return list_ptr;
        }

        void setRound(int round){this->Round = round;}


        std::string active_win_streak();
        std::string active_lose_streak();
        std::string best_win_streak();
        std::string best_lose_streak();

        // Copy Assignment Operator.
        Leauge & operator=(const Leauge &other_Leauge);
        // Move Constructor.
        Leauge (Leauge &&) = default;	
        
        // Move assignment Operator.
        Leauge& operator=(Leauge&& other) = default;
        
        friend std::ostream& operator<<(std::ostream& _os, Leauge& team){
            size_t index=0;
            for(;index<MAX_LEAUGE; index++){
                _os << "     " << team.team_list.at(index) << std::endl;
            }
            return _os;
        }

};
