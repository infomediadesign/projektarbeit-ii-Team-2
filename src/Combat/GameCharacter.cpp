#include "GameCharacter.h"

#include <utility>

Game::GameCharacter::GameCharacter(string n_name, int max_HP, int HP, int DEF, int STR) : name (std::move(n_name)), c_MaxHP(max_HP), c_HP(c_MaxHP), c_DEF(DEF), c_STR(STR) {
}

auto Game::GameCharacter::getLives() -> int
{ 
	return c_HP;
}

auto Game::GameCharacter::getArmor() -> int { return c_DEF; }

auto Game::GameCharacter::getStrength() -> int { return c_STR; }

auto Game::GameCharacter::get_rec() -> Rectangle
{ 
	return rec; 
}

void Game::GameCharacter::heal()
{
    this->c_HP = c_MaxHP;
}

auto Game::GameCharacter::set_rec() -> Rectangle
{ return rec; }

auto Game::GameCharacter::get_turnnumb() -> int
{ 
	return turnnumb; 
}

void Game::GameCharacter::set_turnnumb(int luck)
{ 
	this->turnnumb = GetRandomValue(1, 6) + luck;
}
string Game::GameCharacter::get_Name()
{
  return name;
}
void Game::GameCharacter::draw() {}
