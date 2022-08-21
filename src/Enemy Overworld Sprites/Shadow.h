//
// Created by goerk on 21.08.2022.
//
#include "../INCLUDES.h"


class Shadow {

public:
  void Update();
  void Draw();

  Rectangle getShadowRec();

  Texture2D spr_shadow = LoadTexture("assets/graphics/map/Level1/Timeshadow_Final-Sheet.png");
  Rectangle Shadowrec = { 590.5 + 8, 1014 + 5, 16, 20 };

private:

  Rectangle frameRec = { 0.0f, 0.0f, static_cast<float>((float)spr_shadow.width / 6), (float)spr_shadow.height };
  int currentFrame   = 4;
  int framesCounter  = 0;
  int framesSpeed    = 2; // animation fps
  Rectangle shadowrec  = {}; //The attributes for the Rectangle will be set.
};
