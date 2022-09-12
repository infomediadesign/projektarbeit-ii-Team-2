//
// Created by goerk on 21.08.2022.
//

#include "Mumy.h"

void Mumy::Update() {

  if (f_right)
  {
    Direction = direction::RIGHT;
    MumyRec.x -= 1;
  }

  if (f_left)
  {
    Direction = direction::LEFT;
    MumyRec.x += 1;
  }

  if (CheckCollisionRecs(MumyRec, checkpoint2))
  {
    f_left = false;
    f_right = true;

  }

  if (CheckCollisionRecs(MumyRec, checkpoint1))
  {
    f_right = false;
    f_left = true;
  }

  //std::cout << MumyRec.x << "\n";

  //DrawRectangleRec(MumyRec, YELLOW);

}


void Mumy::Draw() {

  mumyrec = { MumyRec.x, MumyRec.y, 32, 32 };
  DrawRectangleRec(mumyrec, Color {});
  DrawTextureRec(spr_mumy, frameRec, { MumyRec.x, MumyRec.y }, WHITE);

  framesCounter++;

  switch (Direction)
  {
  case direction::RIGHT:
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 7) {
        currentFrame = 5;
      }

      frameRec.x = (float)currentFrame * (float)spr_mumy.width / 8;
    }
    break;

  case direction::LEFT:
    if (framesCounter >= (60 / framesSpeed))
    {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 5)
      {
        currentFrame = 0;
      }

      frameRec.x = (float)currentFrame * (float)spr_mumy.width / 8;
    }
    break;
  }

  //DrawRectangleRec(checkpoint1, RED);
  //DrawRectangleRec(checkpoint2, RED);

  Update();

}

Rectangle Mumy::getMumyRec() {
  return MumyRec;
}
