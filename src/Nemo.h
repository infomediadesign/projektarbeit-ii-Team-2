#pragma once
#include <memory>
#include <raylib.h>
#include <vector>

namespace Game {
  class Nemo {
  public:
    int HP; // The Integer is just temporary
    Texture2D Front = LoadTexture("assets/graphics/NemoFrontwalk-Sheet.png");
    Texture2D Back  = LoadTexture("assets/graphics/NemoHintenWalk-Sheet.png");
    Texture2D Left  = LoadTexture("assets/graphics/NemoLinksWalk-Sheet.png");
    Texture2D Right = LoadTexture("assets/graphics/NemoRechtsWalk-Sheet.png");

    void Draw();   // Drawing the Sprite
    void Update(); // Magical Shit will about to be committed in there! :D
  };
} // namespace Game
