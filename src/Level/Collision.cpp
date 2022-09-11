#include "Collision.h"

Collision::Collision(nlohmann::json levelMapDungeon) {
  int tileWidth = levelMapDungeon["tilewidth"];
  int tileHeight = levelMapDungeon["tileheight"];
  int mapWidth = levelMapDungeon["width"];

  Rectangle  currentHitbox { 0, 0, (float)tileWidth, (float)tileHeight};

  for (auto const &layer : levelMapDungeon["layers"]) {

    if (layer["type"] == "tilelayer" && layer["visible"]) {
      if (layer["name"] == "Object" ){
        for (auto const &tileId : layer["data"]) {
          if (tileId > 0)
            insideWall.push_back(currentHitbox);
          currentHitbox.x += tileWidth;
          if (currentHitbox.x >= mapWidth * tileWidth) {
            currentHitbox.y += tileHeight;
            currentHitbox.x = 0;
          }
        }
      }
    }
  }

  ///now lets try with the torch animations
  for (auto const &layer : levelMapDungeon["layers"]) {

    if (layer["type"] == "tilelayer" && layer["visible"]) {
      if (layer["name"] == "Object" ){
        for (auto const &tileId : layer["data"]) {
          if (tileId == 129)
            torchPosRec.push_back(currentHitbox);
          currentHitbox.x += tileWidth;
          if (currentHitbox.x >= mapWidth * tileWidth) {
            currentHitbox.y += tileHeight;
            currentHitbox.x = 0;
          }
        }
      }
    }
  }

}

void Collision::stopnemo() {
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

void Collision::outPyraWallCollision() {

  wallCollision = CheckCollisionRecs(OutsideWallLeft, nemo->nemorec);
  wallCollision2 = CheckCollisionRecs(OutsideWallRight, nemo->nemorec);
  wallCollision3 = CheckCollisionRecs(OutsideWallBottom, nemo->nemorec);

  if (wallCollision){ stopnemo(); }
  if (wallCollision2){ stopnemo(); }
  if (wallCollision3){ stopnemo(); }

  /*
for (Rectangle & wall : outsideWall) {
    if (CheckCollisionRecs(wall, nemo->nemorec))
      stopnemo();
  }
   */
}

void Collision::inPryaWallCollision() {
  for (Rectangle & wall : insideWall) {
    if (CheckCollisionRecs(wall, nemo->nemorec))
      stopnemo();
  }
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
    stopnemo();
    break;
  }

  EpanoxCollision2 = CheckCollisionRecs(EpanoxRec2, nemo->nemorec); //for the dialog engagement

  while (EpanoxCollision2) {
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)) {
      //PlaySound(GameAudio::epanoxsfx);
      //SetSoundVolume(GameAudio::epanoxsfx, float(0.2));
      text = true;
      break;
    }

    if (!EpanoxCollision2){text = false;}

    if (text) {
      //DrawTexture(Dialogbox, 780, 561, WHITE);
      DrawTexture(Dialogbox, nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 90 , WHITE);
      if (IsKeyPressed(KEY_SPACE)){
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
        DrawText("Welcome traveller", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("Im guessing you've travelled through time?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        break;
      case 2: DrawText("Having Fun? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE); break;
      case 3: DrawText("Well i dont care what think, so fuck off!", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE); break;
      case 4: textState = 1;
        text = false; break;
      }
    }
    break;
  }
}

void Collision::draw() {
  DrawTextureRec(EpanoxSheet, frameRec, EpanoxPosition, WHITE); // Draw nemo animation backwards
}

void Collision::walldraw() {
  for (Rectangle &wall : insideWall) {
    DrawRectangleRec(wall, RED);
  }
  for (Rectangle &wall : outsideWall) {
    DrawRectangleRec(wall, BLUE);
  }

  DrawRectangleRec(OutsideWallLeft, RED);
  DrawRectangleRec(OutsideWallRight, RED);
  DrawRectangleRec(OutsideWallBottom, BLUE);
}


void Collision::torchAnimations() {
  for (Rectangle & torch : torchPosRec) {
    DrawRectangleRec(torch, WHITE);
  }
}
