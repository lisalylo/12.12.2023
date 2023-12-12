#include <cstdlib>

#include "raylib.h"

#include "config.h"

Texture2D cookie = LoadTexture ("assets/graphics/cookie.png");

void screen_menu(){
    DrawTexture(cookie, 10, 100, WHITE);
}