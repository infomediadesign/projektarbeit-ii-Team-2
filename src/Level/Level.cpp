#include "Level.h"

//Setting up a timer and Frame Counter.
bool timer = false;
int framescounter = 0;
int h_amount = 2;
//bool collision = false; // Collision detection

void Game::Level::combat()
{
  //Setting an Input to prevent the Player from attacking, while the countdown runs
  bool input = true;

  //Combat initialization

  //If the Timer is true, the seconds will Run and the Player can´t press any buttons, while the Mumy Attacks
  if (timer == true) {
    framescounter++;
    input = false;
  }

  //If 2 Seconds has Passed, the Player will receive Damage from the Mumy and the timer will be stopped, the Player can
  //then attack again
  if (((framescounter/120)%2) == 1) {
    //player->getDamage(enemy->attack());
    framescounter = 0;

    //After Player Attacks, the Mumy will attack the Player
    if (player->get_turnnumb() > enemy->get_turnnumb()) {
      player->getDamage(enemy->attack());
    }
    //After Mumy Attack, the Player attacks the Mumy
    if (enemy->get_turnnumb() > player->get_turnnumb()) {
      enemy->getDamage(player->attack());
    }

    timer = false;
    input = true;
  }
  //Player Attack
  if (input == true) {

    if(IsKeyPressed(KEY_H))
    {
      if (h_amount > 0) {
        //======================HEAL!!!!=========================
        player->set_turnnumb(GetRandomValue(1, 6));
        enemy->set_turnnumb(GetRandomValue(1, 6));
        // Player heals first, then gets Damage
        if (player->get_turnnumb() >= enemy->get_turnnumb()) {
          player->heal();
          player->getDamage(enemy->attack());
          h_amount--;
        }
        // Mumy Attacks first, then Player heals.
        if (enemy->get_turnnumb() >= player->get_turnnumb()) {
          player->getDamage(enemy->attack());
          player->heal();
          h_amount--;
        }

        timer = true;
        //=========================HEAL END!!!!=================
      }
    }
    if (IsKeyPressed(KEY_R)) {
      //=========================PLAYER ATTACK================
      player->set_turnnumb(GetRandomValue(1, 6));
      enemy->set_turnnumb(GetRandomValue(1, 6));
      //===============PLAYER ATTACK=========================
      if (player->get_turnnumb() >= enemy->get_turnnumb()) {
        enemy->getDamage(player->attack());
      }
      //================ENEMY ATTACK=========================
      if (enemy->get_turnnumb() > player->get_turnnumb()) {
        player->getDamage(enemy->attack());
      }

      timer = true;
      //========================ATTACK END!!!================
    }
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
  //Here would normally come a Switch Case. For now, we initialize our Combat screen in the Main as a test

}

void Game::Level::ScreenDraw() {
  switch (Game::Level::currentscreen) // For this Switch we determine here, what is drawn here
  {
  case GameScreen::TITLESCREEN:
    DrawText("TITLESCREEN FOR CUSTODIA", 500, 320, 20, GRAY);
    DrawText("PRESS ENTER FOR GAME", 500, 340, 20, GRAY);
    break;

  case GameScreen::OVERWORLD: break;

  case GameScreen::PYRAMIDE:
    DrawText("PYRAMIDE", 500, 320, 20, GRAY);
    break;
  case GameScreen::OCEAN:
    DrawText("IM UNDER THE WATER", 500, 320, 20, DARKBLUE);
    DrawText("BLUB BLUB BLUB...", 500, 340, 20, DARKBLUE);
    DrawText("Enter to get back to overworld", 500, 360, 20, DARKBLUE);
    DrawTexture(Fish, 400, 400, WHITE);
    break;
  case GameScreen::COMBAT:

    bool inCombat;

      /*if (inCombat)
      {
        PlaySound(GameAudio::battlemusic);
        SetSoundVolume(GameAudio::battlemusic, float(1.0)); // Set volume for a sound (1.0 is max level) This is a test
      }
*/


    //Background
    //DrawTexturePro(Battlescreen, {0, 0, (float)Battlescreen.width * 2, (float)Battlescreen.height * 2},
                   //{0.0, 0.0, (float)GetScreenWidth(), (float)GetScreenHeight() * 2.0f}, {}, 0, WHITE);

    //battlerec = {player->get_rec().x, player->get_rec().y + 90,(float)Battlescreen.width * 20, (float)Battlescreen.height * 50};
    //DrawTextureRec(Battlescreen, battlerec, {battlerec.x - 110, battlerec.y - 150}, WHITE);
    DrawTexture(Battlescreen, GetScreenWidth()/2 - 350, GetScreenHeight()/2 - 180, WHITE);
    //Draw Player
    Playerrec = {player->get_rec().x + 8, player->get_rec().y + 10, player->get_rec().width, player->get_rec().height};
    DrawRectangleRec(Playerrec, Color{});
    //DrawTextureRec(Back, frameRec, NemoPosition, WHITE);
    DrawTextureRec(spr_Player, frameRec, {player->get_rec().x, player->get_rec().y}, WHITE);
    // animation
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 3)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)spr_Player.width / 7;
    }

    //Timer
    DrawText(TextFormat("Time: %i", framescounter), player->set_rec().x + 100, player->set_rec().y, 20, GREEN);
    //Player Stats
    DrawText(TextFormat("Amount: %i", h_amount), player->set_rec().x, player->set_rec().y - 110, 20, BLUE);
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

void Game::Level::Teleport() {

  // teleport coordinates
  teleportrecOVERWORLDtoPYRAMID = { doorPositionX, doorPositionY, doortileX, doortileY }; // rectangle in overworld to pyramid
  teleportrecPYRAMIDtoOVERWORLD = { doorPositionX + 100 , doorPositionY, doortileX, doortileY }; //rectangle in pyramid to overworld
  teleportrecPYRAMIDtoOCEAN = { doorPositionX - 100 , doorPositionY, doortileX, doortileY }; //rectangle in pyramid to ocean
  teleportrecOCEANtoEND = { doorPositionX - 100, doorPositionY - 100, doortileX, doortileY }; //rectangle in ocean to endscreen

  // collision check with the door & nemo
  teleportcollisionOVERWORLDtoPYRAMID = CheckCollisionRecs(teleportrecOVERWORLDtoPYRAMID, nemo->nemorec); //check collision between door and nemo
  teleportcollisionPYRAMIDtoOVERWORLD = CheckCollisionRecs(teleportrecPYRAMIDtoOVERWORLD, nemo->nemorec);
  teleportcollisionPYRAMIDtoOCEAN = CheckCollisionRecs(teleportrecPYRAMIDtoOCEAN, nemo->nemorec);
  teleportcollisionOCEANtoEND = CheckCollisionRecs(teleportrecOCEANtoEND, nemo->nemorec);

  //bool true -> teleport...
  if (teleportcollisionOVERWORLDtoPYRAMID) { //if the collsion bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::PYRAMIDE;
  }
  if (teleportcollisionPYRAMIDtoOVERWORLD) { //if the collsion bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::OVERWORLD;
  }
  if (teleportcollisionPYRAMIDtoOCEAN) { //if the collsion bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::OCEAN;
  }
  if (teleportcollisionOCEANtoEND) {
    level->currentscreen = Game::Level::GameScreen::TITLESCREEN;
  }
}

Game::Level::~Level() {}

