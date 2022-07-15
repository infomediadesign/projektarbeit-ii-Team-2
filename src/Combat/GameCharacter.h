#pragma once
#include "../INCLUDES.h"

#include "../Sprite/Sprite.h"

namespace Game 
{
  class GameCharacter 
  {
  public:
    GameCharacter(int HP, int DEF, int STR);

    virtual std::vector<int> attack() = 0;

    virtual void getDamage(std::vector<int> damage) = 0;

    virtual void updateCharacter() = 0;

    virtual int getLives();

    virtual int  getArmor();

    virtual int getStrength();

    virtual Rectangle get_rec();

    virtual Rectangle set_rec();

    virtual void heal();

    virtual int get_turnnumb();

    virtual void set_turnnumb(int turnnumb);

  protected:
    int c_HP, c_DEF, c_STR;
    int turnnumb = GetRandomValue(0, 100);
    Rectangle rec { 800, 320, 50, 50 };
  };
}
