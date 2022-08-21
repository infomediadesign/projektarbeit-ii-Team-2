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

private:

  Rectangle frameRec = { 0.0f, 0.0f, (float)spr_mumy.width / 7, (float)spr_mumy.height };
  int currentFrame   = 6;
  Rectangle mumyrec  = {}; //The attributes for the Rectangle will be set.
};


