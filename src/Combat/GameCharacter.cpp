#include "GameCharacter.h"

Game::GameCharacter::GameCharacter(int HP, int DEF, int STR) : c_HP(HP), c_DEF(DEF), c_STR(STR) {}

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

Rectangle Game::GameCharacter::set_rec() 
{ return rec; }

int Game::GameCharacter::get_turnnumb() 
{ 
	return turnnumb; 
}

void Game::GameCharacter::set_turnnumb(int turnnumb) 
{ 
	this->turnnumb = GetRandomValue(0, 100); 
}

