#include <iostream>
#include <fstream>
#include <raylib.h>

using namespace std;
Texture2D backGroundMainMenu;
Texture2D backGroundOffice;
Texture2D thiccChica;
Sound theme;

float textSize = 100;
bool maxTextSize = false;

Color textColorNewGame = WHITE;
Color textColorContinue = WHITE;
Color textColorQuit = WHITE;

int officeX = -400;
int officeY;

int main () {

    bool leftLightOn = false;

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
    
    SetSoundVolume(theme, 1);
    theme = LoadSound("./audio/theme.mp3");
    PlaySound(theme);

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
            DrawTexture(backGroundOffice, officeX, officeY, WHITE);
            
            if(leftLightOn == true){
                DrawTexture(thiccChica, officeX + 1900, -50, WHITE);
            }

            if(IsKeyDown(KEY_RIGHT)){
                leftLightOn = true;
            }
            else{
                leftLightOn = false;
            }

            if(mousePos.x <= 20){
                if(officeX < 0){
                    officeX += 5;
                }
            }
            if(mousePos.x >= 1900){
                
                if(officeX > -1235){
                    officeX -= 5;
                }
                
            }

        }
        EndDrawing();
    }
    UnloadTexture(backGroundMainMenu);
    UnloadTexture(backGroundOffice);
    UnloadSound(theme);
    CloseWindow();
    return 0;
}
