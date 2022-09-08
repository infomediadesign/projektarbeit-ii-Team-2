#include "../INCLUDES.h"
#include "../Level/Level.h"
#include "../Level/Map.h"
#include "../Player/Nemo.h"
#include "../Level/Dialogue.h"

class Collision {
private:
public:

  Game::Nemo * nemo;
  Game::Level * level;
  LevelMap * map;

  Game::Dialog dialog;

  Texture2D Dialogbox = LoadTexture("assets/graphics/Character/Dialogbox.png");
  Texture2D EpanoxSheet = LoadTexture("assets/graphics/Character/ReZeitwesenBouncefuerNick.png");

  Rectangle  EpanoxRec = {972.5, 462.5, 10, 10}; //EpanoxRec
  Rectangle EpanoxRec2 = {961, 458, 20, 24};

  //Sry about all these recs...
  //Outside Rectangles for wall collision
  Rectangle OutsideWallLeft = {865, 320, 32, 288};
  Rectangle OutsideWallRight = {990, 320, 32, 288};
  Rectangle OutsideWallBottom = {873, 576, 160, 32};

  bool wallCollision = false;

  bool EpanoxCollision = false;
  bool EpanoxCollision2 = false;

  int textState = 1;
  bool text = false;

  Vector2 EpanoxPosition = {961, 458};

  //Epanox animation
  Rectangle frameRec = { 0.0f, 0.0f, (float)EpanoxSheet.width / 20, (float)EpanoxSheet.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 4; // animtation fps

  void epanoxCollision();
  void outPyraWallCollision();
  void stopnemo();
  void update();
  void draw();
};