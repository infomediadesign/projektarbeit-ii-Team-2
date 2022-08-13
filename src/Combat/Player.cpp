#include "Player.h"

Game::Player::Player() : GameCharacter("Nemo", 25, c_MaxHP, 5, 5)
{

}

auto Game::Player::attack() -> std::vector<int>
{
  currentFrame = 4;
  State = state::ATTACK;
	std::vector<int> vector;
    vector.push_back(c_STR);
    vector.push_back(0);
	return vector;

}

void Game::Player::getDamage(std::vector<int> damage) 
{

  if (damage[0] - c_DEF > 0) 
  {
    c_HP -= damage[0] - c_DEF;

    DrawText(TextFormat("- %i", damage[0] - c_DEF), set_rec().x + 80, set_rec().y, 20, RED);

  }

  //Sets the HP Automatically to 0. HP will not go Negative
  if (c_HP <= 0)
  {
    c_HP = 0;
  }
}

void Game::Player::updateCharacter() 
{ 
	if (c_HP <= 0) 
	{
    DrawText("You Lost!", 500, 320, 40, RED);
	}
}

auto Game::Player::get_rec() -> Rectangle
{ 
	return this->rec; 
}

auto Game::Player::set_rec() -> Rectangle
{ 
	this->rec = { 430, 370, 32, 32 };
	return rec;
}

void Game::Player::draw()
{
  //Draw Player
  Playerrec = {get_rec().x + 8, get_rec().y + 10, get_rec().width, get_rec().height};
  DrawRectangleRec(Playerrec, Color{});
  DrawTextureRec(spr_Player, frameRec, {get_rec().x, get_rec().y}, WHITE);
  // animation
  framesCounter++;

    switch (State)
    {
    case GameCharacter::state::IDLE:

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3) {
          currentFrame = 0;
        }


        frameRec.x = (float)currentFrame * (float)spr_Player.width / 7;
      break;

      case GameCharacter::state::ATTACK:

        if (framesCounter >= (60 / framesSpeed)) {
          framesCounter = 0;
          currentFrame++;

          if (currentFrame > 5)
          {
            State = state::IDLE;
            currentFrame = 0;
          }

          frameRec.x = (float)currentFrame * (float)spr_Player.width / 7;
          break;

        default: State = GameCharacter::state::IDLE;
          break;
        }

    }
  }

  //Player draw
  healthrec = {0, 0, 192, 96};
  DrawText(TextFormat("Speed: %i", get_turnnumb()), set_rec().x, set_rec().y - 90, 20, BLUE);
  DrawTextureRec(health, healthrec, {set_rec().x - 100, set_rec().y - 200}, WHITE);
  DrawText("NEMO",set_rec().x - 88, set_rec().y - 173, 10, BLACK);
  DrawText(TextFormat("%i/%i", c_MaxHP, c_HP), set_rec().x - 30, set_rec().y - 160, 20, BLACK);
  DrawTexture(healthbar, set_rec().x - 100, set_rec().y - 200, WHITE);

}
auto Game::Player::get_turnnumb() -> int {
  return turnnumb;
}
void Game::Player::heal() {
  c_HP = c_MaxHP;
}

