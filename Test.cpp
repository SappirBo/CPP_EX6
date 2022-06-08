#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "sources/Team.h"
#include "doctest.h"

using namespace std;

TEST_CASE("Class Team"){
    // Test for argumented constractor.
    Team a("Team A",0.5);
    Team b("Team B",0.33);

    CHECK_EQ(a.getName(),"Team A");
    CHECK_EQ(a.getRate(),0.5);
    CHECK_EQ(b.getName(),"Team B");
    CHECK_EQ(b.getRate(),0.33);

    cout << a << endl << b << endl;
}