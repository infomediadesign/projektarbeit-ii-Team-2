#pragma once
#include "../INCLUDES.h"

#include "../Sprite/Sprite.h"
using namespace std;

namespace Game 
{
  class GameCharacter 
  {
  public:
    GameCharacter(string n_name, int max_HP, int HP, int DEF, int STR);

    virtual string get_Name();

    virtual std::vector<int> attack() = 0;

    virtual void getDamage(std::vector<int> damage) = 0;

    virtual void updateCharacter() = 0;

    virtual auto getLives() -> int;

    virtual auto  getArmor() -> int;

    virtual auto getStrength() -> int;

    virtual auto get_rec() -> Rectangle;

    virtual auto set_rec() -> Rectangle;

    virtual void heal();

    virtual auto get_turnnumb() -> int;

    virtual void set_turnnumb(int luck);

    virtual void draw();

    enum class state
    {
      IDLE,
      ATTACK,
    };

    virtual ~GameCharacter() = default;

  protected:
    int c_MaxHP, c_HP, c_DEF, c_STR;
    int c_timeattack = c_STR * 2;
    string name;
    int turnnumb = GetRandomValue(0, 100);
    Rectangle rec { 800, 320, 50, 50 };
    int getDamageNumber();
  };
}
