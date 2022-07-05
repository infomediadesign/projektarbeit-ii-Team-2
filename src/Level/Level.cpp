#include "Level.h"
#include <raylib.h>

//Setting up a timer
bool timer = false;
int framescounter = 0;

void Game::Level::combat()
{
//Combat init

//If the Timer is true, the seconds will Run
if (timer == true)
{
  framescounter++;
}

//If 2 Seconds has Passed, the Player will receive Damage from the Enemy and the timer will be stopped
      if (((framescounter/120)%2) == 1)
      {
        player->getDamage(enemy->attack());
        framescounter = 0;
        timer = false;
      }
//Player Attack
			if (IsKeyPressed(KEY_R))
			{
				enemy->getDamage(player->attack());
        timer = true;
			}
//Setting up the Turnnumber
			if (IsKeyPressed(KEY_Z))
			{
				player->set_turnnumb(GetRandomValue(0, 100));
				enemy->set_turnnumb(GetRandomValue(0, 100));
			}
    
	 if (enemy->getLives() <= 0) 
	{
      //delete enemy;
      //delete player;
     DrawText("YOU WON!", 600, 320, 20, BLACK);
     timer = false;
    } 
	else if (player->getLives() <= 0) 
	{
     // delete enemy;
     // delete player;
      DrawText("YOU LOST!", 600, 320, 20, BLACK);
      timer = false;
    }
}

void Game::Level::Screeninit() {
  //Here would normally come a Switch Case. For now we initialize our Combat screen in the Main as a test

}

void Game::Level::ScreenDraw() {
  switch (Game::Level::currentscreen) // For this Switch we determine here, what is drawn here
  {
  case GameScreen::TITLESCREEN:
    DrawText("TITLESCREEN FOR CUSTODIA", 500, 320, 20, GRAY);
    DrawText("PRESS ENTER FOR GAME", 500, 340, 20, GRAY);
    break;

  case GameScreen::OVERWORLD: DrawTexture(Map, 0, 0, WHITE); break;

		case GameScreen::COMBAT: 

		//DrawTexture(Battlescreen, 410, 320, WHITE);
		//Draw Player
		DrawRectangleRec(player->set_rec(), BLUE);
    //Timer
    DrawText(TextFormat("Time: %i", framescounter), player->set_rec().x + 100, player->set_rec().y, 20, BLUE);

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

void Game::Level::Music() {

  if (IsKeyPressed(KEY_SPACE)) {
    SetSoundVolume(GameAudio::titlescreenmusic, float (0.01)); // Set volume for a sound (1.0 is max level) This is a test
    PlaySound(GameAudio::titlescreenmusic);
    if (IsKeyPressed(KEY_SPACE)) {
      PauseSound(GameAudio::titlescreenmusic);
    }
  }
}

Game::Level::~Level() {}
