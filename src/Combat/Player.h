#pragma once
#include "GameCharacter.h"
#include <vector>

namespace Game 
{
class Player: public GameCharacter 
{
public:
    Player();

    std::vector<int> attack() override;

    void getDamage(std::vector<int> damage) override;

    void updateCharacter() override;

    virtual Rectangle get_rec() override;

    virtual Rectangle set_rec() override;

  };
}
