#include "gui.h"

Gui::Gui(){
    InitWindow(800, 600, "Test Raylib");
    SetTargetFPS(60);
}
Gui::~Gui(){
    CloseWindow();
}

void Gui::guiDraw() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if (startMenu != 0){
            if (startMenu == 1) {
                gamePlay();
            }
            else if (startMenu == 2) {
                cout << "startMenu = " << startMenu << endl;
                gameOver();
                sleep(1);
                break;
            }
            else if (startMenu == 3) {
                cout << "startMenu = " << startMenu << endl;
                gameOver();
                sleep(1);
                break;
            }
        }
        else {
            startPage();
        }


        EndDrawing();
    }
}

void Gui::startPage() {
    const char* text = "Test Text";
    int posX = 260, posY = 0;
    int fontSize = 80;

    int xn = GetTouchX();
    int yn = GetTouchY();

    DrawText(text, posX, posY, fontSize, WHITE);

    DrawRectangle(posX, posY+190, 320, 100, WHITE);
    DrawRectangle(posX, posY+320, 320, 100, WHITE);
    DrawRectangle(posX, posY+450, 320, 100, WHITE);
    
    DrawText("first", posX+10, posY+190, fontSize-10, BLACK);
    DrawText("second", posX+10, posY+320, fontSize-10, BLACK);
    DrawText("thrid", posX+10, posY+450, fontSize-10, BLACK);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if ( (posX<xn && xn<posX+320) && (posY+190<yn && yn<posY+190+100) ){
            startMenu = 1;
            //return 1;
        }
        else if ( (posX<xn && xn<posX+320) && (posY+320<yn && yn<posY+320+100) ){
            startMenu = 2;
        }
        else if ( (posX<xn && xn<posX+320) && (posY+450<yn && yn<posY+450+100) ){
            startMenu = 3;
        }
    }
}

void Gui::gamePlay() {
    int posX = 0;
    int posY = 0;
    DrawRectangle(posX+30, posY+60, 350, 500, GREEN);
    DrawRectangle(posX+400+40, posY+60+20, 330, 180, WHITE);
    DrawRectangle(posX+400+40, posY+60+200+40, 330, 250, WHITE);
}

void Gui::gameOver() {
    DrawText("GAME OVER...", 90, 250, 100, WHITE);
}