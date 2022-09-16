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

  /** Collision Checks Hint Epanox */
  // Check collision between Nemo and Epanox
  EpanoxCollision = CheckCollisionRecs(EpanoxRec, nemo->nemorec); //for the nemo stopping part
  EpanoxCollision2 = CheckCollisionRecs(EpanoxRec2, nemo->nemorec); //for the dialog engagement
}

/** Update the Items/ Chests/ Puzzles */
void Puzzle::update() {

  /** Update Chests */
  //chest update
  while (chestCollision) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)){
      PlaySound(GameAudio::openchest);
      SetSoundVolume(GameAudio::openchest, float(0.4));
      chestIsDrawn = true;
      if(chestIsDrawn){
        helmetIsDrawn = true;
        keyIsDrawn = true;
        Chest = {};
        door2 = {};
        PlaySound(GameAudio::dooropen);
        SetSoundVolume(GameAudio::dooropen, float(0.4));
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
  if(helmetIsDrawn){
    if (helmetCollision){
      //std::cout << "you picked up a helmet" << std::endl;
      PlaySound(GameAudio::pickupitem);
      SetSoundVolume(GameAudio::pickupitem, float(0.4));
      helmetIsDrawn = false;
      Helmet = {};
    }
  }

  //chestplate update
  if (chestplateIsDrawn){
    if (chestplateCollision){
      //std::cout << "you picked up a chestplate" << std::endl;
      PlaySound(GameAudio::pickupitem);
      SetSoundVolume(GameAudio::pickupitem, float(0.4));
      chestplateIsDrawn = false;
      Chestplate = {};
    }
  }

  //hp potion update
  if (hpPotionIsDrawn){
    if (hp_potionCollision){
      //std::cout << "you picked up a hp potion" << std::endl;
      PlaySound(GameAudio::pickupitem);
      SetSoundVolume(GameAudio::pickupitem, float(0.4));
      hpPotionIsDrawn = false;
      HpPotion = {};
    }
  }

  //key update
  if (keyIsDrawn){
    if (keyCollision){
      //std::cout << "you picked up a key" << std::endl;
      PlaySound(GameAudio::pickupitem);
      SetSoundVolume(GameAudio::pickupitem, float(0.4));
      keyIsDrawn = false;
      isKeyPickedUp = true;
      PlaySound(GameAudio::dooropen);
      SetSoundVolume(GameAudio::dooropen, float(0.4));
      door1 = {};
      Key = {};
    }
  }


  /** Update Puzzle */
  if (wallPuzzlePart1){
    if (wallPuzzlePart2){
      if (wallPuzzlePart3){
        wallIsOpen = true;
        door3 = {};
      }
    }
  }

  /** Stop Nemo Door */
  if (doorcollision1){ //key
    stopNemo();
    textdoor = true;
  }

  if (doorcollision2){ //chest
    stopNemo();
    textdoor2 = true;
  }

  if (doorcollision3){ //puzzle
    stopNemo();
    textdoor3 = true;
  }

  if (textdoor){
    timesinceIdle += GetFrameTime();

    DrawTexture(Dialogbox, nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 90, WHITE);
    //DrawTextEx(textFont, "Door Info", fontTextPosLINE1, fontSize, fontSpacing, WHITE);
    //DrawTextEx(textFont, "This Door is locked... ", fontTextPosLINE2, fontSize, fontSpacing, WHITE);
    //DrawTextEx(textFont, "talk to Epanox to get a hint.", fontTextPosLINE3, fontSize, fontSpacing, WHITE);
    DrawText("Door Info", nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75, 15, WHITE);
    DrawText("This Door is locked... ", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("Find a Key to open this door!", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 135, 15, WHITE);

    if (timesinceIdle >= 4){
      textdoor = false;
      timesinceIdle = 0;
    }
  }

  if (textdoor2){
    timesinceIdle += GetFrameTime();

    DrawTexture(Dialogbox, nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 90, WHITE);
    //DrawTextEx(textFont, "Door Info", fontTextPosLINE1, fontSize, fontSpacing, WHITE);
    //DrawTextEx(textFont, "This Door is locked... ", fontTextPosLINE2, fontSize, fontSpacing, WHITE);
    //DrawTextEx(textFont, "talk to Epanox to get a hint.", fontTextPosLINE3, fontSize, fontSpacing, WHITE);
    DrawText("Door Info", nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75, 15, WHITE);
    DrawText("This Door is locked... ", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("Kill the Monster, to enter the door", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 135, 15, WHITE);

    if (timesinceIdle >= 4){
      textdoor2 = false;
      timesinceIdle = 0;
    }
  }

  if (textdoor3){
    timesinceIdle += GetFrameTime();

    DrawTexture(Dialogbox, nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 90, WHITE);
    //DrawTextEx(textFont, "Door Info", fontTextPosLINE1, fontSize, fontSpacing, WHITE);
    //DrawTextEx(textFont, "This Door is locked... ", fontTextPosLINE2, fontSize, fontSpacing, WHITE);
    //DrawTextEx(textFont, "talk to Epanox to get a hint.", fontTextPosLINE3, fontSize, fontSpacing, WHITE);
    DrawText("Door Info", nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75, 15, WHITE);
    DrawText("This Door is locked... ", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110, 15, WHITE);
    DrawText("talk to Epanox to get a hint.", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 135, 15, WHITE);

    if (timesinceIdle >= 4){
      textdoor3 = false;
      timesinceIdle = 0;
    }
  }

  /** Stop Nemo Chest */
  if (chestCollisionNS1){ stopNemo(); }

  if (chestCollisionNS2){ stopNemo(); }

  if (chestCollisionNS3){ stopNemo(); }

  if (EpanoxCollision) { stopNemo(); }

  while (EpanoxCollision2) {
      DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
      if (IsKeyPressed(KEY_F)) {
        PlaySound(GameAudio::dialoge);
        SetSoundVolume(GameAudio::dialoge, float(0.1));
        text = true;
      }
      break;
    }
    if (text) {
      DrawTexture(Dialogbox, nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 90, WHITE);
      timesinceIdle += GetFrameTime();
      /*
       if (timesinceIdle >= 4){
 textState + 1;
 timesinceIdle = 0;
}
       */

      if (IsKeyPressed(KEY_SPACE)) {
        textState + 1;
        PlaySound(GameAudio::dialoge);
        SetSoundVolume(GameAudio::dialoge, float(0.1));
      }

      if (IsKeyReleased(KEY_SPACE) && textState == 0) {
        textState = 1;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 1) {
        textState = 2;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 2) {
        textState = 3;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 3) {
        textState = 4;
      }

      switch (textState) {
      default: break;
      case 1:
        DrawText("Epanox", nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75, 15, WHITE);
        DrawText("Hey again. It seems that your stuck. Let ", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("me give you a hint to solve this puzzle?",nemo->NemoPosition.x - 162,nemo->NemoPosition.y + 135, 15, WHITE);
        break;
      case 2:
        DrawText("Epanox ", nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75, 15, WHITE);
        DrawText("Here goes... ", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110, 15, WHITE);
        break;
      case 3:
        DrawText("Epanox", nemo->NemoPosition.x - 180, nemo->NemoPosition.y + 75, 15, WHITE);
        DrawText("On a mountain stands a house on which the", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("sun shines down...", nemo->NemoPosition.x - 162, nemo->NemoPosition.y + 135, 15, WHITE);
        break;
      case 4:
        textState = 1;
        text = false;
        break;
      }
    }
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
  PortalPosition = {1438, 96};
  DrawTextureRec(Portal, frameRecPortal, PortalPosition, WHITE);

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

void Puzzle::epanoxAnimation() {

  // animation
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 19)
      currentFrame = 0;

    frameRecEpanox.x = (float)currentFrame * (float)EpanoxSheet.width / 20;
  }


}

/** Draw the Items/ Chests/ Puzzles */
void Puzzle::draw() {
  /** CHESTS */
  // chest draw
  if (chestIsDrawn) {
    DrawTexture(DungeonFloorTile, 608, 384, WHITE);
    DrawTexture(ChestOpen, 608, 385, WHITE);
  }
  // chest2 draw
  if (chest2IsDrawn) {
    DrawTexture(DungeonFloorTile, 896, 288, WHITE);
    DrawTexture(ChestOpen, 896, 288, WHITE);
  }
  // chest3 draw
  if (chest3IsDrawn) {
    DrawTexture(DungeonFloorTile, 1504, 480.5, WHITE);
    DrawTexture(ChestOpen, 1504, 480.5, WHITE);
  }

  /** ITEMS */
  // helmet draw/ key for the chest1
  if (helmetIsDrawn) {
    DrawTexture(HelmetTexture, 574, 383.5, WHITE);
  }
  if (keyIsDrawn) {
    DrawTexture(KeyTexture, 645, 380, WHITE);
  }

  // chestplate draw for the chest2
  if (chestplateIsDrawn) {
    DrawTexture(ChestplateTexture, 935, 276, WHITE);
  }

  // hp potion draw for the chest3
  if (hpPotionIsDrawn) {
    DrawTexture(HpPotionTexture, 1452, 504, WHITE);
  }

  /** WALL PARTS/ DOOR */
  // wall opens after picking up the key
  if (isKeyPickedUp) { // wall after the chest
    DrawTexture(WallTile, 736, 673.5, WHITE);
    DrawTexture(DungeonFloorTile, 736, 705, WHITE);
    DrawTexture(DungeonFloorTile, 736, 737, WHITE);
  }
  // wall opens after chest opened
  if (chestIsDrawn) {
    DrawTexture(DungeonFloorTile, 576, 896, WHITE);
    DrawTexture(DungeonFloorTile, 608, 896, WHITE);
  }
  // wall after the puzzle
  if (wallIsOpen) {
    DrawTexture(WallTile, 800, 992, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1024, WHITE);
    DrawTexture(DungeonFloorTile, 800, 1056, WHITE);
  }

  /** PUZZLE */
  // triangle trapdoor draw
  if (puzzleCollision1) {
    DrawTexture(TriangleTrapDoor, 640, static_cast<int>(1055.5), WHITE);
    if (!wallPuzzlePart2) {
      wallPuzzlePart1 = true;
    }
    if (wallPuzzlePart2) {
      wallPuzzlePart1 = false;
      wallPuzzlePart2 = false;
      wallPuzzlePart3 = false;
    }
  }

  // circle trapdoor draw
  if (puzzleCollision2) {
    DrawTexture(CircleTrapDoor, 576, static_cast<int>(1055.5), WHITE);
    if (wallPuzzlePart2) {
      wallPuzzlePart3 = true;
      PlaySound(GameAudio::dooropen);
      SetSoundVolume(GameAudio::dooropen, float(0.4));
    } else {
      wallPuzzlePart1 = false;
      wallPuzzlePart2 = false;
    }
  }

  // square trapdoor draw
  if (puzzleCollision3) {
    DrawTexture(SquareTrapDoor, 704, static_cast<int>(1055.5), WHITE);
    if (wallPuzzlePart1) {
      wallPuzzlePart2 = true;
    } else {
      wallPuzzlePart1 = false;
    }
  }

  /** RECTANGLES */
  DrawRectangleRec(door1, Color {});
  DrawRectangleRec(door2, Color {});
  DrawRectangleRec(door3, Color {});

  if (IsKeyDown(KEY_R)) {
    DrawRectangleRec(ChestNS, RED);
    DrawRectangleRec(ChestNS2, BLUE);
    DrawRectangleRec(ChestNS3, GREEN);
  }

    /** ANIMATIONS */
    // torches
    torchAnimation();
    DrawTextureRec(Torch, frameRecTorch, TorchPosition, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition2, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition3, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition4, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition5, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition6, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition7, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition8, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition9, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition10, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition11, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition12, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition13, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition14, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition15, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition16, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition17, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition18, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition19, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition20, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition21, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition22, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition23, WHITE);
    DrawTextureRec(Torch, frameRecTorch, TorchPosition24, WHITE);

    // epanox
    epanoxAnimation();
    DrawTextureRec(EpanoxSheet, frameRecEpanox, EpanoxPosition, WHITE);
  }


  Puzzle::~Puzzle() {
    /** Unload Textures */
    UnloadTexture(ChestOpen);

    UnloadTexture(HelmetItem);
    UnloadTexture(HelmetTexture);
    UnloadTexture(ChestplateTexture);
    UnloadTexture(HpPotionTexture);
    UnloadTexture(KeyTexture);

    UnloadTexture(PuzzelTriangle);

    UnloadTexture(TriangleTrapDoor);
    UnloadTexture(CircleTrapDoor);
    UnloadTexture(SquareTrapDoor);

    UnloadTexture(WallTile);
    UnloadTexture(DungeonFloorTile);
  }
  void Puzzle::crystaldraw()
  {
    Crystalrec = {1455.5, 215.5, 32, 32};
    //DrawRectangleRec(Crystalrec, RED);
    DrawTextureRec(TimeCrystal, CrystalFrameRec, {Crystalrec.x, Crystalrec.y}, WHITE);

    crystal_framescounter++;

    if (crystal_framescounter >= (60 / crystal_framesspeed)) {
      crystal_framescounter = 0;
      crystal_currentFrame++;

      if (crystal_currentFrame > 3)
      {
        crystal_currentFrame = 0;
      }

      CrystalFrameRec.x = (float)crystal_currentFrame * (float)TimeCrystal.width / 4;
    }
  }
