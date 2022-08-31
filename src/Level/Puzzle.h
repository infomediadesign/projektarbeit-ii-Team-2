#include "../INCLUDES.h"
#include "../Player/Nemo.h"

class Puzzle {

public:

  Game::Nemo *nemo = new Game::Nemo();

  Texture2D ChestOpen = LoadTexture("assets/graphics/Items/OpenChest.png");
  Texture2D PuzzelTriangle = LoadTexture("assets/graphics/Items/DreieckBodenPlattenSenkung.png");
  Texture2D HelmetItem     = LoadTexture("assets/graphics/Items/Helm.png");
  Texture2D DungeonFloorTile = LoadTexture("assets/graphics/Items/DungeonFloorPlate.png");
  Texture2D TriangleTrapDoor = LoadTexture("assets/graphics/Items/Druckplatte.png");
  Texture2D CircleTrapDoor = LoadTexture("assets/graphics/Items/CircleTrapDoor.png");
  Texture2D SquareTrapDoor = LoadTexture("assets/graphics/Items/SquareTrapDoor.png");
  Texture2D WallTile = LoadTexture("assets/graphics/Items/Wand.png");

  Rectangle Chest = {608.5, 386.5, 28, 32};
  Rectangle PuzzleTriangle = {639, 1046, 32, 32}; //triangle
  Rectangle PuzzleCircle   = {575, 1046, 32, 32}; //circle
  Rectangle PuzzleSquare   = {703, 1046, 32, 32}; //square
  Rectangle Helmet = {574, 383.5, 17, 19};

  Vector2 puzzle_position = {608.5, 386.5};

  bool chestCollision = false;
  bool puzzleCollision1 = false;
  bool puzzleCollision2 = false;
  bool puzzleCollision3 = false;
  bool helmetCollision = false;

  bool chestIsDrawn = false;
  bool puzzleIsDrawn = false;
  bool helmetIsDrawn = false;

  bool wallIsOpen = false;

  void chest_collision();
  void puzzle_collision1();
  void puzzle_collision2();
  void puzzle_collision3();
  void helmet_collision();

  void collision();

  void update();
  void draw();


  // divide sprite-sheet into frames
  Rectangle frameRec = { 0.0f, 0.0f, (float)PuzzelTriangle.width / 3, (float)PuzzelTriangle.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 8; // animtation fps

  //~PuzzleTriangle();
  void unloadTextures();
};


