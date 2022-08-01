#include "Player.h"

// (Default) Constructor
Player::Player() {

}

Player::Player(string name, string pos, int age, int att, int def, int gok){
    this->name = name;
    this->pos = pos;
    this->age = age;
    this->att = att;
    this->def = def;
    this->gok = gok;
}

string Player::nameGetter (){
    return this->name;
}