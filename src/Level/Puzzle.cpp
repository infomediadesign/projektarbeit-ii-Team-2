#include "Puzzle.h"


Puzzle::Puzzle() {

}

/** Collision Checks */
void Puzzle::collision() {

  // Check collision between Nemo and chest
  chestCollision = CheckCollisionRecs(Chest, nemo->nemorec);

  // Check collision between Nemo and chest2
  chestCollision2 = CheckCollisionRecs(Chest2, nemo->nemorec);

  // Check collision between Nemo and chest3
  chestCollision3 = CheckCollisionRecs(Chest3, nemo->nemorec);

  // Check collision between Nemo and puzzle triangle
  puzzleCollision1 = CheckCollisionRecs(PuzzleTriangle, nemo->nemorec);

  // Check collision between Nemo and puzzle circle
  puzzleCollision2 = CheckCollisionRecs(PuzzleCircle, nemo->nemorec);

  // Check collision between Nemo and puzzle
  puzzleCollision3 = CheckCollisionRecs(PuzzleSquare, nemo->nemorec);

  // Check collision between Nemo and chest
  helmetCollision = CheckCollisionRecs(Helmet, nemo->nemorec);
}

/** Update the Items/ Chests/ Puzzles */
void Puzzle::update() {

  //chest update
  while (chestCollision) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      std::cout << "Open Chest" << std::endl;
      chestIsDrawn = true;
      if(chestIsDrawn){
        helmetIsDrawn = true;
        break;
      }
      break;
    }
    break;
  }
  while (chestCollision2) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      std::cout << "Open Chest" << std::endl;
      chest2IsDrawn = true;
      if(chest2IsDrawn){
        helmetIsDrawn = true;
        break;
      }
      break;
    }
    break;
  }
  while (chestCollision3) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      std::cout << "Open Chest" << std::endl;
      chest3IsDrawn = true;
      if(chest3IsDrawn){
        helmetIsDrawn = true;
        break;
      }
      break;
    }
    break;
  }

  //helmet update
  if (helmetCollision){
    std::cout << "you picked up a helmet" << std::endl;

    helmetIsDrawn = false;
  }


  //puzzle update
  while (puzzleCollision1) {
    std::cout << "Door open" << std::endl;
    break;
  }

  //puzzle update
  if (puzzleCollision1) {
    wallIsOpen = true;
  }
}

/** Draw the Items/ Chests/ Puzzles */
void Puzzle::draw() {

  //chest draw
  if(chestIsDrawn){
    DrawTexture(DungeonFloorTile, 608, 384, WHITE);
    DrawTexture(ChestOpen, 608, 385, WHITE);
  }
  //chest2 draw
  if(chest2IsDrawn){
    DrawTexture(DungeonFloorTile, 896, 288, WHITE);
    DrawTexture(ChestOpen, 896, 288, WHITE);
  }
  //chest3 draw
  if(chest3IsDrawn){
    DrawTexture(DungeonFloorTile, 1504, 480.5, WHITE);
    DrawTexture(ChestOpen, 1504, 480.5, WHITE);
  }

  //helmet draw for the chest1
  if (helmetIsDrawn){
    //DrawTexture(HelmetItem, 574, 383.5, WHITE);
    DrawTexture(HelmetTexture, 574, 383.5, WHITE);
  }


  //wall opens after chest opened
  if(chestIsDrawn) { //wall after the chest
    DrawTexture(WallTile, 736, 673.5, WHITE);
    DrawTexture(DungeonFloorTile, 736, 705, WHITE);
    DrawTexture(DungeonFloorTile, 736, 737, WHITE);
  }
  //wall opens after chest opened (rn)
  if (helmetIsDrawn){
    DrawTexture(DungeonFloorTile, 576, 896, WHITE);
    DrawTexture(DungeonFloorTile, 608, 896, WHITE);
  }

  //puzzle draw
  if (puzzleCollision1) {
    DrawTexture(TriangleTrapDoor, 640, 1055.5, WHITE);
  }
  if (puzzleCollision2) {
    DrawTexture(CircleTrapDoor, 576, 1055.5, WHITE);
  }
  if (puzzleCollision3) {
    DrawTexture(SquareTrapDoor, 704, 1055.5, WHITE);
  }

  if(wallIsOpen) { //wall after the puzzle
    DrawTexture(WallTile, 800, 992, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1024, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1056, WHITE);
  }
}

Puzzle::~Puzzle() {
  /** Unload Textures */
  UnloadTexture (ChestOpen);

  UnloadTexture (HelmetItem);
  UnloadTexture (HelmetTexture);
  UnloadTexture (ChestplateTexture);
  UnloadTexture (HpPotionTexture);
  UnloadTexture (KeyTexture);

  UnloadTexture (PuzzelTriangle);

  UnloadTexture (TriangleTrapDoor);
  UnloadTexture (CircleTrapDoor);
  UnloadTexture (SquareTrapDoor);

  UnloadTexture (WallTile);
  UnloadTexture (DungeonFloorTile);
}

