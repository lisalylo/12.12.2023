#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "screen_menu.h"

#include "screen_game.h"

#include "screen_gameover.h"

 void game_over(){

     BeginDrawing();
     DrawText("GameOver, Oh man alter",10,10,30,LIGHTGRAY);
     EndDrawing();

}
