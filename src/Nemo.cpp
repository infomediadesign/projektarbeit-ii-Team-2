#include "Nemo.h"

void Game::Nemo::Draw() {}

void Game::Nemo::Update() {
  Nemo nemo;
  Game::Sprite spr(NemoPosition.x, NemoPosition.y, nemo.Front);

  if (IsKeyDown(KEY_D)) { // run right
    spr.pos_x += 2.0f;

    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Right.width / 3;
    }
  }

  if (IsKeyDown(KEY_A)) { // run left
    spr.pos_x -= 2.0f;    // needs change

    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Left.width / 3;
    }
  }

  if (IsKeyDown(KEY_W)) { // run forwards
    spr.pos_y -= 2.0f;

    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 2)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)Front.width / 3;
    }
  }
}
