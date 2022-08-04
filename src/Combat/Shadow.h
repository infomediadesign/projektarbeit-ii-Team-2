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

    auto attack() -> std::vector<int> override;

    void getDamage(std::vector<int> damage) override;

    void updateCharacter() override;

    auto get_rec() -> Rectangle override;

    auto set_rec() -> Rectangle override;
  };

} // namespace Game


