#pragma once

#include "../Combat/Mumy.h"
#include "../Combat/Player.h"
#include "../Combat/Shadow.h"
#include "../Combat/Pharaoh.h"
#include "../INCLUDES.h"
#include "../Player/Nemo.h"
#include "UI.h"
#include "config.h"

namespace Game {
  class Level {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");
    Texture2D Battlescreen = LoadTexture("assets/graphics/BattleScreen/Agypten/HintergrundBatlleScreen_Agypten.png");
    Texture2D spr_Player = LoadTexture("assets/graphics/BattleScreen/Agypten/Nemo_Battle.png");
    Texture2D Fish = LoadTexture("assets/graphics/Fish.png");

    GameCharacter *player         = new Player();
    GameCharacter *enemy          = new Mumy();
    GameCharacter *shadow         = new Shadow();
    GameCharacter *pharaoh        = new Pharaoh();
    Nemo *nemo                    = new Nemo();
    //Level *level                = new Level();
    //UI *ui                      = new UI();

    Game::Level *level;

    Rectangle battlerec = {};

    Rectangle frameRec = { 0.0f, 0.0f, (float)spr_Player.width / 7, (float)spr_Player.height };
    int currentFrame   = 0;
    int framesCounter  = 0;
    int framesSpeed    = 4; // animation fps
    Rectangle Playerrec  = {}; //The attributes for the Rectangle will be set.

    //teleport stuff
    const float doortileX     = 66.0;
    const float doortileY     = 45.0;
    const float doorPositionX = 815.0;
    const float doorPositionY = 276.0;

    Rectangle teleportrecOVERWORLDtoPYRAMID = {};
    Rectangle teleportrecPYRAMIDtoOVERWORLD = {};
    Rectangle teleportrecPYRAMIDtoOCEAN = {};
    Rectangle teleportrecOCEANtoEND = {};

    bool teleportcollisionOVERWORLDtoPYRAMID = true;
    bool teleportcollisionPYRAMIDtoOVERWORLD = true;
    bool teleportcollisionPYRAMIDtoOCEAN = true;
    bool teleportcollisionOCEANtoEND = true;

    void combat();

    enum class GameScreen { TITLESCREEN, OVERWORLD, COMBAT, PYRAMIDE, OCEAN, PAUSEMENU, CUTSCENE }; //This Enum Class is there to set the Screens to TITLE etc.

    GameScreen currentscreen = GameScreen::COMBAT; //TitleScreens is the Start Screen
    //GameScreen currentscreen = GameScreen::TITLESCREEN; // TitleScreens is the Start Screen

    //teleport stuff
    //enum class OverworldState { INPYRAMIDE, OUTPYRAMIDE, OCEAN }; //This Enum Class is there to teleport
    //OverworldState currentscreen = OverworldState::OUTPYRAMIDE; // TitleScreens is the Start Screen

    void Screeninit();

    void ScreenDraw();

    void Draw();

    void Teleport();

    ~Level();
  };
} 