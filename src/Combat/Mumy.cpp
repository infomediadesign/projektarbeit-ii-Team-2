#include "Mumy.h"

Game::Mumy::Mumy() : GameCharacter("Mumy",10, c_MaxHP, 2, 8)
{

}

auto Game::Mumy::attack() -> std::vector<int>
{ 
	//DrawText(TextFormat("You Receive %i", c_STR), 500, 330, 40, BLACK);
  currentFrame = 2;
  State = state::ATTACK;
    std::vector<int> vector;
    vector.push_back(c_STR);
    vector.push_back(0);
    return vector;
}

void Game::Mumy::getDamage(std::vector<int> damage)
{
  if (damage[0] - c_DEF > 0) 
  {
    c_HP -= damage[0] - c_DEF;
  }
  //Sets the HP Automatically to 0. HP will not go Negative
  if (c_HP <= 0)
  {
    c_HP = 0;
  }
}

void Game::Mumy::updateCharacter()
{
  if (c_HP <= 0) 
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

auto Game::Mumy::get_rec() -> Rectangle { return this->rec; }

auto Game::Mumy::set_rec() -> Rectangle {
  this->rec = { 780, 370, 50, 50 };
  return rec;
}
void Game::Mumy::draw() {
  // Draw Enemy
  mumyrec = { get_rec().x + 8, get_rec().y + 10, get_rec().width, get_rec().height };
  DrawRectangleRec(mumyrec, Color {});
  DrawTextureRec(spr_mumy, frameRec, { get_rec().x, get_rec().y }, WHITE);
  // animation
  framesCounter++;
  switch (State) {
  case GameCharacter::state::IDLE:
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 1)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)spr_mumy.width / 4;
      break;

    case GameCharacter::state::ATTACK:
      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3) {
          State        = state::IDLE;
          currentFrame = 0;
        }

        frameRec.x = (float)currentFrame * (float)spr_mumy.width / 4;
        break;

      default: State = GameCharacter::state::IDLE; break;
      }
    }
  }
  // enemy Draw
  healthrec = { 0, 0, static_cast<float>(192 * ((float)c_HP / (float)c_MaxHP)), 96 };

  DrawTexture(healthbar, set_rec().x - 20, set_rec().y - 197, WHITE);
  DrawTextureRec(health, healthrec, { set_rec().x - 20, set_rec().y - 200 }, WHITE);
  DrawText(TextFormat("Speed: %i", get_turnnumb()), set_rec().x, set_rec().y - 90, 20, RED);
  DrawText(TextFormat("%i/%i", c_HP, c_MaxHP), set_rec().x + 50, set_rec().y - 160, 20, BLACK);
  DrawText("MUMY", set_rec().x + 130, set_rec().y - 173, 10, BLACK);
  }

auto Game::Mumy::get_turnnumb() -> int {
  return turnnumb;
}
auto Game::Mumy::getStrength() -> int {
  return c_STR;
}
auto Game::Mumy::getDefense() -> int { return c_DEF; }
