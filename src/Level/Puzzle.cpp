#include "Puzzle.h"

void Puzzle::chest_collision() {

  // Check collision between Nemo and chest
  chestCollision = CheckCollisionRecs(Chest, nemo->nemorec);

  if (chestCollision) {
    std::cout << "Open Chest" << std::endl;

    DrawTexture(ChestOpen, 0, 0, WHITE);
    DrawTexture(HelmetItem, 574, 383.5, WHITE);
  }
}

void Puzzle::puzzle_collision() {

  // Check collision between Nemo and puzzle
  puzzleCollision = CheckCollisionRecs(Puzzle, nemo->nemorec);

  if (puzzleCollision){
    std::cout << "floor plate pressed, door will open" << std::endl;

    // animation
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)PuzzelTriangle.width / 3;
    }
    DrawTextureRec(PuzzelTriangle, frameRec, puzzle_position, WHITE);

    DrawTexture(DungeonFloorTile, 700, 1046, WHITE);
  }
}

void Puzzle::helmet_collision() {

  // Check collision between Nemo and chest
  helmetCollision = CheckCollisionRecs(Helmet, nemo->nemorec);

  if (helmetCollision) {
    std::cout << "Item Pick up" << std::endl;

    UnloadTexture(HelmetItem);
  }
}

void Puzzle::unloadTextures() {
  UnloadTexture(ChestOpen);
  UnloadTexture(PuzzelTriangle);
  UnloadTexture(HelmetItem);
  UnloadTexture(DungeonFloorTile);
}

