#pragma once

#include "raylib.h"

#include <cmath>
#include <array>

namespace Game {
  class Map {
  public:

    void draw();

    const float tile_size   = 32.0;
    const int tiles_per_row = 40;

    // 2D Array
    const std::array<std::array<int, 10>, 10> levelBackground {};
    const std::array<std::array<int, 10>, 10> levelAnimation {};
    const std::array<std::array<int, 10>, 10> levelDecoration {};
    const std::array<std::array<int, 10>, 10> levelCollision {};

    // 1D Array
    // const std::array<int, 100> levelDecoration {};
    // const std::array<int, 100> levelCollision {};

    // Level Structure:
    // Level Background
    // Level Animation
    // Level Decoration
    // Level Collision
  };
}