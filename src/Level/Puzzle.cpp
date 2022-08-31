#include "Puzzle.h"

void Puzzle::chest_collision() {

  // Check collision between Nemo and chest
  chestCollision = CheckCollisionRecs(Chest, nemo->nemorec);
}

void Puzzle::puzzle_collision() {

  // Check collision between Nemo and puzzle
  puzzleCollision = CheckCollisionRecs(Puzzle, nemo->nemorec);
}

void Puzzle::helmet_collision() {

  // Check collision between Nemo and chest
  helmetCollision = CheckCollisionRecs(Helmet, nemo->nemorec);
}

void Puzzle::unloadTextures() {
  UnloadTexture(ChestOpen);
  UnloadTexture(PuzzelTriangle);
  UnloadTexture(HelmetItem);
  UnloadTexture(DungeonFloorTile);
}
void Puzzle::draw() {

  //chest draw
  if (chestCollision) {
    std::cout << "Open Chest" << std::endl;

    DrawTexture(ChestOpen, 609.5, 391, WHITE);
    DrawTexture(HelmetItem, 570.5, 385, WHITE);
  }

  //puzzle draw
  if (puzzleCollision){
    std::cout << "floor plate pressed, door will open" << std::endl;

    DrawTexture(FloorTile, 640.5, 1046.5, WHITE);
    DrawTexture(DungeonFloorTile,800,1014, WHITE);

    /*
     * // animation
     * framesCounter++;

if (framesCounter >= (60 / framesSpeed)) {
  framesCounter = 0;
  currentFrame++;

  if (currentFrame > 2)
    currentFrame = 0;

  frameRec.x = (float)currentFrame * (float)PuzzelTriangle.width / 3;
}
DrawTextureRec(PuzzelTriangle, frameRec, puzzle_position, WHITE);

DrawTexture(DungeonFloorTile, 700, 1046, WHITE);
     * */

  }

  //helmet draw
  if (helmetCollision) {
    std::cout << "Item Pick up" << std::endl;

    UnloadTexture(HelmetItem);
  }
}
