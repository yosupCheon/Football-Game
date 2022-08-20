#include "Simulation.h"
#include <iostream>

using namespace std;

Simulation::Simulation(){
    allTeams = new Team [maxTeam];
}


Simulation::Simulation(Team home, Team away){
    // this is a game loop
    gameState = true;
    while (gameState) {
        gameState = false; // game over
    }

    // need game gui (print statement for now)
    // timestamp
    // 4 TIMESTAMPS
    this->gameGUI(0);
    this->gameLogic(home, away);
    for (int i = 0; i < 4; i++) {
        this->gameGUI(this->timeLine[i]);
        this->gameLogic(home, away);
    }
    this->gameGUI(90);
}


/////////////////////
/////////////////////
/////////////////////
// assume home is a user
void Simulation::gameGUI (int timeStamp) {
    cout << "TIME: " << timeStamp << " MIN" << endl;
    cout << "Home " << homeScore <<"  AWAY " << awayScore << endl;

    if (timeStamp == 90) {
        if (currWinner == 0){cout << "You Won!!!" << endl; }
        else if (currWinner == 1){cout << "You Lose..." << endl; }
        else if (currWinner == 2){cout << "DRAW" << endl; }
        cout << endl;
    }
    else {
        cout << "TEAM MANAGEMENT" << endl;
        cout << "1. DEFENSIVE" << endl;
        cout << "2. BALANCE" << endl;
        cout << "3. OFFENSIVE" << endl;
        cout << "ENTER YOUR TACTIC! (in keyboard 1, 2, or 3): ";
        cin >> tactic;
        cout << endl;
    }
}
/////////////////////
/////////////////////
/////////////////////


/////////////////////
/////////////////////
/////////////////////
// assume a user is always home
void Simulation::gameLogic (Team & home, Team & away) {
    // BASED ON TACTIC, IMPACT ON THE TEAM ABILITY
    if (tactic == '1') { // DEFENSIVE
        home.overAllSetter(3);
    }
    else if (tactic == '2') { //BALANCE
        home.overAllSetter(1);
    }
    else if (tactic == '3') { //OFFENSIVE
        home.overAllSetter(5);
    }
    else {
        cout << "NO VALID TACTIC INPUT" << endl;
    }

    // BASE ON OVERALL WHO SCORE
    if (home.overAllGetter() >= away.overAllGetter()){ //HOME SCORES
        homeScore++;
    }
    else {//AWAY SCORES
        awayScore++;
    }


    // RETURN BASED ON TACTIC
    if (tactic == '1') { // DEFENSIVE
        home.overAllSetter(-3);
    }
    else if (tactic == '2') { //BALANCE
        home.overAllSetter(-1);
    }
    else if (tactic == '3') { //OFFENSIVE
        home.overAllSetter(-8);
    }

    // currently who is winning
    if (homeScore > awayScore){currWinner = 0;}
    else if (homeScore < awayScore){currWinner = 1;}
    else if (homeScore == awayScore){currWinner = 2;}
}
/////////////////////
/////////////////////
/////////////////////


char Simulation::startFunction (){
    char start;
    cout << "Game Started" << endl;
    cout << "Option 1. Play" << endl;
    cout << "Option 2. Create a Player" << endl;
    cout << "Option 3. Create a Team" << endl;
    cout << "Option q. Quit Game" << endl;
    cout << "Enter user option (in keyboard 1, 2, 3, or q): ";
    cin >> start;
    return start;
}

void Simulation::addTeam (Team& tm) {
    allTeams[teamNum] = tm;
    teamNum++;
}

void Simulation::teamAllGetter () {
    for (int i = 0; i < teamNum; i++){
        cout << allTeams[i].nameGetter() << endl;
    }
}

Team Simulation::chosenTeam (string tm) {
    Team ret;
    for (int i = 0; i < teamNum; i++){
        if (tm == allTeams[i].nameGetter()) {
            cout << "Your Team is = ";
            cout << allTeams[i].nameGetter() << endl;
            ret = allTeams[i];
            break;
        }
    }
    return ret;
}