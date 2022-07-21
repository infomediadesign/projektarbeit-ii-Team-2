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

    int get_turnnumb() override;

    void updateCharacter() override;

    virtual Rectangle get_rec() override;

    virtual Rectangle set_rec() override;

    void draw() override;
    //Battlesheet of Player
    Texture2D spr_Player = LoadTexture("assets/graphics/BattleScreen/Agypten/Nemo_Battle.png");

    Rectangle battlerec = {};

    Rectangle frameRec = { 0.0f, 0.0f, (float)spr_Player.width / 7, (float)spr_Player.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 4; // animation fps
    Rectangle Playerrec  = {}; //The attributes for the Rectangle will be set.

  };
}
