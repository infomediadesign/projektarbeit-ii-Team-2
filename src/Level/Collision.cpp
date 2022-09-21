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
    DrawTextEx(textFont, "[F]", { nemo->NemoPosition.x + 7, nemo->NemoPosition.y - 15 }, fontSize, fontSpacing, BLACK);
    if (IsKeyPressed(KEY_F)) {
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
      text = true;
      break;
    }

    if (!EpanoxCollision2){text = false;}

    if (text) {
      if (IsKeyPressed(KEY_SPACE)){
        PlaySound(GameAudio::dialoge);
        SetSoundVolume(GameAudio::dialoge, float(0.1));
      }

      DrawTexture(Dialogbox, nemo->NemoPosition.x - 180 , nemo->NemoPosition.y + 90 , WHITE);
      //stopnemo();

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
      }

      switch (textState) {
      default: break;
      case 1:
        DrawTextEx(textFont, "Epanox", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Welcome traveller, are you alright?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Quite the travel you've done.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 2:
        DrawTextEx(textFont, "Nemo", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Where am I... is that a pyramid? Am I in Egypt?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Wait did you just say time travel?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "By the way who are you?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 3:
        DrawTextEx(textFont, "Epanox", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "I'm Epanox a creature, that can travel through", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "time. Yes we are currently in ancient egypt, the", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Does that mean you can send me back home?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 4:
        DrawTextEx(textFont, "Nemo", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Let me get this straight. I've travelled to ancient", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Egypt and you are a time creature of some sorts?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Does that mean you can send me back home?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 5:
        DrawTextEx(textFont, "Epanox", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "I'm a creature that travels through time... alone.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "So no... I can't get you back. But I do ", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "know how you might get home... wanna know?", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 6:
        DrawTextEx(textFont, "Nemo", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Yes please, I can't wait to get back home.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 7:
        DrawTextEx(textFont, "Epanox", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Alright, there's a Time Crystal in that Pyramid.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "These Time Crystals allow one to travel through", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "time. I'd say it's your best bet to getting home.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 8:
        DrawTextEx(textFont, "Nemo", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Ok, I see... then I'll just get the Time Crystal and.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "poof I'm back home. Cheers thanks for the help.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 9:
        DrawTextEx(textFont, "Epanox", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Before you go let me warn you... ", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "there might be Monsters in there.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Be careful, and safe travels.", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 10:
        DrawTextEx(textFont, "Nemo", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "No need to worry I'm built tough! ", { nemo->NemoPosition.x - 172, nemo->NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "[SPACE ->]", { nemo->NemoPosition.x + 170, nemo->NemoPosition.y + 175 }, fontSizeSPACE, fontSpacing, WHITE);
        break;
      case 11: textState = 1;
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
