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

	std::vector<int> attack() override;

	void getDamage(std::vector<int> damage) override;

	void updateCharacter() override;

	virtual Rectangle get_rec() override;

  virtual Rectangle set_rec() override;

  };
}
