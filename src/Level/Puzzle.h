#include "../INCLUDES.h"
#include "../Player/Nemo.h"

class Puzzle {

public:

  Game::Nemo *nemo = new Game::Nemo();

  Texture2D ChestOpen = LoadTexture("assets/graphics/Items/Helm.png");
  Texture2D PuzzelTriangle = LoadTexture("assets/graphics/Items/DreieckBodenPlattenSenkung.png");
  Texture2D HelmetItem     = LoadTexture("assets/graphics/Nemo_StandingMutze.png");
  Texture2D DungeonFloorTile = LoadTexture("assets/graphics/Items/DungeonFloorPlate.png");

  Rectangle Chest = {608.5, 386.5, 28, 32};
  Rectangle Puzzle = {639, 1046, 32, 32};
  Rectangle Helmet = {574, 383.5, 17, 19};

  Vector2 puzzle_position = {608.5, 386.5};

  bool chestCollision = false;
  bool puzzleCollision = false;
  bool helmetCollision = false;

  void chest_collision();
  void puzzle_collision();
  void helmet_collision();

  // divide sprite-sheet into frames
  Rectangle frameRec = { 0.0f, 0.0f, (float)PuzzelTriangle.width / 3, (float)PuzzelTriangle.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 8; // animtation fps

  //~Puzzle();
  void unloadTextures();
};


