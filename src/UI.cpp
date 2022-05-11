#include "UI.h"

void Game::UI::Draw() {
  DrawText("***********************Controlls**************************", 10, 0, 10, BLACK);
  DrawText("*-> Move with W,A,S,D", 10, 10, 10, BLACK); // x, y , size of text
  DrawText("*-> Exit game with ESC", 10, 20, 10, BLACK);
  DrawText("*-> toggle between windowed mode and fullscreen mode press K", 10, 30, 10, BLACK);
  DrawText("*********************************************************", 10, 40, 10, BLACK);
}
