#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <array>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

class Schedule{
    private:
        Leauge *leauge_ptr;
        int Round; // Round is int in range [0,40] (where 0 means the Schedule hasn't done).
        std::array<size_t,TEN> home_list;
        std::array<size_t,TEN>  out_list;

    public:
        Schedule(Leauge *pleauge);

        /**
         * @brief this function will run only ONE Round of games (One Game for each Team).
         */
        void runRound();
        /**
         * @brief this function will run a An Entire Season of games (38 game for each Team, 38 Rounds).
         *        THis function will start from the point this Schedule Round is.
         */
        void runSeason();

        friend std::ostream& operator<<(std::ostream& _os, Schedule& sch);
};