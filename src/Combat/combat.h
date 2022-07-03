#pragma once
#include "../Combat/Enemy.h"
#include "../Combat/GameCharacter.h"
#include "../Combat/Player.h"

namespace Game 
{
  class Combat : public GameCharacter 
  {
  public:
    GameCharacter* player = new Player();
    GameCharacter *enemy  = new Enemy();

    void Draw();
    void Update();
  };
}
