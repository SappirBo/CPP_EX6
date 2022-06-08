#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <queue>

/**
 * @brief List of 40 Teams Names For Random Team Constractor
 */
std::string team_names[] = {"Boston Celtics","Brooklyn Nets","New York Knicks","Philadelphia 76ers","Toronto Raptors","Chicago Bulls",
                            "Cleveland Cavaliers","Detroit Pistons","Indiana Pacers","Milwaukee Bucks","Atlanta Hawks","Charlotte Hornets","Miami Heat","Orlando Magic"
                            ,"Washington Wizards","Denver Nuggets","Minnesota Timberwolves","Oklahoma City Thunder","Portland Trail Blazers","Utah Jazz"
                            ,"Golden State Warriors","LA Clippers","Los Angeles Lakers","Phoenix Suns","Sacramento Kings","Dallas Mavericks","Houston Rockets"
                            ,"Memphis Grizzlies","New Orleans Pelicans","San Antonio Spurs","FC Barcelona","Anadolu Efes","Real Madrid","Olimpia Milano"
                            ,"Olympiacos","CSKA Moscow","Bayern Munich","Maccabi Tel Aviv","Fenerbahçe","Baskonia"};

/**
 * @brief Function for getting random team index. 
 * @return int - random index number [0,39]. 
 */
int random_team_index(){
    // srand(time(0));
    return (rand()%40) ;
}

/**
 * @brief Function for getting random team rate. 
 * @return double - random index rate [0,1]. 
 */
double random_team_rate(){
    // srand(time(0));
    double num = rand()%101;
    num = num/100;
    return num;
}


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
    Team(){
        int index = random_team_index();
        this->name = team_names[index];
        this->ID = index;
        this->rate = random_team_rate();
    }
    Team(std::string Name, double Rate){
        this->name = Name;
        this->rate = Rate;
        this->ID = -1;
    }
    
    std::string getName(){
        return this->name;
    }
    
    double getRate(){
        return this->rate;
    }

    friend std::ostream& operator<<(std::ostream& os, Team& T){
        os << "Name: "<< T.getName() << ", Rate: " << T.getRate();
        return os;
    }

};