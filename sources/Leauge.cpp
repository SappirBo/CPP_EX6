#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"

using namespace std;

// *** *** *** *** Helpers *** *** *** ***
// Basic Contain Helper.
int contain(int arr[],int num, int size){
    int i;
    for(i=0; i<size; i++){
        if(arr[i] == num){return 1;}
    }
    return 0;
}

// Basic Swap Helper.
void swap(vector<size_t> *arr, size_t i, size_t j){
    size_t tmp = arr->at(i);
    arr->at(i) = arr->at(j);
    arr->at(j) = tmp;
}

// ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** 

// Defualt Constractor.    
Leauge::Leauge():Round(0){
    int ids[20];
    size_t i;
    for(i=0; i<20; i++){
        ids[i] = -1;
    }
    i=0;
    while(this->team_list.size() != 20 && this->team_list.size()<21){
        Team tmp;
        if(!contain(ids,tmp.getID(),20)){
            ids[i] = tmp.getID();
            this->team_list.push_back(tmp);
        }
    }
}

// Argumented Constractor.
Leauge::Leauge(vector<Team> const *teams):Round(0){
    // Check if the given Vector is larger then 20.
    if(teams->size() > 20){
        throw invalid_argument("Team List Must Be Equal or smaller then 20!");
    }
    // If the team vector is exacly 20
    if(teams->size() == 20){
        size_t i;
        for(i=0; i<20; i++){
            this->team_list.push_back(teams->at(i));
        }
    }
    // If we Missing some Teams in are vector, we add the missing teams.
    else{
        int missing = 20 - teams->size();
        // Push the teams we already got.
        size_t i;
        for(i=0; i<teams->size(); i++){
            this->team_list.push_back(teams->at(i));
        }
        // add the remain,
        int ids[missing];
        for(i=0; i<missing; i++){
            ids[i] = -1;
        }
        i=0;
        while(this->team_list.size() != MAX_LEAUGE){
            Team tmp;
            if(!contain(ids,tmp.getID(),missing)){
                ids[i] = tmp.getID();
                this->team_list.push_back(tmp);
                i++;
            }
        }
    }
}

// Copy Constractor.
Leauge::Leauge(const Leauge &leauge):
            team_list(leauge.team_list), Round(leauge.Round){}


// Copy Assignment Operator.
Leauge & Leauge::operator=(const Leauge &other_Leauge){
    size_t index = 0;
    for(;index < MAX_LEAUGE; index++){
        this->team_list.push_back(other_Leauge.team_list.at(index));
    }
    return *this;
}

/**
 * @brief This is sorting function as Helper for the Get Stats.
 * This function will sort the teams by the amount of points they have, and if two teams have exacly the same score 
 * it will sort them by the earned score they gained.
 * 
 * @return vector<size_t> = vector of the INDEXS of the sorted list. 
 *                          For Example: if New York Knicks is number 1 in the ranking, but on the Leauge Vector it's index is 15,
 *                                       the returned Vector will have 15 in the 0 (first) index. AKA: ans.at(0) = 15;
 * 
 * The Time Complexity of this function is O(1), since we have constant Vector size (20 elements). 
 */
vector<size_t> Leauge::getSortedIndexVector(){
    vector<size_t> ans = {0,1,2,3,4,5,6,7,8,9,
                            10,11,12,13,14,15,16,17,18,19};
    size_t i,j;
    for(i=0; i<MAX_LEAUGE-1; i++){
        for(j=i; j<MAX_LEAUGE; j++){
            if(i != j){
                if(this->getTeams_vec()->at(ans.at(i)).getPoints() < this->getTeams_vec()->at(ans.at(j)).getPoints()){
                    swap(&ans,i,j);
                }else if(this->getTeams_vec()->at(ans.at(i)).getPoints() == this->getTeams_vec()->at(ans.at(j)).getPoints()){
                    if(this->getTeams_vec()->at(ans.at(i)).getErned_Score() < this->getTeams_vec()->at(ans.at(j)).getErned_Score()){
                        swap(&ans,i,j);
                    }
                }
            }
        }
    }
    return ans;
}

/**
 * @brief this is a function for getting this leauge stats at this point (in this round).
 * for each team it returns:
 *                          1. current rank
 *                          2. Win / Lose  
 *                          3. Goal Ratio (score this team had divide by the amount they could do (round*110)).
 *                          4. Scores (Amount of total scores they have).
 *                          5. Success rate (the amount of points divide by the rounds (wins/all games)).           
 *                          6. Var (Diffrence between the teams rate to the Goal Ratio).
 *                          7. Average Score per Game.
 * @return std::string 
 */
std::string Leauge::getStats(){
    string ans = "";
    double num = 0;
    vector<size_t> indexs = getSortedIndexVector();
    for(size_t i=0; i<MAX_LEAUGE; i++){
        // Set Team number and Name.
        string s = "";
        s += to_string(i+1);
        s += ". ";
        s += this->getTeams_vec()->at(indexs.at(i)).getName();
        while(s.size() < 26){
            s += " ";
        }
        ans += s;
        s.clear();
        
        // Set Teams Wins and loses. 
        s += "| Won: ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getPoints() );
        while(s.size() < TEN+1){
            s += " ";
        }
        ans += s;
        s.clear();
        s += "| Lose: ";
        s += to_string(this->Round - this->getTeams_vec()->at(indexs.at(i)).getPoints() );
        while(s.size() < TEN+2){
            s += " ";
        }
        ans += s;
        s.clear();

        // Setting Score Ratio (Amount of score the team have / Amount of Gouls the Team could achived).
        s += "| Goal Ratio: ";
        s += "(";
        num = (double) this->getTeams_vec()->at(indexs.at(i)).getErned_Score() / (this->Round*110);
        s += to_string((int)(num*HUNDRED));
        s += "%)";
        while(s.size() < TEN-1){
            s += " ";
        }
        ans += s;
        s.clear();

        // Setting Erned vd Absorved Scores.
        s += "| Scores: ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getErned_Score());
        while(s.size() < TEN+3){
            s += " ";
        }
        ans+=s;
        s.clear();
        s += "/ ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getAbsorbed_Score());
        while(s.size() < 6){
            s += " ";
        }
        ans += s;
        s.clear();

        // Addind Success rate of wins / amount of games. 
        s += " | Success rate: ";
        ans += s;
        s.clear();
        num = (double)(this->getTeams_vec()->at(indexs.at(i)).getPoints()) / this->Round;
        s += to_string((int) (num*HUNDRED));
        s += "%";
        while(s.size() < 4){
            s += " ";
        }
        ans += s;
        s.clear();

        // Adding Var of the success rate in the real world than the rate this Team has.
        s += "| Var : ";
        num = (double) this->getTeams_vec()->at(indexs.at(i)).getErned_Score() / (this->Round*110);
        num = num/100;
        num = (num / (double) this->getTeams_vec()->at(indexs.at(i)).getRate());
        num *= 100000;
        num = num / 1000;
        s += to_string(num);
        size_t index = s.size();
        while(index > 13){
            s.erase(index);
            index--;
        }
        ans += s ;
        s.clear();
        s += "| Ave Score : ";
        s += to_string(this->getTeams_vec()->at(indexs.at(i)).getErned_Score()/this->Round);
        ans += s;

        ans += "\n"; 
    }
    return ans;
}


// string of all the wins / lose streks (active or all time).

string Leauge::active_win_streak(){
    size_t index=0;
    int max = 0;
    string data = "";
    for(;index <MAX_LEAUGE; index++){
        if(this->getTeams_vec()->at(index).getActiveWin() > max){
            max = this->getTeams_vec()->at(index).getActiveWin();
            data.clear();
            data += this->getTeams_vec()->at(index).getName();
            while(data.size() < 20){
                data += " ";
            }
            data += " [";
            data += to_string(this->getTeams_vec()->at(index).getActiveWin());
            data += "].";
        }
    }
    return data;
}
string Leauge::active_lose_streak(){
    size_t index=0;
    int max = 0;
    string data = "";
    for(;index <MAX_LEAUGE; index++){
        if(this->getTeams_vec()->at(index).getActiveLose() > max){
            data.clear();
            data += this->getTeams_vec()->at(index).getName();
            while(data.size() < 20){
                data += " ";
            }
            data += " [";
            data += to_string(this->getTeams_vec()->at(index).getActiveLose());
            data += "].";
            max = this->getTeams_vec()->at(index).getActiveLose();
        }
    }
    return data;
}
string Leauge::best_win_streak(){
    size_t index=0;
    int max = 0;
    string data = "";
    for(;index <MAX_LEAUGE; index++){
        if(this->getTeams_vec()->at(index).getMaxWin() > max){
            max = this->getTeams_vec()->at(index).getMaxWin();
            data.clear();
            data += this->getTeams_vec()->at(index).getName();
            while(data.size() < 20){
                data += " ";
            }
            data += " [";
            data += to_string(this->getTeams_vec()->at(index).getMaxWin());
            data += "].";
        }
    }
    return data;
}
string Leauge::best_lose_streak(){
    size_t index=0;
    int max = 0;
    string data = "";
    for(;index <MAX_LEAUGE; index++){
        if(this->getTeams_vec()->at(index).getMaxLose() > max){
            max = this->getTeams_vec()->at(index).getMaxLose();
            data.clear();
            data += this->getTeams_vec()->at(index).getName();
            while(data.size() < 20){
                data += " ";
            }
            data += " [";
            data += to_string(this->getTeams_vec()->at(index).getMaxLose());
            data += "].";
        }
    }
    return data;
}


