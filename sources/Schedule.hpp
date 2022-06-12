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

/**
 * @brief Schedule class for run the leauge, set the matches and print result and satistics.
 * It has a pointer to a Leauge Object, two arrays (vectors) for seting matches, and Rounds counter.
 */
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

        /**
         * @brief Ordering the next matches in the Leauge,
         * Follows the 'Round-robin tournament' (https://en.wikipedia.org/wiki/Round-robin_tournament).
         * after each round, this function will be called and set up the matches for the next round.
         */
        void next_game_reorder();

        /**
         * @brief Get the current Round number
         * 
         * @return int - The Current Round.
         */
        int getRound() const {return this->Round;}

        friend std::ostream& operator<<(std::ostream& _os, Schedule& sch);
};