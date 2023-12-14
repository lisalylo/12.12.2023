#include <cstdlib>

#include "raylib.h"

#include <iostream>

#include "config.h"

#include "screen_menu.h"

#include "screen_game.h"

#include "screen_gameover.h"


enum states {menu, game, gameover};

enum states globalgamestate = menu;


int main() {
    int time = 0;
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif
    Texture2D cookie = LoadTexture("assets/graphics/cookie-png-transparent-images-background-23.png");

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()


        ClearBackground(WHITE);
        if (globalgamestate == game) {


            if (time < 3600) {
                time++;
            }
            if (time == 3600) {
                globalgamestate = gameover;
            }
        }


        if (IsKeyReleased(KEY_ENTER)){
            globalgamestate = game;
        }
        if (IsKeyReleased(KEY_TWO)){
            globalgamestate = menu;
        }



        switch (globalgamestate) {
            case menu:
               screen_menu();
               break;

            case game:
                DrawTexture(cookie, 10, 100, WHITE);
                break;
            case gameover:
               screen_gameover();
               break;
        }

        EndDrawing();
    } // Main game loop end

    UnloadTexture(cookie);

    CloseWindow();

    return EXIT_SUCCESS;
}
