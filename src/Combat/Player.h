#pragma once
#include "GameCharacter.h"
#include <vector>
#include "../Sprite/Sprite.h"

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

    virtual Texture2D get_texture();

    Texture2D t_Player = LoadTexture("assets/graphics/Ägypten/Nemo_BattleSheet.png");

    Rectangle frameRec = { 0.0f, 0.0f, (float)t_Player.width / 7, (float)t_Player.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 4; // animtation fps
    Rectangle nemorec  = {}; //The attributes for the Rectangle will be set in the Draw method.

  };
}
