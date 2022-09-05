#include "../INCLUDES.h"
#include "../Player/Nemo.h"

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


  /** Vector's */
  //Vector2 puzzle_position = {608.5, 386.5};

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

  /** Function's */
  Puzzle(); //Constructor
  void collision();
  void update();
  void draw();
  void unloadTextures();

  /** Animation */
  // divide sprite-sheet into frames
  Rectangle frameRec = { 0.0f, 0.0f, (float)PuzzelTriangle.width / 3, (float)PuzzelTriangle.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 8; // animtation fps

  ~Puzzle(); //Destructor
};


