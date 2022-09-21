#include "../INCLUDES.h"

class Endscreen {
public:

  ///Textures and Fonts
  Texture2D ThankYou = LoadTexture("assets/graphics/backgrounds/Thankyouscreen.png");
  Texture2D Endscreen = LoadTexture("assets/graphics/Credits/Credit_Hintergrund.png");

  Texture2D Monster1 = LoadTexture("assets/graphics/Credits/Mumie_credit-Sheet.png");
  Texture2D Monster2 = LoadTexture("assets/graphics/Credits/Pharao_credit-Sheet.png");
  Texture2D Monster3 = LoadTexture("assets/graphics/Credits/Timeshadow_credit-Sheet.png");

  Texture2D Epanox = LoadTexture("assets/graphics/Credits/Epanox_credit-Sheet.png");
  Texture2D Nemo = LoadTexture("assets/graphics/Credits/Nemo_Credit_walk-Sheet.png");


  Font textFont = LoadFont("assets/Born2bSportyV2.ttf");
  ///Rectangles
  Rectangle Monster1FrameRec = { 0.0f, 0.0f, (float)Monster1.width / 4, (float)Monster1.height };
  Rectangle Monster1rec = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 - 80, 32, 32};

  Rectangle Monster2FrameRec = { 0.0f, 0.0f, (float)Monster2.width / 2, (float)Monster2.height };
  Rectangle Monster2rec = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 - 40, 32, 32};

  Rectangle Monster3FrameRec = { 0.0f, 0.0f, (float)Monster3.width / 6, (float)Monster3.height };
  Rectangle Monster3rec = { Game::ScreenWidth / 2, Game::ScreenHeight / 2, 32, 32};

  Rectangle EpanoxFrameRec = { 0.0f, 0.0f, (float)Epanox.width / 20, (float)Epanox.height };
  Rectangle Epanoxrec = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 + 40, 32, 32};

  Rectangle NemoFrameRec = { 0.0f, 0.0f, (float)Nemo.width / 8, (float)Nemo.height };
  Rectangle Nemorec = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 + 80, 32, 32};

  ///Ints
  int positionX = 200;
  int positionTitleX = 540;
  int positionTitle2X = 360;
  int positionTitle3X = 460;

  int monster1_currentFrame   = 0;
  int monster1_framescounter = 0;
  int monster1_framesspeed    = 4;

  int monster2_currentFrame   = 0;
  int monster2_framescounter = 0;
  int monster2_framesspeed    = 4;

  int monster3_currentFrame   = 0;
  int monster3_framescounter = 0;
  int monster3_framesspeed    = 4;

  int epanox_currentFrame   = 0;
  int epanox_framescounter = 0;
  int epanox_framesspeed    = 4;

  int nemo_currentFrame   = 0;
  int nemo_framescounter = 0;
  int nemo_framesspeed    = 4;

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
  Vector2 textPosTitle3   = {static_cast<float>(positionTitle3X), static_cast<float>(creditPosY)};


  ///Functions
  void update();
  void draw();
  void thankyoudraw();

};

