#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"


class Game{
    
    private:
        Team home_team;
        Team out_team;
        int home_score;
        int out_score;
        bool finish_stats; // 0 for game hasn't finished, 1 for game is finished.  

    public:
        Game(Team home, Team out): 
            home_team(std::move(home)), out_team(std::move(out)), finish_stats(false),
            home_score(-1), out_score(-1){
                if(home == out){
                    throw std::invalid_argument("Same team cant play against it self.");
                }
            }
        Game(const Game &game):
            home_team(game.home_team), out_team(game.out_team), finish_stats(game.finish_stats),
            home_score(-1), out_score(-1){}
        ~Game(){}
        
        // Get Functions for The teams, return a reffrence to the team.
        Team *getHomeTeam(){return &(this->home_team);}
        Team *getOutTeam(){return &(this->out_team);}

        // Get Game Stats (Finished or Not).
        bool isFinished() const{
            if(this->finish_stats == 0){return false;}
            else{return true;}
        }
        
        // Getters for Scores;
        int getHomeScore() const{
            return this->home_score;
        }
        int getOutScore() const{
            return this->out_score;
        }

        /**
         * @brief function for creating a match and  get a winner of the match,
         *        The Function will get to Random numbers in [0,1], divide them by 3, and add them to the teams rate. 
         *        So the team with the higher Rate will have an adventage, But still can lose.
         * @return int - 0 if the Home team won, 1 if the Out team has lost.
         */
        int winner();

        // Copy Assignment Operator.
        Game & operator=(const Game &other_game){
            this->home_team = other_game.home_team;
            this->out_team = other_game.out_team;
            this->finish_stats =other_game.finish_stats;
            this->home_score = other_game.home_score;
            this->out_score = other_game.out_score;
            return *this;
        }
        
        // Move Constructor.
        Game (Game &&) = default;	
        
        // Move assignment Operator.
        Game& operator=(Game&& other) = default;

        //Overloading the << Operator for Game.
        friend std::ostream& operator<<(std::ostream& _os, Game& game){
            if(! game.finish_stats){
                _os << game.home_team.getName() << " vs " << game.out_team.getName() << " Hasn't Finished !";    
            }else{
                _os << game.home_team.getName() << " vs " << game.out_team.getName() << " :\n";
                _os << "    Game stats:\n" << "        ";
                _os<< game.getHomeTeam()->getName()<<": "<< game.home_score <<" | "<< game.getOutTeam()->getName() << ": "<<game.out_score <<std::endl;
                if(game.home_score >= game.out_score){
                    _os << "        " << game.getHomeTeam()->getName() << " Won !";
                }else{
                    _os << "        " << game.getOutTeam()->getName() << " Won !";
                }

            }
            return _os;
        }
};