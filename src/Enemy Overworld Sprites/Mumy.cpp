//
// Created by goerk on 21.08.2022.
//

#include "Mumy.h"

void Mumy::Update() {

}


void Mumy::Draw() {

  mumyrec = { 592 + 8, 721 + 10, 32, 32 };
  DrawRectangleRec(mumyrec, Color {});
  DrawTextureRec(spr_mumy, frameRec, { static_cast<float>(592), static_cast<float>(721) }, WHITE);
  frameRec.x = (float)currentFrame * (float)spr_mumy.width / 4;

}

Rectangle Mumy::getMumyRec() {
  return MumyRec;
}
