#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Team.hpp"

using namespace std;

int main(){
    // Test for argumented constractor.
    Team a("Team A",0.5);
    Team b("Team B",0.33);

    cout << a << endl << b << endl;
    
    Team c;
    Team d;
    cout << c << endl << d << endl;
    
    return -1;
}