#pragma once
#include <raylib.h>
#include "../Player/Nemo.h"
#include "config.h"
#include "../Combat/GameCharacter.h"
#include "../Combat/Combat.h"

namespace Game {
  class Level {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");
    Texture2D Battlescreen = LoadTexture("assets/graphics/BattleScreen/Ägypten/HintergrundBatlleScreen_Ägypten.png");

    Sound OutPyra = LoadSound("assets/audio/sfx/cave_theme_2.wav"); 

    GameCharacter *player       = new Player();
    GameCharacter *enemy        = new Enemy();

    int wantedAction;
    bool gameloop = true;

    void combat();

    enum class GameScreen { TITLESCREEN, OVERWORLD, COMBAT, PAUSEMENU, CUTSCENE }; //This Enum Class is there to set the Screens to TITLE etc.

    GameScreen currentscreen = GameScreen::COMBAT; //TitleScreens is the Start Screen
    //GameScreen currentscreen = GameScreen::TITLESCREEN; // TitleScreens is the Start Screen

    void Screeninit();

    void ScreenDraw();

    void Draw();

    void Music();

    ~Level();
  };
} 