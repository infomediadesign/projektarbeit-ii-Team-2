#pragma once
#include <raylib.h>

namespace Game {
//Setting up the Stats of the Enemy in a seperate Header, for testing I generated now a general Enemy, it will change in the future
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