#pragma once
#include <raylib.h>

namespace Game 
{
  class Level 
  {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");        

    void Draw();
  };
}