#include"INCLUDES.h"

#include "Level/GameAudio.h"
#include "Level/Inventory.h"
#include "Level/Level.h"

#include "Level/UI.h"
#include "Level/Puzzle.h"

#include "Player/Nemo.h"
#include "Enemy Overworld Sprites/Mumy.h"
#include "Enemy Overworld Sprites/Shadow.h"
#include "Enemy Overworld Sprites/Pharaoh.h"

#include "Sprite/Sprite.h"

/** Custodia - Trapped in time */

int main() {
  // Raylib initialization
  //--------------------------------------------------------------------------------------------
  Image Epanox = LoadImage("assets/graphics/Epanox_Standing - Kopie.png");

  InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
  InitAudioDevice(); // Initialize audio device

  SetWindowIcon(Epanox);
  SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN

#endif

  // Initialization
  //--------------------------------------------------------------------------------------------
  Puzzle puzzle;

  GameAudio::Load();

  Game::Level level;
  Game::Level levelcollision;
  Game::UI ui;
  Game::Nemo nemo; // Initializing the Nemo (Player) Class
  Game::Sprite spr(nemo.NemoPosition.x, nemo.NemoPosition.y, nemo.Front);

  Mumy *overworld_mumy = new Mumy();
  Pharaoh *overworld_pharaoh = new Pharaoh();
  Shadow *overwold_shadow = new Shadow();

  Game::Sprite Mumy_Sprite(592, 721, overworld_mumy->spr_mumy);
  Game::Sprite Shadow_Sprite(590.5, 1014, overwold_shadow->spr_shadow);
  Game::Sprite Pharaoh_Sprite(1455, 198, overworld_pharaoh->spr_Pharaoh);

  level.level = &level;
  level.nemo = &nemo;
  level.spr = &spr;

  puzzle.nemo = &nemo;

  bool MumyDraw = true;   // To set the drawing if it is true or false. In short if it is draw or deleted
  bool ShadowDraw = true;
  bool PharaohDraw = true;
  bool TimeCrystalDraw = true;
  bool collisiononce = false;
  bool epanoxEndDialog = false;

  //for puzzleroom door to open when mumy dies...
  Rectangle door2 = {576, 896, 64, 32};   //door 2 to puzzle room
  Texture2D WallTile = LoadTexture("assets/graphics/Items/Wand.png");
  Texture2D DungeonFloorTile = LoadTexture("assets/graphics/Items/DungeonFloorPlate.png");
  Texture2D ChestOpen = LoadTexture("assets/graphics/Items/OpenChest.png");
  bool doorOpen = false;
  bool doorText = false;
  Texture2D Dialogbox = LoadTexture("assets/graphics/Character/Dialogbox.png");
  /** Floats */
  float timesinceIdle = 0;

  //fonts stuff
  Font textFont = LoadFont("assets/Born2bSportyV2.ttf");
  float fontSize = 20;
  float fontSpacing = 0.05;

  //Map stuff
  std::ifstream tilesetDescriptionFile("assets/graphics/map/Level1/PhyramidSheet.json"); //Pyramiden_SheetJamey.json needed as json, pls do in tiled
  assert(tilesetDescriptionFile.is_open());
  nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
  tilesetDescriptionFile.close();

  //Outside the Pyramid
  std::ifstream levelMapFile("assets/graphics/map/Level1/PhyramidEntry.json");
  assert(levelMapFile.is_open());
  nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
  levelMapFile.close();

  //Inside the Pyramid
  std::ifstream levelMapFileDungeon("assets/graphics/map/Level1/PhyramidDungeon.json");
  assert(levelMapFileDungeon.is_open());
  nlohmann::json levelMapDungeon = nlohmann::json::parse(levelMapFileDungeon);
  levelMapFileDungeon.close();

  Texture2D tileAtlasTexture = LoadTexture("assets/graphics/map/Level1/Egypt-Sheet.png");
  /**/

  Collision collision (levelMapDungeon);

  collision.nemo = &nemo;
  collision.level = &level;

    // Camera settings
  //--------------------------------------------------------------------------------------------
  Camera2D camera = { 0 };
  camera.target   = Vector2 { spr.pos_x + 20.0f, spr.pos_y + 20.0f };
  camera.offset   = Vector2 { Game::ScreenWidth / 2.0f, Game::ScreenHeight / 2.0f };
  camera.zoom     = 2.0f;

  // Main game loop
  //--------------------------------------------------------------------------------------------
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    HideCursor();
    SetExitKey(KEY_O);

    // Begin drawing
    //--------------------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode2D(camera);

    level.ScreenDraw(); // the switchcase for switching between rooms (in the level.cpp) (the same as is underneath this)

    // Using Switch Case to Initialize the requirements to move to certain positions
    switch (level.currentscreen) { // Get Ready for some Spaghetti Code

    case Game::Level::GameScreen::TITLESCREEN:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      camera.zoom   = 1.0f;
      break;

    case Game::Level::GameScreen::PAUSEMENU:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      camera.zoom   = 1.0f;
      break;

    case Game::Level::GameScreen::PAUSEMENU_OVERWORLD:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      camera.zoom   = 1.0f;
      break;

    case Game::Level::GameScreen::PAUSEMENU_PYRAMID:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      camera.zoom   = 1.0f;
      break;

    case Game::Level::GameScreen::OVERWORLD:

      camera.zoom = 2.0f;

      // map.drawOVERWORLD();

      // map
      Vector2 vec;
      Rectangle rec;

      vec = { 0, 0 };
      rec = { 0, 0, levelMap["tilewidth"], levelMap["tileheight"] };
      for (auto const &layer : levelMap["layers"]) {
        if (layer["type"] == "tilelayer" && layer["visible"]) {
          vec.y = 0;
          for (auto const &tileId : layer["data"]) {
            int counter = (int)tileId;
            counter--;
            if (counter != -1) {
              rec.x = (float)((int)counter % (int)tilesetDescription["columns"]) * (float)levelMap["tilewidth"];
              rec.y =
                (float)floor((float)counter / (float)tilesetDescription["columns"]) * (float)levelMap["tileheight"];
              DrawTextureRec(tileAtlasTexture, rec, vec, WHITE); // entkoppeln, 2 vektoren machen
            }
            vec.x += (float)levelMap["tilewidth"];
            if (vec.x >= (float)layer["width"] * (float)levelMap["tilewidth"]) {
              vec.x = 0;
              vec.y += (float)levelMap["tileheight"];
            }
          }
        }
      }

      /**/

      collision.draw();
      collision.torchAnimations();

      if (IsKeyDown(KEY_R)) {
        collision.walldraw();
      }

      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      nemo.Draw();   // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

      collision.epanoxCollision();
      collision.outPyraWallCollision();

      ui.Draw(); // controlls description

      if (IsKeyPressed(KEY_E)) {
        DrawFPS(nemo.NemoPosition.x - 280, nemo.NemoPosition.y - 150);
      }

      // teleport into pyramid
      level.Teleport();
      DrawRectangleRec(level.teleportrecOVERWORLDtoPYRAMID, Color {});
      // DrawRectangleRec(level.teleportrecOVERWORLDtoPYRAMID, RED);

      break;

    case Game::Level::GameScreen::PYRAMIDE:

      camera.zoom = 2.0f;

      // map.drawPYRAMID();

      Vector2 vecDungeon;
      Rectangle recDungeon;

      vecDungeon = { 0, 0 };
      recDungeon = { 0, 0, levelMapDungeon["tilewidth"], levelMapDungeon["tileheight"] };
      for (auto const &layer : levelMapDungeon["layers"]) {
        if (layer["type"] == "tilelayer" && layer["visible"]) {
          vecDungeon.y = 0;
          for (auto const &tileId : layer["data"]) {
            int counter = (int)tileId;
            counter--;
            if (counter != -1) {
              recDungeon.x = (float)((int)counter % (int)tilesetDescription["columns"]) * (float)levelMap["tilewidth"];
              recDungeon.y =
                (float)floor((float)counter / (float)tilesetDescription["columns"]) * (float)levelMap["tileheight"];
              DrawTextureRec(tileAtlasTexture, recDungeon, vecDungeon, WHITE); // entkoppeln, 2 vektoren machen
            }
            vecDungeon.x += (float)levelMapDungeon["tilewidth"];
            if (vecDungeon.x >= (float)layer["width"] * (float)levelMapDungeon["tilewidth"]) {
              vecDungeon.x = 0;
              vecDungeon.y += (float)levelMapDungeon["tileheight"];
            }
          }
        }
      }

      //=============================INITIALIZE COMBAT ONCE BEEING ENCOUNTERED====================================

      //====================================================MUMMY=============================================================
      if (MumyDraw) {
        overworld_mumy->Draw();
      }
      // Collision check
      if (CheckCollisionRecs(overworld_mumy->getMumyRec(),
                             nemo.nemorec)) // Where the Collision between Two Objects happen happens
      {
        level.currentscreen = Game::Level::GameScreen::COMBAT; // After Returning back to the OVERWORLD ya get
        level.opponent      = Game::Level::EnemyType::MUMY;

        MumyDraw                = false; // NPC is deleted
        overworld_mumy->MumyRec = {};
      }

      if (!MumyDraw) {
        DrawTexture(DungeonFloorTile, 576, 896, WHITE);
        DrawTexture(DungeonFloorTile, 608, 896, WHITE);
        door2 = {};
      }
      //====================================================TIME SHADOW=======================================================
      if (ShadowDraw) {
        overwold_shadow->Draw();
      }

      if (CheckCollisionRecs(overwold_shadow->getShadowRec(), nemo.nemorec)) {
        level.currentscreen = Game::Level::GameScreen::COMBAT;
        level.opponent      = Game::Level::EnemyType::SHADOW;

        ShadowDraw                 = false;
        overwold_shadow->Shadowrec = {};
      }
      //====================================================PHARAOH===========================================================

      if (CheckCollisionRecs(puzzle.Crystalrec, nemo.nemorec)) {
        TimeCrystalDraw = false;
        collisiononce   = true;
        epanoxEndDialog = true;
      }
      if (collisiononce) {
        puzzle.portalAnimation();
        puzzle.Crystalrec = {};
      }
      if (!PharaohDraw) {
        if (TimeCrystalDraw) {
          puzzle.crystaldraw();
        }
      }

      if (PharaohDraw) {
        overworld_pharaoh->Draw();
      }

      if (CheckCollisionRecs(overworld_pharaoh->getPharaohRec(), nemo.nemorec)) {
        level.currentscreen = Game::Level::GameScreen::COMBAT;
        level.opponent      = Game::Level::EnemyType::PHARAOH;

        PharaohDraw                   = false;
        overworld_pharaoh->Pharaohrec = {};
      }
      //==========================================THE END=========================================================

      if (epanoxEndDialog){
        timesinceIdle += GetFrameTime();
        DrawTexture(Dialogbox, nemo.NemoPosition.x - 180, nemo.NemoPosition.y + 90, WHITE);

        DrawTextEx(textFont, "Epanox", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Now that you've defeated the Boss and picked up", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "the Time Crystal, you'll be able to continue your ", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "journey home. Now step into the Portal to continue", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 150 }, fontSize, fontSpacing, WHITE);

        if (timesinceIdle >= 10) {
          epanoxEndDialog = false;
          timesinceIdle = 0;
        }
      }

      if (IsKeyPressed(KEY_E)) {
        DrawFPS(nemo.NemoPosition.x - 280, nemo.NemoPosition.y - 150);
      }

      puzzle.epanoxAnimation();
      puzzle.draw();

      collision.torchAnimations();

      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      nemo.Draw();   // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

      if (CheckCollisionRecs(door2, nemo.nemorec)) {
        puzzle.stopNemo();
        doorText = true;
      }

      if (doorText) {
        timesinceIdle += GetFrameTime();

        DrawTexture(Dialogbox, nemo.NemoPosition.x - 180, nemo.NemoPosition.y + 90, WHITE);
        DrawTextEx(textFont, "Door Info", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 65 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "This Door is locked... ", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 100 }, fontSize, fontSpacing, WHITE);
        DrawTextEx(textFont, "Kill the Mummy, to enter the door", { nemo.NemoPosition.x - 172, nemo.NemoPosition.y + 125 }, fontSize, fontSpacing, WHITE);

        if (timesinceIdle >= 4) {
          doorText      = false;
          timesinceIdle = 0;
        }
      }

      collision.inPryaWallCollision();

      puzzle.collisionChecks();
      puzzle.update();

      //teleport back to overworld
      level.Teleport();
      DrawRectangleRec(level.teleportrecPYRAMIDtoOVERWORLD, Color{});
      DrawRectangleRec(level.teleportrecPYRAMIDtoENDSCREEN, Color{});

      break;

    case Game::Level::GameScreen::ENDSCREEN:

      camera.zoom     = 1.0f;
      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      break;

    case Game::Level::GameScreen::THANKYOU:

      camera.zoom     = 1.0f;
      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      break;

    case Game::Level::GameScreen::NEMO_WAKEUP:

      camera.zoom     = 2.0f;
      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      break;


    case Game::Level::GameScreen::COMBAT:
      camera.zoom     = 2.0f;

      nemo.active = false; // Nemo is set to false, so that he is not drawn in the Combat screen.
      camera.target =
        Vector2 { Game::ScreenWidth / 2,
                  Game::ScreenHeight / 2 }; // Setting Camera to a Constant Position. Otherwise it would follow Nemo
      break;

    case Game::Level::GameScreen::GAMEOVER:
      camera.zoom     = 1.0f;
      camera.target = Vector2 {Game::ScreenWidth / 2 , Game::ScreenHeight / 2};
      break;
    }

    EndMode2D(); // camera

    EndDrawing();
    //--------------------------------------------------------------------------------------------
  }
  // Main game loop end
  //--------------------------------------------------------------------------------------------

  // De-initialization here
  //--------------------------------------------------------------------------------------------


  level.~Level();
  puzzle.~Puzzle();

  CloseAudioDevice(); // Close audio device

  CloseWindow(); // Close window and OpenGL context

  return EXIT_SUCCESS;
}
