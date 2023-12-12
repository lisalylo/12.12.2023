#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "screen_menu.h"

#include "screen_game.h"

#include "screen_gameover.h"

void gameover(){
    DrawText("Game Over ... Oh man alter!", 10, 10, 30, PURPLE);
}