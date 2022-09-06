#pragma once

#include "../Combat/Mumy.h"
#include "../Combat/Player.h"
#include "../Combat/Shadow.h"
#include "../Combat/Pharaoh.h"
#include "../INCLUDES.h"
#include "../Player/Nemo.h"
#include "UI.h"
#include "../Sprite/Sprite.h"
#include "../Level/Endscreen.h"
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
    Texture2D Titlescreen = LoadTexture("assets/graphics/titlepic.png");
    Texture2D Pausescreen = LoadTexture("assets/graphics/backgrounds/testtitlescreen.png");
    Texture2D TitlescreenText = LoadTexture("assets/graphics/Titel1.png");
    Texture2D spr_Battery = LoadTexture("assets/graphics/BattleScreen/Agypten/Batterieanzeige-Sheet.png");
    Texture2D gameover = LoadTexture("assets/graphics/backgrounds/GameOverScreen.png");

//Class initialization



    unique_ptr<GameCharacter> player = std::make_unique<Player>();

    GameCharacter *enemy          = new Mumy();
    GameCharacter *shadow         = new Shadow();
    GameCharacter *pharaoh        = new Pharaoh();
    Nemo *nemo                    = new Nemo();
    //Level *level                = new Level();
    //UI *ui                      = new UI();

    //===================ENERGY BATTERY======================================
    int energy = 2;
    Rectangle batteryrec1 = {0, 0, (float)spr_Battery.width/2, (float)spr_Battery.height};
    int b1_c_frame = 0;
    Rectangle B1rec = {};


    Rectangle batteryrec2 = {0, 0, (float)spr_Battery.width/2, (float)spr_Battery.height};
    int b2_c_frame = 0;
    Rectangle B2rec = {};

    //===================END ENERGY BATTERY==================================


    Game::Level *level;
    Game::Sprite *spr;
    Endscreen endscreen;

    //Setting an Input to prevent the Player from attacking, while the countdown runs
    bool input = true;

    //Setting up a timer and Frame Counter.
    bool timer = false;
    int framescounter = 0;
    int h_amount = 2;

    int p_framescounter;
    int e_framescounter;
    bool p_damaged = false;
    bool T_damaged = false;
    bool e_damaged = false;

    //teleport stuff
    const float doortileX     = 67.0;
    const float doortileY     = 45.0;
    const float doorPositionX = 910.0;
    const float doorPositionY = 276.0;

    Rectangle teleportrecOVERWORLDtoPYRAMID = {};
    Rectangle teleportrecPYRAMIDtoOVERWORLD = {};
    Rectangle teleportrecPYRAMIDtoENDSCREEN = {};

    bool teleportcollisionOVERWORLDtoPYRAMID = true;
    bool teleportcollisionPYRAMIDtoOVERWORLD = true;
    bool teleportcollisionPYRAMIDtoENDSCREEN = true;

    void combat(GameCharacter *c_enemy);

    enum class GameScreen { TITLESCREEN, OVERWORLD, COMBAT, PYRAMIDE,
      ENDSCREEN, PAUSEMENU, CUTSCENE, GAMEOVER}; //This Enum Class is there to set the Screens to TITLE etc.

    GameScreen currentscreen = GameScreen::TITLESCREEN; //TitleScreens is the Start Screen
    //GameScreen currentscreen = GameScreen::PYRAMIDE; //TitleScreens is the Start Screen

    enum class EnemyType {NONE, MUMY, SHADOW, PHARAOH};

    EnemyType opponent = EnemyType::NONE;

    void ScreenDraw();

    void Draw();

    Rectangle box_rec_titlescreen = {ScreenWidth / 2 - 130 , Game::ScreenHeight / 2 - 50, 234, 64};
    Rectangle t_rec_start = {ScreenWidth / 2 - 130, Game::ScreenHeight / 2 - 50, 234, 64};
    Rectangle t_rec_settings = {ScreenWidth / 2 - 130 , Game::ScreenHeight / 2 + 50, t_rec_start.width, t_rec_start.height};
    Rectangle t_rec_exit_game = {ScreenWidth / 2 - 130, Game::ScreenHeight / 2 + 150, t_rec_start.width, t_rec_start.height};
    float thick = 30;

    Rectangle t_rec_attack = {565, 470, 78, 32};
    Rectangle box_rec = {565, 470, 78, 32};
    Rectangle t_rec_time = {t_rec_attack.x + 90, t_rec_attack.y, t_rec_attack.width, t_rec_attack.height};
    Rectangle t_rec_item = {t_rec_attack.x, t_rec_attack.y + 35, t_rec_attack.width, t_rec_attack.height};
    Rectangle t_rec_escape = {t_rec_time.x, t_rec_time.y + 35, t_rec_attack.width, t_rec_attack.height };
    float thickness = 15;

    int t_framescounter = 0;

    //====================BLUE CLOCK=========================================

    Texture2D Blue_Clock = LoadTexture("assets/graphics/BattleScreen/Agypten/BlaueUhr-Sheet.png");
    Rectangle BlueClockFrameRec = { 0.0f, 0.0f, (float)Blue_Clock.width / 4, (float)Blue_Clock.height };
    int b_currentFrame   = 0;
    Rectangle Bluerec  = {}; //The attributes for the Rectangle will be set.

    //================END OF BLUE CLOCK======================================

    //====================RED CLOCK=========================================

    Texture2D Red_Clock = LoadTexture("assets/graphics/BattleScreen/Agypten/RoteUhr-Sheet.png");
    Rectangle RedClockFrameRec = { 0.0f, 0.0f, (float)Red_Clock.width / 4, (float)Red_Clock.height };
    int r_currentFrame   = 0;
    Rectangle Redrec  = {}; //The attributes for the Rectangle will be set.

    //=================END OF RED CLOCK=====================================


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

    void damaged(GameCharacter *enemy_)
    {
      //Drawing Player received damage number
      if (p_damaged) {

        p_framescounter++;

        DrawText(TextFormat("- %i", enemy_->getStrength() - player->getDefense()),player->set_rec().x + 80,player->set_rec().y,20,RED);

        if (((p_framescounter / 60) % 2) == 1) {
          p_framescounter = 0;
          p_damaged = false;
        }
      }

      if (T_damaged)
      {
        e_framescounter++;

        DrawText(TextFormat("- %i", (player->getStrength() * 2) - enemy_->getDefense() - 2),enemy_->set_rec().x - 40,enemy_->set_rec().y,20,RED);

        if (((e_framescounter / 60) % 2) == 1) {
          e_framescounter = 0;
          T_damaged       = false;
        }

      }

      //Drawing the Enemy Damage received number
      if (e_damaged) {

        e_framescounter++;

        DrawText(TextFormat("- %i", player->getStrength() - enemy_->getDefense()),enemy_->set_rec().x - 40,enemy_->set_rec().y,20,RED);

        if (((e_framescounter / 60) % 2) == 1) {
          e_framescounter = 0;
          e_damaged  = false;
        }
      }
    }

  };
} 