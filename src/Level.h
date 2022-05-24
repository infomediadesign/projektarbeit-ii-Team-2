#pragma once
#include <raylib.h>

namespace Game {
  class Level {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");

    Music music = LoadMusicStream("resources/Hair-Trigger-WST011601.mp3"); // placeholder music

    enum class GameScreen { TITLESCREEN, OVERWORLD, COMBAT, PAUSEMENU, CUTSCENE }; //This Enum Class is there to set the Screens to TITLE etc.

    GameScreen currentscreen = GameScreen::TITLESCREEN; //TitleScreens is the Start Screen

    void Screeninit();

    void ScreenDraw();

    void Draw();

    void Music();
  };
} // namespace Game