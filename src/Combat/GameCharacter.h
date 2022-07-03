#pragma once
#include <raylib.h>
#include <vector>

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

    virtual int getArmor();

    virtual int getStrength();

    virtual Rectangle get_rec();

    virtual Rectangle set_rec();

    virtual int get_turnnumb();

  protected:
    int c_HP, c_DEF, c_STR;
    int turnnumb = GetRandomValue(0, 100);
    Rectangle rec { 800, 320, 50, 50 };
  };
}