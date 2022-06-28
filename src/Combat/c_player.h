#pragma once
#include <raylib.h>

namespace Game {

class Player {
  public:
  float HP;
  float ATK;
  float DEF;
  float Energy;
  bool turn = false;
  };

}
