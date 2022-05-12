#include "Nemo.h"

void Game::Nemo::Update() {
  Nemo nemo;
  Game::Sprite spr(NemoPosition.x, NemoPosition.y, nemo.Front);

  // animation and movement
  if (IsKeyDown(KEY_W)) { // run forwards
    spr.pos_y -= 2.0f;
    PlaySound(fxMp3);

    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Front.width / 3;
    }
  }
  if (IsKeyDown(KEY_A)) { // run left
    spr.pos_x -= 2.0f;    // needs change
    PlaySound(fxMp3);

    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Left.width / 3;
    }
  }
  if (IsKeyDown(KEY_S)) { // run backwards
    spr.pos_y += 2.0f;
    PlaySound(fxMp3);

    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Right.width / 3;
    }
  }
  if (IsKeyDown(KEY_D)) { // run right
    spr.pos_x += 2.0f;
    PlaySound(fxMp3);

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
    DrawTextureRec(Back, frameRec, NemoPosition, WHITE); // Draw nemo animation backwards
    move = true;
  }
  if (IsKeyDown(KEY_S)) {
    DrawTextureRec(Front, frameRec, NemoPosition, WHITE); // Draw nemo animation forwards
    move = true;
  }
  if (IsKeyDown(KEY_D)) {
    DrawTextureRec(Right, frameRec, NemoPosition, WHITE); // Draw nemo animation right
    move = true;
  }
  if (IsKeyDown(KEY_A)) {
    DrawTextureRec(Left, frameRec, NemoPosition, WHITE); // Draw nemo animation left
    move = true;
  }

  if (move == false) {
    DrawTextureRec(Front, frameRec, NemoPosition, WHITE); // standing animation i dont have that yet
  }
}