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
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
      text = true;
      break;
    }

    if (!EpanoxCollision2){text = false;}

    if (text) {
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
      } else if (IsKeyReleased(KEY_SPACE) && textState == 4) {
        textState = 5;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 5) {
        textState = 6;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 6) {
        textState = 7;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 7) {
        textState = 8;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 8) {
        textState = 9;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 9) {
        textState = 10;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 10) {
        textState = 11;
      } else if (IsKeyReleased(KEY_SPACE) && textState == 11) {
        textState = 12;
      }

      switch (textState) {
      default: break;
      case 1:
        DrawText("Instructions", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("To start the conversation press SPACE.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("To skip to the next part of the", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("conversation press SPACE again.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 2:
        DrawText("Epanox ", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Welcome traveller, are you alright? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("Quite the travel you've done.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        break;
      case 3:
        DrawText("Nemo ", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Where am I... is that a pyramid? Am I in Egypt? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("Wait did you just say time travel?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("By the way who are you?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 4:
        DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("I'm Epanox a creature, that can travel through", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("time. Yes we are currently in ancient egypt, the", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("date is currently Monday 12.June 2470 BC.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 5:
        DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Let me get this straight. I've travelled to ancient ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("Egypt and you are a time creature of some sorts? ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("Does that mean you can send me back home?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 6:
        DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("I'm a creature that travels through time... alone.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("So no... I can't get you back. But I do ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("know how you might get home... wanna know?", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 7:
        DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Yes please, I can't wait to get back home.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        break;
      case 8:
        DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Alright, there's a Time Crystal in that Pyramid.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("These Time Crystals allow one to travel through ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("time. I'd say it's your best bet to getting home.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 9:
        DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Ok, I see... then I'll just get the Time Crystal and ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("poof I'm back home. Cheers thanks for the help.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        break;
      case 10:
        DrawText("Epanox", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("Before you go let me warn you... ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        DrawText("there might be Monsters in there.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 135, 15, WHITE);
        DrawText("Be careful, and safe travels.", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 160, 15, WHITE);
        break;
      case 11:
        DrawText("Nemo", nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 75, 15, BLACK);
        DrawText("No need to worry I'm built tough! ", nemo->NemoPosition.x - 162 , nemo->NemoPosition.y + 110, 15, WHITE);
        break;
      case 12: textState = 1;
        text = false;
        break;
      }
    }
    break;
  }
}

void Collision::draw() {
  DrawTextureRec(EpanoxSheet, frameRec, EpanoxPosition, WHITE); // Draw nemo animation backwards
  //DrawRectangleRec(EpanoxRec, WHITE);
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
