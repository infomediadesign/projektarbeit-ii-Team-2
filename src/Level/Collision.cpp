#include "Collision.h"

void Collision::update() {
  ;

  /** Check collision between Nemo and Wall/ Interactables... */
  /*
  wallCollision = false;
  for (auto &rect : map->collisionRectangles) { //change the vector into a rectangle
    if (CheckCollisionRecs(rect, nemo->nemorec)) { //check the collision between said rectangle and nemo
      wallCollision = true; //set the wallcollision to true...
      break;
    }
  }

  if (wallCollision) { //if wallcollision true then nemo does...

    std::cout << "HIT!";

    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { // Left
      nemo->NemoPosition.x += 2.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
    if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
      nemo->NemoPosition.x -= 2.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
    if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
      nemo->NemoPosition.y += 2.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
    if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
      nemo->NemoPosition.y -= 2.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
  }
}*/
}

void Collision::epanoxCollision() { // Epanox collision

  // animation
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 19)
      currentFrame = 0;

    frameRec.x = (float)currentFrame * (float)EpanoxSheet.width / 20;
  }

  // Check collision between Nemo and Epanox
  EpanoxCollision = CheckCollisionRecs(EpanoxRec, nemo->nemorec); //for the nemo stopping part

  while (EpanoxCollision){
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
    break;
  }

  EpanoxCollision2 = CheckCollisionRecs(EpanoxRec2, nemo->nemorec); //for the dialog engagement

  while (EpanoxCollision2) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)) {
      text = true;
      break;
    }

    if (!EpanoxCollision2){text = false;}

    if (text) {
      DrawTexture(Dialogbox, 780, 561, WHITE);
      if (IsKeyPressed(KEY_SPACE)){
        textState + 1;
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
        DrawText("Welcome traveller", 810, 581, 15, WHITE);
        DrawText("Im guessing you've travelled through time?", 810, 606, 15, WHITE);
        break;
      case 2: DrawText("Having Fun? ", 810, 581, 15, WHITE); break;
      case 3: DrawText("Well i dont care what think, so fuck off!", 810, 581, 15, WHITE); break;
      case 4: textState = 1;
        text = false; break;
      }
    }
    break;
  }
}


void Collision::outPyraWallCollision() {

  wallCollision = CheckCollisionRecs(OutsideWallLeft, nemo->nemorec);
  wallCollision = CheckCollisionRecs(OutsideWallRight, nemo->nemorec);
  wallCollision = CheckCollisionRecs(OutsideWallBottom, nemo->nemorec);



while (wallCollision){
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
  break;
  }
}


void Collision::draw() {
  DrawTextureRec(EpanoxSheet, frameRec, EpanoxPosition, WHITE); // Draw nemo animation backwards
  //DrawRectangleRec(OutsideWallLeft, RED);
  //DrawRectangleRec(OutsideWallRight, RED);
  //DrawRectangleRec(OutsideWallBottom, BLUE);
}
