#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

using namespace std;

int main(){
    // Test for argumented constractor.
    Team a("Team A",0.5);
    Team b("Team B",0.33);
    cout << a << endl << b << endl;
    
    Team c;
    Team d;
    cout << c << endl << d << endl;
    
    // Create Game A vs B
    Game game1(&a,&b);
    int i = game1.winner();
    cout << i << endl;
    // Create Game C vs D
    Game game2(&c,&d);
    i = game2.winner();
    cout << i << endl;
    // Create Game A vs C
    Game game3(&c,&c);
    i = game3.winner();
    cout << i << endl;

    // Create Leauge
    Leauge l;

    cout << l << endl;

    return -1;
}