#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Player.h"

using namespace std;

using std::string;
using std::vector;

class Team {
public:
    Team();
    Team(string name);

    string nameGetter ();
    void playersGetter ();
    int overAllGetter ();

    void addPlayer(Player plr);
    
private:
    string name;
    Player* players;
    int playersLim = 14;
    int curPlayers = 0;
    int teamOverall;

    void overAllCal (Player plr);
};