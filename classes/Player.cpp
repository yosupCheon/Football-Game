#include "Player.h"

// (Default) Constructor
Player::Player() {
}

void Player::createPlayer(string name, string pos, int age, int gok, int def, int att){
    this->name = name;
    this->pos = pos;
    this->age = age;

    this->gok = gok;
    this->def = def;
    this->att = att;

    this->next = NULL;
}

Player* Player::copyPlayer (const Player plr) {
    Player* tempPlr;
    tempPlr->name = plr.name;
    tempPlr->pos = plr.pos;
    tempPlr->age = plr.age;
    
    tempPlr->gok = plr.gok;
    tempPlr->def = plr.def;
    tempPlr->att = plr.att;

    return tempPlr;
}



string Player::nameGetter (){
    return this->name;
}