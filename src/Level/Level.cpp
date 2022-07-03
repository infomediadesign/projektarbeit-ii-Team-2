#include "Level.h"

#include <raylib.h>

void Game::Level::Screeninit() {
  // Here would normally come a Switch Case. For now we initialize our Combat screen in the Main as a test
}

void Game::Level::ScreenDraw() {
  switch (Game::Level::currentscreen) // For this Switch we determine here, what is drawn here
  {
  case GameScreen::TITLESCREEN:
    DrawText("TITLESCREEN FOR CUSTODIA", 500, 320, 20, GRAY);
    DrawText("PRESS ENTER FOR GAME", 500, 340, 20, GRAY);
    break;

  case GameScreen::OVERWORLD: DrawTexture(Map, 0, 0, WHITE); break;

  case GameScreen::COMBAT:
    DrawText("COMBATSCREEN FOR CUSTODIA", 500, 320, 20, GRAY);
    DrawText("PRESS ENTER TO RETURN", 500, 340, 20, GRAY);
    break;
  }
}

//void Game::Level::Draw() { DrawTexture(Map, 0, 0, WHITE); }

void Game::Level::Music() {

  if (IsKeyPressed(KEY_SPACE)) {
    SetSoundVolume(GameAudio::titlescreenmusic, float (0.01)); // Set volume for a sound (1.0 is max level) This is a test
    PlaySound(GameAudio::titlescreenmusic);
    if (IsKeyPressed(KEY_SPACE)) {
      PauseSound(GameAudio::titlescreenmusic);
    }
  }
}

Game::Level::~Level() {}
