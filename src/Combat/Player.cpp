#include "Player.h"

Game::Player::Player() : GameCharacter("Nemo", 25, c_MaxHP, 5, 5)
{
}

std::vector<int> Game::Player::attack() 
{ 
	//DrawText(TextFormat("You Deal %i", c_STR), 500, 330, 40, BLACK);
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

Rectangle Game::Player::get_rec() 
{ 
	return this->rec; 
}

Rectangle Game::Player::set_rec() 
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

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    if (currentFrame > 3)
      currentFrame = 0;

    frameRec.x = (float)currentFrame * (float)spr_Player.width / 7;
  }

  //Player draw
  DrawText(TextFormat("Speed: %i", get_turnnumb()), set_rec().x, set_rec().y - 90, 20, BLUE);
  DrawText(TextFormat("HP: %i", getLives()), set_rec().x, set_rec().y - 70, 20, BLUE);
  DrawText(TextFormat("STR: %i", getStrength()), set_rec().x, set_rec().y - 50, 20, BLUE);
  DrawText(TextFormat("DEF: %i", getArmor()), set_rec().x, set_rec().y - 30, 20, BLUE);
}
int Game::Player::get_turnnumb() {
  return turnnumb;
}
