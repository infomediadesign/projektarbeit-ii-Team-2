//
// Created by goerk on 21.08.2022.
//

#include "Shadow.h"

void Shadow::Draw() {

  shadowrec = { 590.5 + 8, 1014 + 10, 16, 32 };
  DrawRectangleRec(shadowrec, Color {});
  DrawTextureRec(spr_shadow, frameRec, { 590.5, 1014 }, WHITE);

}

void Shadow::Update() {

}

Rectangle Shadow::getShadowRec() { return Shadowrec; }