#include "../INCLUDES.h"
#include "../Level/Level.h"
#include "../Player/Nemo.h"
#include "../Level/Dialogue.h"

class Collision {
private:
public:

  Game::Nemo * nemo;
  Game::Level * level;

  Game::Dialog dialog;

  Texture2D Dialogbox = LoadTexture("assets/graphics/Character/Dialogbox.png");
  Texture2D EpanoxSheet = LoadTexture("assets/graphics/Character/ReZeitwesenBouncefuerNick.png");
  Texture2D Torch = LoadTexture("assets/graphics/Items/Asset_Feuerschale-Sheet.png");

  Rectangle  EpanoxRec = {972.5, 462.5, 10, 20}; //EpanoxRec
  Rectangle EpanoxRec2 = {961, 458, 20, 28};

  /// RECTANGLES
  //Outside Rectangles for wall collision

  Rectangle OutsideWallLeft = {865, 320, 32, 288};
  Rectangle OutsideWallRight = {990, 320, 32, 288};
  Rectangle OutsideWallBottom = {873, 576, 160, 32};

  //Inside Rectangles for wall collision
  vector<Rectangle> outsideWall;
  vector<Rectangle> insideWall;
  vector<Rectangle> torchPosRec;

  //outside the pyramid
  bool wallCollision  = false;
  bool wallCollision2 = false;
  bool wallCollision3 = false;

  bool EpanoxCollision = false;
  bool EpanoxCollision2 = false;

  int textState = 1;
  bool text = false;

  Vector2 EpanoxPosition = {961, 458};

  // animation
  Rectangle frameRec = { 0.0f, 0.0f, (float)EpanoxSheet.width / 20, (float)EpanoxSheet.height };
  Rectangle frameRecTorch = { 0.0f, 0.0f, (float)Torch.width / 4, (float)Torch.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 4; // animtation fps

  Collision(nlohmann::json levelMapDungeon); //wall collision

  void stopnemo(); //funkction to stop nemos movement

  void epanoxCollision(); //dialog starts when the collision with epanox happens

  void outPyraWallCollision(); //both have to do with the collision creation of the rectangles for the wall collision
  void inPryaWallCollision();

  void draw();
  void walldraw();
  void torchAnimations();
};