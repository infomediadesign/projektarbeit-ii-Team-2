#include "../INCLUDES.h"
#include "../Player/Nemo.h"
#include "Collision.h"

class Puzzle {

public:

  Game::Nemo *nemo = new Game::Nemo();

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

  Texture2D Dialogbox = LoadTexture("assets/graphics/Character/Dialogbox.png");

  Texture2D EpanoxSheet = LoadTexture("assets/graphics/Character/ReZeitwesenBouncefuerNick.png");
  Texture2D TimeCrystal = LoadTexture("assets/graphics/Items/Standuhr_Final_Sheet.png");

  Rectangle CrystalFrameRec = { 0.0f, 0.0f, (float)TimeCrystal.width / 4, (float)TimeCrystal.height };
  int crystal_currentFrame   = 0;
  int crystal_framescounter = 0;
  int crystal_framesspeed = 4;
  Rectangle Crystalrec  = {}; //The attributes for the Rectangle will be set.

  Rectangle EpanoxFrameRec = { 0.0f, 0.0f, (float)TimeCrystal.width / 20, (float)TimeCrystal.height };
  int epanox_currentFrame   = 0;
  int epanox_framescounter = 0;
  int epanox_framesspeed    = 4;
  Rectangle Epanoxrec  = {}; //The attributes for the Rectangle will be set.

  void crystaldraw();


  /** Rectangles */
  Rectangle Chest = {608, 385, 32, 36};
  Rectangle Chest2 = {896, 288, 32, 36};
  Rectangle Chest3 = {1504, 480.5, 32, 36};
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

  Rectangle ChestNS = {608, 385, 28, 32};
  Rectangle ChestNS2 = {896, 288, 28, 32};
  Rectangle ChestNS3 = {1504, 480.5, 28, 32};

  Rectangle  EpanoxRec = {770, 945, 10, 20}; //EpanoxRec
  Rectangle EpanoxRec2 = {760, 945, 20, 28};

  ///animation Rectangles
  // divide sprite-sheet into frames
  Rectangle frameRec = { 0.0f, 0.0f, (float)PuzzelTriangle.width / 3, (float)PuzzelTriangle.height };
  Rectangle frameRecTorch = { 0.0f, 0.0f, (float)Torch.width / 4, (float)Torch.height };
  Rectangle frameRecPortal = { 0.0f, 0.0f, (float)Portal.width / 12, (float)Portal.height };
  Rectangle frameRecEpanox = { 0.0f, 0.0f, (float)EpanoxSheet.width / 20, (float)EpanoxSheet.height };

  /** Int's */
  //animation
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 8; // animtation fps
  int framesSpeed4  = 4; // torch animtation fps

  int textState = 1;

  /** Floats */
  float timesinceIdle = 0;

  /** Vector's */
  //Vector2 puzzle_position = {608.5, 386.5};
  Vector2 TorchPosition = {160, 672};
  Vector2 TorchPosition2 = {320, 672};
  Vector2 TorchPosition3 = {352, 702};
  Vector2 TorchPosition4 = {448, 702};
  Vector2 TorchPosition5 = {544, 606};
  Vector2 TorchPosition6 = {640, 606};
  Vector2 TorchPosition7 = {544, 318};
  Vector2 TorchPosition8 = {640, 318};
  Vector2 TorchPosition9 = {768, 670};
  Vector2 TorchPosition10 = {1024, 670};
  Vector2 TorchPosition11 = {960, 446};
  Vector2 TorchPosition12 = {928, 222};
  Vector2 TorchPosition13 = {896, 222};

  Vector2 TorchPosition14 = {544, 894};
  Vector2 TorchPosition15 = {640, 894};
  Vector2 TorchPosition16 = {864, 990};
  Vector2 TorchPosition17 = {1120, 990};
  Vector2 TorchPosition18 = {1376, 990};
  Vector2 TorchPosition19 = {1408, 446};
  Vector2 TorchPosition20 = {1504, 446};
  Vector2 TorchPosition21 = {1472, 62};
  Vector2 TorchPosition24 = {1440, 62};
  Vector2 TorchPosition22 = {1312, 62};
  Vector2 TorchPosition23 = {1600, 62};

  Vector2 PortalPosition = {};

  Vector2 EpanoxPosition = {760, 945};

  Font textFont = LoadFont("assets/Born2bSportyV2.ttf");

  float fontSize = 20;
  float fontSpacing;
  Vector2 fontTextPosLINE1   = {nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75};
  Vector2 fontTextPosLINE2 = {nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110};
  Vector2 fontTextPosLINE3    = {nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 135};

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

  bool wallPuzzlePart1 = false;
  bool wallPuzzlePart2 = false;
  bool wallPuzzlePart3 = false;
  bool wallIsOpen = false;

  bool text = false;
  bool textdoor = false;
  bool textdoor2 = false;
  bool textdoor3 = false;

  bool EpanoxCollision = false;
  bool EpanoxCollision2 = false;

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
  void epanoxAnimation();
  void update();
  void draw();

  ~Puzzle(); //Destructor
};