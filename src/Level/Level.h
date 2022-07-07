#pragma once
#include <raylib.h>
#include <chrono>
#include <thread>

#include "UI.h"
#include "config.h"

#include "../Player/Nemo.h"
#include "../Combat/Player.h"
#include "../Combat/Enemy.h"


namespace Game {
  class Level {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");
    Texture2D Battlescreen = LoadTexture("assets/graphics/BattleScreen/Ägypten/HintergrundBatlleScreen_Ägypten.png");

    GameCharacter *player       = new Player();
    GameCharacter *enemy        = new Enemy();
    Nemo *nemo                  = new Nemo();
    //Level *level                = new Level();
    //UI *ui                      = new UI();

    void combat();

    enum class GameScreen { TITLESCREEN, OVERWORLD, COMBAT, PAUSEMENU, CUTSCENE }; //This Enum Class is there to set the Screens to TITLE etc.

    GameScreen currentscreen = GameScreen::COMBAT; //TitleScreens is the Start Screen
    //GameScreen currentscreen = GameScreen::TITLESCREEN; // TitleScreens is the Start Screen

    //teleport stuff
    //enum class OverworldState { INPYRAMIDE, OUTPYRAMIDE, OCEAN }; //This Enum Class is there to teleport
    //OverworldState currentscreen = OverworldState::OUTPYRAMIDE; // TitleScreens is the Start Screen

    void Screeninit();

    void ScreenDraw();

    void Draw();

    //void Teleport();

    void Collision();

    void Music();

    ~Level();
  };
} 