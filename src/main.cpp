﻿#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "Screen_menu.h"

int globalgamestate = 0;

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    Texture2D myTexture = LoadTexture("assets/graphics/testimage.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        //die abfrage ist schlecht, weil wenn 0 gedrückt ist, macht es keinen SInn danach noch nach 1 und 2 zu prüfen
       if (IsKeyReleased(KEY_KP_0)){
           globalgamestate = 0;
       }
        if (IsKeyReleased(KEY_KP_1)){
            globalgamestate = 1;
        }
        if (IsKeyReleased(KEY_KP_2)){
            globalgamestate = 2;
        }

        ClearBackground(WHITE);

        switch (globalgamestate){
            case 0 :
                screen_menu();
            break;
            case 1 :
                DrawText("das ist der game screen state", 10, 10, 30, LIGHTGRAY);
            break;
            case 2 :
                DrawText("das ist der game over screen state", 10, 10, 30, LIGHTGRAY);
            default:
                break;
        }

        if (globalgamestate == 0) {
        DrawText("das ist der menu screen state", 10, 10, 30, LIGHTGRAY);
    }else{
        DrawText("das ist was anderes", 10, 10, 30, LIGHTGRAY);
        }
        DrawTexture(myTexture, 10, 100, WHITE);

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
