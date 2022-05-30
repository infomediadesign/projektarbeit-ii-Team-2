#pragma once
#include "../Sprite/Sprite.h"

#include <config.h>
#include <memory>
#include <raylib.h>
#include <vector>

namespace Game {
  class Nemo {
  public:
    int HP; // The Integer is just temporary; HP is not initiallised!
    float walkspeed = 1.5;
    float nemowidth = 16;
    float nemoheight = 16;
    Vector2 NemoPosition = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 }; //Starting Point for Nemo
    bool alive = true;
    bool active = true; //This Bool determines, if Nemo is drawn, if it is set to false, Nemo dissapears from the Overworld
    
    enum class direction // Setting the Enum for the direction
    {
      UP,
      DOWN,
      LEFT,
      RIGHT,
    };
    direction Direction = direction::DOWN; // Setting the Standard for the Enum on down.

    Texture2D Front = LoadTexture("assets/graphics/NemoFrontwalk-Sheet.png");
    Texture2D Back  = LoadTexture("assets/graphics/NemoHintenWalk-Sheet.png");
    Texture2D Left  = LoadTexture("assets/graphics/NemoLinksWalk-Sheet.png");
    Texture2D Right = LoadTexture("assets/graphics/NemoRechtsWalk-Sheet.png");

    Sound fxMp3 = LoadSound("resources/BodyCrawlsGearBody FS047801.mp3"); // Load Mp3 audio file

    // devide spritesheet into frames
    Rectangle frameRec = { 0.0f, 0.0f, (float)Front.width / 3, (float)Front.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 8; // animtation fps
    Rectangle nemorec  = {}; //The attributes for the Rectangle will be set in the Draw method.

    void Update(); // Magical Shit will about to be committed in there! :D

    void Draw(); // Drawing the Sprite

    ~Nemo();
  };
} // namespace Game
