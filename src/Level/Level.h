#pragma once
#include <raylib.h>

namespace Game {
  class Level {
  public:
    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");

    Sound OutPyra = LoadSound("assets/audio/sfx/cave_theme_2.mp3"); 

    enum class GameScreen { TITLESCREEN, OVERWORLD, COMBAT, PAUSEMENU, CUTSCENE }; //This Enum Class is there to set the Screens to TITLE etc.

    GameScreen currentscreen = GameScreen::COMBAT; //TitleScreens is the Start Screen
    //GameScreen currentscreen = GameScreen::TITLESCREEN; // TitleScreens is the Start Screen

    void Screeninit();

    void ScreenDraw();

    void Draw();

    void Music();

    ~Level();
  };
} 