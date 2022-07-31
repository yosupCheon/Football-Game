#include "Simulation.h"
#include <iostream>

using namespace std;

// +5 for home advantage
Simulation::Simulation(Team home, Team away){
    if (home.overAllGetter()+5 < away.overAllGetter()){
        cout << "Winner: " << away.nameGetter() << endl;
    }
    else { //home wins for the equal overall due to home advantage
        cout << "Winner: " << home.nameGetter() << endl;
    }

}