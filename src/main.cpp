#include"INCLUDES.h"

#include "Level/GameAudio.h"
#include "Level/Inventory.h"
#include "Level/Level.h"
#include "Level/Map.h"
#include "Level/UI.h"
#include "Level/Collision.h"

#include "Player/Nemo.h"

#include "Sprite/Sprite.h"





//bla bla
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

  GameAudio::Load();
  Game::Level level;
  Game::Level levelcollision;
  //Game::Map map;
  Game::UI ui;
  Game::Nemo nemo; // Initializing the Nemo (Player) Class
  Game::Sprite spr(nemo.NemoPosition.x, nemo.NemoPosition.y, nemo.Front);
  Game::Sprite NPC(100, 100, StandStil);

  Rectangle NPCRec = {}; // Rectangle Position has to be set after it is drawn, leaving it free is so much better, until
                         // it is called. Do not touch it!!!
  bool NPCDraw = true;   // To set the drawing if it is true or false. In short if it is draw or deleted
/*
  //Map Markus stuff

    std::ifstream tilesetDescriptionFile("assets/graphics/map/Pyramiden_SheetJamey.json"); //Pyramiden_SheetJamey.json needed as json, pls do in tiled
    assert(tilesetDescriptionFile.is_open());
    nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
    tilesetDescriptionFile.close();

    std::ifstream levelMapFile("assets/graphics/map/PhyramidenEingangNeu.json");
    assert(levelMapFile.is_open());
    nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
    levelMapFile.close();

    Texture2D tileAtlasTexture = LoadTexture("assets/graphics/Tiles-Atlas/Pyramiden_SheetJamey.png");
    //Texture2D tileAtlasTexture = LoadTexture((tilesetDescription["image"].get<std::string>()).c_str());

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
*/
/*
    //Music Tests
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



    //collision.update();
/*
    // Check levelcollision between Nemo and Rectangle
    collision.collisionObject = CheckCollisionRecs(collision.rectangleObject, nemo.nemorec);

        // Get levelcollision rectangleCollision (only on levelcollision)
        if (collision.collisionObject)
          collision.rectangleCollision = GetCollisionRec(collision.rectangleObject, nemo.nemorec);

        if (collision.collisionObject) { //Change the Floats to Ints, that should solve the bugs
              if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { //Left
                nemo.NemoPosition.x += 10.0; //Pushback
                PlaySound(GameAudio::collision); //Play Collision Sound
                SetSoundVolume(GameAudio::collision, float(0.07)); //adjust its volume
                sleep_for(1s); // disable input -> (being stunned after colliding)
                //sleep_until(  system_clock::now() + 1s); //both work
                }
                if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
                  nemo.NemoPosition.x -= 10.0;
                  PlaySound(GameAudio::collision);
                  SetSoundVolume(GameAudio::collision, float(0.07));
                  sleep_for(1s); // disable input -> (being stunned after colliding)
                }
                if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
                  nemo.NemoPosition.y += 10.0;
                  PlaySound(GameAudio::collision);
                  SetSoundVolume(GameAudio::collision, float(0.07));
                  sleep_for(1s); // disable input -> (being stunned after colliding)
                }
                if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
                  nemo.NemoPosition.y -= 10.0;
                  PlaySound(GameAudio::collision);
                  SetSoundVolume(GameAudio::collision, float(0.07));
                  sleep_for(1s); // disable input -> (being stunned after colliding)
                }
            }
        //--- Collision will be put somewhere else soon
*/

    // Begin drawing
    //--------------------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(WHITE);



    /*
//Programming 1 Moodle:
    Vector2 vec = {0, 0};
    Rectangle rec = {0, 0, levelMap["tilewidth"], levelMap["tileheight"]};

    for (auto const &layer : levelMap["layers"]) {
      if (layer["type"] == "tilelayer" && layer["visible"]) {
        for (auto const &tileId : layer["data"]) {
          if (tileId != 0) {
            rec.x = (float) ((int) tileId - 1 % (int) tilesetDescription["columns"]) *
                    (float) levelMap["tilewidth"];
            rec.y = (float) floor((float) tileId / (float) tilesetDescription["columns"]) *
                    (float) levelMap["tilewidth"];

            DrawTextureRec(tileAtlasTexture, rec, vec, WHITE);
          }

          vec.x += (float) levelMap["tilewidth"];
          if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) {
            vec.x = 0;
            vec.y += (float) levelMap["tileheight"];
          }
        }
      }
    }
     */

    // map.draw(); //draw the map

    BeginMode2D(camera);

    level.ScreenDraw();

    // Using Switch Case to Initialize the requirements to move to certain positions
    switch (level.currentscreen) { // Get Ready for some Spaghetti Code
    case Game::Level::GameScreen::TITLESCREEN:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      nemo.active   = false; // Erase Nemo

      if (IsKeyDown(KEY_ENTER)) {
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
      }
      break;

    case Game::Level::GameScreen::OVERWORLD:

      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      nemo.Draw();   // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

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

    case Game::Level::GameScreen::COMBAT:

      nemo.active = false; // Nemo is set to false, so that he is not drawn in the Combat screen.
      camera.target =
        Vector2 { Game::ScreenWidth / 2,
                  Game::ScreenHeight / 2 }; // Setting Camera to a Constant Position. Otherwise it would follow Nemo
      if (IsKeyDown(KEY_ENTER)) {
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
      }
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

  CloseAudioDevice(); // Close audio device

  CloseWindow(); // Close window and OpenGL context

  return EXIT_SUCCESS;
}
