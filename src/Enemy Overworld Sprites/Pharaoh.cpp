//
// Created by goerk on 21.08.2022.
//

#include "Pharaoh.h"

void Pharaoh::Update() {

}

void Pharaoh::Draw() {
  pharaohrec = { 1455 + 8, 198 + 10, 16, 32 };
  DrawRectangleRec(pharaohrec, Color {});
  DrawTextureRec(spr_Pharaoh, frameRec, { 1455, 198 }, WHITE);
  framesCounter++;
}

Rectangle Pharaoh::getPharaohRec() { return Rectangle(); }
