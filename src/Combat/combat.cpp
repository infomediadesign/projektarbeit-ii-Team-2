#include "combat.h"

void Game::Combat::Draw() {

}

void Game::Combat::update() 
{ 
	PlaySound(BattleMusic);

	if (IsKeyPressed(KEY_P)) 
	{
    StopSound(BattleMusic);
    PlaySound(BattleMusic);
	}  
}

Game::Combat::~Combat() 
{ 
	UnloadSound(BattleMusic); 
}
