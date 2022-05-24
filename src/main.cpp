#include "Level.h"
#include "Nemo.h"
#include "Sprite.h"
#include "UI.h"
#include "config.h"
#include "raylib.h"

#include <cstdlib>
#include <iostream>
#include <memory>

// Project = Custodia - Trapped in the past

//@todo liste: @ Görkem und Nick
/*  -> can we export the camera into level to clean up the main?
    -> Walking animation is put into the nemo class, its working but the movement aint! @todo nemo walking movement
    -> 16:9 not working, 640p : 360p ? or larger?, fullscreen toggle mode, HideCursor not working, Music aint working
   @todo Nick
    -> When the character does not move, it stays in it´s current frame
 */

int main() {
  // Raylib initialization
  //--------------------------------------------------------------------------------------------

  InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
  InitAudioDevice(); // Initialize audio device

  SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN

#endif

  // Initialization
  //--------------------------------------------------------------------------------------------
  Texture2D StandStil = LoadTexture("assets/graphics/Charakter_Vorschlag_vorne_laufen1.png");

  Game::Level level;
  Game::UI ui;
  Game::Nemo nemo; // Initializing the Nemo (Player) Class
  Game::Sprite spr(nemo.NemoPosition.x, nemo.NemoPosition.y, nemo.Front);
  Game::Sprite NPC(100, 100, StandStil);

  Rectangle NPCRec = { NPC.pos_x + 8, NPC.pos_y + 5, 16, 20 };

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
    if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_F)) {
      ToggleFullscreen();
    }

    level.Music(); // music

    // Begin drawing
    //--------------------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(WHITE);
    
    //Using Switch Case to Initialize the requirements to move to certain positions

    switch (level.currentscreen) { //Get Ready for some Sphagetthi Code
    case Game::Level::GameScreen::TITLESCREEN:

      camera.target = Vector2 { Game::ScreenWidth/2, Game::ScreenHeight/2 };
      nemo.active   = false; //Undraw Nemo

      if (IsKeyDown(KEY_ENTER)) {
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
      }
      break;

    case Game::Level::GameScreen::OVERWORLD:
      nemo.active = true;
      nemo.Update(); // nemo walking movement and animation
      camera.target = Vector2 { nemo.NemoPosition.x + 20.0f, nemo.NemoPosition.y + 20.0f };

      if (CheckCollisionRecs(NPCRec, nemo.nemorec)) // Where the Collision between Two Objects happen happens
      {
        level.currentscreen = Game::Level::GameScreen::COMBAT; //After Returning back to the OVERWORLD ya get immediately back to the Combat screen
        //This happens, because the Player still collides with the player, deleting the NPC may work, but I still don´t know if it worked.
      }
      break;

    case Game::Level::GameScreen::COMBAT:

      nemo.active = false;
      camera.target = Vector2 { Game::ScreenWidth / 2, Game::ScreenHeight / 2 }; //Setting Camera to a Constant Position. Otherwise it would follow Nemo

      if (IsKeyDown(KEY_ENTER)) 
      {
        
        level.currentscreen = Game::Level::GameScreen::OVERWORLD;
        
      }
      break;
    }

    BeginMode2D(camera);

    level.ScreenDraw();

    //level.Draw(); // map

    nemo.Draw(); // nemo walking movement and animation
    DrawRectangleRec(NPCRec, Color(00)); //COLOR is for the Transparency.
    DrawTexture(NPC.texture_, NPC.pos_x, NPC.pos_y, WHITE); //Drawing the Rectangle
    
    EndMode2D(); // camera

    ui.Draw(); // controlls description

    EndDrawing();
    //--------------------------------------------------------------------------------------------

  } // Main game loop end
    //--------------------------------------------------------------------------------------------

  // De-initialization here
  //--------------------------------------------------------------------------------------------

  UnloadSound(nemo.fxMp3);

  CloseAudioDevice(); // Close audio device

  CloseWindow(); // Close window and OpenGL context

  return EXIT_SUCCESS;
}
