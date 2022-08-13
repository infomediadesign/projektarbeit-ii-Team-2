#pragma once
#include "../INCLUDES.h"
#include <string.h>
#include "GameCharacter.h"


namespace Game 
{
  class Mumy :
	  public GameCharacter
  {
  public:
    Mumy();

	auto attack() -> std::vector<int> override;

	void getDamage(std::vector<int> damage) override;

  auto get_turnnumb() -> int override;

	void updateCharacter() override;

	Rectangle get_rec() override;

  Rectangle set_rec() override;

  void draw() override;

  GameCharacter::state State = state::IDLE;

  //Battlesheet of Player
  Texture2D spr_mumy = LoadTexture("assets/graphics/BattleScreen/Agypten/Mumy_Battle.png");
  Texture2D healthbar = LoadTexture("assets/graphics/battlescreen/Agypten/spr_healthbar_enemy.png");
  Texture2D health = LoadTexture("assets/graphics/battlescreen/Agypten/spr_health_red.png");
  Rectangle healthrec = {};

  Rectangle frameRec = { 0.0f, 0.0f, (float)spr_mumy.width / 4, (float)spr_mumy.height };
  int currentFrame   = 0;
  int framesCounter  = 0;
  int framesSpeed    = 2; // animation fps
  Rectangle mumyrec  = {}; //The attributes for the Rectangle will be set.

  };
}
