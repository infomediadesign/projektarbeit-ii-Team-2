#pragma once
#include <raylib.h>

namespace Game {

class Player {
	//setting up the player for Combat, his stats will be changed in the future, it is for now just a prototype
  public:
  float HP;
  float ATK;
  float DEF;
  float Energy;
  bool turn = false;
  };

}
