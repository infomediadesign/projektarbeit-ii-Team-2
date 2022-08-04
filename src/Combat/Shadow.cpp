#include "Shadow.h"

Game::Shadow::Shadow() : GameCharacter("Shadow",15, c_MaxHP, 1, 9)
{

}

auto Game::Shadow::attack() -> std::vector<int>
{
  //DrawText(TextFormat("You Receive %i", c_STR), 500, 330, 40, BLACK);
  std::vector<int> vector;
  vector.push_back(c_STR);
  vector.push_back(0);
  return vector;
}

void Game::Shadow::getDamage(std::vector<int> damage)
{
  if (damage[0] - c_DEF > 0)
  {
    c_HP -= damage[0] - c_DEF;
  }
  //Sets the HP Automatically to 0. HP will not go Negative
  if (c_HP <= 0)
  {
    c_HP = 0;
  }
}

void Game::Shadow::updateCharacter()
{
  if (c_HP <= 0)
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

auto Game::Shadow::get_rec() -> Rectangle { return this->rec; }

auto Game::Shadow::set_rec() -> Rectangle {
  this->rec = { 780, 370, 50, 50 };
  return rec;
}