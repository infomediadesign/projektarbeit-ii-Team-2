#include "Level.h"
#include "../Combat/combat.h"
#include <raylib.h>

Game::Combat combat;

void Game::Level::Screeninit() 
{
  //Here would normally come a Switch Case. For now we initialize our Combat screen in the Main as a test
}

void Game::Level::ScreenDraw() 
{ 

	switch (Game::Level::currentscreen)  //For this Switch we determine here, what is drawn here
	{
  case GameScreen::TITLESCREEN: 
			DrawText("TITLESCREEN FOR CUSTODIA", 500, 320, 20, GRAY); 
			DrawText("PRESS ENTER FOR GAME", 500, 340, 20, GRAY);
			break;

		case GameScreen::OVERWORLD:
		DrawTexture(Map, 0, 0, WHITE); 
			break;

		case GameScreen::COMBAT: 
		combat.Draw();
		combat.update();
		//DrawText("COMBATSCREEN FOR CUSTODIA", 500, 320, 20, GRAY);
		//DrawText("PRESS ENTER TO RETURN", 500, 340, 20, GRAY);
      break;
	}
}

//void Game::Level::Draw() { DrawTexture(Map, 0, 0, WHITE); }

void Game::Level::Music() 
{
	if (IsKeyPressed(KEY_SPACE)) 
	{
	PlaySound(OutPyra);
	}
	
}

Game::Level::~Level() 
{ 
	UnloadSound(OutPyra);
}
