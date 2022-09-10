#include "../INCLUDES.h"
#include "../Player/Nemo.h"
#include "Collision.h"

class Puzzle {

public:

  Game::Nemo *nemo = new Game::Nemo();
  Collision collision;

  /** Textures */
  Texture2D ChestOpen = LoadTexture("assets/graphics/Items/OpenChest.png");

  Texture2D HelmetItem = LoadTexture("assets/graphics/Items/Helm.png");
  Texture2D HelmetTexture = LoadTexture("assets/graphics/Items/Helm.png");
  Texture2D ChestplateTexture = LoadTexture("assets/graphics/Items/Chestplate.png");
  Texture2D HpPotionTexture = LoadTexture("assets/graphics/Items/HP_Potion.png");
  Texture2D KeyTexture = LoadTexture("assets/graphics/Items/Key.png");

  Texture2D PuzzelTriangle = LoadTexture("assets/graphics/Items/DreieckBodenPlattenSenkung.png");

  Texture2D TriangleTrapDoor = LoadTexture("assets/graphics/Items/Druckplatte.png");
  Texture2D CircleTrapDoor = LoadTexture("assets/graphics/Items/CircleTrapDoor.png");
  Texture2D SquareTrapDoor = LoadTexture("assets/graphics/Items/SquareTrapDoor.png");

  Texture2D WallTile = LoadTexture("assets/graphics/Items/Wand.png");
  Texture2D DungeonFloorTile = LoadTexture("assets/graphics/Items/DungeonFloorPlate.png");

  Texture2D Torch = LoadTexture("assets/graphics/Items/Asset_Feuerschale-Sheet.png");
  Texture2D Portal = LoadTexture("assets/graphics/Items/ZeitportalOpenClose-Sheet.png");

  /** Rectangles */
  Rectangle Chest = {608, 385, 28, 32};
  Rectangle Chest2 = {896, 288, 28, 32};
  Rectangle Chest3 = {1504, 480.5, 28, 32};
  Rectangle PuzzleTriangle = {639, 1046, 32, 32}; //triangle
  Rectangle PuzzleCircle   = {575, 1046, 32, 32}; //circle
  Rectangle PuzzleSquare   = {703, 1046, 32, 32}; //square
  Rectangle Helmet = {574, 383.5, 17, 19};
  Rectangle Chestplate = {935, 276, 17, 19};
  Rectangle HpPotion = {1452, 504, 17, 19};
  Rectangle Key = {645, 380, 17, 19};

  Rectangle door1 = {736, 673.5, 32, 96};  //door 1 after key
  Rectangle door2 = {576, 896, 64, 32};   //door 2 to puzzle room
  Rectangle door3 = {800, 992, 32, 96};   //door 3 after puzzle door1

  Rectangle ChestNS = {608, 385, 18, 32};
  Rectangle ChestNS2 = {896, 288, 18, 32};
  Rectangle ChestNS3 = {1504, 480.5, 18, 32};

  ///animation Rectangles
  // divide sprite-sheet into frames
  Rectangle frameRec = { 0.0f, 0.0f, (float)PuzzelTriangle.width / 3, (float)PuzzelTriangle.height };
  Rectangle frameRecTorch = { 0.0f, 0.0f, (float)Torch.width / 4, (float)Torch.height };
  Rectangle frameRecPortal = { 0.0f, 0.0f, (float)Portal.width / 12, (float)Portal.height };

  /** Int's */
  //animation
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 8; // animtation fps
  int framesSpeedTorch  = 4; // torch animtation fps
  int framesSpeedPortal = 4; // portal animtation fps

  /** Vector's */
  //Vector2 puzzle_position = {608.5, 386.5};
  Vector2 TorchPosition = {160, 672};
  Vector2 TorchPosition2 = {320, 672};
  Vector2 PortalPosition = {1438, 76};

  /** Bool's */
  bool chestCollision = false;
  bool chestCollision2 = false;
  bool chestCollision3 = false;

  bool puzzleCollision1 = false;
  bool puzzleCollision2 = false;
  bool puzzleCollision3 = false;

  bool helmetCollision = false;
  bool chestplateCollision = false;
  bool hp_potionCollision = false;
  bool keyCollision = false;

  bool chestIsDrawn = false;
  bool chest2IsDrawn = false;
  bool chest3IsDrawn = false;
  bool helmetIsDrawn = false;
  bool chestplateIsDrawn = false;
  bool hpPotionIsDrawn = false;
  bool keyIsDrawn = false;

  bool isKeyPickedUp = false;

  bool wallIsOpen = false;

  /** Bool's Nemo Stop */
  bool doorcollision1 = false;
  bool doorcollision2 = false;
  bool doorcollision3 = false;

  bool chestCollisionNS1 = false;
  bool chestCollisionNS2 = false;
  bool chestCollisionNS3 = false;

  /** Function's */
  Puzzle(); //Constructor

  void collisionChecks();
  void stopNemo();
  void torchAnimation();
  void portalAnimation();
  void update();
  void draw();

  ~Puzzle(); //Destructor
};