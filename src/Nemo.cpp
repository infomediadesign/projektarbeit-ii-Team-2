#include "Nemo.h"

void Game::Nemo::Update() {  

  // animation and movement
  if (IsKeyDown(KEY_W)) {
    position.y -= 2.0f; // run forwards
    PlaySound(fxMp3);  // play sfx

    // animation
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Front.width / 3;
    }
  }
  if (IsKeyDown(KEY_A)) {
    position.x -= 2.0f; // run left ->needs change
    PlaySound(fxMp3);  // play sfx

    // animation
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Left.width / 3;
    }
  }
  if (IsKeyDown(KEY_S)) {
    position.y += 2.0f; // run backwards
    PlaySound(fxMp3);  // play sfx

    // animtaion
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Right.width / 3;
    }
  }
  if (IsKeyDown(KEY_D)) {
    position.x += 2.0f; // run right
    PlaySound(fxMp3);  // play sfx

    // animtaion
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Right.width / 3;
    }
  }
}

void Game::Nemo::Draw() {
  // Draw nemo walking animation
  bool move = false;

  if (IsKeyDown(KEY_W)) {
    DrawTextureRec(Back, frameRec, position, WHITE); // Draw nemo animation backwards
    move = true;
  }
  if (IsKeyDown(KEY_S)) {
    DrawTextureRec(Front, frameRec, position, WHITE); // Draw nemo animation forwards
    move = true;
  }
  if (IsKeyDown(KEY_D)) {
    DrawTextureRec(Right, frameRec, position, WHITE); // Draw nemo animation right
    move = true;
  }
  if (IsKeyDown(KEY_A)) {
    DrawTextureRec(Left, frameRec, position, WHITE); // Draw nemo animation left
    move = true;
  }

  if (move == false) {
    DrawTextureRec(Front, frameRec, position, WHITE); // standing animation i dont have that yet
  }
}

Game::Nemo::~Nemo() {
  UnloadTexture(Front);
  UnloadTexture(Back);
  UnloadTexture(Right);
  UnloadTexture(Left);
}
