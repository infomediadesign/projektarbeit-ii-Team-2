#pragma once
#include <raylib.h>
#include "c_player.h"
#include "c_enemy.h"

namespace Game {
  class Combat {
	//Here will be set a overall general Combat class, where Player and Enemy Class will be initislized
	
	//initiallizes:
	Sound BattleMusic = LoadSound("assets/audio/sfx/chibi-robot-b.ogg");
	bool pause = false;

	Game::Player player;
	Game::Enemy enemy;

	void Draw();
    void update();

	~Combat();
  };
}