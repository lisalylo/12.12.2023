#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "screen_menu.h"

#include "screen_game.h"

#include "screen_gameover.h"


enum states {menu, game, gameover};

enum states globalgamestate = menu;

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

        if (IsKeyReleased(KEY_ENTER)){
            globalgamestate = game;
        }
        if (IsKeyReleased(KEY_TWO)){
            globalgamestate = menu;
        }
        if (IsKeyReleased(KEY_THREE)){
            globalgamestate = gameover;
        }

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(WHITE);


        switch (globalgamestate) {
            case menu:
               screen_menu();
               break;

            case game:
                screen_game();
                break;
            case gameover:
               screen_gameover();
               break;
        }
            //if(globalgamestate == 0){
               // DrawText("Das ist der Menu Screen-state", 10, 10, 30, LIGHTGRAY);
           // }
            //else{
            //    DrawText("Das ist ein anderer State",10,10,30,LIGHTGRAY);
           // }


            DrawText("Hello, world!", 10, 10, 30, LIGHTGRAY);
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
