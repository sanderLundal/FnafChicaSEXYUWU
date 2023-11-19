#include <iostream>
#include <fstream>
#include <raylib.h>

using namespace std;
Texture2D backGroundMainMenu;
Texture2D backGroundOffice;
Texture2D thiccChica;
Texture2D chicaCams;
Texture2D camMap;
Texture2D bonnie;
Texture2D bonnieCams;
Texture2D freddy;
Texture2D ShowStage;
Texture2D DiningTable;
Texture2D Backstage;
Texture2D PiratesCove;
Texture2D SupplyCloset;
Texture2D WestHall;
Texture2D WestHallCorner;
Texture2D EastHall;
Texture2D EastHallCorner;
Texture2D Restroom;
Sound theme;
Sound windowScare;

float textSize = 100;
bool maxTextSize = false;

Color textColorNewGame = WHITE;
Color textColorContinue = WHITE;
Color textColorQuit = WHITE;

int officeX = -400;
int officeY;

int main () {

    int BonnieLocation = 00;
    int ChicaLocation = 0;
    int FreddyLocation = 0;

    int CameraLocation = 1;
    bool CameraUp = false;

    bool leftLightOn = false;
    bool rightLightOn = false;

    bool hoveringNewGameX = false;
    bool hoveringNewGameY = false;

    bool hoveringContinueX = false;
    bool hoveringContinueY = false;

    bool hoveringQuitX = false;
    bool hoveringQuitY = false;

    const int screenWidth = 1920;
    const int screenHeight = 1080;
    
    int currentNight;

    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    ToggleFullscreen();
    
    InitAudioDevice();

    backGroundMainMenu = LoadTexture("./images/Background.png");
    backGroundOffice = LoadTexture("./images/office.png");
    thiccChica = LoadTexture("./images/chica.png");
    chicaCams = LoadTexture("./images/chicaCams.png");
    camMap = LoadTexture("./images/camMap.png");
    bonnie = LoadTexture("./images/bonnie.png");
    bonnieCams = LoadTexture("./images/bonnieCams.png");
    freddy = LoadTexture("./images/Freddy.png");
    DiningTable = LoadTexture("./images/diningTable.png");
    ShowStage = LoadTexture("./images/showStage.png");
    Backstage = LoadTexture("./images/backstage.png");
    PiratesCove = LoadTexture("./images/piratesCove.png");
    SupplyCloset = LoadTexture("./images/supplyCloset.png");
    WestHall = LoadTexture("./images/westHall.png");
    WestHallCorner = LoadTexture("./images/westHallCorner.png");
    EastHall = LoadTexture("./images/eastHall.png");
    EastHallCorner = LoadTexture("./images/eastHallCorner.png");
    Restroom = LoadTexture("./images/restrooms.png");
    
    
    
    theme = LoadSound("./audio/theme.mp3");
    windowScare = LoadSound("./audio/WindowScare.mp3");
    PlaySound(theme);
    SetSoundVolume(theme, 0.25f);

    int currentScene = 0;
    
    SetTargetFPS(60);

    while (WindowShouldClose() == false){

        Vector2 mousePos = GetMousePosition();

        BeginDrawing();
        ClearBackground(WHITE);

        if(currentScene == 0){
            DrawTexture(backGroundMainMenu, 0, 0, RAYWHITE);
            DrawText("Five\n", 20, 50, textSize, WHITE);
            DrawText("Nights\n", 20, 150, textSize, WHITE);
            DrawText("At\n", 20, 250, textSize, WHITE);
            DrawText("Freddy's\n", 20, 350, textSize, WHITE);
            DrawText("Goofy AHHH Edition\n", 1000, 100, textSize-10, YELLOW);
            DrawText("New Game", 20, 700, 100, textColorNewGame);
            DrawText("Continue", 20, 800, 100, textColorContinue);
            DrawText("Quit", 20, 900, 100, textColorQuit);

            // New Button
            if(mousePos.x > 20 && mousePos.x < 520){
                hoveringNewGameX = true;
            }
            else{
                hoveringNewGameX = false;
            }
            if(mousePos.y > 700 && mousePos.y < 800){
                hoveringNewGameY = true;
            }  
            else{
                hoveringNewGameY = false;
            }
            if(hoveringNewGameX == true && hoveringNewGameY == true){
                textColorNewGame = LIGHTGRAY;
            }
            else{
                textColorNewGame = WHITE;
            }
            // Continue Button
            if(mousePos.x > 20 && mousePos.x < 520){
                hoveringContinueX = true;
            }
            else{
                hoveringContinueX = false;
            }
            if(mousePos.y > 800 && mousePos.y < 900){
                hoveringContinueY = true;
            }
            else{
                hoveringContinueY = false;
            }
            if(hoveringContinueX == true && hoveringContinueY == true){
                textColorContinue = LIGHTGRAY;
                if(IsMouseButtonPressed(0)){
                    currentScene = 1;
                    StopSound(theme);
                }
            }
            else{
                textColorContinue = WHITE;
            }
            // Quit Button
            if(mousePos.x > 20 && mousePos.x < 520){
                hoveringQuitX = true;
            }
            else{
                hoveringQuitX = false;
            }
            if(mousePos.y > 900 && mousePos.y < 1000){
                hoveringQuitY = true;
            }
            else{
                hoveringQuitY = false;
            }
            if(hoveringQuitX == true && hoveringQuitY == true){
                textColorQuit = LIGHTGRAY;
                if(IsMouseButtonPressed(0)){
                    CloseWindow();
                    return 0;
                }
            }
            else{
                textColorQuit = WHITE;
            }
            if(textSize == 110){
                maxTextSize = true;
            }
            else if(textSize == 90){
                maxTextSize = false;
            }
            if(maxTextSize == true){
                textSize -= 0.25f;
            }
            else if(maxTextSize == false){
                textSize += 0.25f;
            }
        }
         
        else if(currentScene == 1){
            if(CameraUp == false){
                DrawTexture(backGroundOffice, officeX, officeY, WHITE);
            
                if(rightLightOn == true){
                    if(ChicaLocation == 11){
                        DrawTexture(thiccChica, officeX + 1900, -50, WHITE);
                    }
                }
                if(IsKeyPressed(KEY_RIGHT)){
                    if(rightLightOn == false){
                        rightLightOn = true;
                        if(ChicaLocation == 11){
                            PlaySound(windowScare);
                        }
                    }
                    else if(rightLightOn == true){
                        rightLightOn = false;
                    }
                }

                if(leftLightOn == true){
                    if(BonnieLocation == 11){
                        DrawTexture(bonnie, officeX + 450, 150, WHITE);
                    }
                }
                if(IsKeyPressed(KEY_LEFT)){
                    if(leftLightOn == false){
                        leftLightOn = true;
                        if(BonnieLocation == 11){
                            PlaySound(windowScare);
                        }
                    }
                    else if(leftLightOn == true){
                        leftLightOn = false;
                    }
                }

                if(mousePos.x <= 20){
                    if(officeX < 0){
                        officeX += 10;
                    }
                }
                if(mousePos.x >= 1900){

                    if(officeX > -1235){
                        officeX -= 10;
                    }   
                }
            }
            if(IsKeyPressed(KEY_DOWN)){
                if(CameraUp == false){
                    CameraUp = true;
                }
                else if(CameraUp == true){
                    CameraUp = false;
                }
            }
        }
        if(CameraUp == true){
            if(CameraLocation == 0){
                DrawTexture(ShowStage, 0, 0, WHITE);
                if(BonnieLocation == 0){
                    DrawTexture(bonnieCams, 0, 0, WHITE);
                }
                if(ChicaLocation == 0){
                    DrawTexture(chicaCams, 0, 0, WHITE);
                }
                if(FreddyLocation == 0){
                    DrawTexture(freddy, 0, 0, WHITE);
                }
            }
            if(CameraLocation == 1){
                DrawTexture(DiningTable, 0, 0, WHITE);
            }
            if(CameraLocation == 2){
                DrawTexture(Backstage, 0, 0, WHITE);
            }
            if(CameraLocation == 3){
                DrawTexture(PiratesCove, 0, 0, WHITE);
            }
            if(CameraLocation == 4){
                DrawTexture(SupplyCloset, 0, 0, WHITE);
            }
            if(CameraLocation == 5){
                DrawTexture(WestHall, 0, 0, WHITE);
            }
            if(CameraLocation == 6){
                DrawTexture(WestHallCorner, 0, 0, WHITE);
            }
            if(CameraLocation == 7){
                DrawTexture(EastHall, 0, 0, WHITE);
            }
            if(CameraLocation == 8){
                DrawTexture(EastHallCorner, 0, 0, WHITE);
            }
            if(CameraLocation == 9){
                DrawRectangle(0, 0, 1920, 1080, BLACK);
            }
            if(CameraLocation == 10){
                DrawTexture(Restroom, 0, 0, WHITE);
            }
            DrawTexture(camMap, 1500, 800, WHITE);   
            DrawRectangle(1575, 800, 40, 25, GREEN);
            DrawRectangle(1565, 833, 40, 25, GREEN);
            DrawRectangle(1500, 850, 40, 25, GREEN);
            DrawRectangle(1545, 882, 40, 25, GREEN);
            DrawRectangle(1710, 850, 40, 25, GREEN);
            DrawRectangle(1705, 934, 40, 25, GREEN);
            DrawRectangle(1525, 943, 40, 25, GREEN);
            DrawRectangle(1575, 955, 40, 25, GREEN);
            DrawRectangle(1575, 980, 40, 25, GREEN);
            DrawRectangle(1645, 955, 40, 25, GREEN);
            DrawRectangle(1645, 980, 40, 25, GREEN);
            //Buttons
            if(mousePos.x >= 1575 && mousePos.x <= 1575+40){
                if(mousePos.y >= 800 && mousePos.y <= 800+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 0;
                    }
                    DrawRectangle(1575, 800, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1565 && mousePos.x <= 1565+40){
                if(mousePos.y >= 833 && mousePos.y <= 833+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 1;
                    }
                    DrawRectangle(1565, 833, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1500 && mousePos.x <= 1500+40){
                if(mousePos.y >= 850 && mousePos.y <= 850+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 2;
                    }
                    DrawRectangle(1500, 850, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1545 && mousePos.x <= 1545+40){
                if(mousePos.y >= 882 && mousePos.y <= 882+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 3;
                    }
                    DrawRectangle(1545, 882, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1525 && mousePos.x <= 1525+40){
                if(mousePos.y >= 943 && mousePos.y <= 943+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 4;
                    }
                    DrawRectangle(1525, 943, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1575 && mousePos.x <= 1575+40){
                if(mousePos.y >= 955 && mousePos.y <= 955+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 5;
                    }
                    DrawRectangle(1575, 955, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1575 && mousePos.x <= 1575+40){
                if(mousePos.y >= 980 && mousePos.y <= 980+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 6;
                    }
                    DrawRectangle(1575, 980, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1645 && mousePos.x <= 1645+40){
                if(mousePos.y >= 955 && mousePos.y <= 955+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 7;
                    }
                    DrawRectangle(1645, 955, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1645 && mousePos.x <= 1645+40){
                if(mousePos.y >= 980 && mousePos.y <= 980+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 8;
                    }
                    DrawRectangle(1645, 980, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1705 && mousePos.x <= 1705+40){
                if(mousePos.y >= 934 && mousePos.y <= 934+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 9;
                    }
                    DrawRectangle(1705, 934, 40, 25, BLUE);
                }
            }
            if(mousePos.x >= 1710 && mousePos.x <= 1710+40){
                if(mousePos.y >= 850 && mousePos.y <= 850+25){
                    if(IsMouseButtonPressed(0)){
                        CameraLocation = 10;
                    }
                    DrawRectangle(1710, 850, 40, 25, BLUE);
                }
            }
            
        }
        EndDrawing();
    }       
    UnloadTexture(backGroundMainMenu);
    UnloadTexture(backGroundOffice);
    UnloadTexture(thiccChica);
    UnloadTexture(chicaCams);
    UnloadTexture(camMap);
    UnloadTexture(bonnie);
    UnloadTexture(bonnieCams);
    UnloadTexture(ShowStage);
    UnloadTexture(DiningTable);
    UnloadTexture(Backstage);
    UnloadTexture(PiratesCove);
    UnloadTexture(SupplyCloset);
    UnloadTexture(WestHall);
    UnloadTexture(WestHallCorner);
    UnloadTexture(EastHall);
    UnloadTexture(EastHallCorner);
    UnloadTexture(Restroom);
    UnloadTexture(freddy);

    UnloadSound(theme);
    UnloadSound(windowScare);
    CloseWindow();
    return 0;
}