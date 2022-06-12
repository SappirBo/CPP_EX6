#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "sources/Team.hpp"
#include "sources/Game.hpp"
#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"

using namespace std;

int main(){
    cout << "\n-----------------------------------------------------------------------   leauge1  -----------------------------------------------------------------------\n";
    /*
    First we will Create 7 Teams and put them in Vector, then we will create a new Leauge using this Vector (Expecting the Constractor will fill the
    missing Teams in the Leauge (13 more Team). then we will create a Schedule for this leauge, 4 Rounds, And print the current leauge stats. 
    */
    Team team1("Team 1",0.83);
    Team team2("Team 2",0.22);
    Team team3("Team 3",0.45);
    Team team4("Team 4",0.47);
    Team team5("Team 5",0.59);
    Team team6("Team 6",0.81);
    Team team7("Team 7",0.15);

    vector<Team> sevenVec = {team1,team2,team3,team4,team5,team6,team7};

    Leauge leauge1(&sevenVec);

    Schedule sch1(&leauge1);
    
    int i = 0;
    // Run 5 Rounds.
    while(i < 5){
        sch1.runRound();
        i++;
    }
    cout << sch1 << endl;
    // Run more 5 Rounds (to Round 10).
    while(i < 10){
        sch1.runRound();
        i++;
    }
    cout << sch1 << endl;
    // Run more 10 Rounds (to Round 20).
    while(i < 20){
        sch1.runRound();
        i++;
    }
    cout << sch1 << endl;

    // Finish the Schedule.
    sch1.runSeason();
    cout << sch1 << endl;

    cout << "\n-----------------------------------------------------------------------   leauge2  -----------------------------------------------------------------------\n";
    /*
    Now we will create a random Leauge, using the default Leauge Constructor.
    We will also create a Schedule for this leauge and print the details.  
    */
    Leauge leauge2;
    Schedule sch2(&leauge2);
    sch2.runRound();
    cout << sch2 << endl;

    for(int i=1; i<32;i++){
        sch2.runRound();
    }
    cout << sch2 << endl;

    sch2.runSeason();

    cout << sch2 << endl;
    


    return -1;
}