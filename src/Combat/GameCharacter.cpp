#include "GameCharacter.h"

Game::GameCharacter::GameCharacter(string n_name, int max_HP, int HP, int DEF, int STR) : name (n_name), c_MaxHP(max_HP), c_HP(c_MaxHP), c_DEF(DEF), c_STR(STR) {
}

int Game::GameCharacter::getLives() 
{ 
	return c_HP;
}

int Game::GameCharacter::getArmor() { return c_DEF; }

int Game::GameCharacter::getStrength() { return c_STR; }

Rectangle Game::GameCharacter::get_rec() 
{ 
	return rec; 
}

void Game::GameCharacter::heal()
{
    this->c_HP = c_MaxHP;
}

Rectangle Game::GameCharacter::set_rec() 
{ return rec; }

int Game::GameCharacter::get_turnnumb() 
{ 
	return turnnumb; 
}

void Game::GameCharacter::set_turnnumb(int turnnumb) 
{ 
	this->turnnumb = GetRandomValue(1, 6);
}
string Game::GameCharacter::get_Name()
{
  return name;
}
