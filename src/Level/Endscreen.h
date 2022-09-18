#include "../INCLUDES.h"

class Endscreen {
public:

  ///Textures and Fonts
  Texture2D Endscreen = LoadTexture("assets/graphics/backgrounds/Start.png");

  Font textFont = LoadFont("assets/Born2bSportyV2.ttf");

  ///Ints
  int positionX = 200;
  int positionTitleX = 540;
  int positionTitle2X = 360;

  ///Floats
  float creditPosY = 500;

  float fontSize = 45;
  float fontTitleSize = 60;

  float fontSpacing = 0.05;
  float add40 = 50;

  ///Vectors
  Vector2 textPos   = {static_cast<float>(positionX), static_cast<float>(creditPosY)};
  Vector2 textPosTitle   = {static_cast<float>(positionTitleX), static_cast<float>(creditPosY)};
  Vector2 textPosTitle2   = {static_cast<float>(positionTitle2X), static_cast<float>(creditPosY)};

  ///Functions
  void update();
  void draw();

};

