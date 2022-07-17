#pragma once
#include "../INCLUDES.h"
#include "GameCharacter.h"

namespace Game
{

  class Shadow:
    public GameCharacter
  {
  public:
    Shadow();

    std::vector<int> attack() override;

    void getDamage(std::vector<int> damage) override;

    void updateCharacter() override;

    virtual Rectangle get_rec() override;

    virtual Rectangle set_rec() override;
  };

} // namespace Game


