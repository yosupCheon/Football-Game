#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Simulation.h"
#include "Team.h"
#include "Player.h"
#include "unistd.h"
#include "raylib.h"
#include <cstring>

using namespace std;

using std::string;
using std::vector;

class Gui {

public:
    int startMenu = 0;
    int timeCount = 0;
    string timeLine [6] = {"00:00", "25:00", "45:00", "60:00", "70:00", "85:00"};

    Team* homeTeam = NULL;
    Team* awayTeam = NULL;
    Simulation gameLogic;

    Gui();
    Gui(Team& home, Team& away);
    ~Gui();
    
    void guiDraw();
    void startPage();
    void gamePlay ();
    void createPlayerGui();
    void createTeamGui();
    void gameOver();


};