#pragma once
#include "../INCLUDES.h"

#include "GameCharacter.h"
#include "../Sprite/Sprite.h"

namespace Game 
{
class Player: public GameCharacter 
{
public:
    Player();

    std::vector<int> attack() override;

    void getDamage(std::vector<int> damage) override;

    auto get_turnnumb() -> int override;

    auto getStrength() -> int override;

    auto getDefense() -> int override;

    void updateCharacter() override;

    auto get_rec() -> Rectangle override;

    auto set_rec() -> Rectangle override;

    virtual void heal() override;

    void draw() override;

    GameCharacter::state State = GameCharacter::state::IDLE;

    int framescounter = 0;

    //Battlesheet of Player
    Texture2D spr_Player = LoadTexture("assets/graphics/BattleScreen/Agypten/Nemo_Battle.png");
    Texture2D healthbar = LoadTexture("assets/graphics/battlescreen/Agypten/spr_healthbar.png");
    Texture2D health = LoadTexture("assets/graphics/battlescreen/Agypten/spr_health.png");
    Texture2D swing = LoadTexture("assets/graphics/BattleScreen/Agypten/final_swing_1-Sheet.png");
    Rectangle healthrec = {};

    Rectangle swinframeRec = {0.0f, 0.0f, (float)swing.width / 5, (float)swing.height};
    int swingcurrentFrame = 0;
    int swingFramesCounter = 0;
    int swingFramesSpeed = 6;
    Rectangle Swingrec = {};

    Rectangle frameRec = { 0.0f, 0.0f, (float)spr_Player.width / 7, (float)spr_Player.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 5; // animation fps
    Rectangle Playerrec  = {}; //The attributes for the Rectangle will be set.
    bool swungblade = false;

  };
}
