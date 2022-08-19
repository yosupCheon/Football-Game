#pragma once

#include "Team.h"

#include <iostream>
#include <string>

using namespace std;

class Simulation {
public:
    Team* allTeams;
    int maxTeam = 10;
    int teamNum = 0;
    
    Simulation();
    Simulation(Team home, Team away);
    char startFunction (); // ASKS FOR A USER INPUT OPTION

    void addTeam (Team& tm); //CREATES A TEAM(?)
    void teamAllGetter ();

    Team chosenTeam (string tm);

private:
    bool gameState;
    int timeLine [4] = {25, 45, 70, 80};
    int homeScore = 0;
    int awayScore = 0;
    char tactic;
    int currWinner = 2;

    void gameGUI (int timeStamp);
    void gameLogic (Team & home, Team & away);

};