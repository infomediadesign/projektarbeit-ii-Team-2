#pragma once
#include "GameCharacter.h"
#include <vector>

namespace Game 
{
  class Enemy :
	  public GameCharacter
  {
  public:
    Enemy();

	std::vector<int> attack() override;

	void getDamage(std::vector<int> damage) override;

	void updateCharacter() override;

	virtual Rectangle get_rec() override;

    virtual Rectangle set_rec() override;
  };
}
