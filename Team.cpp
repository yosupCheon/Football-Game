#include "Team.h"

#include <iostream>

// (Default) Constructor
Team::Team() {

}

Team::Team(string name) {
    this->name = name;
    teamOverall = 0;
    players = new Player [playersLim];
}

string Team::nameGetter () {
    return name;
}

void Team::addPlayer(Player plr) {
    if (curPlayers <= playersLim){
        players[curPlayers] = plr;
        curPlayers++;      
        overAllCal(plr);
    }
    else {
        std::cout << "team is full" << std::endl;
    }
}

void Team::playersGetter () {
    for (int i = 0; i < curPlayers; i++) {
        std::cout << "Team Name: " << name << endl;
        std::cout << "Name: " << players[i].name << endl;
        std::cout << "Position: " << players[i].pos << endl;
        std::cout << "Age: " << players[i].age << endl; 
    }
}

int Team::overAllGetter () {
    return teamOverall;
}

void Team::overAllCal (Player plr) {
    int temp = (plr.att) + (plr.def) + (plr.gok + 90);
    temp /= 3;
    teamOverall += temp;
    if (curPlayers > 1) {
        teamOverall /= 2;
    }
}