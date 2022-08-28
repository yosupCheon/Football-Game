#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

using std::string;
using std::vector;

class Player {
public:
    // need to be private after test in team
    string name; 
    string pos; //position
    int age;
    int gok;
    int def;
    int att;
    Player* next;

    // Default Constructor
    Player();
    
    // Create a Player Constructor
    void createPlayer(string name, string pos, int age, int gok, int def, int att);
    //void createPlayer(string name, string pos, int age, int att, int def, int gok);

    Player* copyPlayer (const Player plr);

    // Name Getter
    string nameGetter ();
private:   

};