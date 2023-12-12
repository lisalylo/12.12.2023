#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "screen_menu.h"

#include "screen_game.h"

#include "screen_gameover.h"


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
        if (IsKeyReleased(KEY_ONE)){
            globalgamestate = 0;
        }
        if (IsKeyReleased(KEY_TWO)){
            globalgamestate = 1;
        }
        if (IsKeyReleased(KEY_THREE)){
            globalgamestate = 2;
        }

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(WHITE);


        switch (globalgamestate) {
            case 0:
               screen_menu();
               break;
                break;
            case 1:
                screen_game();
                break;
            case 2:
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
