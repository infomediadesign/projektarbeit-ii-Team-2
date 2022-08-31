#include "Puzzle.h"


/** Collision Checks */
void Puzzle::collision() {

  // Check collision between Nemo and chest
  chestCollision = CheckCollisionRecs(Chest, nemo->nemorec);

  // Check collision between Nemo and puzzle triangle
  puzzleCollision1 = CheckCollisionRecs(PuzzleTriangle, nemo->nemorec);

  // Check collision between Nemo and puzzle circle
  puzzleCollision2 = CheckCollisionRecs(PuzzleCircle, nemo->nemorec);

  // Check collision between Nemo and puzzle
  puzzleCollision3 = CheckCollisionRecs(PuzzleSquare, nemo->nemorec);

  // Check collision between Nemo and chest
  helmetCollision = CheckCollisionRecs(Helmet, nemo->nemorec);
}

/*
void Puzzle::chest_collision() {

  // Check collision between Nemo and chest
  chestCollision = CheckCollisionRecs(Chest, nemo->nemorec);
}

void Puzzle::puzzle_collision1() { //triangle puzzle

  // Check collision between Nemo and puzzle
  puzzleCollision1 = CheckCollisionRecs(PuzzleTriangle, nemo->nemorec);
}

void Puzzle::puzzle_collision2() { //circle puzzle

  // Check collision between Nemo and puzzle
  puzzleCollision2 = CheckCollisionRecs(PuzzleCircle, nemo->nemorec);
}

void Puzzle::puzzle_collision3() { //square puzzle

  // Check collision between Nemo and puzzle
  puzzleCollision3 = CheckCollisionRecs(PuzzleSquare, nemo->nemorec);
}

void Puzzle::helmet_collision() {

  // Check collision between Nemo and chest
  helmetCollision = CheckCollisionRecs(Helmet, nemo->nemorec);
} */

/** Update the Items/ Chests/ Puzzles */
void Puzzle::update() {

  //chest update
  while (chestCollision) {
    if (IsKeyPressed(KEY_SPACE)){
      std::cout << "Open Chest" << std::endl;
      chestIsDrawn = true;
      break;
    }
    break;
  }

  //helmet update
  while (chestIsDrawn) {
    helmetIsDrawn = true;
    if (helmetCollision){
      std::cout << "you picked up a helmet" << std::endl;

      helmetIsDrawn = false;
      break;
    }
    break;
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
    DrawTexture(DungeonFloorTile, 609.5, 390, WHITE);
    DrawTexture(ChestOpen, 609.5, 391, WHITE);
  }

  //helmet draw
  if (helmetIsDrawn){
    //DrawTexture(HelmetItem, 574, 383.5, WHITE);
    DrawTexture(HelmetItem, 609.5, 390, WHITE);
  }
  //helmet erase (when picked up)
  if (!helmetIsDrawn) {
    UnloadTexture(HelmetItem);
  }

  //puzzle draw
  if (puzzleCollision1) {
    DrawTexture(TriangleTrapDoor, 640, 1055.5, WHITE);
  }
  //puzzle draw
  if (puzzleCollision2) {
    DrawTexture(CircleTrapDoor, 576, 1055.5, WHITE);
  }
  //puzzle draw
  if (puzzleCollision3) {
    DrawTexture(SquareTrapDoor, 704, 1055.5, WHITE);
  }

  if(wallIsOpen) {
    DrawTexture(WallTile, 800, 992, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1024, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1056, WHITE);
  }
}

/** Unload Textures */
void Puzzle::unloadTextures() {
  UnloadTexture(ChestOpen);
  UnloadTexture(PuzzelTriangle);
  UnloadTexture(HelmetItem);
  UnloadTexture(DungeonFloorTile);
}

