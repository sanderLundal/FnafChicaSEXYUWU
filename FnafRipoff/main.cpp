#include <iostream>
#include <fstream>
#include <raylib.h>
#include <fstream>

int bonnieRandomNumber;
int chicaRandomNumber;
int freddyRandomNumber;

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
Texture2D leftDoor;
Texture2D rightDoor;
Texture2D winScreen;

Texture2D bonnieFrame1;
Texture2D bonnieFrame2;
Texture2D bonnieFrame3;
Texture2D bonnieFrame4;
Texture2D bonnieFrame5;
Texture2D bonnieFrame6;
Texture2D bonnieFrame7;
Texture2D bonnieFrame8;
Texture2D bonnieFrame9;

Texture2D chicaFrame1;
Texture2D chicaFrame2;
Texture2D chicaFrame3;
Texture2D chicaFrame4;
Texture2D chicaFrame5;
Texture2D chicaFrame6;
Texture2D chicaFrame7;
Texture2D chicaFrame8;
Texture2D chicaFrame9;
Texture2D chicaFrame10;
Texture2D chicaFrame11;

Texture2D freddyFrame1; 
Texture2D freddyFrame2;
Texture2D freddyFrame3;
Texture2D freddyFrame4;
Texture2D freddyFrame5;
Texture2D freddyFrame6;
Texture2D freddyFrame7;
Texture2D freddyFrame8;
Texture2D freddyFrame9;
Texture2D freddyFrame10;
Texture2D freddyFrame11;
Texture2D freddyFrame12;
Texture2D freddyFrame13;
Texture2D freddyFrame14;
Texture2D freddyFrame15;
Texture2D freddyFrame16;
Texture2D freddyFrame17;
Texture2D freddyFrame18;
Texture2D freddyFrame19;
Texture2D freddyFrame20;
Texture2D freddyFrame21;
Texture2D freddyFrame22;
Texture2D freddyFrame23;
Texture2D freddyFrame24;
Texture2D freddyFrame25;
Texture2D freddyFrame26;

Sound theme;
Sound windowScare;
Sound jumpscaresound;
Sound freddygyat;
Sound door;
Sound win;
Sound phoneNight1;
Sound phoneNight2;
Sound phoneNight3;
Sound phoneNight4;
Sound phoneNight5;

int bonniePath[] = {0, 1, 2, 4, 5, 6, 11};
int chicaPath[] = {0, 1, 10, 9, 7, 8, 11};
int freddyPath[] = {0, 1, 10, 8, 11};

float textSize = 100;
bool maxTextSize = false;

Color textColorNewGame = WHITE;
Color textColorContinue = WHITE;
Color textColorQuit = WHITE;

int officeX = -400;
int officeY;

int BonnieLocation = 0;
int ChicaLocation = 0;
int FreddyLocation = 0;

int LocationCounter = 360;
int bonnieFrameCounter = 0;

bool bonniejumpscare = false;
bool freddyjumpscare = false;
bool chicajumpscare = false;

bool leftDoorOn = false;
bool rightDoorOn = false;

int maxBattery = 100;
int currentBattery = maxBattery;
int leftDoorPowerDraw = 0;
int rightDoorPowerDraw = 0;
int leftLightPowerDraw = 0;
int rightLightPowerDraw = 0;
int idlePowerDraw = 1;
int totalPowerDraw;

int clockCountStart = 21600;
int clockCount = clockCountStart;
int currentHour = 0;

char *clockChar;

ofstream ofs;
ifstream ifs;


namespace retard{
    void moveBonnie(int currentLocation){
        if(currentLocation == bonniePath[0]){
            BonnieLocation = bonniePath[1];
        }
        else if(currentLocation == bonniePath[1]){
            BonnieLocation = bonniePath[2];
        }
        else if(currentLocation == bonniePath[2]){
            BonnieLocation = bonniePath[3];
        }
        else if(currentLocation == bonniePath[3]){
            BonnieLocation = bonniePath[4];
        }
        else if(currentLocation == bonniePath[4]){
            BonnieLocation = bonniePath[5];
        }
        else if(currentLocation == bonniePath[5]){
            BonnieLocation = bonniePath[6];
        }
        else if(currentLocation == bonniePath[6]){
            if(rightDoorOn == true){
                BonnieLocation = bonniePath[2];
            }
            else if(rightDoorOn == false){
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
                bonnieFrame1 = LoadTexture("./images/bonnieframs/bonnieFrame1.png");
                bonnieFrame2 = LoadTexture("./images/bonnieframs/bonnieFrame2.png");
                bonnieFrame3 = LoadTexture("./images/bonnieframs/bonnieFrame3.png");
                bonnieFrame4 = LoadTexture("./images/bonnieframs/bonnieFrame4.png");
                bonnieFrame5 = LoadTexture("./images/bonnieframs/bonnieFrame5.png");
                bonnieFrame6 = LoadTexture("./images/bonnieframs/bonnieFrame6.png");
                bonnieFrame7 = LoadTexture("./images/bonnieframs/bonnieFrame7.png");
                bonnieFrame8 = LoadTexture("./images/bonnieframs/bonnieFrame8.png");
                bonnieFrame9 = LoadTexture("./images/bonnieframs/bonnieFrame9.png");

                bonniejumpscare = true;
                PlaySound(jumpscaresound);
            }
        }
    }

    void moveChica(int currentLocation){
        if(currentLocation == chicaPath[0]){
            ChicaLocation = chicaPath[1];
        }
        else if(currentLocation == chicaPath[1]){
            ChicaLocation = chicaPath[2];
        }
        else if(currentLocation == chicaPath[2]){
            ChicaLocation = chicaPath[3];
        }
        else if(currentLocation == chicaPath[3]){
            ChicaLocation = chicaPath[4];
        }
        else if(currentLocation == chicaPath[4]){
            ChicaLocation = chicaPath[5];
        }
        else if(currentLocation == chicaPath[5]){ 
            ChicaLocation = chicaPath[6];
        }
        else if(currentLocation == chicaPath[6]){
            if(rightDoorOn == true){
                ChicaLocation = chicaPath[1];
            }
            else if(rightDoorOn == false){
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
                UnloadTexture(bonnieFrame1);
                UnloadTexture(bonnieFrame2);
                UnloadTexture(bonnieFrame3);
                UnloadTexture(bonnieFrame4);
                UnloadTexture(bonnieFrame5);
                UnloadTexture(bonnieFrame6);
                UnloadTexture(bonnieFrame7);
                UnloadTexture(bonnieFrame8);
                UnloadTexture(bonnieFrame9);
                chicaFrame1 = LoadTexture("./images/chicaFrames/chica1.png");
                chicaFrame2 = LoadTexture("./images/chicaFrames/chica2.png");
                chicaFrame3 = LoadTexture("./images/chicaFrames/chica3.png");
                chicaFrame4 = LoadTexture("./images/chicaFrames/chica4.png");
                chicaFrame5 = LoadTexture("./images/chicaFrames/chica5.png");
                chicaFrame6 = LoadTexture("./images/chicaFrames/chica6.png");
                chicaFrame7 = LoadTexture("./images/chicaFrames/chica7.png");
                chicaFrame8 = LoadTexture("./images/chicaFrames/chica8.png");
                chicaFrame9 = LoadTexture("./images/chicaFrames/chica9.png");
                chicaFrame10 = LoadTexture("./images/chicaFrames/chica10.png");
                chicaFrame11 = LoadTexture("./images/chicaFrames/chica11.png");
                chicajumpscare = true;   
            }
        }
    }
    void moveFreddy(int currentLocation){
        if(currentLocation == freddyPath[0]){
            FreddyLocation = freddyPath[1];
        }
        else if(currentLocation == freddyPath[1]){
            FreddyLocation = freddyPath[2];
        }
        else if(currentLocation == freddyPath[2]){
            FreddyLocation = freddyPath[3];
        }
        else if(currentLocation == freddyPath[3]){
            FreddyLocation = freddyPath[4];
        }
        else if(currentLocation == freddyPath[4]){
            if(rightDoorOn == true){
                FreddyLocation = freddyPath[0];
            }
            else if(rightDoorOn == false){
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
                UnloadTexture(bonnieFrame1);
                UnloadTexture(bonnieFrame2);
                UnloadTexture(bonnieFrame3);
                UnloadTexture(bonnieFrame4);
                UnloadTexture(bonnieFrame5);
                UnloadTexture(bonnieFrame6);
                UnloadTexture(bonnieFrame7);
                UnloadTexture(bonnieFrame8);
                UnloadTexture(bonnieFrame9);

                freddyFrame1 = LoadTexture("./images/freddyFrames/rizz1.png");
                freddyFrame2 = LoadTexture("./images/freddyFrames/rizz2.png");
                freddyFrame3 = LoadTexture("./images/freddyFrames/rizz3.png");
                freddyFrame4 = LoadTexture("./images/freddyFrames/rizz4.png");
                freddyFrame5 = LoadTexture("./images/freddyFrames/rizz5.png");
                freddyFrame6 = LoadTexture("./images/freddyFrames/rizz6.png");
                freddyFrame7 = LoadTexture("./images/freddyFrames/rizz7.png");
                freddyFrame8 = LoadTexture("./images/freddyFrames/rizz8.png");
                freddyFrame9 = LoadTexture("./images/freddyFrames/rizz9.png");
                freddyFrame10 = LoadTexture("./images/freddyFrames/rizz10.png");
                freddyFrame11 = LoadTexture("./images/freddyFrames/rizz11.png");
                freddyFrame12 = LoadTexture("./images/freddyFrames/rizz12.png");
                freddyFrame13 = LoadTexture("./images/freddyFrames/rizz13.png");
                freddyFrame14 = LoadTexture("./images/freddyFrames/rizz14.png");
                freddyFrame15 = LoadTexture("./images/freddyFrames/rizz15.png");
                freddyFrame16 = LoadTexture("./images/freddyFrames/rizz16.png");
                freddyFrame17 = LoadTexture("./images/freddyFrames/rizz17.png");
                freddyFrame18 = LoadTexture("./images/freddyFrames/rizz18.png");
                freddyFrame19 = LoadTexture("./images/freddyFrames/rizz19.png");
                freddyFrame20 = LoadTexture("./images/freddyFrames/rizz20.png");
                freddyFrame21 = LoadTexture("./images/freddyFrames/rizz21.png");
                freddyFrame22 = LoadTexture("./images/freddyFrames/rizz22.png");
                freddyFrame23 = LoadTexture("./images/freddyFrames/rizz23.png");
                freddyFrame24 = LoadTexture("./images/freddyFrames/rizz24.png");
                freddyFrame25 = LoadTexture("./images/freddyFrames/rizz25.png");
                freddyFrame26 = LoadTexture("./images/freddyFrames/rizz26.png");
                freddyjumpscare = true;
                PlaySound(freddygyat);
            }
            
        }
    }   
    void placeAnimatronic(int currentCamLocation){
        if(BonnieLocation == currentCamLocation){
            DrawTexture(bonnieCams, 0, 0, WHITE);
        }
        if(ChicaLocation == currentCamLocation){
            DrawTexture(chicaCams, 0, 0, WHITE);
        }
        if(FreddyLocation == currentCamLocation){
            DrawTexture(freddy, 0, 0, WHITE);
        }
    }
    void unloadAll(){
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
        UnloadTexture(leftDoor);
        UnloadTexture(rightDoor);

        UnloadTexture(bonnieFrame1);
        UnloadTexture(bonnieFrame2);
        UnloadTexture(bonnieFrame3);
        UnloadTexture(bonnieFrame4);
        UnloadTexture(bonnieFrame5);
        UnloadTexture(bonnieFrame6);
        UnloadTexture(bonnieFrame7);
        UnloadTexture(bonnieFrame8);
        UnloadTexture(bonnieFrame9);

        UnloadTexture(chicaFrame1);
        UnloadTexture(chicaFrame2);
        UnloadTexture(chicaFrame3);
        UnloadTexture(chicaFrame4);
        UnloadTexture(chicaFrame5);
        UnloadTexture(chicaFrame6);
        UnloadTexture(chicaFrame7);
        UnloadTexture(chicaFrame8);
        UnloadTexture(chicaFrame9);
        UnloadTexture(chicaFrame10);
        UnloadTexture(chicaFrame11);

        UnloadTexture(freddyFrame1);
        UnloadTexture(freddyFrame2);
        UnloadTexture(freddyFrame3);
        UnloadTexture(freddyFrame4);
        UnloadTexture(freddyFrame5);
        UnloadTexture(freddyFrame6);
        UnloadTexture(freddyFrame7);
        UnloadTexture(freddyFrame8);
        UnloadTexture(freddyFrame9);
        UnloadTexture(freddyFrame10);
        UnloadTexture(freddyFrame11);
        UnloadTexture(freddyFrame12);
        UnloadTexture(freddyFrame13);
        UnloadTexture(freddyFrame14);
        UnloadTexture(freddyFrame15);
        UnloadTexture(freddyFrame16);
        UnloadTexture(freddyFrame17);
        UnloadTexture(freddyFrame18);
        UnloadTexture(freddyFrame19);
        UnloadTexture(freddyFrame20);
        UnloadTexture(freddyFrame21);
        UnloadTexture(freddyFrame22);
        UnloadTexture(freddyFrame23);
        UnloadTexture(freddyFrame24);
        UnloadTexture(freddyFrame25);
        UnloadTexture(freddyFrame26);
        UnloadTexture(winScreen);

        UnloadSound(theme);
        UnloadSound(windowScare);
        UnloadSound(jumpscaresound);
        UnloadSound(freddygyat);
        UnloadSound(door);
        UnloadSound(win);
        UnloadSound(phoneNight1);
        UnloadSound(phoneNight2);
        UnloadSound(phoneNight3);
        UnloadSound(phoneNight4);
        UnloadSound(phoneNight5);
    }

}

int main () {

    int CameraLocation = 0;
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
    
    int currentNight = 1;

    InitWindow(screenWidth, screenHeight, "Fnaf But Bad!");
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
    leftDoor = LoadTexture("./images/leftDoor.png");
    rightDoor = LoadTexture("./images/rightDoor.png"); 
    winScreen = LoadTexture("./images/6am.png");

    win = LoadSound("./audio/win.mp3");
    door = LoadSound("./audio/door.mp3");
    theme = LoadSound("./audio/theme.mp3");
    windowScare = LoadSound("./audio/WindowScare.mp3");
    jumpscaresound = LoadSound("./audio/jumpscare.mp3");
    freddygyat = LoadSound("./audio/gyat.mp3");
    phoneNight1 = LoadSound("./audio/phoneNight1.mp3");
    phoneNight2 = LoadSound("./audio/phoneNight2.mp3");
    phoneNight3 = LoadSound("./audio/phoneNight3.mp3");
    phoneNight4 = LoadSound("./audio/phoneNight4.mp3");
    phoneNight5 = LoadSound("./audio/quirky.mp3");

    PlaySound(theme);
    SetSoundVolume(theme, 0.25f);

    int currentScene = 0;
    
    SetTargetFPS(60);

    while (WindowShouldClose() == false){

        if(leftDoorOn == true){
            leftDoorPowerDraw = 1;
        }
        else if(leftDoorOn == false){
            leftDoorPowerDraw = 0;
        }
        if(rightDoorOn == true){
            rightDoorPowerDraw = 1;
        }
        else if(rightDoorOn == false){
            rightDoorPowerDraw = 0;
        }
        if(leftLightOn == true){
            leftLightPowerDraw = 1;
        }
        else if(leftLightOn == false){
            leftLightPowerDraw = 0;
        }
        if(rightLightOn == true){
            rightLightPowerDraw = 1;
        }
        else if(rightLightOn == false){
            rightLightPowerDraw = 0;
        }
        string curPowStr = to_string(currentBattery);
        char const *currentBatteryAsChar = curPowStr.c_str();

        string curNightStr = "Night " + to_string(currentNight);
        char const *currentNightAsChar = curNightStr.c_str();

        Vector2 mousePos = GetMousePosition();
        totalPowerDraw = rightDoorPowerDraw + leftDoorPowerDraw + rightLightPowerDraw + leftLightPowerDraw + idlePowerDraw;

        BeginDrawing();
        ClearBackground(WHITE);
        if(currentScene == 0){
            clockCount = clockCountStart;
            currentBattery = maxBattery;
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
            if(hoveringNewGameX == true && hoveringNewGameY == true){
                textColorContinue = LIGHTGRAY;
                if(IsMouseButtonPressed(0)){
                    currentNight = 1;
                    currentScene = 1;
                    StopSound(theme);
                }
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
                    ifs.open("saveData.txt");
                    ifs >> currentNight;
                    ifs.close();
    
                    currentScene = 1;
                    StopSound(theme);
                    if(currentNight == 1){
                        if(!IsSoundPlaying(phoneNight1)){
                            PlaySound(phoneNight1);
                        }
                    }
                    else if(currentNight == 2){
                        if(!IsSoundPlaying(phoneNight2)){
                            PlaySound(phoneNight2);
                        }
                    }
                    else if(currentNight == 3){
                        if(!IsSoundPlaying(phoneNight3)){
                            PlaySound(phoneNight3);
                        }
                    }
                    else if(currentNight == 4){
                        if(!IsSoundPlaying(phoneNight4)){
                            PlaySound(phoneNight4);
                        }
                    }
                    else if(currentNight == 5){
                        if(!IsSoundPlaying(phoneNight5)){
                            PlaySound(phoneNight5);
                        }
                    }
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
            
            if(clockCount == 21600){
                clockChar = " 12AM";
            }
            if(clockCount == 18000){
                clockChar = " 1AM";
            }
            if(clockCount == 14400){
                clockChar = "2 AM";
            }
            if(clockCount == 10800){
                clockChar = "3 AM";
            }
            if(clockCount == 7200){
                clockChar = "4 AM";
            }
            if(clockCount == 3600){
                clockChar = "5 AM";
            }
            if(clockCount <= 0){
                EndDrawing();
                BeginDrawing();
                clockChar = "6 AM";
                PlaySound(win);
                ClearBackground(WHITE);
                DrawTexture(winScreen, 0, 0, WHITE);
                EndDrawing();
                WaitTime(10);
                currentNight++;
                currentScene = 0;
                ofs.open("saveData.txt");
                ofs << currentNight;
                ofs.close();

                FreddyLocation = freddyPath[0];
                BonnieLocation = bonniePath[0];
                ChicaLocation = chicaPath[0];
                BeginDrawing();        
            }
            clockCount--;

            if(bonniejumpscare == true){
                BeginDrawing();
                DrawTexture(bonnieFrame1, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame2, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame3, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame4, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame5, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame6, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame7, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame8, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame9, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);
            }

            if(bonniejumpscare == true){
                BeginDrawing();
                DrawTexture(bonnieFrame1, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame2, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame3, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame4, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame5, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame6, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame7, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame8, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame9, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);
            }
            
            if(freddyjumpscare == true){
                BeginDrawing();
                DrawTexture(bonnieFrame1, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame2, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame3, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame4, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame5, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame6, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame7, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame8, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(bonnieFrame9, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);
            }

            if(chicajumpscare == true){
                BeginDrawing();
                DrawTexture(chicaFrame1, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame2, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame3, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame4, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame5, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame6, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame7, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame8, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame9, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame10, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);

                BeginDrawing();
                DrawTexture(chicaFrame11, 0, 0, WHITE);
                EndDrawing();
                WaitTime(0.2);
            }

            if(freddyjumpscare == true){
                BeginDrawing();
                DrawTexture(freddyFrame1, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame2, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame3, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame4, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame5, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame6, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame7, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame8, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame9, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame10, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame11, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame12, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame13, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame14, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame15, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame16, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame17, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame18, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame19, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame20, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame21, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame22, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame23, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame24, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame25, 0, 0, WHITE);
                EndDrawing();

                WaitTime(0.2);
                BeginDrawing();
                DrawTexture(freddyFrame26, 0, 0, WHITE);
                EndDrawing();
            }
            
            if (LocationCounter > 0){
                LocationCounter--;
            }
            else if(LocationCounter == 0){

                currentBattery -= totalPowerDraw;

                bonnieRandomNumber = rand() % 5 + currentNight;
                chicaRandomNumber = rand() % 5 + currentNight;
                freddyRandomNumber = rand() % 5 + currentNight;
                if(bonnieRandomNumber == 5){
                    retard::moveBonnie(BonnieLocation);
                }
                if(chicaRandomNumber == 5){
                    retard::moveChica(ChicaLocation);
                }
                if(freddyRandomNumber == 5){
                    retard::moveFreddy(FreddyLocation);
                }
                LocationCounter = 360;
            }

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

                if(leftDoorOn == true){
                    DrawTexture(leftDoor, officeX, 0 , WHITE);
                }
                if (IsKeyPressed(KEY_Z))
                {
                    if (leftDoorOn == false)
                    {
                        leftDoorOn = true;
                        PlaySound(door);
                    }
                    else if(leftDoorOn == true){
                        leftDoorOn = false;
                    }
                    
                }

                if(rightDoorOn == true){
                    DrawTexture(rightDoor, officeX, 0 , WHITE);
                }
                if (IsKeyPressed(KEY_X))
                {
                    if (rightDoorOn == false)
                    {
                        rightDoorOn = true;
                        PlaySound(door);
                    }
                    else if(rightDoorOn == true){
                        rightDoorOn = false;
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
                if(leftDoorOn == true){
                    leftDoorPowerDraw = 1;
                    DrawText("Left Door Is Down", 100, 0, 10, WHITE);
                }
                else if(leftDoorOn == false){
                    leftDoorPowerDraw = 0;
                    DrawText("Left Door Is Up", 100, 10, 10, WHITE);
                }
                if(rightDoorOn == true){
                    rightDoorPowerDraw = 1;
                    DrawText("Right Door Is Down", 100, 30, 10, WHITE);
                }
                else if(rightDoorOn == false){
                    rightDoorPowerDraw = 0;
                    DrawText("Right Door Is Up", 100, 50, 10, WHITE);
                }
                if(leftLightOn == true){
                    leftLightPowerDraw = 1;
                    DrawText("Left Light Is On", 100, 70, 10, WHITE);
                }
                else if(leftLightOn == false){
                    leftLightPowerDraw = 0;
                    DrawText("Left Light Is Off", 100, 90, 10, WHITE);
                }
                if(rightLightOn == true){
                    rightLightPowerDraw = 1;
                    DrawText("Right Light Is On", 100, 110, 10, WHITE);
                }
                else if(rightLightOn == false){
                    rightLightPowerDraw = 0;
                    DrawText("Right Light Is Off", 100, 130, 10, WHITE);
                }
                DrawText(currentBatteryAsChar, 10, 1000, 100, WHITE);
                DrawText(clockChar, 1000, 20, 100, WHITE);
                DrawText(currentNightAsChar, 1500, 20, 100,WHITE);
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
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 1){
                DrawTexture(DiningTable, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 2){
                DrawTexture(Backstage, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 3){
                DrawTexture(PiratesCove, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 4){
                DrawTexture(SupplyCloset, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 5){
                DrawTexture(WestHall, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 6){
                DrawTexture(WestHallCorner, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 7){
                DrawTexture(EastHall, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 8){
                DrawTexture(EastHallCorner, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 9){
                DrawRectangle(0, 0, 1920, 1080, BLACK);
                retard::placeAnimatronic(CameraLocation);
            }
            if(CameraLocation == 10){
                DrawTexture(Restroom, 0, 0, WHITE);
                retard::placeAnimatronic(CameraLocation);
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
    retard::unloadAll();

    CloseWindow();
    return 0;
}