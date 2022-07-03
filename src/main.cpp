#include "Combat/combat.h"
#include "Level/GameAudio.h"
#include "Level/Level.h"
#include "Level/UI.h"
#include "Player/Nemo.h"
#include "Sprite/Sprite.h"
#include "config.h"
#include "raylib.h"

#include <cstdlib>
#include <iostream>
#include <memory>

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

  GameAudio::Load();
  Game::Level level;
  Game::UI ui;
  Game::Nemo nemo; // Initializing the Nemo (Player) Class
  Game::Sprite spr(nemo.NemoPosition.x, nemo.NemoPosition.y, nemo.Front);
  Game::Sprite NPC(100, 100, StandStil);

  Rectangle NPCRec = {}; // Rectangle Position has to be set after it is drawn, leaving it free is so much better, until
                         // it is called. Do not touch it!!!
  bool NPCDraw = true;   // To set the drawing if it is true or false. In short if it is draw or deleted

  //--- Collision will be put somewhere else soon
  Rectangle recTile      = { 400, 703 / 2, 32, 32 }; // Test Rectangle for Collision should be 32x32 same as a tile
  Rectangle recCollision = { 0 };                    // Collision rectangle to see the collision

  int screenUpperLimit = 40; // Top menu limits

  bool pause     = false; // Movement pause
  bool collision = false; // Collision detection
  //--- Collision will be put somewhere else soon

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

    level.Game::Level::Music();

    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_F)) { // toggle fullscreenmode
      ToggleFullscreen();
    }

    //--- Collision will be put somewhere else soon
    if ((nemo.nemorec.y + nemo.nemorec.height) >= GetScreenHeight())
      nemo.nemorec.y = GetScreenHeight() - nemo.nemorec.height;
    else if (nemo.nemorec.y <= screenUpperLimit)
      nemo.nemorec.y = (float)screenUpperLimit;

    // Check collision between Nemo and Rectangle
    collision = CheckCollisionRecs(recTile, nemo.nemorec);

    // Get collision rectangle (only on collision)
    if (collision)
      recCollision = GetCollisionRec(recTile, nemo.nemorec);


    //Nemo when collides stand still and cant move at all, after that you have to forcefully close the programm, cuz nothing responds

      if (collision) {
        if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { //Left         
          nemo.NemoPosition.x += 20.0; //In theory nemo when colliding should be teleportet back by 2 positionpoints... but nothing happens
          PlaySound(GameAudio::collision);//But the sound isnt playing either so that means that the collision commands arent being executed correctly
        }
        if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
          nemo.NemoPosition.x -= 20.0;
          PlaySound(GameAudio::collision);
        }
        if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
          nemo.NemoPosition.y += 20.0;
          PlaySound(GameAudio::collision);
        }
        if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
          nemo.NemoPosition.y -= 20.0;
          PlaySound(GameAudio::collision);
        }
      }
  
    //--- Collision will be put somewhere else soon

    // Begin drawing
    //--------------------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(WHITE);

    //--- Collision will be put somewhere else soon
    nemo.active = true;
    nemo.Update(); // nemo walking movement and animation
    nemo.Draw();   // nemo walking movement and animation
    camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };   

    DrawRectangleRec(recTile, YELLOW);
    //--- Collision will be put somewhere else soon

    BeginMode2D(camera);

    level.ScreenDraw();

    // Using Switch Case to Initialize the requirements to move to certain positions
    switch (level.currentscreen) { // Get Ready for some Sphagetthi Code
    case Game::Level::GameScreen::TITLESCREEN:

      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
      nemo.active   = false; // Undraw Nemo

      if (IsKeyDown(KEY_ENTER)) {
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
      }
      break;

    case Game::Level::GameScreen::OVERWORLD:
      // nemo.active = true;
      // nemo.Update(); // nemo walking movement and animation
      // nemo.Draw();   // nemo walking movement and animation
      // camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

      if (NPCDraw == true) {
        NPCRec = { 100 + 8, 100 + 5, 16, 20 };
        DrawRectangleRec(NPCRec, Color(00));                    // COLOR is for the Transparency.
        DrawTexture(NPC.texture_, NPC.pos_x, NPC.pos_y, WHITE); // Drawing the Rectangle
      }
      // Collision check
      if (CheckCollisionRecs(NPCRec, nemo.nemorec)) // Where the Collision between Two Objects happen happens
      {
        level.currentscreen = Game::Level::GameScreen::COMBAT; // After Returning back to the OVERWORLD ya get
        // immediately back to the Combat screen
        // This happens, because the Player still collides with the player, deleting the NPC may work, but I still don´t
        // know if it worked.
        NPCDraw = false; // NPC is deleted
        NPCRec = {}; // His Rectangle doesn´t get a position, so it is deleted instead, if you would set the attributes,
                     // the rectangle remains active instead
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
