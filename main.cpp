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
    // // Test for argumented constractor.
    // Team team_a("Team A",HALF);
    // Team team_b("Team B",A_THIRD);
    // cout << team_a << endl << team_b << endl;
    
    // Team team_c;
    // Team team_d;
    // cout << team_c << endl << team_d << endl;
    
    // // Create Game A vs B
    // Game game1(&team_a,&team_b);
    // game1.winner();
    // cout << game1 << endl;
    // // Create Game C vs D
    // Game game2(&team_c,&team_d);
    // game2.winner();
    // cout << game2 << endl;
    // // Create Game A vs C
    // Game game3(&team_c,&team_a);
    // game3.winner();
    // cout << game3 << endl;

    // // Create Leauge and Print the result.
    // Leauge l;
    // cout << l << endl;

    // // Create Leauge With half vector and Print the result.
    // Team team_a1("a1",HALF);
    // Team team_a2("a2",HALF);
    // Team team_a3("a3",HALF);
    // Team team_a4("a4",HALF);
    // Team team_a5("a5",HALF);
    // Team team_a6("a6",HALF);
    // Team team_a7("a7",HALF);
    // Team team_a8("a8",HALF);
    // Team team_a9("a9",HALF);
    // Team team_a10("a10",HALF);

    // vector<Team> tenTeamVec = {team_a1,team_a2,team_a3,team_a4,team_a5,team_a6,team_a7,team_a8,team_a9,team_a10};
    // Leauge halfVec(&tenTeamVec);
    // cout << halfVec << endl;

    // // Create Leauge With full vector and Print the result.
    // Team team_a11("a11",HALF);
    // Team team_a12("a12",HALF);
    // Team team_a13("a13",HALF);
    // Team team_a14("a14",HALF);
    // Team team_a15("a15",HALF);
    // Team team_a16("a16",HALF);
    // Team team_a17("a17",HALF);
    // Team team_a18("a18",HALF);
    // Team team_a19("a19",HALF);
    // Team team_a20("a20",HALF);
    // vector<Team> fullTeamVec = {team_a1,team_a2,team_a3,team_a4,team_a5,team_a6,team_a7,team_a8,team_a9,team_a10,
    //                             team_a11,team_a12,team_a13,team_a14,team_a15,team_a16,team_a17,team_a18,team_a19,team_a20};
    // Leauge fullVec(&fullTeamVec);
    // cout << fullVec << endl;

    Leauge leauge1;

    Schedule sch(&leauge1);
    for(int i=0;i<20;i++){
        sch.runRound();
    }
    cout << sch << endl;

    for(int i=0;i<20;i++){
        sch.runRound();
    }
    cout << sch << endl;

    return -1;
}