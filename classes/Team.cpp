#include "Team.h"
#include "Simulation.h"

#include <iostream>


Team::Team(string name) {
    teamName = name;
    head = new Player;
    head->createPlayer("header", "NO", 0,0,0,0);
}

void Team::addPlayer(string plrName, string pos, int age, int gok, int def, int att) {
    Player* newPlayer = new Player;
    //newPlayer->name = plrName;
    //newPlayer->next = NULL;
    newPlayer->createPlayer(plrName, pos, age, gok, def, att);
    if (head->next == NULL) {head->next = newPlayer; return;}

    Player* lastPlayer;
    lastPlayer = head->next;
    while (lastPlayer->next != NULL) {
        lastPlayer = lastPlayer->next;
    }
    lastPlayer->next = newPlayer;


    if (!(pos.compare("GK"))) {
        defSum += gok;
    }
    else if (!(pos.compare("CB"))) {
        defSum += def;
    }
    else if (!(pos.compare("MF"))) {
        midSum += (def + att)/2;
    }
    else if (!(pos.compare("ST"))) {
        offendSum += att;
    }

    curPlayers++;
}

void Team::delThisPlayer (string plrName) {
    Player* delPlayer;
    Player* prev;
    prev = head;
    //prev = head->next;

    while (prev->next->name.compare(plrName) != 0) {
        prev = prev->next;
    }

    delPlayer = prev->next;
    prev->next = delPlayer->next;
    
    delete delPlayer;
}

void Team::updateOverall (Player* plr) {
    if (!(plr->pos.compare("CB"))){
        defSum -= plr->def;
    }
    else if ((plr->pos.compare("MF"))==0){
        midSum -= ((plr->def)+(plr->att))/2;
    }
    else if (!(plr->pos.compare("ST"))){
        offendSum -= plr->att;
    }
}

void Team::updatePosition (Player* plr, string toPos) {
    Player* plrTemp;
    plrTemp = head;
    while (plrTemp != NULL) {
        if (plrTemp == plr) {
            if (!(toPos.compare("CB"))) {
                updateOverall(plrTemp);
                plrTemp->pos = "CB";
                defSum += plrTemp->def;
            }
            else if (!(toPos.compare("MF"))) {
                updateOverall(plrTemp);
                plrTemp->pos = "MF";
                midSum += ((plrTemp->def)+(plrTemp->att))/2;
            }
            else if (!(toPos.compare("ST"))) {
                updateOverall(plrTemp);
                plrTemp->pos = "ST";
                offendSum += plrTemp->att;
            }
            
            break;
        }
        plrTemp = plrTemp->next;
    }


}

void Team::printPlayers () {
    Player* temp = head->next;
    while (temp != NULL) {
        cout << temp->name <<" "<< temp->pos << endl;
        temp = temp->next;
    }
}





/*
in addPlayer logic
    if (curPlayers <= playersLim){
        //players[curPlayers] = plr;
        if (!(plr.pos.compare("GK"))) {
            defSum += plr.gok;
        }
        else if (!(plr.pos.compare("CB"))) {
            defSum += plr.def;
        }
        else if (!(plr.pos.compare("MF"))) {
            midSum += (plr.def + plr.att)/2;
        }
        else if (!(plr.pos.compare("ST"))) {
            offendSum += plr.att;
        }
        curPlayers++;
    }
    else {
        std::cout << "team is full" << std::endl;
    }
*/

