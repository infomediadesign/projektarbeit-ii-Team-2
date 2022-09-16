#pragma once
#include "../INCLUDES.h"
#include "GameCharacter.h"


namespace Game
{
  class Pharaoh :
      public GameCharacter
  {
  public:
    Pharaoh();

    auto attack() -> std::vector<int> override;

    void getDamage(std::vector<int> damage) override;

    auto get_turnnumb() -> int override;

    void updateCharacter() override;

    auto getStrength() -> int override;

    auto getDefense() -> int override;

    auto get_rec() -> Rectangle override;

    auto set_rec() -> Rectangle override;

    void draw() override;

    GameCharacter::state State = state::IDLE;

    int framescounter;

    //Battlesheet of Pharaoh
    Texture2D spr_pharaoh = LoadTexture("assets/graphics/BattleScreen/Agypten/Pharaoh_BattleSheet.png");
    Texture2D healthbar = LoadTexture("assets/graphics/battlescreen/Agypten/spr_healthbar_enemy.png");
    Texture2D health = LoadTexture("assets/graphics/battlescreen/Agypten/spr_health_red.png");
    Texture2D shadow = LoadTexture("assets/graphics/BattleScreen/Agypten/PharaoShadow-Sheet.png");
    Rectangle healthrec = {};

    Rectangle frameRec = { 0.0f, 0.0f, (float)spr_pharaoh.width / 4, (float)spr_pharaoh.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 2; // animation fps
    Rectangle pharaohrec  = {}; //The attributes for the Rectangle will be set.

    Rectangle s_frameRec = {0.0f, 0.0f, (float) shadow.width / 4, (float) shadow.height};
    int s_currentFrame = 0;
    int s_framesCounter = 0;
    int s_framesSpeed = 2;
    Rectangle shadowrec = {};

  };
}