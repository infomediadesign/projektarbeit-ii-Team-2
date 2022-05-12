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
    -> 16:9 not working, 640p : 360p ? or larger?, fullscreen toggle mode, HideCursor not working, Music aint working @todo Nick
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

  Vector2 NemoPosition = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
  Vector2 position     = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };

  Game::Level level;
  Game::UI ui;
  Game::Nemo nemo; // Initializing the Nemo (Player) Class
  Game::Sprite spr(NemoPosition.x, NemoPosition.y, nemo.Front);
  Game::Sprite NPC(100, 100, StandStil);

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
    //Update
    if (IsKeyDown(KEY_LEFT_CONTROL) || IsKeyPressed(KEY_F)) {
      ToggleFullscreen();
    }

    nemo.Update(); // nemo walking movement and animation

    level.Music(); // music    

    camera.target = Vector2 { nemo.position.x + 20.0f, nemo.position.y + 20.0f };

    // Begin drawing
    //--------------------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(WHITE);

    BeginMode2D(camera);

    level.Draw(); // map    
    
    nemo.Draw();   // nemo walking movement and animation

    DrawTexture(NPC.texture_, NPC.pos_x, NPC.pos_y, WHITE);  

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
