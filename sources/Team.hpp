#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <array>

// Settingup const numbers (As the Format tidy suggests).
constexpr int FORTY = 40;
constexpr int ONE_HUNDRED_AND_ONE = 101;
constexpr int HUNDRED = 100;
constexpr int FIFTY = 50;
constexpr int FIFTY_FIVE = 55;
constexpr double HALF = 0.5;
constexpr double A_THIRD = 0.33;



// CONSIDER USE ENUM
/**
 * @brief List of 40 Teams Names For Random Team Constractor
 */
std::array<std::string,40> const team_names = {"Boston Celtics","Brooklyn Nets","New York Knicks","Philadelphia 76ers","Toronto Raptors","Chicago Bulls",
                            "Cleveland Cavaliers","Detroit Pistons","Indiana Pacers","Milwaukee Bucks","Atlanta Hawks","Charlotte Hornets","Miami Heat","Orlando Magic"
                            ,"Washington Wizards","Denver Nuggets","Minnesota Timberwolves","Oklahoma City Thunder","Portland Trail Blazers","Utah Jazz"
                            ,"Golden State Warriors","LA Clippers","Los Angeles Lakers","Phoenix Suns","Sacramento Kings","Dallas Mavericks","Houston Rockets"
                            ,"Memphis Grizzlies","New Orleans Pelicans","San Antonio Spurs","FC Barcelona","Anadolu Efes","Real Madrid","Olimpia Milano"
                            ,"Olympiacos","CSKA Moscow","Bayern Munich","Maccabi Tel Aviv","Fenerbahçe","Baskonia"};

/**
 * @brief Function for getting random team index. 
 * @return int - random index number [0,39]. 
 */
int random_team_index();

/**
 * @brief Function for getting random team rate. 
 * @return double - random index rate [0,1]. 
 */
double random_team_rate();


/**
 * @brief This class Represent Basketball Team.
 * each team have a name (as String), and rate (as double, the rate is a number belonging to the group [0,1]).
 */
class Team{
    private:
        std::string name;
        double rate;
        int ID; // The Index of the team in the team name array, if it is not in the array it is -1;
    
    public:
        /**
         * @brief Defult Constructor For Team object,
         *        Creating New Random Team with a Random Rate: Using 'random_team_rate()' and 'random_team_index()'.
         */
        Team(): rate(random_team_rate()) {
            size_t index = (size_t) random_team_index();
            this->name = team_names.at(index);
            this->ID = (int) index;
        }
        // Argumented Constractor.
        Team(std::string Name, double Rate): name(std::move(Name)), ID(-1){
            if(rate > 1 || rate < 0){
                throw std::invalid_argument("Rate Must Be In Range [0,1]!.");
            }
            this->rate = Rate;
        }
        // Copy Constractor.
        Team(const Team &other_team): 
            name(std::move(other_team.getName())), rate(other_team.getRate()),ID(other_team.getID()){}
        // Destructor For Team Object.
        ~Team(){}
        
        // Getters For Team Arguments: name, rate and id.
        std::string getName() const {return this->name;}
        double getRate() const {return this->rate;}
        int getID() const {return this->ID;}

        // Copy Assignment Operator.
        Team & operator=(const Team &other_team){
            this->name = other_team.getName();
            this->rate = other_team.getRate();
            this->ID = other_team.getID();
            return *this;
        }
        
        // Move Constructor.
        Team (Team &&) = default;	
        
        // Move assignment Operator.
        Team& operator=(Team&& other) = default;
        
        friend bool operator==(const Team &team1, const Team &team2);

        //Overloading the << Operator for Team.
        friend std::ostream& operator<<(std::ostream& _os, Team& team){
            _os << "Name: "<< team.getName() << ", Rate: " << team.getRate();
            return _os;
        }
};