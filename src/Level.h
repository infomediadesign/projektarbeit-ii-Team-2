#pragma once
#include <raylib.h>

namespace Game 
{
  class Level 
  {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png"); 

    Music music   = LoadMusicStream("resources/Hair-Trigger-WST011601.mp3"); //placeholder music 

    void Draw();

    void Music();
  };
}