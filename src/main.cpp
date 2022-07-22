#include"INCLUDES.h"

#include "Level/GameAudio.h"
#include "Level/Inventory.h"
#include "Level/Level.h"
#include "Level/Map.h"
#include "Level/UI.h"
#include "Level/Collision.h"

#include "Player/Nemo.h"

#include "Sprite/Sprite.h"

#include "Titlescreen.h"

// Project = Custodia - Trapped in the past

int main() {
  // Raylib initialization
  //--------------------------------------------------------------------------------------------
  Image Epanox = LoadImage("assets/graphics/Epanox_Standing - Kopie.png");

  InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
  SetWindowIcon(Epanox);
  InitAudioDevice(); // Initialize audio device
  SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN

#endif

  // Initialization
  //--------------------------------------------------------------------------------------------
  Texture2D StandStil = LoadTexture("assets/graphics/Charakter_Vorschlag_vorne_laufen1.png");

  Collision collision;
  //Titlescreen titlescreen;

  Map map;

  GameAudio::Load();
  Game::Level level;
  Game::Level levelcollision;
  Game::UI ui;
  Game::Nemo nemo; // Initializing the Nemo (Player) Class
  Game::Sprite spr(nemo.NemoPosition.x, nemo.NemoPosition.y, nemo.Front);
  Game::Sprite NPC(100, 100, StandStil);

  collision.nemo = &nemo;
  collision.level = &level;

  level.level = &level;
  level.nemo = &nemo;

  //titlescreen.level = &level;

  Rectangle NPCRec = {}; // Rectangle Position has to be set after it is drawn, leaving it free is so much better, until
                         // it is called. Do not touch it!!!
  bool NPCDraw = true;   // To set the drawing if it is true or false. In short if it is draw or deleted

  //Map Markus stuff
    std::ifstream tilesetDescriptionFile("assets/graphics/map/Level1/PhyramidSheet.json"); //Pyramiden_SheetJamey.json needed as json, pls do in tiled
    assert(tilesetDescriptionFile.is_open());
    nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
    tilesetDescriptionFile.close();

    /** Outside the Pyramid*/
    std::ifstream levelMapFile("assets/graphics/map/Level1/PhyramidEntry.json");
    assert(levelMapFile.is_open());
    nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
    levelMapFile.close();

    /** Inside the Pyramid*/
    std::ifstream levelMapFileDungeon("assets/graphics/map/Level1/PhyramidDungeon.json");
    assert(levelMapFileDungeon.is_open());
    nlohmann::json levelMapDungeon = nlohmann::json::parse(levelMapFileDungeon);
    levelMapFileDungeon.close();

    Texture2D tileAtlasTexture = LoadTexture("assets/graphics/map/Level1/Egypt-Sheet.png");
    //Texture2D tileAtlasTexture = LoadTexture((tilesetDescription["image"].get<std::string>()).c_str());

    //Music Tests
    /*
  if (level.currentscreen == Game::Level::GameScreen::OVERWORLD)
  {
    StopSound(GameAudio::battlemusic);
    PlaySound(GameAudio::outdungeon);
    SetSoundVolume(GameAudio::outdungeon, float(0.5)); // Set volume for a sound (1.0 is max level) This is a test
  }
  else if (level.currentscreen == Game::Level::GameScreen::COMBAT)
  {
    StopSound(GameAudio::outdungeon);
    PlaySound(GameAudio::battlemusic);
    SetSoundVolume(GameAudio::outdungeon, float(0.5)); // Set volume for a sound (1.0 is max level) This is a test
  }
  else
  {
    StopSound(GameAudio::outdungeon);
    StopSound(GameAudio::battlemusic);
  }
*/

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

    /**map updates...*/
    map.update();

    // Begin drawing
    //--------------------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(WHITE);

    // map.draw(); //draw the map

    BeginMode2D(camera);

    level.ScreenDraw();

    // Using Switch Case to Initialize the requirements to move to certain positions
    switch (level.currentscreen) { // Get Ready for some Spaghetti Code
    case Game::Level::GameScreen::TITLESCREEN:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      nemo.active   = false; // Erase Nemo

      //titlescreen.draw();

      if (IsKeyDown(KEY_ENTER)) {
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
      }
      break;

    case Game::Level::GameScreen::OVERWORLD:

      //nemo.NemoPosition = {910.0, 400};

      //map
      Vector2 vec;
      Rectangle rec;

      vec = {0, 0};
      rec = {0, 0, levelMap["tilewidth"], levelMap["tileheight"]};
      for (auto const &layer : levelMap["layers"]) {

        if (layer["type"] == "tilelayer" && layer["visible"]) {
          vec.y = 0;
          for (auto const &tileId : layer["data"]) {

            int counter = (int) tileId;
            counter--;
            if (counter != -1) {
              rec.x = (float) ((int) counter % (int) tilesetDescription["columns"]) *
                      (float) levelMap["tilewidth"];
              rec.y = (float) floor((float) counter / (float) tilesetDescription["columns"]) *
                      (float) levelMap["tileheight"];
              DrawTextureRec(tileAtlasTexture, rec, vec, WHITE); //entkoppeln, 2 vektoren machen
            }
            vec.x += (float) levelMap["tilewidth"];
            if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) {
              vec.x = 0;
              vec.y += (float) levelMap["tileheight"];
            }
          }
        }
      }

      //Vector2 NemoPosition = {500,500};

      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      nemo.Draw();   // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

      collision.update(); //collision mit

      //teleport into pyramid
      level.Teleport();
      DrawRectangleRec(level.teleportrecOVERWORLDtoPYRAMID, Color{});

      if (NPCDraw == true) {
        NPCRec = { 100 + 8, 100 + 5, 16, 20 };
        // DrawRectangleRec(NPCRec, Color(00));                    // COLOR is for the Transparency.
        DrawTexture(NPC.texture_, NPC.pos_x, NPC.pos_y, WHITE); // Drawing the Rectangle
        collision.draw();
      }
      // Collision check
      while (CheckCollisionRecs(NPCRec, nemo.nemorec)) // Where the Collision between Two Objects happen happens
      {
        level.currentscreen = Game::Level::GameScreen::COMBAT; // After Returning back to the OVERWORLD ya get

        // immediately back to the Combat screen
        // This happens, because the Player still collides with the player, deleting the NPC may work, but I still don´t
        // know if it worked.
        NPCDraw = false; // NPC is deleted
        NPCRec = {}; // His Rectangle doesn´t get a position, so it is deleted instead, if you would set the attributes,
                     // the rectangleCollision remains active instead
        // It might not be clean, but it solves the issue for now
      }
      break;

    case Game::Level::GameScreen::PYRAMIDE: //TODO CAMERA CENTER MOVEMENT!!!

      ClearBackground(BLACK);

      Vector2 vecDungeon;
      Rectangle recDungeon;

      vecDungeon = {0, 0};
      recDungeon = {0, 0, levelMapDungeon["tilewidth"], levelMapDungeon["tileheight"]};
      for (auto const &layer : levelMapDungeon["layers"]) {

        if (layer["type"] == "tilelayer" && layer["visible"]) {
          vecDungeon.y = 0;
          for (auto const &tileId : layer["data"]) {

            int counter = (int) tileId;
            counter--;
            if (counter != -1) {
              recDungeon.x = (float) ((int) counter % (int) tilesetDescription["columns"]) *
                      (float) levelMap["tilewidth"];
              recDungeon.y = (float) floor((float) counter / (float) tilesetDescription["columns"]) *
                      (float) levelMap["tileheight"];
              DrawTextureRec(tileAtlasTexture, recDungeon, vecDungeon, WHITE); //entkoppeln, 2 vektoren machen
            }
            vecDungeon.x += (float) levelMapDungeon["tilewidth"];
            if (vecDungeon.x >= (float) layer["width"] * (float) levelMapDungeon["tilewidth"]) {
              vecDungeon.x = 0;
              vecDungeon.y += (float) levelMapDungeon["tileheight"];
            }
          }
        }
      }

      //nemo.NemoPosition = {225,980};

      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      nemo.Draw();   // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };


      //teleport back to overworld
      level.Teleport();
      DrawRectangleRec(level.teleportrecPYRAMIDtoOVERWORLD, Color{});
      DrawRectangleRec(level.teleportrecPYRAMIDtoOCEAN, Color{});

      break;

    case Game::Level::GameScreen::OCEAN:

      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      nemo.Draw();   // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

      //teleport back to overworld
      if (IsKeyDown(KEY_ENTER)) {
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
      }

      break;


    case Game::Level::GameScreen::COMBAT:

      nemo.active = false; // Nemo is set to false, so that he is not drawn in the Combat screen.
      camera.target =
        Vector2 { Game::ScreenWidth / 2,
                  Game::ScreenHeight / 2 }; // Setting Camera to a Constant Position. Otherwise it would follow Nemo
      break;
    }

    EndMode2D(); // camera

    if (level.currentscreen ==
        Game::Level::GameScreen::OVERWORLD) // Setting it on an if case, so it is only drawn in OVERWORLD
    {
      ui.Draw(); // controlls description
    }

    EndDrawing();
    //--------------------------------------------------------------------------------------------
  }
  // Main game loop end
  //--------------------------------------------------------------------------------------------

  // De-initialization here
  //--------------------------------------------------------------------------------------------

  //UnloadTexture(button);  // Unload button texture

  CloseAudioDevice(); // Close audio device

  CloseWindow(); // Close window and OpenGL context

  return EXIT_SUCCESS;
}
