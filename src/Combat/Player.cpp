#include "Player.h"

Game::Player::Player() : GameCharacter(100, 5, 40) 
{
}

std::vector<int> Game::Player::attack() 
{ 
	//DrawText(TextFormat("You Deal %i", c_STR), 500, 330, 40, BLACK);
	std::vector<int> vector;
    vector.push_back(c_STR);
    vector.push_back(0);
	return vector; 
}

void Game::Player::getDamage(std::vector<int> damage) 
{
  //DrawText(TextFormat("You receive %i", damage[0] - c_DEF), 500, 330, 40, BLACK);
  if (damage[0] - c_DEF > 0) 
  {
    c_HP -= damage[0] + c_DEF;
  }
}

void Game::Player::updateCharacter() 
{ 
	if (c_HP <= 0) 
	{
    DrawText("You Lost!", 500, 320, 40, RED);
	}
}

Rectangle Game::Player::get_rec() 
{ 
	return this->rec; 
}

Rectangle Game::Player::set_rec() 
{ 
	this->rec = { 400, 320, 50, 50 }; 
	return rec;
}
