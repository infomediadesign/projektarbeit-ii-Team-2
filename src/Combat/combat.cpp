#include "Combat.h"

void Game::Combat::Draw() {
  DrawRectangleRec(player->set_rec(), BLUE);
  //DrawRectangleRec(enemy.enemyrec, RED);
  // Player and Enemy HP
  //DrawText(TextFormat("HP: %i", player->c_HP), player.playerrec.x, player.playerrec.y - 40, 20, BLUE);
  //DrawText(TextFormat("HP: %i", enemy.HP), enemy.enemyrec.x, enemy.enemyrec.y - 40, 20, RED);
  // Turnnumber
  //DrawText(TextFormat("Turnnumber: %i", player.turnnumb), player.playerrec.x - 30, player.playerrec.y - 60, 20, BLUE);
  //DrawText(TextFormat("Turnnumber: %i", enemy.turnnumb), enemy.enemyrec.x - 30, enemy.enemyrec.y - 60, 20, RED);
}

void Game::Combat::Update() {}
