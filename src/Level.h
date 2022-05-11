#pragma once
#include <raylib.h>

namespace Game 
{
  class Level 
  {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");

    //Music music   = LoadMusicStream("assets/audio/tracks/song.mp3/wav");
    
    //UnloadMusicStream(music); // Unload music stream buffers from RAM

    void Draw();
  };
}