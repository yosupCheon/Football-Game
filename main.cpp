#include "classes/Player.h"
#include "classes/Team.h"
#include "classes/Simulation.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

/* demo versino
    - TEAM 1: 4-3-3
    - TEAM 2: 3-5-2
*/

int main () {
    // CREATE HOME TEAM (4-3-3)
    Team team1 ("Team 1");
    // GOAL KEEPER [age att def gok]
    Player t1GK ("t1GK", "GK", 35, 10, 20, 84);
    // CENTER BACK
    Player t1CB1 ("t1CB1", "CB", 30, 35, 80, 25);
    Player t1CB2 ("t1CB2", "CB", 24, 35, 80, 25);
    Player t1CB3 ("t1CB3", "CB", 28, 35, 80, 25);
    Player t1CB4 ("t1CB4", "CB", 25, 35, 80, 25);
    // MIDFIELDER
    Player t1MF1 ("t1MF1", "MF", 27, 60, 60, 20);
    Player t1MF2 ("t1MF2", "MF", 25, 60, 60, 20);
    Player t1MF3 ("t1MF3", "MF", 25, 60, 60, 20);
    // STRIKER
    Player t1ST1 ("t1ST1", "ST", 29, 80, 20, 10);
    Player t1ST2 ("t1ST2", "ST", 30, 80, 20, 10);
    Player t1ST3 ("t1ST3", "ST", 23, 80, 20, 10);

    // CREATE AWAYS TEAM (3-5-2)
    Team team2 ("Team 2");
    // GOAL KEEPER
    Player t2GK ("t2GK", "GK", 33, 10, 20, 81);
    // CENTER BACK
    Player t2CB1 ("t2CB1", "CB", 21, 40, 70, 25);
    Player t2CB2 ("t2CB2", "CB", 30, 30, 90, 25);
    Player t2CB3 ("t2CB3", "CB", 24, 40, 80, 25);
    // MIDFIELDER
    Player t2MF1 ("t2MF1", "MF", 22, 60, 60, 20);
    Player t2MF2 ("t2MF2", "MF", 27, 60, 60, 20);
    Player t2MF3 ("t2MF3", "MF", 29, 60, 60, 20);
    Player t2MF4 ("t2MF4", "MF", 32, 60, 60, 20);
    Player t2MF5 ("t2MF5", "MF", 30, 60, 60, 20);
    // STRIKER
    Player t2ST1 ("t2ST1", "ST", 35, 85, 15, 10);
    Player t2ST2 ("t2ST1", "ST", 35, 58, 15, 10);

    //ADD PLAYERS TO THE TEAM
    // TEAM 1
    team1.addPlayer(t1GK);
    team1.addPlayer(t1CB1);
    team1.addPlayer(t1CB2);
    team1.addPlayer(t1CB3);
    team1.addPlayer(t1CB4);
    team1.addPlayer(t1MF1);
    team1.addPlayer(t1MF2);
    team1.addPlayer(t1MF3);
    team1.addPlayer(t1ST1);
    team1.addPlayer(t1ST2);
    team1.addPlayer(t1ST3);
    //team1.playersGetter();
    cout << team1.overAllGetter() << endl;
    
    // TEAM 2
    team2.addPlayer(t2GK);
    team2.addPlayer(t2CB1);
    team2.addPlayer(t2CB2);
    team2.addPlayer(t2CB3);
    team2.addPlayer(t2MF1);
    team2.addPlayer(t2MF2);
    team2.addPlayer(t2MF3);
    team2.addPlayer(t2MF4);
    team2.addPlayer(t2MF5);
    team2.addPlayer(t2ST1);
    team2.addPlayer(t2ST2);
    //team2.playersGetter();
    cout << team2.overAllGetter() << endl;

    Simulation game (team1, team2);
    cout <<"game over in main" << endl;

    return 0;
}