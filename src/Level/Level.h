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
    //Textures
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");
    Texture2D Battlescreen = LoadTexture("assets/graphics/BattleScreen/Agypten/HintergrundBatlleScreen_Agypten.png");
    Texture2D Fish = LoadTexture("assets/graphics/Fish.png");
    Texture2D Box = LoadTexture("assets/graphics/BattleScreen/Agypten/Auswahl_Cursor.png");
    Texture2D Box_S = LoadTexture("assets/graphics/BattleScreen/Agypten/Auswahl_Cursor_S.png");
    Texture2D Attack = LoadTexture("assets/graphics/BattleScreen/Agypten/Attack_Schrift.png");

//Class initialization

    //GameCharacter *player          = new Player();
    unique_ptr<GameCharacter> player = std::make_unique<Player>();
    unique_ptr<GameCharacter> enemy = std::make_unique<Mumy>();
    //GameCharacter *enemy          = new Mumy();
    GameCharacter *shadow         = new Shadow();
    GameCharacter *pharaoh        = new Pharaoh();
    Nemo *nemo                    = new Nemo();
    //Level *level                = new Level();
    //UI *ui                      = new UI();
    Game::Level *level;

    //teleport stuff
    const float doortileX     = 67.0;
    const float doortileY     = 45.0;
    const float doorPositionX = 910.0;
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

    Rectangle t_rec_attack = {565, 470, 78, 32};
    Rectangle box_rec = {565, 470, 78, 32};
    Rectangle t_rec_time = {t_rec_attack.x + 90, t_rec_attack.y, t_rec_attack.width, t_rec_attack.height};
    Rectangle t_rec_item = {t_rec_attack.x, t_rec_attack.y + 35, t_rec_attack.width, t_rec_attack.height};
    Rectangle t_rec_escape = {t_rec_time.x, t_rec_time.y + 35, t_rec_attack.width, t_rec_attack.height };
    float thickness = 15;

    static void Draw9Slice(Texture2D& Box, Rectangle rec, float thickness, Color tint)
    {
      //slice is a const that helps with readability of the function
      const auto slice = Box.width / 3.0f;
      //Stuffing
      DrawTexturePro(Box, { slice,slice,slice,slice }, { rec.x + thickness,rec.y + thickness,rec.width - thickness * 2,rec.height - thickness * 2 }, {}, 0, tint);
      //top left corner
      DrawTexturePro(Box, { 0,0,slice,slice }, { rec.x, rec.y, thickness, thickness }, {}, 0, tint);
      //top right corner
      DrawTexturePro(Box, { slice * 2,0,slice,slice }, { rec.x + rec.width - thickness,rec.y,thickness,thickness }, {}, 0, tint);
      //bottom left corner
      DrawTexturePro(Box, { 0,slice * 2,slice,slice }, { rec.x,rec.y + rec.height - thickness,thickness,thickness }, {}, 0, tint);
      //bottom right corner
      DrawTexturePro(Box, { slice * 2,slice * 2,slice,slice }, { rec.x + rec.width - thickness ,rec.y + rec.height - thickness ,thickness,thickness }, {}, 0, tint);
      //top bumper
      DrawTexturePro(Box, { slice,0,slice,slice }, { rec.x + thickness,rec.y,rec.width - thickness * 2,thickness }, {}, 0, tint);
      //bottom bumper
      DrawTexturePro(Box, { slice,slice * 2,slice,slice }, { rec.x + thickness,rec.y + rec.height - thickness, rec.width - thickness * 2,thickness }, {}, 0, tint);
      //left bumper
      DrawTexturePro(Box, { 0, slice, slice,slice }, { rec.x, rec.y + thickness, thickness, rec.height - thickness * 2 }, {}, 0, tint);
      //right bumper
      DrawTexturePro(Box, { slice * 2,slice,slice,slice }, { rec.x + rec.width - thickness, rec.y + thickness, thickness, rec.height - thickness * 2 }, {}, 0, tint);
    }

    void Teleport();

    ~Level();

  };
} 