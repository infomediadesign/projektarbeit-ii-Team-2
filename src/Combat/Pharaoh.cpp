#include "Pharaoh.h"

Game::Pharaoh::Pharaoh() : GameCharacter("Pharaoh",20, c_MaxHP, 2, 12)
{

}

std::vector<int> Game::Pharaoh::attack()
{
  //DrawText(TextFormat("You Receive %i", c_STR), 500, 330, 40, BLACK);
  std::vector<int> vector;
  vector.push_back(c_STR);
  vector.push_back(0);
  return vector;
}

void Game::Pharaoh::getDamage(std::vector<int> damage)
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

void Game::Pharaoh::updateCharacter()
{
  if (c_HP <= 0)
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

Rectangle Game::Pharaoh::get_rec() { return this->rec; }

Rectangle Game::Pharaoh::set_rec() {
  this->rec = { 780, 370, 50, 50 };
  return rec;
}
