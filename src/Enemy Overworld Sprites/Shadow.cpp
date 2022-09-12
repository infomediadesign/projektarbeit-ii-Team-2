//
// Created by goerk on 21.08.2022.
//

#include "Shadow.h"

void Shadow::Draw() {

  shadowrec = { 590.5 + 8, 928 + 10, 16, 32 };
  DrawRectangleRec(shadowrec, Color {});
  DrawTextureRec(spr_shadow, frameRec, { 590.5, 928 }, WHITE);

  framesCounter++;
  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 4)
      currentFrame = 0;

    frameRec.x = (float)currentFrame * (float)spr_shadow.width / 6;
  }

}

void Shadow::Update() {

}

Rectangle Shadow::getShadowRec() { return Shadowrec; }