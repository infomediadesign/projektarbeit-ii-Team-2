#include "Endscreen.h"
void Endscreen::draw() {

  DrawText("THANK YOU FOR PLAYING", Game::ScreenWidth / 2 - 50,  Game::ScreenHeight / 2, 10, WHITE);
  DrawText("TO RETURN BACK TO THE TITLESCREEN PRESS ENTER", Game::ScreenWidth / 2 - 50, Game::ScreenHeight / 2 + 20, 10, WHITE);

}
