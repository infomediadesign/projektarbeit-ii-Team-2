#include "Mumy.h"

Game::Mumy::Mumy() : GameCharacter("Mumy",10, c_MaxHP, 2, 8)
{

}

std::vector<int> Game::Mumy::attack()
{ 
	//DrawText(TextFormat("You Receive %i", c_STR), 500, 330, 40, BLACK);
    std::vector<int> vector;
    vector.push_back(c_STR);
    vector.push_back(0);
    return vector;
}

void Game::Mumy::getDamage(std::vector<int> damage)
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

void Game::Mumy::updateCharacter()
{
  if (c_HP <= 0) 
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

Rectangle Game::Mumy::get_rec() { return this->rec; }

Rectangle Game::Mumy::set_rec() {
  this->rec = { 780, 370, 50, 50 };
  return rec;
}
