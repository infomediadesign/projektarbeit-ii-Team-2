//
// Created by goerk on 21.08.2022.
//
#include "../INCLUDES.h"

class Mumy {

public:
  void Update();
  void Draw();

  Rectangle getMumyRec();

  Texture2D spr_mumy = LoadTexture("assets/graphics/map/Level1/Mumie_Final-Sheet.png");
  Rectangle MumyRec = { 592 + 8, 712 + 5, 16, 20 };

  Rectangle checkpoint1 {470.5, 722, 32, 32};
  Rectangle checkpoint2 {688, 722, 32, 32};

  bool f_right = false;
  bool f_left = true;

  enum class direction { LEFT, RIGHT};

  direction Direction = direction::LEFT;

private:

  Rectangle frameRec = { 0.0f, 0.0f, (float)spr_mumy.width / 7, (float)spr_mumy.height };
  int currentFrame   = 4;
  int framesCounter  = 0;
  int framesSpeed    = 2; // animation fps
  Rectangle mumyrec  = {}; //The attributes for the Rectangle will be set.
};


