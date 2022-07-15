#pragma once

#include "../INCLUDES.h"

namespace Game {
  class Sprite {
  public:
    int pos_x;
    int pos_y;
    Texture2D texture_;

    Sprite() = delete;

    Sprite(int pos_x, int pos_y, Texture2D texture);

    Sprite(int pos_x, int pos_y, const std::string &filename);

    Sprite(int pos_x, int pos_y, const char *filename);

    ~Sprite();
  };
} // namespace Game