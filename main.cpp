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

    sch.runSeason();

    cout << sch << endl;

    return -1;
}