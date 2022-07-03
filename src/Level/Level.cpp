#include "Level.h"
#include <raylib.h>
#include "config.h"

void Game::Level::combat() 
{ 

			if (IsKeyPressed(KEY_R)) 
			{
				enemy->getDamage(player->attack()); 
			}

			if (IsKeyPressed(KEY_T)) 
			{
				player->getDamage(enemy->attack());
			}

			if (IsKeyPressed(KEY_Z))
			{
				player->get_turnnumb();
				enemy->get_turnnumb();
			}
    
	 if (enemy->getLives() <= 0) 
	{
      //delete enemy;
      //delete player;
     DrawText("YOU WON!", 600, 320, 20, BLACK);
    } 
	else if (player->getLives() <= 0) 
	{
     // delete enemy;
     // delete player;
      DrawText("YOU LOST!", 600, 320, 20, BLACK);
    }
}

void Game::Level::Screeninit() {
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

		DrawTexture(Battlescreen, 0, 0, WHITE);
		//Draw Player
		DrawRectangleRec(player->set_rec(), BLUE);
		DrawText(TextFormat("Speed: %i", player->get_turnnumb()), player->set_rec().x, player->set_rec().y - 90, 20, BLUE);
		DrawText(TextFormat("HP: %i", player->getLives()), player->set_rec().x, player->set_rec().y - 70, 20, BLUE);
		DrawText(TextFormat("STR: %i", player->getStrength()), player->set_rec().x, player->set_rec().y - 50, 20, BLUE);
		DrawText(TextFormat("DEF: %i", player->getArmor()), player->set_rec().x, player->set_rec().y - 30, 20, BLUE);
		//Draw enemy
		DrawText(TextFormat("Speed: %i", enemy->get_turnnumb()), enemy->set_rec().x, enemy->set_rec().y - 90, 20, RED);
		DrawRectangleRec(enemy->set_rec(), RED);
		DrawText(TextFormat("HP: %i", enemy->getLives()), enemy->set_rec().x, enemy->set_rec().y - 70, 20, RED);
		DrawText(TextFormat("STR: %i", enemy->getStrength()), enemy->set_rec().x, enemy->set_rec().y - 50, 20, RED);
		DrawText(TextFormat("DEF: %i", enemy->getArmor()), enemy->set_rec().x, enemy->set_rec().y - 30, 20, RED);

		combat();

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
