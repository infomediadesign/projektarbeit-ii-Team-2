#include "Puzzle.h"


Puzzle::Puzzle() {}

/** Collision Checks */
void Puzzle::collisionChecks() {

  /** Collision Checks Chests */
  // Check collision between Nemo and chest
  chestCollision = CheckCollisionRecs(Chest, nemo->nemorec);

  // Check collision between Nemo and chest2
  chestCollision2 = CheckCollisionRecs(Chest2, nemo->nemorec);

  // Check collision between Nemo and chest3
  chestCollision3 = CheckCollisionRecs(Chest3, nemo->nemorec);

  /** Collision Checks Items */
  // Check collision between Nemo and chest
  helmetCollision = CheckCollisionRecs(Helmet, nemo->nemorec);

  // Check collision between Nemo and chestplate
  chestplateCollision = CheckCollisionRecs(Chestplate, nemo->nemorec);

  // Check collision between Nemo and hp potion
  hp_potionCollision = CheckCollisionRecs(HpPotion, nemo->nemorec);

  // Check collision between Nemo and chest
  keyCollision = CheckCollisionRecs(Key, nemo->nemorec);

  /** Collision Checks Puzzle */
  // Check collision between Nemo and puzzle triangle
  puzzleCollision1 = CheckCollisionRecs(PuzzleTriangle, nemo->nemorec);

  // Check collision between Nemo and puzzle circle
  puzzleCollision2 = CheckCollisionRecs(PuzzleCircle, nemo->nemorec);

  // Check collision between Nemo and puzzle
  puzzleCollision3 = CheckCollisionRecs(PuzzleSquare, nemo->nemorec);

  /** Collision Checks Doors */
  // Check collision between Nemo and doors
  doorcollision1 = CheckCollisionRecs(door1, nemo->nemorec);

  // Check collision between Nemo and doors
  doorcollision2 = CheckCollisionRecs(door2, nemo->nemorec);

  // Check collision between Nemo and doors
  doorcollision3 = CheckCollisionRecs(door3, nemo->nemorec);

  /** Collision Checks Chests Nemo Stop */
  // Check collision between Nemo and doors
  chestCollisionNS1 = CheckCollisionRecs(ChestNS, nemo->nemorec);

  // Check collision between Nemo and doors
  chestCollisionNS2 = CheckCollisionRecs(ChestNS2, nemo->nemorec);

  // Check collision between Nemo and doors
  chestCollisionNS3 = CheckCollisionRecs(ChestNS3, nemo->nemorec);
}

/** Update the Items/ Chests/ Puzzles */
void Puzzle::update() {

  /** Update Chests */
  //chest update
  while (chestCollision) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      //std::cout << "Open Chest" << std::endl;
      PlaySound(GameAudio::openchest);
      SetSoundVolume(GameAudio::openchest, float(0.4));
      chestIsDrawn = true;
      if(chestIsDrawn){
        helmetIsDrawn = true;
        keyIsDrawn = true;
        Chest = {};
        door1 = {};
        break;
      }
      break;
    }
    break;
  }

  //chest2 update
  while (chestCollision2) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      //std::cout << "Open Chest" << std::endl;
      PlaySound(GameAudio::openchest);
      SetSoundVolume(GameAudio::openchest, float(0.4));
      chest2IsDrawn = true;
      if(chest2IsDrawn){
        chestplateIsDrawn = true;
        Chest2 = {};
        break;
      }
      break;
    }
    break;
  }

  //chest3 update
  while (chestCollision3) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      //std::cout << "Open Chest" << std::endl;
      PlaySound(GameAudio::openchest);
      SetSoundVolume(GameAudio::openchest, float(0.4));
      chest3IsDrawn = true;
      if(chest3IsDrawn){
        hpPotionIsDrawn = true;
        Chest3 = {};
        break;
      }
      break;
    }
    break;
  }

  /** Update Items */
  //helmet update
  if (helmetCollision){
    //std::cout << "you picked up a helmet" << std::endl;
    PlaySound(GameAudio::pickupitem);
    SetSoundVolume(GameAudio::pickupitem, float(0.4));
    helmetIsDrawn = false;
    Helmet = {};
  }

  //chestplate update
  if (chestplateCollision){
    //std::cout << "you picked up a chestplate" << std::endl;
    PlaySound(GameAudio::pickupitem);
    SetSoundVolume(GameAudio::pickupitem, float(0.4));
    chestplateIsDrawn = false;
    Chestplate = {};
  }

  //hp potion update
  if (hp_potionCollision){
    //std::cout << "you picked up a hp potion" << std::endl;
    PlaySound(GameAudio::pickupitem);
    SetSoundVolume(GameAudio::pickupitem, float(0.4));
    hpPotionIsDrawn = false;
    HpPotion = {};
  }

  //key update
  if (keyCollision){
    //std::cout << "you picked up a key" << std::endl;
    PlaySound(GameAudio::pickupitem);
    SetSoundVolume(GameAudio::pickupitem, float(0.4));
    keyIsDrawn = false;
    isKeyPickedUp = true;
    door2 = {};

    Key = {};
  }

  /** Update Puzzle */
  //puzzle update
  if (puzzleCollision1) { wallIsOpen = true; door3 = {};}


  /** Stop Nemo Door */
  if (doorcollision1){ stopNemo(); }

  if (doorcollision2){ stopNemo(); }

  if (doorcollision3){ stopNemo(); }

  /** Stop Nemo Chest */
  if (chestCollisionNS1){ stopNemo(); }

  if (chestCollisionNS2){ stopNemo(); }

  if (chestCollisionNS3){ stopNemo(); }
}

/** Only to stop Nemo's movement */
void Puzzle::stopNemo() {
  //walking
  if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { nemo->NemoPosition.x += 1.5; }
  if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { nemo->NemoPosition.x -= 1.5; }
  if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { nemo->NemoPosition.y += 1.5; }
  if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { nemo->NemoPosition.y -= 1.5; }

  //sprinting
  if (IsKeyPressed(KEY_A) && IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_A) && IsKeyDown(KEY_LEFT_SHIFT) )
  { nemo->NemoPosition.x += 2.0; }
  if (IsKeyPressed(KEY_D) && IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_D) && IsKeyDown(KEY_LEFT_SHIFT))
  { nemo->NemoPosition.x -= 2.0; }
  if (IsKeyPressed(KEY_W) && IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_W) && IsKeyDown(KEY_LEFT_SHIFT))
  { nemo->NemoPosition.y += 2.0; }
  if (IsKeyPressed(KEY_S) && IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_S) && IsKeyDown(KEY_LEFT_SHIFT))
  { nemo->NemoPosition.y -= 2.0; }
}

void Puzzle::torchAnimation() {

  // animation
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 3)
      currentFrame = 0;

    frameRecTorch.x = (float)currentFrame * (float)Torch.width / 4;
  }
}

void Puzzle::portalAnimation() {

  // animation
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 11)
      currentFrame = 0;

    frameRecPortal.x = (float)currentFrame * (float)Portal.width / 12;
  }
}

/** Draw the Items/ Chests/ Puzzles */
void Puzzle::draw() {

  /** CHESTS */
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

  /** ITEMS */
  //helmet draw/ key for the chest1
  if (helmetIsDrawn){ DrawTexture(HelmetTexture, 574, 383.5, WHITE); }
  if (keyIsDrawn){ DrawTexture(KeyTexture, 645, 380, WHITE); }

  //chestplate draw for the chest2
  if (chestplateIsDrawn){ DrawTexture(ChestplateTexture, 935, 276, WHITE); }

  //hp potion draw for the chest3
  if (hpPotionIsDrawn){ DrawTexture(HpPotionTexture, 1452, 504, WHITE); }

  /** WALL PARTS/ DOOR */
  //wall opens after picking up the key
  if(isKeyPickedUp) { //wall after the chest
    DrawTexture(WallTile, 736, 673.5, WHITE);
    DrawTexture(DungeonFloorTile, 736, 705, WHITE);
    DrawTexture(DungeonFloorTile, 736, 737, WHITE);
  }
  //wall opens after chest opened
  if (chestIsDrawn){
    DrawTexture(DungeonFloorTile, 576, 896, WHITE);
    DrawTexture(DungeonFloorTile, 608, 896, WHITE);
  }
  //wall after the puzzle
  if(wallIsOpen) {
    DrawTexture(WallTile, 800, 992, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1024, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1056, WHITE);
  }

  /** PUZZLE */
  //triangle trapdoor draw
  if (puzzleCollision1) { DrawTexture(TriangleTrapDoor, 640, 1055.5, WHITE); }

  //circle trapdoor draw
  if (puzzleCollision2) { DrawTexture(CircleTrapDoor, 576, 1055.5, WHITE); }

  //square trapdoor draw
  if (puzzleCollision3) { DrawTexture(SquareTrapDoor, 704, 1055.5, WHITE); }

  /** RECTANGLES */
  DrawRectangleRec(door1, Color{});
  DrawRectangleRec(door2, Color{});
  DrawRectangleRec(door3, Color{});
  DrawRectangleRec(ChestNS, RED);
  DrawRectangleRec(ChestNS2, BLUE);
  DrawRectangleRec(ChestNS3, GREEN);

  /** ANIMATIONS */
  //torches
  DrawTextureRec(Torch, frameRecTorch, TorchPosition, WHITE);
  DrawTextureRec(Torch, frameRecTorch, TorchPosition2, WHITE);
  //portal
  DrawTextureRec(Portal, frameRecPortal, PortalPosition, WHITE);

  torchAnimation();
  portalAnimation();
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