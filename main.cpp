#include "Player.h"
#include "Team.h"
#include "Simulation.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

int main () {
    // create home team
    Team manFC ("Manchester FC");
    //age att def gok
    Player vdS ("VDS", "GK", 35, 10, 20, 84); //GK
    Player nV ("Vidic", "CB", 30, 30, 90, 45); //CB
    Player jsP ("Park", "CM", 32, 80, 80, 20); //CM
    Player wR ("Rooney", "ST", 33, 94, 33, 10); //ST

    // create away team
    Team cheUTD ("Chelsea UTD");
    Player pC ("Cecb", "GK", 34, 10, 15, 85); //GK
    Player jT ("Terry", "CB", 31, 25, 90, 40); //CB
    Player nK ("Kante", "CM", 28, 85, 85, 10); //CM
    Player dD ("Drogba", "ST", 34, 98, 20, 10); //ST

    //add players to the team
    manFC.addPlayer(vdS);
    manFC.addPlayer(nV);
    manFC.addPlayer(jsP);
    manFC.addPlayer(wR);
    //manFC.playersGetter();
    //cout << manFC.overAllGetter() << endl;
    //cout << endl;
    cheUTD.addPlayer(pC);
    cheUTD.addPlayer(jT);
    cheUTD.addPlayer(nK);
    cheUTD.addPlayer(dD);
    //cheUTD.playersGetter();
    //cout << cheUTD.overAllGetter() << endl;

    //game simulate
    // first parameter is home (adds +5 to the overall)
    // the result is return by the team's player's overall
    Simulation round1 (manFC, cheUTD);
    Simulation round2 (cheUTD, manFC);

    return 0;
}