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

/* FORMATION
default 4-3-3
defense 5-3-2
balance 4-3-3
offence 3-3-4
*/

int main () {
    // [name, position, age, gok, def, att]
    Team team1("Team1");
    // GK
    team1.addPlayer ("t1GK", "GK", 35, 84, 20, 10);
    // CENTER BACK
    team1.addPlayer ("t1CB1", "CB", 30, 25, 90, 35);
    team1.addPlayer ("t1CB2", "CB", 24, 25, 70, 35);
    team1.addPlayer ("t1CB3", "CB", 28, 25, 71, 35);
    team1.addPlayer ("t1CB4", "CB", 25, 25, 70, 35);
    // MIDFIELDERS
    team1.addPlayer ("t1MF1", "MF", 27, 20, 60, 60);
    team1.addPlayer ("t1MF2", "MF", 25, 20, 62, 60);
    team1.addPlayer ("t1MF3", "MF", 25, 20, 60, 61);
    // STRIKERS
    team1.addPlayer ("t1ST1", "ST", 29, 10, 20, 80);
    team1.addPlayer ("t1ST2", "ST", 30, 10, 20, 80);
    team1.addPlayer ("t1ST3", "ST", 23, 10, 20, 85);

    Team team2 ("Team2");
    //GK
    team2.addPlayer ("t2GK", "GK", 33, 81, 20, 10);
    //CB
    team2.addPlayer ("t2CB1", "CB", 21, 25, 70, 40);
    team2.addPlayer ("t2CB2", "CB", 30, 25, 70, 30);
    team2.addPlayer ("t2CB3", "CB", 24, 25, 80, 40);
    team2.addPlayer ("t2CB4", "CB", 32, 20, 60, 20);
    //MF
    team2.addPlayer ("t2MF1", "MF", 22, 20, 65, 60);
    team2.addPlayer ("t2MF2", "MF", 27, 20, 60, 65);
    team2.addPlayer ("t2MF3", "MF", 29, 20, 60, 60);
    //ST
    team2.addPlayer ("t2ST1", "ST", 35, 10, 15, 85);
    team2.addPlayer ("t2ST2", "ST", 35, 10, 15, 70);
    team2.addPlayer ("t2ST3", "ST", 30, 20, 10, 80);

    Simulation game;
    char startMenu = game.startFunction();
    if (startMenu == '1') {
        game.gameLoop(team1, team2);
    }
    else if (startMenu == '2') {
        cout << "CREATE A PLAYER..." << endl;
    }
    else if (startMenu == '3') {
        cout << "CREATE A TEAM..." << endl;
    }
    else if (startMenu == 'q') {
        cout << "BYE!!!" << endl;
        return 0;
    }
    cout << endl;
    cout <<"game over in main" << endl;

    return 0;
} 