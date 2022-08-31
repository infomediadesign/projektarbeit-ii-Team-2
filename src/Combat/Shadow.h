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

    auto get_turnnumb() -> int override;

    void updateCharacter() override;

    auto getStrength() -> int override;

    auto getDefense() -> int override;

    void draw() override;

    auto get_rec() -> Rectangle override;

    auto set_rec() -> Rectangle override;

    GameCharacter::state State = state::IDLE;

    int framescounter;

    Texture2D spr_shadow = LoadTexture("assets/graphics/BattleScreen/Agypten/Timeshadow_Battle_Final-Sheet.png");
    Texture2D healthbar = LoadTexture("assets/graphics/battlescreen/Agypten/spr_healthbar_enemy.png");
    Texture2D health = LoadTexture("assets/graphics/battlescreen/Agypten/spr_health_red.png");
    Rectangle healthrec = {};

    Rectangle frameRec = { 0.0f, 0.0f, static_cast<float>((float)spr_shadow.width / 8), (float)spr_shadow.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 4; // animation fps
    Rectangle shadowrec  = {}; //The attributes for the Rectangle will be set.

  };

} // namespace Game


