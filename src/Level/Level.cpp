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

//Bewegung der Box
  if(IsKeyPressed(KEY_RIGHT))
  {
    box_rec.x += 90;
  }

  if (IsKeyPressed(KEY_LEFT))
  {
    box_rec.x -= 90;
  }

  if (IsKeyPressed(KEY_DOWN))
  {
    box_rec.y += 35;
  }

  if (IsKeyPressed(KEY_UP))
  {
    box_rec.y -= 35;
  }

  //Knopf soll nicht out of border gehen
  if (box_rec.y < 470) box_rec.y = 470;
  else if (box_rec.y > 505) box_rec.y = 505;


  if (box_rec.x < 565) box_rec.x = 565;
  else if (box_rec.x > 655) box_rec.x = 655;
  //==========================================


  //PLAYER ENERGY
  int energy = 2;

//Wenn eine Taste gedrückt wurde
  if (input == true)
  {
    if (IsKeyPressed(KEY_SPACE) ) {
      if (t_rec_attack.x == box_rec.x && t_rec_attack.y == box_rec.y && t_rec_attack.width == box_rec.width &&
          t_rec_attack.height == box_rec.height)
      {
        //=========================PLAYER ATTACK================
        player->set_turnnumb(0);
        enemy->set_turnnumb(0);
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
      if (t_rec_item.x == box_rec.x && t_rec_item.y == box_rec.y && t_rec_item.width == box_rec.width &&
          t_rec_item.height == box_rec.height)
      {
        if (h_amount > 0) {
          //======================HEAL!!!!=========================
          player->set_turnnumb(0);
          enemy->set_turnnumb(0);
          // Player heals first, then gets Damage
          if (player->get_turnnumb() >= enemy->get_turnnumb()) {
            player->heal();
            //player->getDamage(enemy->attack());
            h_amount--;
          }
          // Mumy Attacks first, then Player heals.
          if (enemy->get_turnnumb() >= player->get_turnnumb()) {
            //player->getDamage(enemy->attack());
            player->heal();
            h_amount--;
          }
          //=========================HEAL END!!!!=================
        }
      }

      if (t_rec_time.x == box_rec.x && t_rec_time.y == box_rec.y && t_rec_time.width == box_rec.width &&
          t_rec_time.height == box_rec.height)
      {
            if (energy > 0)
        {
              enemy->getDamage(player->attack());
              energy--;
            }

        timer = true;

      }

      if (t_rec_escape.x == box_rec.x && t_rec_escape.y == box_rec.y && t_rec_escape.width == box_rec.width &&
          t_rec_escape.height == box_rec.height) {
        currentscreen = GameScreen::OVERWORLD;
      }
    }
  }
  if (enemy->getLives() <= 0)
  {
    //delete enemy;

    DrawText("YOU WON!", 600, 320, 20, BLACK);
    timer = false;
    input = false;
  }
  else if (player->getLives() <= 0)
  {
    // delete enemy;
    // delete player;
    DrawText("YOU LOST!", 600, 320, 20, BLACK);
    timer = false;
    input = false;
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
  //=====================================DRAWING THE PLAYER AND ENEMY===================================================
    DrawTexture(Battlescreen, GetScreenWidth()/2 - 350, GetScreenHeight()/2 - 180, WHITE);

    //Timer
    //DrawText(TextFormat("Time: %i", framescounter), player->set_rec().x + 100, player->set_rec().y, 20, GREEN);


    //Player
    player->draw();
    //Draw enemy
    enemy->draw();
    combat();


    Draw9Slice(Box, t_rec_attack, thickness, WHITE);
    Draw9Slice(Box, t_rec_time, thickness, WHITE);
    Draw9Slice(Box, t_rec_item, thickness, WHITE);
    Draw9Slice(Box, t_rec_escape, thickness, WHITE);
    Draw9Slice(Box_S, box_rec, thickness, WHITE);
    DrawText("ATTACK",t_rec_attack.x + 5, t_rec_attack.y + 10, 17, WHITE);
    DrawText("TIME",t_rec_time.x + 15, t_rec_time.y + 10, 17, WHITE);
    DrawText("ITEM",t_rec_item.x + 15, t_rec_item.y + 10, 17, WHITE);
    DrawText("ESCAPE",t_rec_escape.x + 5, t_rec_escape.y + 10, 17, WHITE);


    break;
  }
}
//======================================================================================================================

void Game::Level::Teleport() { //X 910-685, Y 276 + 780 X = 225, Y= 1056

  // teleport coordinates
  teleportrecOVERWORLDtoPYRAMID = { doorPositionX, doorPositionY, doortileX, doortileY }; // rectangle in overworld to pyramid
  teleportrecPYRAMIDtoOVERWORLD = { doorPositionX - 685, doorPositionY + 780, doortileX, doortileY }; //rectangle in pyramid to overworld
  teleportrecPYRAMIDtoOCEAN = { doorPositionX + 528 , doorPositionY - 200, doortileX, doortileY }; //rectangle in pyramid to ocean
  teleportrecOCEANtoEND = { doorPositionX - 200, doorPositionY - 100, doortileX, doortileY }; //rectangle in ocean to endscreen

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

Game::Level::~Level()
{
  std::cout<<"Destructor Level\n";
}

