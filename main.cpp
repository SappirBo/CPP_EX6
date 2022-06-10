#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "sources/Team.hpp"
#include "sources/Game.hpp"
// #include "Leauge.hpp"

using namespace std;

int main(){
    // Test for argumented constractor.
    Team team_a("Team A",HALF);
    Team team_b("Team B",A_THIRD);
    cout << team_a << endl << team_b << endl;
    
    Team team_c;
    Team team_d;
    cout << team_c << endl << team_d << endl;
    
    // Create Game A vs B
    Game game1(team_a,team_b);
    game1.winner();
    cout << game1 << endl;
    // Create Game C vs D
    Game game2(team_c,team_d);
    game2.winner();
    cout << game2 << endl;
    // Create Game A vs C
    Game game3(team_c,team_c);
    game3.winner();
    cout << game3 << endl;

    // // Create Leauge and Print the result.
    // Leauge l;
    // cout << l << endl;

    // // Create Leauge With half vector and Print the result.
    // Team a1("a1",0.5);
    // Team a2("a2",0.5);
    // Team a3("a3",0.5);
    // Team a4("a4",0.5);
    // Team a5("a5",0.5);
    // Team a6("a6",0.5);
    // Team a7("a7",0.5);
    // Team a8("a8",0.5);
    // Team a9("a9",0.5);
    // Team a10("a10",0.5);

    // vector<Team> tenTeamVec = {a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};
    // Leauge halfVec(&tenTeamVec);
    // cout << halfVec << endl;

    // // Create Leauge With full vector and Print the result.
    // Team a11("a11",0.5);
    // Team a12("a12",0.5);
    // Team a13("a13",0.5);
    // Team a14("a14",0.5);
    // Team a15("a15",0.5);
    // Team a16("a16",0.5);
    // Team a17("a17",0.5);
    // Team a18("a18",0.5);
    // Team a19("a19",0.5);
    // Team a20("a20",0.5);
    // vector<Team> fullTeamVec = {a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20};
    // Leauge fullVec(&fullTeamVec);
    // cout << fullVec << endl;


    return -1;
}