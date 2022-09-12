//
// Created by goerk on 21.08.2022.
//

#include "../INCLUDES.h"

class Pharaoh {
public:
  void Update();
  void Draw();

  Rectangle getPharaohRec();

  Texture2D spr_Pharaoh = LoadTexture("assets/graphics/map/Level1/Pharao_Final-Sheet.png");
  Rectangle Pharaohrec = { 1442 + 8, 208.5 + 5, static_cast<float>(spr_Pharaoh.width), static_cast<float>(spr_Pharaoh.height) };
  Rectangle pharaohrec  = {}; //The attributes for the Rectangle will be set.
private:

  Rectangle frameRec = { 0.0f, 0.0f, static_cast<float>((float)spr_Pharaoh.width / 2), (float)spr_Pharaoh.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 2; // animation fps

};

