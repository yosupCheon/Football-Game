#include "gui.h"

Gui::Gui(){
}
Gui::Gui(Team& home, Team& away) {
    InitWindow(800, 600, "Test Raylib");
    SetTargetFPS(60);
    
    homeTeam = &home;
    awayTeam = &away;

    //gameLogic = NULL;
    //gameLogic->homeScore = 0;
    //gameLogic->awayScore = 0;
}
Gui::~Gui(){
    cout << "Destructor" << endl;
    CloseWindow();
}

void Gui::guiDraw() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

//START PAGE MENU
        if (startMenu != 0){
            if (startMenu == 1) {
                if (timeCount < 6) {
                    gamePlay();
                }
                // INIT GAME LOGIC AS WELL
                else if (timeCount == 6){
                    gameOver();
                }
                else if (timeCount > 6) {
                    startMenu=0;
                    timeCount=0;
                }        
            }
            else if (startMenu == 2) {
                createPlayerGui();
            }
            else if (startMenu == 3) {
                createTeamGui();
            }
            else if (startMenu == 4) {
                cout << "Quit" << startMenu << endl;
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
    //Start Page
    // Title
    const char* inGameTitle = "Football Game";
    int posX = 150, posY = 0;
    int fontSize = 80;
    DrawText(inGameTitle, posX, posY, fontSize, WHITE);

    // Rectangles
    int recGap = 70;
    int recPosX = posX, recPosY = posY+190;
    DrawRectangle(recPosX, recPosY, 500, 50, WHITE);
    recPosY += recGap;
    DrawRectangle(recPosX, recPosY, 500, 50, WHITE);
    recPosY += recGap;
    DrawRectangle(recPosX, recPosY, 500, 50, WHITE);
    recPosY += recGap;
    DrawRectangle(recPosX, recPosY, 500, 50, WHITE);
    
    // Options(Text) in Rectangles
    int txtPosX = posX+10, txtPosY = posY + 190;
    int recFontSize = fontSize - 45;
    DrawText("Play", txtPosX, txtPosY, recFontSize, BLACK);
    txtPosY += recGap;
    DrawText("Create a Player", txtPosX, txtPosY, recFontSize, BLACK);
    txtPosY += recGap;
    DrawText("Create a Team", txtPosX, txtPosY, recFontSize, BLACK);
    txtPosY += recGap;
    DrawText("Exit", txtPosX, txtPosY, recFontSize, BLACK);

    // Clickable Interaction within Rectangles
    int xn = GetTouchX();
    int yn = GetTouchY();
    recPosY = posY + 190;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if ( (recPosX<xn && xn<recPosX+500) && (recPosY<yn && yn<recPosY+50) ){
            startMenu = 1;
        }
        else if ( (recPosX<xn && xn<recPosX+500) && (recPosY+recGap<yn && yn<recPosY+recGap+50) ){
            startMenu = 2;
        }
        else if ( (recPosX<xn && xn<recPosX+500)  && (recPosY+(2*recGap)<yn && yn<recPosY+(2*recGap)+50) ){
            startMenu = 3;
        }
        else if ( (recPosX<xn && xn<recPosX+500)  && (recPosY+(3*recGap)<yn && yn<recPosY+(3*recGap)+50) ){
            startMenu = 4;
        }
    }
}

void helperUserDefenceLine (int n){
    int posX = 30 , posY = 60+425;
    if (n == 3){
        posX += 95;
        DrawCircle(posX, posY, 10, PINK);
        posX += 95;
        DrawCircle(posX, posY, 10, PINK);
        posX += 95;
        DrawCircle(posX, posY, 10, PINK);
    }
    else if (n==4){
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
    }
    else if (n==5) {
        posX += 62;
        DrawCircle(posX, posY, 10, PINK);
        posX += 62;
        DrawCircle(posX, posY, 10, PINK);
        posX += 62;
        DrawCircle(posX, posY, 10, PINK);
        posX += 62;
        DrawCircle(posX, posY, 10, PINK);
        posX += 62;
        DrawCircle(posX, posY, 10, PINK);
    }
}
void helperUserMidLine (){
    int posX = 30, posY = 60+275;
    posX += 95;
    DrawCircle(posX, posY, 10, PINK);
    posX += 95;
    DrawCircle(posX, posY, 10, PINK);
    posX += 95;
    DrawCircle(posX, posY, 10, PINK);
}
void helperUserOffenceLine (int n){
    int posX = 30, posY = 60+125;
    if (n==2){
        posX += 123;
        DrawCircle(posX, posY, 10, PINK);
        posX += 123;
        DrawCircle(posX, posY, 10, PINK);
    }
    else if(n==3){
        posX += 95;
        DrawCircle(posX, posY, 10, PINK);
        posX += 95;
        DrawCircle(posX, posY, 10, PINK);
        posX += 95;
        DrawCircle(posX, posY, 10, PINK);
    }
    else if (n==4) {
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
        posX += 76;
        DrawCircle(posX, posY, 10, PINK);
    }
}

void helperOppoDefenceLine (int n){
    int posX = 30, posY = 60+125-50;
    if (n==3){
        posX += 95;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 95;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 95;
        DrawCircle(posX, posY, 10, BLUE);
    }
    else if(n==4){
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
    }
    else if (n==5) {
        posX += 62;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 62;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 62;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 62;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 62;
        DrawCircle(posX, posY, 10, BLUE);
    }
}
void helperOppoMidLine (){
    int posX = 30, posY = 60+275-50;
    posX += 95;
    DrawCircle(posX, posY, 10, BLUE);
    posX += 95;
    DrawCircle(posX, posY, 10, BLUE);
    posX += 95;
    DrawCircle(posX, posY, 10, BLUE);
}
void helperOppoOffenceLine (int n){
    int posX = 30 , posY = 60+425-50;
    if (n==2){
        posX += 123;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 123;
        DrawCircle(posX, posY, 10, BLUE);
    }
    else if(n==3){
        posX += 95;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 95;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 95;
        DrawCircle(posX, posY, 10, BLUE);
    }
    else if (n==4) {
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
        posX += 76;
        DrawCircle(posX, posY, 10, BLUE);
    }
}

void Gui::gamePlay() {
    int fieldPosX = 30, fieldPosY = 60;
    int fontSize = 30;
    // MATCH FIELD
    //      OUTER BOX
    DrawRectangle(fieldPosX-10, fieldPosY-10, 380+20, 500+20, WHITE);
    //   GREEN FIELD
    DrawRectangle(fieldPosX, fieldPosY, 380, 500, GREEN);
    //   MIDDLE LINE
    DrawRectangle(fieldPosX, fieldPosY+245, 380, 10, WHITE);
    //  CENTER CIRCLE
    DrawCircle(fieldPosX+190, fieldPosY+250, 25, WHITE);
    //  GOAL POST 1 (OPPONENT SIDE)
    DrawRectangle(fieldPosX+148, fieldPosY, 95, 50, WHITE);
    DrawRectangle(fieldPosX+148+10, fieldPosY, 95-20, 50-10, GREEN);
    //  GOAL POST 2 (USER SIDE)
    DrawRectangle(fieldPosX+148, fieldPosY+450, 95, 50, WHITE);
    DrawRectangle(fieldPosX+148+10, fieldPosY+450+10, 95-20, 50-10, GREEN);
    // (DEFAULT; BALANCED; 4-3-3 FORMATIONS FOR A USER)
    if (homeTeam->formation[0] == 5) { //Defence
        helperUserOffenceLine(2);
        helperUserMidLine();
        helperUserDefenceLine(5);
    }
    else if (homeTeam->formation[0] == 4) { //Balance
        helperUserOffenceLine(3);
        helperUserMidLine();
        helperUserDefenceLine(4);
    }
    else if (homeTeam->formation[0] == 3) { //Attack
        helperUserOffenceLine(4);
        helperUserMidLine();
        helperUserDefenceLine(3);
    }
    // FORMATIONS FOR A OPPONENT
    if (awayTeam->formation[0]==5){ //Defence
        helperOppoOffenceLine(2);
        helperOppoMidLine();
        helperOppoDefenceLine(5);
    }
    else if (awayTeam->formation[0]==4){ //Balance
        helperOppoOffenceLine(3);
        helperOppoMidLine();
        helperOppoDefenceLine(4);
    }
    else if (awayTeam->formation[0]==3) { //Atack
        helperOppoOffenceLine(4);
        helperOppoMidLine();
        helperOppoDefenceLine(3);
    }
    //TEST LINES
    //DrawRectangle(fieldPosX, fieldPosY+50-5, 380, 10, PURPLE);
    //DrawRectangle(fieldPosX, fieldPosY+50-5+100, 380, 10, PURPLE);
    //DrawRectangle(fieldPosX, fieldPosY+50-5+100+100+100, 380, 10, PURPLE);
    //DrawRectangle(fieldPosX, fieldPosY+50-5+100+100+100+100, 380, 10, PURPLE);

    // TIME
    int timePosX = fieldPosX+410, timePosY = fieldPosY+20;
    //char* temp;
    //strcpy(temp, matchTime);
    DrawRectangle(timePosX, timePosY, 330, 180, WHITE);
    DrawText(timeLine[timeCount].c_str(), timePosX+115, timePosY+10, fontSize+10, BLACK);
    //DrawText("00:00", timePosX+115, timePosY+10, fontSize+10, BLACK);
    // SCORE BOARD
    int optionPosX = fieldPosX+410, optionPosY = fieldPosY+20+50;
    DrawRectangle(optionPosX, optionPosY, 330, 180, YELLOW);
    //  Score
    DrawText("SCORE", optionPosX+110, optionPosY+10, fontSize, BLACK);
    //  Home Away
    DrawText("HOME", optionPosX+40, optionPosY+50, fontSize, BLACK);
    DrawText("AWAY", optionPosX+205, optionPosY+50, fontSize, BLACK);
    //  3:2
    DrawText(to_string(gameLogic.homeScore).c_str(), optionPosX+40+20, optionPosY+95, fontSize+50, BLACK);
    DrawText(":", optionPosX+160, optionPosY+95, fontSize+50, BLACK);
    DrawText(to_string(gameLogic.awayScore).c_str(), optionPosX+205+20, optionPosY+95, fontSize+50, BLACK);
    //DrawText("aaa", optionPosX+205+20, optionPosY+95, fontSize+50, BLACK);


    // TACTIC SELECTION
    optionPosY -= 20;
    int selRecX = optionPosX + 20, selRecY = optionPosY+310;
    int selTxtX = optionPosX + 20, selTxtY = optionPosY+250;
    fontSize = 30;
    int tactic = 0;
    //  Select!
    DrawText("Select Tactic!", selTxtX, selTxtY, fontSize, WHITE);
    //  1 defense
    selTxtX += 25;
    selTxtY += 70;
    DrawRectangle(selRecX, selRecY, 220, 40, WHITE);
    DrawText("DEFENSIVE", selTxtX, selTxtY, fontSize, BLACK);
    //  2 balance
    selTxtY += 50;
    selRecY += 50;
    DrawRectangle(selRecX, selRecY, 220, 40, WHITE);
    DrawText("BALANCE", selTxtX, selTxtY, fontSize, BLACK);
    //  3 offense
    selTxtY += 50;
    selRecY += 50;
    DrawRectangle(selRecX, selRecY, 220, 40, WHITE);
    DrawText("OFFENSE", selTxtX, selTxtY, fontSize, BLACK);
    
    // + update tactic variable in simulation class
    int xn = GetTouchX();
    int yn = GetTouchY();
    selRecY -= 100;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if ( (selRecX <= xn&&xn <= selRecX+220) && ( selRecY <= yn&&yn <= selRecY+40 ) ) {
            cout << "DEFENSIVE" <<endl;
            gameLogic.gameInput(homeTeam, 1);
            timeCount++;
        }
        else if ( (selRecX <= xn&&xn <= selRecX+220) && ( selRecY+50 <= yn&&yn <= selRecY+40+50 ) ) {
            cout << "BALANCE" <<endl;
            gameLogic.gameInput(homeTeam, 2);
            timeCount++;
        }
        else if ( (selRecX <= xn&&xn <= selRecX+220) && ( selRecY+100 <= yn&&yn <= selRecY+40+100 ) ) {
            cout << "OFFENSE" <<endl;
            gameLogic.gameInput(homeTeam, 3);
            timeCount++;
        }
        gameLogic.opponentFormation(awayTeam);
        gameLogic.gameLogic(*homeTeam, *awayTeam);
    }
}

void Gui::createPlayerGui() {
    DrawText("Will Be Implimented...", 90, 250, 50, WHITE);
    DrawText("Click to Exit", 90, 450, 50, WHITE);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        startMenu = 4;
    }
}
void Gui::createTeamGui() {
    DrawText("Will Be Implimented...", 90, 250, 50, WHITE);
    DrawText("Click to Exit", 90, 450, 50, WHITE);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        startMenu = 4;
    }
    
}

void Gui::gameOver() {
    //Time = 90:00
    int fontsize = 100;
    fontsize -= 10;
    DrawText("TIME 90:00", 800/5, 0, fontsize, WHITE);
    //Who Win
    DrawText("Who Win", 800/5 + 50, 100, fontsize, WHITE);

    //Home Away
    fontsize = 80;
    DrawText((homeTeam->teamName).c_str(), 800/5-60, 200, fontsize, WHITE);
    DrawText((awayTeam->teamName).c_str(), 800*3/5+60, 200, fontsize, WHITE);
    //Score
    DrawText(to_string(gameLogic.homeScore).c_str(), 800*2/5-15, 300, fontsize, WHITE);
    DrawText(":", 400, 300, fontsize, WHITE);
    DrawText(to_string(gameLogic.awayScore).c_str(), 800*3/5-15, 300, fontsize, WHITE);

    //Replay
    fontsize = 50;
    DrawRectangle(60, 415, 280, 60, PINK);
    DrawText("REPLAY?", 80, 425, fontsize, BLACK);
    //Exit
    DrawRectangle(60, 515, 180, 60, PINK);
    DrawText("EXIT", 80, 525, fontsize, BLACK);

    int xn = GetTouchX();
    int yn = GetTouchY();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if ( (60 <= xn&&xn <= 340) && ( 415 <= yn&&yn <= 475 ) ) {
            startMenu = 0;
            timeCount=0;
        }
        else if ( (60 <= xn&&xn <= 240) && ( 515 <= yn&&yn <= 575 ) ) {
            startMenu = 4;
        }
    }//outer if
}