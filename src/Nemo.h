#pragma once
#include "Sprite.h"

#include <config.h>
#include <memory>
#include <raylib.h>
#include <vector>

namespace Game {
  class Nemo {
  public:
    Vector2 NemoPosition = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };

    int HP; // The Integer is just temporary
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 8; // animtation fps
    Texture2D Front    = LoadTexture("assets/graphics/NemoFrontwalk-Sheet.png");
    Texture2D Back     = LoadTexture("assets/graphics/NemoHintenWalk-Sheet.png");
    Texture2D Left     = LoadTexture("assets/graphics/NemoLinksWalk-Sheet.png");
    Texture2D Right    = LoadTexture("assets/graphics/NemoRechtsWalk-Sheet.png");
    Rectangle frameRec = { 0.0f, 0.0f, (float)Front.width / 3, (float)Front.height };

    void Draw();   // Drawing the Sprite
    void Update(); // Magical Shit will about to be committed in there! :D
  };
} // namespace Game
