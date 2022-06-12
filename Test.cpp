#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "sources/Team.hpp"
#include "sources/Game.hpp"
#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"
// Since I use Clang 14, the old version of docktest doesnt compile so 
// I have the newest docktest addition, and the one from the task renamed: 'docktest_old.h'.
#include "doctest.h" 

using namespace std;

TEST_CASE("Class Team"){
    cout << "----- ----- ----- Test 1 ----- ----- -----\n";
    // Test for invalid argument
    CHECK_NOTHROW(Team team("test",0.2););
    // CHECK_THROWS(Team team("test",-0.2););
    // CHECK_THROWS(Team team("test",11););
    // CHECK_THROWS(Team team("test",-13););

    // Test for argumented constractor.
    Team team_a("Team A",0.5);
    Team team_b("Team B",0.33);

    CHECK_EQ(team_a.getName(),"Team A");
    CHECK_EQ(team_a.getRate(),0.5);
    CHECK_EQ(team_b.getName(),"Team B");
    CHECK_EQ(team_b.getRate(),0.33);

    // Test for Defult Constractor.
    Team team_c;
    Team team_d;
    // Checking that random rate is between 0 to 1;
    CHECK_FALSE(!(team_c.getRate() <= 1 && team_c.getRate() >= 0));
    CHECK_FALSE(!(team_d.getRate() <= 1 && team_d.getRate() >= 0));
    // Check that the ID between 0 to 39;
    CHECK_FALSE(!(team_c.getID() > -1 && team_c.getID() < 40));
    CHECK_FALSE(!(team_d.getID() > -1 && team_d.getID() < 40));

}

TEST_CASE("Class Game"){
    cout << "----- ----- ----- Test 2 ----- ----- -----\n";
    Team team_a("team A",0.66);
    Team team_b("team B", 0.33);
    // Check Argument Constractors
    CHECK_NOTHROW(Game nothrow_game(&team_a,&team_b););
    // CHECK_THROWS(Game nothrow_game(&team_a,&team_a););
    Game game(&team_a,&team_b);

    // CHECK if the Game id finished (expectin gto get false).
    CHECK_FALSE(game.isFinished());
    
    //CHeck Winner Function.
    int winner = game.winner();
    CHECK_FALSE(!(winner==1 || winner==0));

    // Checking if the winner number that the function returned realy is the winner (couse it random it is splited to cases).
    if(winner == 0){
        CHECK_FALSE(!(game.getHomeScore() >= game.getOutScore()));
    }else{
        CHECK_FALSE(!(game.getHomeScore() < game.getOutScore()));
    }

    // CHECK if the Game id finished (expectin gto get true).
    CHECK_FALSE(!game.isFinished());
    
}

TEST_CASE("Class Leauge"){
    cout << "----- ----- ----- Test 3 ----- ----- -----\n";
    //Create Leauge with defualt constractor.
    Leauge first;
    // Expecting this Leauge size will be 20;
    CHECK_EQ(first.size(), 20);


    // Create Leauge With half vector.
    Team team_a1("a1",HALF);
    Team team_a2("a2",HALF);
    Team team_a3("a3",HALF);
    Team team_a4("a4",HALF);
    Team team_a5("a5",HALF);
    Team team_a6("a6",HALF);
    Team team_a7("a7",HALF);

    vector<Team> sevenTeamVec = {team_a1,team_a2,team_a3,team_a4,team_a5,team_a6,team_a7};
    Leauge halfVec(&sevenTeamVec);
    /**
     *  Now the 'halfVec' Leauge was initialized with 7 teams vector, means the constractor need to fix it and 
     * add 13 more to make a 20 Teams Leauge. So halfVec size need to still be 20.
     *  Also we will Check if the first 7 teams in the leauge is the same 7 teams we created.
     */

    CHECK_EQ(halfVec.size(),20);
    size_t index = 0;
    for(; index<sevenTeamVec.size(); index++){
        CHECK_EQ(halfVec.getTeams_vec()->at(index), sevenTeamVec.at(index));
    }

    // Create Leauge With full vector and Print the result.
    Team team_a8("a8",HALF);
    Team team_a9("a9",HALF);
    Team team_a10("a10",HALF);
    Team team_a11("a11",HALF);
    Team team_a12("a12",HALF);
    Team team_a13("a13",HALF);
    Team team_a14("a14",HALF);
    Team team_a15("a15",HALF);
    Team team_a16("a16",HALF);
    Team team_a17("a17",HALF);
    Team team_a18("a18",HALF);
    Team team_a19("a19",HALF);
    Team team_a20("a20",HALF);

    vector<Team> fullTeamVec = {team_a1,team_a2,team_a3,team_a4,team_a5,team_a6,team_a7,team_a8,team_a9,team_a10,
                                team_a11,team_a12,team_a13,team_a14,team_a15,team_a16,team_a17,team_a18,team_a19,team_a20};
    Leauge fullVec(&fullTeamVec);
    
    /**
     * Now the 'fullVec' Leauge was initialized with exacly 20 teams vector.
     * we will Check if the 20 teams in the leauge is the same 20 teams we created.
     */
    CHECK_EQ(fullVec.size(),20);
    index = 0;
    for(; index<fullTeamVec.size(); index++){
        CHECK_EQ(fullVec.getTeams_vec()->at(index), fullTeamVec.at(index));
    }

    // Check for vector bigger than 20;
    Team team_a21("a21",HALF);
    fullTeamVec.push_back(team_a21);
    
    // // Check That throw exeption.
    // CHECK_THROWS(Leauge leage(&fullTeamVec););

}

TEST_CASE("Class Schedule "){
    cout << "----- ----- ----- Test 4 ----- ----- -----\n";

    // Checking the Schedule Constractor.
    Leauge test_leauge;
    CHECK_NOTHROW(Schedule sch(&test_leauge));

    Schedule sch(&test_leauge);
    // Checking runRound Function
    for(int i=0; i<MAX_LEAUGE; i++){
        CHECK_NOTHROW(sch.runRound(););
    }
    // Check if we are now at round 20
    CHECK_EQ(20,sch.getRound());

    // Check the runSeason function.
    sch.runSeason();
    CHECK_EQ(40,sch.getRound());
}

TEST_CASE("Full Leauge Season"){
    cout << "----- ----- ----- Test 5 ----- ----- -----\n";
    // Create Leauge and Schedule.
    Leauge test_leauge;
    Schedule sch(&test_leauge);

    // Run 10 Rounds.
    int index =0;
    for(;index<TEN;index++){
        sch.runRound();
    }
    // Check if this leauge Round Changed.
    CHECK_EQ(10,test_leauge.getRound());
}