#include "Shadow.h"

Game::Shadow::Shadow() : GameCharacter("Shadow",15, c_MaxHP, 1, 9)
{

}

auto Game::Shadow::attack() -> std::vector<int>
{
  currentFrame = 6;
  State = state::ATTACK;
  std::vector<int> vector;
  vector.push_back(c_STR);
  vector.push_back(0);
  return vector;
}

void Game::Shadow::getDamage(std::vector<int> damage)
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

void Game::Shadow::updateCharacter()
{
  if (c_HP <= 0)
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

auto Game::Shadow::get_rec() -> Rectangle {

  return this->rec;
}

auto Game::Shadow::set_rec() -> Rectangle {
  this->rec = { 780, 370, 50, 50 };
  return rec;
}

auto Game::Shadow::get_turnnumb() -> int {

  return turnnumb;

}

auto Game::Shadow::getStrength() -> int {

  return c_STR;

}

auto Game::Shadow::getDefense() -> int {

  return c_DEF;

}

void Game::Shadow::draw() {

  shadowrec = {get_rec().x + 8, get_rec().y + 10, get_rec().width, get_rec().height};
  DrawRectangleRec(shadowrec, Color {});
  DrawTextureRec(spr_shadow, frameRec, {get_rec().x, get_rec().y}, WHITE);
  //animation
  framesCounter++;
  switch (State) {
  case GameCharacter::state::IDLE:
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 4)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)spr_shadow.width / 8;
      break;

    case GameCharacter::state::ATTACK:
      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 8) {
          State        = state::IDLE;
          currentFrame = 0;
        }

        frameRec.x = (float)currentFrame * (float)spr_shadow.width / 8;
        break;

      default: State = GameCharacter::state::IDLE; break;
      }
    }
  }

  // enemy Draw
  healthrec = { 0, 0, static_cast<float>(192 * ((float)c_HP / (float)c_MaxHP)), 96 };

  DrawTexture(healthbar, set_rec().x - 20, set_rec().y - 177, WHITE);
  DrawTextureRec(health, healthrec, { set_rec().x - 20, set_rec().y - 180 }, WHITE);
  DrawText(TextFormat("%i/%i", c_HP, c_MaxHP), set_rec().x + 50, set_rec().y - 140, 20, BLACK);
}
