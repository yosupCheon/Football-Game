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

int main () {
    // create home team
    Team team1 ("Team 1");
    //age att def gok
    Player vdS ("VDS", "GK", 35, 10, 20, 84); //GK
    Player nV ("Vidic", "CB", 30, 30, 90, 45); //CB
    Player jsP ("Park", "CM", 32, 80, 80, 20); //CM
    Player wR ("Rooney", "ST", 33, 94, 33, 10); //ST

    // create away team
    Team team2 ("Team 2");
    Player pC ("Cecb", "GK", 34, 10, 15, 85); //GK
    Player jT ("Terry", "CB", 31, 25, 90, 40); //CB
    Player nK ("Kante", "CM", 28, 85, 85, 10); //CM
    Player dD ("Drogba", "ST", 34, 98, 20, 10); //ST

    //add players to the team
    team1.addPlayer(vdS);
    team1.addPlayer(nV);
    team1.addPlayer(jsP);
    team1.addPlayer(wR);
    //team1.playersGetter();
    //cout << team1.overAllGetter() << endl;
    //cout << endl;
    team2.addPlayer(pC);
    team2.addPlayer(jT);
    team2.addPlayer(nK);
    team2.addPlayer(dD);
    //team2.playersGetter();
    //cout << team2.overAllGetter() << endl;

    //game simulate
    // first parameter is home (adds +5 to the overall)
    // the result is return by the team's player's overall
    Simulation round1 (team1, team2);
    Simulation round2 (team2, team1);

    return 0;
}