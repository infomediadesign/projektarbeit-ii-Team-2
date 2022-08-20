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
      p_damaged = true;
    }
    //After Mumy Attack, the Player attacks the Mumy
    if (enemy->get_turnnumb() > player->get_turnnumb()) {
      enemy->getDamage(player->attack());
      e_damaged = true;
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
          e_damaged = true;

        }
        //================ENEMY ATTACK=========================
        if (enemy->get_turnnumb() > player->get_turnnumb()) {
          player->getDamage(enemy->attack());
          p_damaged = true;
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
              e_damaged = true;
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

  bool key_input = true;

  /** SWITCH CASE FOR ROOM SWITCHING */

  switch (Game::Level::currentscreen) // For this Switch we determine here, what is drawn here
  {
  case GameScreen::TITLESCREEN:

    /*if (!IsSoundPlaying(GameAudio::titlescreenmusic)) {
    PlaySound(GameAudio::titlescreenmusic);
    SetSoundVolume(GameAudio::titlescreenmusic, float(0.2));
    }*/

    /** BUTTON FUNCTIONS */
    if (key_input == true) {
      if (IsKeyPressed(KEY_SPACE)) {
        if (t_rec_start.x == box_rec.x && t_rec_start.y == box_rec.y && t_rec_start.width == box_rec.width &&
            t_rec_start.height == box_rec.height) {
          currentscreen = GameScreen::OVERWORLD;
        }
        if (t_rec_settings.x == box_rec.x && t_rec_settings.y == box_rec.y && t_rec_settings.width == box_rec.width &&
            t_rec_settings.height == box_rec.height) {
          currentscreen = GameScreen::PAUSEMENU;
        }
        if (t_rec_exit_game.x == box_rec.x && t_rec_exit_game.y == box_rec.y &&
            t_rec_exit_game.width == box_rec.width && t_rec_exit_game.height == box_rec.height) {
          SetExitKey(KEY_SPACE);
        }
      }
    }

    /** MOVE THE BOX */
    if (IsKeyPressed(KEY_DOWN))
    { box_rec_titlescreen.y += 50; }

    if (IsKeyPressed(KEY_UP))
    { box_rec_titlescreen.y -= 50; }

    //Knopf soll nicht out of border gehen
    if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50) box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
    else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 50) box_rec_titlescreen.y = Game::ScreenHeight / 2 + 50;

    /** BUTTONS TITLESCREEN */
    Draw9Slice(Box, t_rec_start, thickness, WHITE);
    Draw9Slice(Box, t_rec_settings, thickness, WHITE);
    Draw9Slice(Box, t_rec_exit_game, thickness, WHITE);
    Draw9Slice(Box_S, box_rec_titlescreen, thickness, WHITE);

    DrawText("START GAME", Game::ScreenWidth / 2 - 50 , Game::ScreenHeight / 2 - 40 , 17, WHITE);
    DrawText("SETTINGS", Game::ScreenWidth / 2 - 50 , Game::ScreenHeight / 2 + 10, 17, WHITE);
    DrawText("EXIT GAME", Game::ScreenWidth / 2 - 50 , Game::ScreenHeight / 2 + 60 , 17, WHITE);

  case GameScreen::OVERWORLD:
    //nemo->NemoPosition.x = 920.0;
    //nemo->NemoPosition.y = 500;


    break;

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
    // Draw enemy
    enemy->draw();

    //Drawing the Player Damage Number
    if (p_damaged) {

      p_framescounter++;

      DrawText(TextFormat("- %i", enemy->getStrength() - player->getDefense()),player->set_rec().x + 80,player->set_rec().y,20,RED);

      if (((p_framescounter / 60) % 2) == 1) {
        p_framescounter = 0;
        p_damaged = false;
      }
    }
    //Drawing the Enemy Damage Number
    if (e_damaged) {

      e_framescounter++;

      DrawText(TextFormat("- %i", player->getStrength() - enemy->getDefense()),enemy->set_rec().x - 40,enemy->set_rec().y,20,RED);

      if (((e_framescounter / 60) % 2) == 1) {
        e_framescounter = 0;
        e_damaged  = false;
      }
    }
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

void Game::Level::Teleport() {

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
    nemo->NemoPosition.x = doorPositionX - 670;
    nemo->NemoPosition.y = doorPositionY + 700;
  }
  if (teleportcollisionPYRAMIDtoOVERWORLD) { //if the collsion bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::OVERWORLD;
    nemo->NemoPosition.x = doorPositionX + 20;
    nemo->NemoPosition.y = doorPositionY + 60;
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

