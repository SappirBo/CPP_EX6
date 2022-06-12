#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"


class Game{
    
    private:
        Team *home_team;
        Team *out_team;
        int home_score;
        int out_score;
        bool finish_stats; // 0 for game hasn't finished, 1 for game is finished.  

    public:
        Game();
        Game(Team *home, Team *out);
        Game(const Game &game);
        ~Game(){}
        
        // Get Functions for The teams, return a reffrence to the team.
        Team *getHomeTeam(){return (this->home_team);}
        Team *getOutTeam(){return (this->out_team);}

        void setHomeTeam(Team *h_team);
        void setOutTeam(Team *o_team);

        // Get Game Stats (Finished or Not).
        bool isFinished()  const{return this->finish_stats;}
        
        // Getters for Scores;
        int getHomeScore() const{return this->home_score;}
        int getOutScore()  const{return this->out_score ;}

        /**
         * @brief function for creating a match and  get a winner of the match,
         *        The Function will get to Random numbers in [0,1], divide them by 3, and add them to the teams rate. 
         *        So the team with the higher Rate will have an adventage, But still can lose.
         * @return int - 0 if the Home team won, 1 if the Out team has lost.
         */
        int winner();

        /**
         * @brief Function for clearing the game data -> for reusing this game object.
         */
        void clear();

        // Copy Assignment Operator.
        Game & operator=(const Game &other_game){
            Game tmp_g(other_game);
            this->home_team = tmp_g.getHomeTeam();
            this->out_team = tmp_g.getOutTeam();
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
                _os << game.home_team->getName() << " vs " << game.out_team->getName() << " Hasn't Finished !";    
            }else{
                _os << game.home_team->getName() << " vs " << game.out_team->getName() << " :\n";
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