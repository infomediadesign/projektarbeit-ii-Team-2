#include "Level.h"

void Game::Level::Draw() 
{ 
	DrawTexture(Map, 0, 0, WHITE); 
}

void Game::Level::Music() 
{ 
	PlayMusicStream(music); 
}
