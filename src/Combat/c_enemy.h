#pragma once
#include <raylib.h>

namespace Game {
//Setting up the Stats of the Enemy in a seperate Header, for testing I generated now a general Enemy, it will change in the future
  class Enemy {
  public:
        int HP = 2;
        int ATK = 2;
        int DEF = 2;
        int Energy = 2;
        int Turn = 2;
        int Turnused = 2;
        bool turn    = false;
        int turnnumb = GetRandomValue(0, 100);
        Rectangle enemyrec { 800, 320, 50, 50 };
        
        //Everything the Enemy does during Combat
        void update();
  };
}