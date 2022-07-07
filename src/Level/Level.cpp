#include "Level.h"
#include <raylib.h>

//Setting up a timer and Frame Counter.
bool timer = false;
int framescounter = 0;
bool collision = false; // Collision detection

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

void Game::Level::combat()
{
  //Setting an Input to prevent the Player from attacking, while the countdown runs
  bool input = true;

  //Combat init

  //If the Timer is true, the seconds will Run and the Player can´t press any buttons, while the Enemy Attacks
  if (timer == true) {
    framescounter++;
    input = false;
  }

  //If 2 Seconds has Passed, the Player will receive Damage from the Enemy and the timer will be stopped, the Player can
  //then attack again
  if (((framescounter/120)%2) == 1) {
    //player->getDamage(enemy->attack());
    framescounter = 0;

    if (player->get_turnnumb() > enemy->get_turnnumb()) {
      player->getDamage(enemy->attack());
    }

    if (enemy->get_turnnumb() > player->get_turnnumb()) {
      enemy->getDamage(player->attack());
    }

    timer = false;
    input = true;
  }
  //Player Attack
  if (input == true) {
    if (IsKeyPressed(KEY_R)) {
      //enemy->getDamage(player->attack());
      player->set_turnnumb(GetRandomValue(0, 100));
      enemy->set_turnnumb(GetRandomValue(0, 100));

      if (player->get_turnnumb() > enemy->get_turnnumb()) {
        enemy->getDamage(player->attack());
      }

      if (enemy->get_turnnumb() > player->get_turnnumb()) {
        player->getDamage(enemy->attack());
      }

      timer = true;
    }
  }
  //Setting up the Turnnumber
  /*if (IsKeyPressed(KEY_Z))
  {
    player->set_turnnumb(GetRandomValue(0, 100));
    enemy->set_turnnumb(GetRandomValue(0, 100));
  }*/

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

void Game::Level::Collision() {

  Rectangle Collision   = { 400, 703 / 2, 32, 32 };

  int screenUpperLimit  = 40; // Top menu limits
  bool input = true;

  if(timer == true) {
    sleep_for(10ms); // disable input for 1/4 sec (being stunned after colliding)
    input = false;
  }

  if ((nemo->nemorec.y + nemo->nemorec.height) >= GetScreenHeight())
    nemo->nemorec.y = GetScreenHeight() - nemo->nemorec.height;
  else if (nemo->nemorec.y <= screenUpperLimit)
    nemo->nemorec.y = (float)screenUpperLimit;

  //collision nemo with collision object
  collision = CheckCollisionRecs(Collision, nemo->nemorec);

  if (collision) { //Change the Floats to Ints, that should solve the bugs
    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { //Left
      nemo->NemoPosition.x += 4.0; //Pushback
      PlaySound(GameAudio::collision); //Play Collision Sound
      SetSoundVolume(GameAudio::collision, float(0.07)); //adjust its volume
      timer = false;
      input = true;
    }
    if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
      nemo->NemoPosition.x -= 4.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
      timer = false;
      input = true;
    }
    if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
      nemo->NemoPosition.y += 4.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
      timer = false;
      input = true;
    }
    if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
      nemo->NemoPosition.y -= 4.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
      timer = false;
      input = true;
    }
  }
}

Game::Level::~Level() {}

