#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "unistd.h"
#include "raylib.h"
#include "Simulation.h"

using namespace std;

using std::string;
using std::vector;

class Gui {

public:
    int startMenu = 0;
    Simulation* gameLogic;
    
    Gui();
    ~Gui();
    void guiDraw();

    void startPage();
    void gamePlay();
    void gameOver();


};