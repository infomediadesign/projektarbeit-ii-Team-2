#include "Enemy.h"

Game::Enemy::Enemy() : GameCharacter(200, 15, 35)
{

}

std::vector<int> Game::Enemy::attack() 
{ 
	//DrawText(TextFormat("You Receive %i", c_STR), 500, 330, 40, BLACK);
    std::vector<int> vector;
    vector.push_back(c_STR);
    vector.push_back(0);
    return vector;
}

void Game::Enemy::getDamage(std::vector<int> damage) 
{
  if (damage[0] - c_DEF > 0) 
  {
    c_HP -= damage[0] + c_DEF;
  }
  //Sets the HP Automatically to 0. HP will not go Negative
  if (c_HP <= 0)
  {
    c_HP = 0;
  }
}

void Game::Enemy::updateCharacter() 
{
  if (c_HP <= 0) 
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

Rectangle Game::Enemy::get_rec() { return this->rec; }

Rectangle Game::Enemy::set_rec() {
  this->rec = { 800, 320, 50, 50 };
  return rec;
}
