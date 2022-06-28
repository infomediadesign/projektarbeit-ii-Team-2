#pragma once
#include <raylib.h>

namespace Game {
  class Enemy {
  public:
    float HP;
    float ATK;
    float DEF;
    float Energy;
    bool Turn;
    bool Turnused;
  };
}