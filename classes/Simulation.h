#pragma once

#include "Team.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

class Simulation {
public: 
    Simulation();
    Simulation(Team& home, Team& away);
    
    char startFunction (); // ASKS FOR A USER INPUT OPTION
    void gameLoop(Team home, Team away);

    bool gameState = false;
    int timeLine [5] = {25, 45, 60, 70, 85};
    int homeScore = 0;
    int awayScore = 0;
    //char tactic = 0;
    int currWinner = 2;

    //Gui drawPage;

    void gameGUI (int timeStamp);

    // this functions need for gmae input
    Player* highestPlayer (Team & userTeam, string position, string toPosition);
    void updateToDefence(Team* userTeam);
    void updateToBalance(Team* userTeam);
    void updateToOffence(Team* userTeam);
    void gameInput (Team* userTeam, int tactic);

    bool competition (int userStat, int oppoStat);

    void opponentFormation (Team* away);
    void gameLogic (Team & userTeam, Team & oppoTeam);

private:
};