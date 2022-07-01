#pragma once
#include <raylib.h>

namespace Game {

class Player {
	//setting up the player for Combat, his stats will be changed in the future, it is for now just a prototype
  public:
	  int HP = 2;
	  int ATK = 2;
	  int DEF = 2;
	  int Energy = 2;
	  int turn = false;
	  int turnnumb = GetRandomValue(0, 100);
	  Rectangle playerrec {410, 320, 50, 50};
  
	  //Everything the player does during Combat
	  void update();

  };

}
