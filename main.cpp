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
    Leauge leauge1;

    Schedule sch(&leauge1);
    for(int i=0;i<40;i++){
        sch.runRound();
    }
    cout << sch << endl;

    // for(int i=0;i<20;i++){
    //     sch.runRound();
    // }
    // cout << sch << endl;

    return -1;
}