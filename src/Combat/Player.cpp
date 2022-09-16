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

  if (damage[0] - c_DEF > 0) {
    c_HP -= damage[0] - c_DEF;
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

  Swingrec = {get_rec().x + 370, get_rec().y + 10, 32, 32};
  DrawRectangleRec(Swingrec, Color{});
  DrawTextureRec(swing,swinframeRec, {get_rec().x + 370, get_rec().y}, WHITE);
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
        //swingcurrentFrame = 0;
      break;

      case GameCharacter::state::ATTACK:

        swungblade = true;

        if (framesCounter >= (60 / framesSpeed)) {
          framesCounter = 0;
          currentFrame++;


          if (currentFrame > 5) {
            State        = state::IDLE;
            currentFrame = 0;
          }

          frameRec.x = (float)currentFrame * (float)spr_Player.width / 7;

          break;

        default: State = GameCharacter::state::IDLE;

          break;
        }

    }
  }
  if(swungblade) {
    // ATTACK SWING!!!

    swingFramesCounter++;

    if (swingFramesCounter >= (60 / swingFramesSpeed)) {
      swingFramesCounter = 0;
      swingcurrentFrame++;

      if (swingcurrentFrame > 4) {
        State             = state::IDLE;
        swingcurrentFrame = 0;
        swungblade = false;
      }

      swinframeRec.x = (float)swingcurrentFrame * (float)swing.width / 5;
    }
  }
  //Player draw
  healthrec = {0, 0, static_cast<float>(192 * ((float)c_HP/(float)c_MaxHP)), 96};
  DrawTextureRec(health, healthrec, {set_rec().x - 100, set_rec().y - 180}, WHITE);
  DrawText(TextFormat("%i/%i", c_HP, c_MaxHP), set_rec().x - 30, set_rec().y - 140, 20, BLACK);
  DrawTexture(healthbar, set_rec().x - 100, set_rec().y - 180, WHITE);

  }

auto Game::Player::get_turnnumb() -> int {
  return turnnumb;
}
void Game::Player::heal() {
  c_HP = c_MaxHP;
}
auto Game::Player::getStrength() -> int {
  return c_STR;
}
auto Game::Player::getDefense() -> int { return c_DEF; }
