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
    int att;
    int def;
    int gok;

    // Default Constructor
    Player();
    
    // Create a Player Constructor
    Player(string name, string pos, int age, int att, int def, int gok);

    // Name Getter
    string nameGetter ();
private:   
/* comment out for test 
    string name; 
    string pos; //position
    int age;
    int att;
    int def;
    int gok;
*/
};