#pragma once
#include "Sprite.h"

#include <config.h>
#include <memory>
#include <raylib.h>
#include <vector>

namespace Game {
  class Nemo {
  public:
    int HP; // The Integer is just temporary; HP is not initiallised!

    Vector2 NemoPosition = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 }; // Starting point for nemo

    Texture2D Front = LoadTexture("assets/graphics/NemoFrontwalk-Sheet.png");
    Texture2D Back  = LoadTexture("assets/graphics/NemoHintenWalk-Sheet.png");
    Texture2D Left  = LoadTexture("assets/graphics/NemoLinksWalk-Sheet.png");
    Texture2D Right = LoadTexture("assets/graphics/NemoRechtsWalk-Sheet.png");

    // devide spritesheet into frames
    Rectangle frameRec = { 0.0f, 0.0f, (float)Front.width / 3, (float)Front.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 8; // animtation fps

    void Update(); // Magical Shit will about to be committed in there! :D

    void Draw(); // Drawing the Sprite
  };
} // namespace Game
