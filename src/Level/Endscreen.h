#include "../INCLUDES.h"

class Endscreen {
public:
  Texture2D Endscreen = LoadTexture("assets/graphics/backgrounds/Start.png");

  int creditPosY = 500;
  int positionX = 450;
  int Textsize = 20;

  void update();
  void draw();

};

