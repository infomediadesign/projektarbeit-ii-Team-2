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

  };
}
