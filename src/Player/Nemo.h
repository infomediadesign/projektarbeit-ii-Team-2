#pragma once
#include "../Sprite/Sprite.h"
#include "../Level/GameAudio.h"

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
    bool sound = true;  //This Bool deterimines, if Sound is Played
    
    enum class direction // Setting the Enum for the direction
    {
      STAND,
      UP,
      DOWN,
      LEFT,
      RIGHT,
    };
    direction Direction = direction::DOWN; // Setting the Standard for the Enum on down.    

    Texture2D Stand = LoadTexture("assets/graphics/Nemo_StandingMutze.png");
    Texture2D Front = LoadTexture("assets/graphics/Character/Nemo_Walkfront.png");
    Texture2D Back  = LoadTexture("assets/graphics/Character/Nemo_Walkback.png");
    Texture2D Left  = LoadTexture("assets/graphics/Character/Nemo_Walkleft.png");
    Texture2D Right = LoadTexture("assets/graphics/Character/Nemo_Walkright.png");    

    // devide spritesheet into frames
    Rectangle frameRec = { 0.0f, 0.0f, (float)Front.width / 3, (float)Front.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 8; // animtation fps
    Rectangle nemorec  = {}; //The attributes for the Rectangle will be set in the Draw method.

    // devide spritesheet into frames
    //for the Standing Animation
    Rectangle StandframeRec = { 0.0f, 0.0f, (float)Front.width / 4, (float)Front.height };
    int Stand_currentFrame   = 0;
    int Stand_framesCounter  = 0;
    int Stand_framesSpeed    = 8; 
    Rectangle Stand_nemorec  = {}; 

    void Update(); // Magical Shit will about to be committed in there! :D

    void Draw(); // Drawing the Sprite

    ~Nemo();
  };
} // namespace Game
