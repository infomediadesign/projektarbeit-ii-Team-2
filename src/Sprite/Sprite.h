#pragma once

#include "../INCLUDES.h"

namespace Game {
  class Sprite {
  public:
    int pos_x;
    int pos_y;
    Texture2D texture_;

    Texture2D EpanoxStil = LoadTexture("assets/graphics/Epanox_Standing - Kopie.png");

    //Epanox Stuff for Collision
    Rectangle  EpanoxRec = {961, 458, 16, 20}; //EpanoxRec
    bool EpanoxCollision = false;

    void EpanoxDraw();

    Sprite() = delete;

    Sprite(int pos_x, int pos_y, Texture2D texture);

    Sprite(int pos_x, int pos_y, const std::string &filename);

    Sprite(int pos_x, int pos_y, const char *filename);

    ~Sprite();
  };
} // namespace Game