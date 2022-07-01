#include "combat.h"

//drawing the Objects for the combat system
void Game::Combat::Draw() { 
	//Player and Enemy rectangle
	DrawRectangleRec(player.playerrec, BLUE); 
	DrawRectangleRec(enemy.enemyrec, RED);
	//Player and Enemy HP
	DrawText(TextFormat("HP: %i", player.HP), player.playerrec.x, player.playerrec.y - 40, 20, BLUE);
	DrawText(TextFormat("HP: %i", enemy.HP), enemy.enemyrec.x, enemy.enemyrec.y - 40, 20, RED);
	//Turnnumber
	DrawText(TextFormat("Turnnumber: %i", player.turnnumb), player.playerrec.x - 30, player.playerrec.y - 60, 20,	BLUE);
	DrawText(TextFormat("Turnnumber: %i", enemy.turnnumb), enemy.enemyrec.x - 30, enemy.enemyrec.y - 60, 20, RED);
}

void Game::Combat::update() { 
	//Check to see if the random numbers get set
	if (IsKeyPressed(KEY_R)) 
	{
    player.turnnumb = GetRandomValue(0, 100);
    enemy.turnnumb  = GetRandomValue(0, 100);
	}
	
}
