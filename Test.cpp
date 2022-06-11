#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "sources/Team.hpp"
#include "sources/Game.hpp"
// Since I use Clang 14, the old version of docktest doesnt compile so 
// I have the newest docktest addition, and the one from the task renamed: 'docktest_old.h'.
#include "doctest.h" 

using namespace std;

TEST_CASE("Class Team"){
    cout << "----- ----- ----- Test 1 ----- ----- -----\n";
    // Test for invalid argument
    CHECK_NOTHROW(Team team("test",0.2););

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
    CHECK_NOTHROW(Game nothrow_game(team_a,team_b););
    Game game(team_a,team_b);

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