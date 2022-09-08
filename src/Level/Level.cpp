#include "Level.h"

//bool collision = false; // Collision detection

void Game::Level::combat(Game::GameCharacter *c_enemy)
{
  if (((t_framescounter/120)%2) == 1) {
    t_framescounter = 0;
    b_currentFrame = 0;
  }

  if (((t_framescounter/120)%2) == 1) {
    t_framescounter = 0;
    r_currentFrame  = 0;
  }

  //Combat initialization

  //If the Timer is true, the seconds will Run and the Player can´t press any buttons, while the Mumy Attacks
  if (timer) {
    framescounter++;
    input = false;
  }

  //If 2 Seconds has Passed, the Player will receive Damage from the Mumy and the timer will be stopped, the Player can
  //then attack again
  if (((framescounter/120)%2) == 1) {
    framescounter = 0;

    //After Player Attacks, the Mumy will attack the Player
    if (player->get_turnnumb() > c_enemy->get_turnnumb()) {
      player->getDamage(c_enemy->attack());
      p_damaged = true;
      b_currentFrame = 0;
    }
    //After Mumy Attack, the Player attacks the Mumy
    if (c_enemy->get_turnnumb() > player->get_turnnumb()) {
      c_enemy->getDamage(player->attack());
      e_damaged = true;
      r_currentFrame = 0;
    }

    timer = false;
    input = true;
  }

  //Box Movement
  if(IsKeyPressed(KEY_D))
  {
    box_rec.x += 90;
  }

  if (IsKeyPressed(KEY_A))
  {
    box_rec.x -= 90;
  }

  if (IsKeyPressed(KEY_S))
  {
    box_rec.y += 35;
  }

  if (IsKeyPressed(KEY_W))
  {
    box_rec.y -= 35;
  }

  //Knopf soll nicht out of border gehen
  if (box_rec.y < 470) box_rec.y = 470;
  else if (box_rec.y > 505) box_rec.y = 505;


  if (box_rec.x < 565) box_rec.x = 565;
  else if (box_rec.x > 655) box_rec.x = 655;
  //==========================================

  //If a button is pressed
  if (input)
  {
    if (IsKeyPressed(KEY_SPACE) ) {
      if (t_rec_attack.x == box_rec.x && t_rec_attack.y == box_rec.y && t_rec_attack.width == box_rec.width &&
          t_rec_attack.height == box_rec.height)
      {
        //=========================PLAYER ATTACK================
        player->set_turnnumb(0);
        c_enemy->set_turnnumb(0);

        if (player->get_turnnumb() == c_enemy->get_turnnumb())
        {
          player->set_turnnumb(0);
          c_enemy->set_turnnumb(0);
        }
        //===============PLAYER ATTACK=========================
        if (player->get_turnnumb() > c_enemy->get_turnnumb()) {
          c_enemy->getDamage(player->attack());
          e_damaged = true;
          b_currentFrame = 3;

        }
        //================ENEMY ATTACK=========================
        if (c_enemy->get_turnnumb() > player->get_turnnumb()) {
          player->getDamage(c_enemy->attack());
          p_damaged = true;
          r_currentFrame = 3;
        }

        timer = true;
        //========================ATTACK END!!!================
      }

      if (h_amount > 0)
      {

      if (t_rec_item.x == box_rec.x && t_rec_item.y == box_rec.y && t_rec_item.width == box_rec.width &&
          t_rec_item.height == box_rec.height)
      {
          //======================HEAL!!!!=========================
          player->set_turnnumb(0);
          c_enemy->set_turnnumb(0);
          // Player heals first, then gets Damage
          if (player->get_turnnumb() >= c_enemy->get_turnnumb()) {
            player->heal();
            // player->getDamage(enemy->attack());
            h_amount--;
          }
          // Mumy Attacks first, then Player heals.
          if (c_enemy->get_turnnumb() >= player->get_turnnumb()) {
            // player->getDamage(enemy->attack());
            player->heal();
            h_amount--;
          }

          if (0 >= h_amount)
          {
            timer = false;
            input = false;
          }
          //=========================HEAL END!!!!=================
        }
        timer = true;
      }

      //=============================TIME ATTACK!!!=================

      //If 2 Seconds has Passed, the Player will receive Damage from the Mumy and the timer will be stopped, the Player can
      //then attack again

      if (energy > 0)
      {
       if (t_rec_time.x == box_rec.x && t_rec_time.y == box_rec.y && t_rec_time.width == box_rec.width &&
          t_rec_time.height == box_rec.height) {

           c_enemy->getDamage(player->attack());
           c_enemy->getDamage(player->attack());
           T_damaged = true;
           e_framescounter++;
           energy--;
       }
        if (0 == energy)
        {
          timer = false;
          //input = false;
        }

        //timer = true;

      }
      //=================================TIME ATTACK END!!!==============

      if (t_rec_escape.x == box_rec.x && t_rec_escape.y == box_rec.y && t_rec_escape.width == box_rec.width &&
          t_rec_escape.height == box_rec.height) {
        currentscreen = GameScreen::PYRAMIDE;
      }
    }
  }
  //==================================TIME ATTACK END!!!==============================================
  if (c_enemy->getLives() <= 0)
  {
    //delete enemy;

    DrawText("YOU WON!", 600, 320, 20, BLACK);
    timer = false;
  }
  else if (player->getLives() <= 0)
  {
    // delete enemy;
    // delete player;
    currentscreen = GameScreen::GAMEOVER;
    timer = false;
  }

  player->draw();
  c_enemy->draw();
}

void Game::Level::ScreenDraw() {

  bool key_input = true;

  /** SWITCH CASE FOR ROOM SWITCHING */

  switch (Game::Level::currentscreen) // For this Switch we determine here, what is drawn here
  {
  case GameScreen::TITLESCREEN:

    ClearBackground(BLACK);

    DrawTexture(Titlescreen,0,0, WHITE);

    if (IsSoundPlaying(GameAudio::pausemenu)){
      StopSound(GameAudio::pausemenu);
    }

    if(!IsSoundPlaying(GameAudio::titlescreenmusic)){
      PlaySound(GameAudio::titlescreenmusic);
      SetSoundVolume(GameAudio::titlescreenmusic, float(0.1));
    }
    if (IsSoundPlaying(GameAudio::titlescreenmusic)){}

    /** BUTTON FUNCTIONS */

    if (IsKeyPressed(KEY_SPACE)) {
      if (t_rec_start.x == box_rec_titlescreen.x && t_rec_start.y == box_rec_titlescreen.y &&
          t_rec_start.width == box_rec_titlescreen.width && t_rec_start.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::OVERWORLD;
      }
      if (t_rec_settings.x == box_rec_titlescreen.x && t_rec_settings.y == box_rec_titlescreen.y &&
          t_rec_settings.width == box_rec_titlescreen.width && t_rec_settings.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::PAUSEMENU;
      }
      if (t_rec_exit_game.x == box_rec_titlescreen.x && t_rec_exit_game.y == box_rec_titlescreen.y &&
          t_rec_exit_game.width == box_rec_titlescreen.width && t_rec_exit_game.height == box_rec_titlescreen.height) {
        exit(0);
      }
    }

    /** MOVE THE BOX */
    if (IsKeyPressed(KEY_S)) {
      box_rec_titlescreen.y += 100;
    }

    if (IsKeyPressed(KEY_W)) {
      box_rec_titlescreen.y -= 100;
    }

    if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50)
      box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
    else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 150)
      box_rec_titlescreen.y = Game::ScreenHeight / 2 + 150;

    /** BUTTONS TITLESCREEN */
    Draw9Slice(Box, t_rec_start, thick, WHITE);
    Draw9Slice(Box, t_rec_settings, thick, WHITE);
    Draw9Slice(Box, t_rec_exit_game, thick, WHITE);
    Draw9Slice(Box_S, box_rec_titlescreen, thick, WHITE);

    DrawText("START GAME", Game::ScreenWidth / 2 - 115, Game::ScreenHeight / 2 - 30, 30, WHITE);
    DrawText("SETTINGS", Game::ScreenWidth / 2 - 100, Game::ScreenHeight / 2 + 70, 30, WHITE);
    DrawText("EXIT GAME", Game::ScreenWidth / 2 - 100, Game::ScreenHeight / 2 + 170, 30, WHITE);

    break;

  case GameScreen::PAUSEMENU:

    ClearBackground(BLACK);

    DrawTexture(Titlescreen,0,0, WHITE);

    if (IsSoundPlaying(GameAudio::titlescreenmusic)){
      StopSound(GameAudio::titlescreenmusic);
    }

    if(!IsSoundPlaying(GameAudio::pausemenu)){
      PlaySound(GameAudio::pausemenu);
      SetSoundVolume(GameAudio::pausemenu, float(0.1));
    }
    if (IsSoundPlaying(GameAudio::pausemenu)){}

    /** BUTTON FUNCTIONS */
    if (IsKeyPressed(KEY_SPACE)) { //MUSIC ON/OFF
      if (t_rec_start.x == box_rec_titlescreen.x && t_rec_start.y == box_rec_titlescreen.y && t_rec_start.width == box_rec_titlescreen.width &&
          t_rec_start.height == box_rec_titlescreen.height) {
        std::cout << "Pause Music" << endl;
      }
      // FULLSCREEN
      if (t_rec_settings.x == box_rec_titlescreen.x && t_rec_settings.y == box_rec_titlescreen.y && t_rec_settings.width == box_rec_titlescreen.width &&
          t_rec_settings.height == box_rec_titlescreen.height) {
        std::cout << "Fullscreen on" << endl;
        ToggleFullscreen();
      }

      // BACK
      if (t_rec_exit_game.x == box_rec_titlescreen.x && t_rec_exit_game.y == box_rec_titlescreen.y &&
          t_rec_exit_game.width == box_rec_titlescreen.width && t_rec_exit_game.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::TITLESCREEN;
      }
    }

      /** MOVE THE BOX */
      if (IsKeyPressed(KEY_S)) {
        box_rec_titlescreen.y += 100;
      }

      if (IsKeyPressed(KEY_W)) {
        box_rec_titlescreen.y -= 100;
      }

      if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50)
        box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
      else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 150)
        box_rec_titlescreen.y = Game::ScreenHeight / 2 + 150;

      /** BUTTONS TITLESCREEN */
      Draw9Slice(Box, t_rec_start, thick, WHITE);
      Draw9Slice(Box, t_rec_settings, thick, WHITE);
      Draw9Slice(Box, t_rec_exit_game, thick, WHITE);
      Draw9Slice(Box_S, box_rec_titlescreen, thick, WHITE);

      DrawText("MUSIC ON/OFF", Game::ScreenWidth / 2 - 117, Game::ScreenHeight / 2 - 30, 28, WHITE);
      DrawText("FULLSCREEN", Game::ScreenWidth / 2 - 113, Game::ScreenHeight / 2 + 70, 30, WHITE);
      DrawText("BACK", Game::ScreenWidth / 2 - 57, Game::ScreenHeight / 2 + 170, 30, WHITE);

      break;

    case GameScreen::ENDSCREEN:

      ClearBackground(BLACK);

      if (IsKeyPressed(KEY_SPACE)) {
        currentscreen = GameScreen::TITLESCREEN;
      }

      endscreen.update();
      endscreen.draw();
      break;

    case GameScreen::OVERWORLD:

      /** sounds */
      if (IsSoundPlaying(GameAudio::titlescreenmusic)) {
        StopSound(GameAudio::titlescreenmusic);
      }
      if (IsSoundPlaying(GameAudio::battlemusic)) {
        StopSound(GameAudio::battlemusic);
      }
      if (IsSoundPlaying(GameAudio::indungeon)) {
        StopSound(GameAudio::indungeon);
      }

      if (!IsSoundPlaying(GameAudio::outdungeon)) {
        PlaySound(GameAudio::outdungeon);
        SetSoundVolume(GameAudio::outdungeon, float(0.1));
      }
      if (IsSoundPlaying(GameAudio::outdungeon)) {}

      /** update */
      if (IsKeyPressed(KEY_C))
      {
        std::cout << "X: " << nemo->NemoPosition.x << endl;
        std::cout << "Y: " << nemo->NemoPosition.y << endl;
      }
      if (IsKeyPressed(KEY_P)) {
        level->currentscreen = Game::Level::GameScreen::PAUSEMENU;
      }


      //teleport conditions
      if (teleportcollisionOVERWORLDtoPYRAMID) { //if the collision bool is true, nemo is transported to PYRAMIDE
        level->currentscreen = Game::Level::GameScreen::PYRAMIDE;
        nemo->NemoPosition.x = doorPositionX - 670;
        nemo->NemoPosition.y = doorPositionY + 700;
      }

      /** draw */


      break;

    case GameScreen::PYRAMIDE:

      if (IsSoundPlaying(GameAudio::battlemusic)) {
        StopSound(GameAudio::battlemusic);
      }
      if (IsSoundPlaying(GameAudio::outdungeon)) {
        StopSound(GameAudio::outdungeon);
      }

      if (!IsSoundPlaying(GameAudio::indungeon)) {
        PlaySound(GameAudio::indungeon);
        SetSoundVolume(GameAudio::indungeon, float(0.1));
      }
      if (IsSoundPlaying(GameAudio::indungeon)) {}

      if (IsKeyPressed(KEY_C))
      {
        std::cout << "X: " << nemo->NemoPosition.x << endl;
        std::cout << "Y: " << nemo->NemoPosition.y << endl;
      }

      //Teleport();

      //teleport conditions
      if (teleportcollisionPYRAMIDtoOVERWORLD) { //if the collision bool is true, nemo is transported to PYRAMIDE
        level->currentscreen = Game::Level::GameScreen::OVERWORLD;
        nemo->NemoPosition.x = doorPositionX + 20;
        nemo->NemoPosition.y = doorPositionY + 60;
      }
      if (teleportcollisionPYRAMIDtoENDSCREEN) { //if the collision bool is true, nemo is transported to the ENDSCREEN
        level->currentscreen = Game::Level::GameScreen::ENDSCREEN;
      }
      break;

    case GameScreen::COMBAT:

      bool inCombat;

      if (IsSoundPlaying(GameAudio::indungeon)) {
        StopSound(GameAudio::indungeon);
      }
      if (IsSoundPlaying(GameAudio::outdungeon)) {
        StopSound(GameAudio::outdungeon);
      }

      if (!IsSoundPlaying(GameAudio::battlemusic)) {
        PlaySound(GameAudio::battlemusic);
        SetSoundVolume(GameAudio::battlemusic, float(0.1));
      }
      if (IsSoundPlaying(GameAudio::battlemusic)) {}

      //=====================================DRAWING THE PLAYER AND ENEMY===================================================
      DrawTexture(Battlescreen, GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 180, WHITE);

      // Timer
      DrawText(TextFormat("Time: %i", framescounter), player->set_rec().x + 100, player->set_rec().y, 20, GREEN);
      DrawFPS(player->set_rec().x + 200, player->set_rec().y);

      //=========================Blue TIMER===================================
      // Draw Blue Clock
      Bluerec = { 440, 500, 32, 32 };
      DrawRectangleRec(Bluerec, Color {});
      DrawTextureRec(Blue_Clock, BlueClockFrameRec, { 440, 470 }, WHITE);
      BlueClockFrameRec.x = (float)b_currentFrame * (float)Blue_Clock.width / 4;
      //=======================Blue TIMER END=================================

      //=========================Red TIMER===================================
      // Draw Blue Clock
      Redrec = { 790, 500, 32, 32 };
      DrawRectangleRec(Redrec, Color {});
      DrawTextureRec(Red_Clock, RedClockFrameRec, { 790, 470 }, WHITE);
      RedClockFrameRec.x = (float)r_currentFrame * (float)Red_Clock.width / 4;
      //=======================Red TIMER END=================================

      //Initialize the combat with the enemy
      switch (opponent)
      {
      case EnemyType::MUMY:
        combat(enemy);
        damaged(enemy);
        break;

      case EnemyType::SHADOW:
        combat(shadow);
        damaged(shadow);
        break;

      case EnemyType::PHARAOH:
        combat(pharaoh);
        damaged(pharaoh);
        break;

      default: break;
      }

      //==================DEBUG====================================================
      DrawText(TextFormat("ENERGY: %i", energy), 500, 300, 20, BLACK);
      //DrawText(TextFormat("Heal Amount: %i", h_amount), 500, 320, 20, BLACK);
      //DrawTexture(spr_Battery, 500, 300, WHITE);

      //==================================DRAWING BATTERY!!!!====================================================
      B1rec = {player->set_rec().x - 60, player->set_rec().y - 130, 48, 48};
      DrawRectangleRec(B1rec, Color{});
      DrawTextureRec(spr_Battery,batteryrec1, {player->set_rec().x - 60, player->set_rec().y - 130}, WHITE);
      batteryrec1.x = (float)b1_c_frame * (float)spr_Battery.width / 2;
//Battery Conditions
      if (energy <= 1)
      {
        b2_c_frame = 1;
      }

      if (energy == 0)
      {
        b1_c_frame = 1;
      }

      B2rec = {player->set_rec().x + 10, player->set_rec().y - 130, 48, 48};
      DrawRectangleRec(B2rec, Color{});
      DrawTextureRec(spr_Battery,batteryrec2, {player->set_rec().x + 10, player->set_rec().y - 130}, WHITE);
      batteryrec2.x = (float)b2_c_frame * (float)spr_Battery.width / 2;
      //=================================DRAWING BATTERY END!!!!=================================================


    Draw9Slice(Box, t_rec_attack, thickness, WHITE);
    Draw9Slice(Box, t_rec_time, thickness, WHITE);
    Draw9Slice(Box, t_rec_item, thickness, WHITE);
    Draw9Slice(Box, t_rec_escape, thickness, WHITE);
    Draw9Slice(Box_S, box_rec, thickness, WHITE);
    DrawText("ATTACK",t_rec_attack.x + 5, t_rec_attack.y + 10, 17, WHITE);
    DrawText("TIME",t_rec_time.x + 15, t_rec_time.y + 10, 17, WHITE);
    DrawText("HEAL",t_rec_item.x + 15, t_rec_item.y + 10, 17, WHITE);
    DrawText("ESCAPE",t_rec_escape.x + 5, t_rec_escape.y + 10, 17, WHITE);

      break;
//GameOver Screen
    case GameScreen::GAMEOVER:
      DrawTexture(gameover, GetScreenWidth() / 2 - 15, GetScreenHeight() / 2 - 20, WHITE);
      DrawText("GAME OVER!", GetScreenWidth() / 2 + 280, GetScreenHeight() / 2 + 100, 50, RED);
      DrawText("PRESS <<ENTER>> TO RESTART", GetScreenWidth()/ 2 + 280, GetScreenHeight() / 2 + 150, 20, YELLOW);
      if (IsKeyPressed(KEY_ENTER))
      {
        currentscreen = GameScreen::TITLESCREEN;
      }
    break;
    }

  }

//======================================================================================================================

void Game::Level::Teleport() {

  // teleport coordinates (JUST FOR DRAW)
  teleportrecOVERWORLDtoPYRAMID = { doorPositionX, doorPositionY, doortileX, doortileY }; // rectangle in overworld to pyramid
  teleportrecPYRAMIDtoOVERWORLD = { doorPositionX - 685, doorPositionY + 780, doortileX, doortileY }; //rectangle in pyramid to overworld
  teleportrecPYRAMIDtoENDSCREEN = { doorPositionX + 528 , doorPositionY - 200, doortileX, doortileY }; //rectangle in pyramid to endscreen

  // collision check with the door & nemo (RECTANGLES FOR COLLISION)
  teleportcollisionOVERWORLDtoPYRAMID = CheckCollisionRecs(teleportrecOVERWORLDtoPYRAMID, nemo->nemorec); //check collision between door and nemo
  teleportcollisionPYRAMIDtoOVERWORLD = CheckCollisionRecs(teleportrecPYRAMIDtoOVERWORLD, nemo->nemorec);
  teleportcollisionPYRAMIDtoENDSCREEN = CheckCollisionRecs(teleportrecPYRAMIDtoENDSCREEN, nemo->nemorec);

  /*
  //bool true -> teleport...
  if (teleportcollisionOVERWORLDtoPYRAMID) { //if the collision bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::PYRAMIDE;
    nemo->NemoPosition.x = doorPositionX - 670;
    nemo->NemoPosition.y = doorPositionY + 700;
  }
  if (teleportcollisionPYRAMIDtoOVERWORLD) { //if the collision bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::OVERWORLD;
    nemo->NemoPosition.x = doorPositionX + 20;
    nemo->NemoPosition.y = doorPositionY + 60;
  }
  if (teleportcollisionPYRAMIDtoENDSCREEN) { //if the collision bool is true, nemo is transported to PYRAMIDE
    level->currentscreen = Game::Level::GameScreen::ENDSCREEN;
  }
   */
}

//Destrucotr
Game::Level::~Level()
{
  std::cout<<"Destructor Level\n";
  delete enemy;
  delete shadow;
  delete pharaoh;
}
