//
// Created by goerk on 21.08.2022.
//

#include "Pharaoh.h"

void Pharaoh::Update() {

}

void Pharaoh::Draw() {
  pharaohrec = { Pharaohrec.x, Pharaohrec.y, static_cast<float>(spr_Pharaoh.width), static_cast<float>(spr_Pharaoh.height) };
  DrawRectangleRec(pharaohrec, Color {});
  DrawTextureRec(spr_Pharaoh, frameRec, { 1442, 208.5 }, WHITE);
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 2) {
      currentFrame = 0;
    }

    frameRec.x = (float)currentFrame * (float)spr_Pharaoh.width / 2;
  }
}

Rectangle Pharaoh::getPharaohRec() { return Pharaohrec; }
