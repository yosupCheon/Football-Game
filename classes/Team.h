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
    string teamName; //change to team name
    int playersLim = 14;
    int formation[3] = {4,3,3}; //CURRENT, DEFAULT = 433

    int defSum = 0;
    int midSum = 0;
    int offendSum = 0;

    int curPlayers = 0;
    Player* head;


    Team(string name);

    void addPlayer(string plrName, string pos, int age, int gok, int def, int att);
    void delThisPlayer(string plrName);

    void updateOverall (Player* plr);
    void updatePosition (Player* plr, string toPos);

    void printPlayers ();
    
private:
};