#include "Simulation.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "unistd.h"
#include <stdlib.h>

using namespace std;

Simulation::Simulation(){//allTeams = new Team [maxTeam];
}

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
////////////////
////////////////
////////////////
void Simulation::gameLoop(Team home, Team away){
    // this is a game loop
    gameState = true;
    while (gameState) {
        gameState = false; // game over
    }

    // 4 TIMESTAMPS
    // first display at 0:00
    // run the game logic based on the init formation
    this->gameGUI(0);
    this->gameLogic(home, away); // 0->25
    cout << endl;
    for (int i = 0; i < 5; i++) {
        this->gameGUI(this->timeLine[i]); //25, 45, 60, 70, 85
        this->gameInput(home);
        this->gameLogic(home, away); // [26->45] [45->60] [60->70] [70->85]
    }
    this->gameGUI(90);
    
}
/////////////////////
/////////////////////
/////////////////////
// assume home is a user
void Simulation::gameGUI (int timeStamp) {
    if (timeStamp == 0) {
        homeScore = 0;
        awayScore = 0;
        cout << "Game Begin!" << endl;
        cout << endl;
    }
    cout <<"************************************************" << endl;
    cout << "TIME: " << timeStamp << " MINUTE" << endl;
    cout << "Home " << homeScore <<"  AWAY " << awayScore << endl;
    
    if (timeStamp == 90) {
        if (currWinner == 1){cout << "You Won!!!" << endl; }
        else if (currWinner == 2){cout << "DRAW" << endl; }
        else if (currWinner == 3){cout << "You Lose..." << endl; }
        cout << endl;
    }
}
/////////////////////
/////////////////////
/////////////////////
Player* Simulation::highestPlayer (Team & userTeam, string position, string toPosition){
    //find player in a certain position with its highest corresponding stat
    Player* highestPlr;
    Player* curr;
    curr = userTeam.head;
    highestPlr = userTeam.head;

    while (curr != NULL) {
        //CB->MF
        if (curr->pos.compare(position)==0 && position.compare("CB")==0){
            //cout << "compare def" << endl;
            if (!(toPosition.compare("MF"))) {
                int highestMid = (highestPlr->def + highestPlr->att)/2;
                int currMid = (curr->def + curr->att)/2;
                if (highestMid < currMid) {
                    highestPlr = curr;
                }
            }
            else {
                cout << "CB CAN ONLY MOVE TO MF" << endl;
            }
        }
        //MF->CB or MF->ST
        else if (curr->pos.compare(position)==0 && position.compare("MF")==0){
            //cout << "compare mid" << endl;
            if ( ((highestPlr->def)+(highestPlr->att))/2 < ((curr->def)+(curr->att))/2){
                highestPlr = curr;
            }

            int highestMid = (highestPlr->def + highestPlr->att)/2;
            int currMid = (curr->def + curr->att)/2;
            if (!(toPosition.compare("CB"))) {
                if (highestPlr->def < curr->def) {
                    highestPlr = curr;
                }
            }
            else {//if (!(toPosition.compare("ST"))) {
                if (highestPlr->att < curr->att) {
                    highestPlr = curr;
                }
            }

        }
        //ST->MF
        else if (curr->pos.compare(position)==0 && position.compare("ST")==0){
            //cout << "compare att" << endl;
            if (!(toPosition.compare("MF"))) {
                int highestMid = (highestPlr->def + highestPlr->att)/2;
                int currMid = (curr->def + curr->att)/2;
                if (highestMid < currMid) {
                    highestPlr = curr;
                }
            }
            else {
                cout << "ST CAN ONLY MOVE TO MF" << endl;
            }
        }
        curr = curr->next;
    }

    return highestPlr;    
}
//4-3-3(default) to 5-3-2
// 1. move midfielder to defender
// 2. move offender to midfielder 
void Simulation::updateToDefence(Team & userTeam) {
    // to default formation
    updateToBalance(userTeam);

    // change the sum of team's def, bal, off
    /*
    1. pick best defensive midfielder
    2. move to centerback
    3. pick best balanced player in offenders
    4. move to midfiled
    */
    Player* attToMid = highestPlayer(userTeam, "ST", "MF");
    userTeam.updatePosition(attToMid, "MF");
    Player* midToDef = highestPlayer(userTeam, "MF", "CB");
    userTeam.updatePosition(midToDef, "CB");

    // change the array of the formation for the team
    userTeam.formation[0] = 5;
    userTeam.formation[1] = 3;
    userTeam.formation[2] = 2;
}
//4-3-3
void Simulation::updateToBalance(Team & userTeam) {
    // CURRENT POSITION = DEFENSIVE (532)
    // move CBs->MFs
    // move MFs->STs
    if (userTeam.formation[0] == 5) {
        Player* defToMid = highestPlayer(userTeam, "CB", "MF");
        userTeam.updatePosition(defToMid, "MF");
        Player* midToAtt = highestPlayer(userTeam, "MF", "ST");
        userTeam.updatePosition(midToAtt, "ST");
    }
    // CURRENT POSITION = OFFENSIVE (344)
    // move STs -> MFs
    // move MFs -> CBs
    else if (userTeam.formation[0] == 3) {
        Player* attToMid = highestPlayer(userTeam, "ST", "MF");
        userTeam.updatePosition(attToMid, "MF");
        Player* midToDef = highestPlayer(userTeam, "MF", "CB");
        userTeam.updatePosition(midToDef, "CB");
    }


    userTeam.formation[0] = 4;
    userTeam.formation[1] = 3;
    userTeam.formation[2] = 3;
}

//3-3-4
void Simulation::updateToOffence(Team & userTeam) {
    updateToBalance(userTeam);
    Player* defToMid = highestPlayer(userTeam, "CB", "MF");
    userTeam.updatePosition(defToMid, "MF");
    Player* midToAtt = highestPlayer(userTeam, "MF", "ST");
    userTeam.updatePosition(midToAtt, "ST");
    userTeam.formation[0] = 3;
    userTeam.formation[1] = 3;
    userTeam.formation[2] = 4;
}

void Simulation::gameInput (Team & userTeam) {
    /*
    randScore(Mid1, Mid2)
    if user mid wins --> randScore(userAttack, oppoDef)
    else--> randScore(oppoAttack, userDef)
    */
    cout << "ENTER YOUR TACTIC!" << endl;
    //cout << "TEAM MANAGEMENT" << endl;
    cout << "1. DEFENSIVE" << endl;
    cout << "2. BALANCE" << endl;
    cout << "3. OFFENSIVE" << endl;
    cout << "(in keyboard 1, 2, or 3): ";
    cin >> tactic;
    cout <<"************************************************" << endl;
    cout << endl;

    if (tactic == '0'){
        cout << "tactic is 0" << endl;
    }
    else if (tactic == '1') {
        updateToDefence(userTeam);
    }
    else if (tactic == '2') {
        updateToBalance(userTeam);
    }
    else if (tactic == '3') {
        updateToOffence(userTeam);
    }
    else {
        cout << "handle invalid input..." << endl;
    }
}
/////////////////////
/////////////////////
/////////////////////
bool Simulation::competition (int userStat, int oppoStat) {
    /*
    if def = 0.3 and offend = 0.7
    then out of 10
    
    if 1, 2 or 3 --> defence success
    otherwise --> scored

    return true for defence success
    return false for offend success
    */
    int total = userStat + oppoStat;
    //cout << "user stat = " << userStat << " total = " << total << endl; 
    bool scoredOrNot;
    srand((unsigned int)time(NULL));
    int randNum = rand() % 10 + 1;
    /* 
                abs(
                    ((rand()%100) * (rand()%100))
                    % 100
                  )+1;
    */
    //cout << "time = " << time(NULL) << endl;
    //cout << "rand = " << randNum << " user = " << float(userStat)/float(total) * 10 +1<< endl;
    scoredOrNot = randNum <= float(userStat)/float(total) * 10 +1; // 1~10

    return scoredOrNot;
}

void Simulation::gameLogic (Team & userTeam, Team & oppoTeam) {
    bool res;
    
    // 1. COMPETITION IN MIDFIELD
    res = competition(userTeam.midSum, oppoTeam.midSum);
    
    // sleep takes long...?
    // sleep takes long...?
    // sleep takes long...?
    sleep(1);
    // 2. COMPETITION IN DEF VS ATT OR VICE VERSA
    if (res) {// if a user attack
        res = competition(userTeam.offendSum, oppoTeam.defSum);
        if (res) { // 3. UPDATE SCORE
            homeScore++;
        }
    }
    else {// if a user defence
        res = competition(userTeam.defSum, oppoTeam.offendSum);
        if (!res) { // 3. UPDATE SCORE
            awayScore++;
        }
    }

    // currently who is winning
    if (homeScore > awayScore){currWinner = 1;}
    else if (homeScore == awayScore){currWinner = 2;}
    else if (homeScore < awayScore){currWinner = 3;}
    
}