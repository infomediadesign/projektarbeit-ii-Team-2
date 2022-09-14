#include "Level.h"

//bool collision = false; // Collision detection

void Game::Level::combat(Game::GameCharacter *c_enemy)
{
  //WENN DER SPIELER GEWINNT
  if (battleEnd)
  {
    finisher_timer++;
  }

  if (((finisher_timer/120)%2) == 1)
  {
    finisher_timer = 0;
    currentscreen = GameScreen::PYRAMIDE;
  }
//===============================================
  //WENN DER SPIELER VERLIERT

  if (GameOver)
  {
    GO_timer++;
  }

  if (((GO_timer/120)%2) == 1)
  {
    GO_timer = 0;
    currentscreen = GameScreen::GAMEOVER;
  }
//===============================================
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

    input = true;
    timer = false;

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
    DrawText("YOU WON!", 580, 320, 30, DARKGREEN);
    timer = false;
    //battleEnd = true;
    //input = false;
  }
  else if (player->getLives() <= 0)
  {
    DrawText("YOU LOST!", 580, 320, 30, RED);
    timer = false;
    GameOver = true;
    input = false;
  }

  player->draw();
  c_enemy->draw();
}

void Game::Level::ScreenDraw() {
  switch (Game::Level::currentscreen)
  {
  case GameScreen::CUTSCENE:

    if (IsKeyPressed(KEY_SPACE)){
      currentscreen = GameScreen::TITLESCREEN;
    }

    if (state == 0)                 // State 0: Small box blinking
    {
      framesCounter++;

      if (framesCounter == 120)
      {
        state = 1;
        framesCounter = 0;      // Reset counter... will be used later...
      }
    }
    else if (state == 1)            // State 1: Top and left bars growing
    {
      topSideRecWidth += 4;
      leftSideRecHeight += 4;

      if (topSideRecWidth == 256) state = 2;
    }
    else if (state == 2)            // State 2: Bottom and right bars growing
    {
      bottomSideRecWidth += 4;
      rightSideRecHeight += 4;

      if (bottomSideRecWidth == 256) state = 3;
    }
    else if (state == 3)            // State 3: Letters appearing (one by one)
    {
      framesCounter++;

      if (framesCounter/12)       // Every 12 frames, one more letter!
      {
        lettersCount++;
        framesCounter = 0;
      }

      if (lettersCount >= 10)     // When all letters have appeared, just fade out everything
      {
        alpha -= 0.02f;

        if (alpha <= 0.0f)
        {
          alpha = 0.0f;
          state = 4;
        }
      }
    }
    else if (state == 4)            // State 4: Reset and Replay
    {
      currentscreen = GameScreen::TITLESCREEN;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (state == 0)
    {
      if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
    }
    else if (state == 1)
    {
      DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
      DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
    }
    else if (state == 2)
    {
      DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
      DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

      DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
      DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
    }
    else if (state == 3)
    {
      DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
      DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));

      DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
      DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));

      DrawRectangle(GetScreenWidth()/2 - 112, GetScreenHeight()/2 - 112, 224, 224, Fade(RAYWHITE, alpha));

      DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth()/2 - 44, GetScreenHeight()/2 + 48, 50, Fade(BLACK, alpha));
    }
    else if (state == 4)
    {
      DrawText("[R] REPLAY", 340, 200, 20, GRAY);
    }
    break;

  case GameScreen::TITLESCREEN:
    ///UPDATE
    ///-----------------------------------------------------------------------------------------------------------------
    ///sound
    if (IsSoundPlaying(GameAudio::pausemenu))  { StopSound(GameAudio::pausemenu); }
    if (IsSoundPlaying(GameAudio::outdungeon)) { StopSound(GameAudio::outdungeon);}
    if (IsSoundPlaying(GameAudio::indungeon))  { StopSound(GameAudio::indungeon); }

    if (!IsSoundPlaying(GameAudio::titlescreenmusic))
    {
      PlaySound(GameAudio::titlescreenmusic);
      SetSoundVolume(GameAudio::titlescreenmusic, float(0.05));
    }
    if (IsSoundPlaying(GameAudio::titlescreenmusic)){}

    /// Buttons
    /** Button Functions */
    if (IsKeyPressed(KEY_SPACE)) {
      if (t_rec_start.x == box_rec_titlescreen.x && t_rec_start.y == box_rec_titlescreen.y &&
          t_rec_start.width == box_rec_titlescreen.width && t_rec_start.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::OVERWORLD;
        nemo->NemoPosition.x = 925;
        nemo->NemoPosition.y = 500;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
      }
      if (t_rec_settings.x == box_rec_titlescreen.x && t_rec_settings.y == box_rec_titlescreen.y &&
          t_rec_settings.width == box_rec_titlescreen.width && t_rec_settings.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::PAUSEMENU;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
      }
      if (t_rec_exit_game.x == box_rec_titlescreen.x && t_rec_exit_game.y == box_rec_titlescreen.y &&
          t_rec_exit_game.width == box_rec_titlescreen.width && t_rec_exit_game.height == box_rec_titlescreen.height) {
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
        exit(0);
      }
    }

    /** Move the box */
    if (IsKeyPressed(KEY_S)) {
      box_rec_titlescreen.y += 100;
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
    }
    if (IsKeyPressed(KEY_W)) {
      box_rec_titlescreen.y -= 100;
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
    }

    if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50) {
      box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
    }
    else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 150) {
      box_rec_titlescreen.y = Game::ScreenHeight / 2 + 150;
}

    ///DRAW
    ///-----------------------------------------------------------------------------------------------------------------
    ClearBackground(BLACK);
    DrawTexture(Titlescreen,0,0, WHITE);

    /** draw buttons titlescreen */
    Draw9Slice(Box, t_rec_start, thick, WHITE);
    Draw9Slice(Box, t_rec_settings, thick, WHITE);
    Draw9Slice(Box, t_rec_exit_game, thick, WHITE);
    Draw9Slice(Box_S, box_rec_titlescreen, thick, WHITE);

    /** draw button-text titlescreen */
    //DrawText("START GAME", Game::ScreenWidth / 2 - 115, Game::ScreenHeight / 2 - 30, 30, WHITE);
    DrawTextEx(textFont, "START GAME", fontTextPosSTART, fontSize, fontSpacing, WHITE);
    DrawTextEx(textFont, "SETTINGS", fontTextPosSETTINGS, fontSize, fontSpacing, WHITE);
    DrawTextEx(textFont, "EXIT GAME", fontTextPosEXIT, fontSize, fontSpacing, WHITE);
    //DrawText("SETTINGS", Game::ScreenWidth / 2 - 100, Game::ScreenHeight / 2 + 70, 30, WHITE);
    //DrawText("EXIT GAME", Game::ScreenWidth / 2 - 100, Game::ScreenHeight / 2 + 170, 30, WHITE);
    break;

  case GameScreen::PAUSEMENU:
    ///UPDATE
    ///-----------------------------------------------------------------------------------------------------------------
    ///sound
    if (IsSoundPlaying(GameAudio::titlescreenmusic)) { StopSound(GameAudio::titlescreenmusic); }
    if (IsSoundPlaying(GameAudio::outdungeon)) { StopSound(GameAudio::outdungeon); }
    if (IsSoundPlaying(GameAudio::indungeon)) { StopSound(GameAudio::indungeon); }

    if(!IsSoundPlaying(GameAudio::pausemenu))
    {
      PlaySound(GameAudio::pausemenu);
      SetSoundVolume(GameAudio::pausemenu, float(0.1));
    }
    if (IsSoundPlaying(GameAudio::pausemenu)){}

    /** Button functions */
    if (IsKeyPressed(KEY_SPACE)) {
      //FULLSCREEN
        if (t_rec_start.x == box_rec_titlescreen.x && t_rec_start.y == box_rec_titlescreen.y && t_rec_start.width == box_rec_titlescreen.width &&
            t_rec_start.height == box_rec_titlescreen.height) {
          PlaySound(GameAudio::buttonpress);
          SetSoundVolume(GameAudio::buttonpress, float(0.6));
          ToggleFullscreen();
        }
        // FULLSCREEN
        if (t_rec_settings.x == box_rec_titlescreen.x && t_rec_settings.y == box_rec_titlescreen.y && t_rec_settings.width == box_rec_titlescreen.width &&
            t_rec_settings.height == box_rec_titlescreen.height) {
          currentscreen = GameScreen::TITLESCREEN;
          PlaySound(GameAudio::buttonpress);
          SetSoundVolume(GameAudio::buttonpress, float(0.6));
        }
    }

      /** move the box */
      if (IsKeyPressed(KEY_S)) {
        box_rec_titlescreen.y += 100;
        PlaySound(GameAudio::dialoge);
        SetSoundVolume(GameAudio::dialoge, float(0.1));
      }

      if (IsKeyPressed(KEY_W)) {
        box_rec_titlescreen.y -= 100;
        PlaySound(GameAudio::dialoge);
        SetSoundVolume(GameAudio::dialoge, float(0.1));
      }

      if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50) {
        box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
      } else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 50) {
        box_rec_titlescreen.y = Game::ScreenHeight / 2 + 50;
}

      ///DRAW
      ///-----------------------------------------------------------------------------------------------------------------
      ClearBackground(BLACK);
      DrawTexture(TitlescreenWithoutText,0,0, WHITE);
      DrawTexture(Pausescreen,0,0, WHITE);

      /** Button draw pause screen */
      Draw9Slice(Box, t_rec_start, thick, WHITE);
      Draw9Slice(Box, t_rec_settings, thick, WHITE);
      Draw9Slice(Box_S, box_rec_titlescreen, thick, WHITE);

      //DrawText("FULLSCREEN", Game::ScreenWidth / 2 - 117, Game::ScreenHeight / 2 - 30, 28, WHITE);
      //DrawText("BACK", Game::ScreenWidth / 2 - 113, Game::ScreenHeight / 2 + 70, 30, WHITE);
      DrawTextEx(textFont, "FULLSCREEN", fontTextPosFULLSCREEN, fontSize, fontSpacing, WHITE);
      DrawTextEx(textFont, "BACK", fontTextPosBACK, fontSize, fontSpacing, WHITE);
      break;

  case GameScreen::PAUSEMENU_OVERWORLD:
    ///UPDATE
    ///-----------------------------------------------------------------------------------------------------------------
    ///sounds
    if (IsSoundPlaying(GameAudio::titlescreenmusic)) { StopSound(GameAudio::titlescreenmusic); }
    if (IsSoundPlaying(GameAudio::outdungeon)) { StopSound(GameAudio::outdungeon); }
    if (IsSoundPlaying(GameAudio::indungeon)) { StopSound(GameAudio::indungeon); }

    if(!IsSoundPlaying(GameAudio::pausemenu))
    {
      PlaySound(GameAudio::pausemenu);
      SetSoundVolume(GameAudio::pausemenu, float(0.1));
    }
    if (IsSoundPlaying(GameAudio::pausemenu)){}

    /** Button functions */
    if (IsKeyPressed(KEY_SPACE)) { //MUSIC ON/OFF
      if (t_rec_start.x == box_rec_titlescreen.x && t_rec_start.y == box_rec_titlescreen.y && t_rec_start.width == box_rec_titlescreen.width &&
          t_rec_start.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::OVERWORLD;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));

      }
      // FULLSCREEN
      if (t_rec_settings.x == box_rec_titlescreen.x && t_rec_settings.y == box_rec_titlescreen.y && t_rec_settings.width == box_rec_titlescreen.width &&
          t_rec_settings.height == box_rec_titlescreen.height) {
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
        ToggleFullscreen();
      }

      // BACK
      if (t_rec_exit_game.x == box_rec_titlescreen.x && t_rec_exit_game.y == box_rec_titlescreen.y &&
          t_rec_exit_game.width == box_rec_titlescreen.width && t_rec_exit_game.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::TITLESCREEN;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
      }
    }

    /** MOVE THE BOX */
    if (IsKeyPressed(KEY_S)) {
      box_rec_titlescreen.y += 100;
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
    }

    if (IsKeyPressed(KEY_W)) {
      box_rec_titlescreen.y -= 100;
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
    }

    if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50) {
      box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
    }
    else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 150) {
      box_rec_titlescreen.y = Game::ScreenHeight / 2 + 150;
}

    ///DRAW
    ///-----------------------------------------------------------------------------------------------------------------
    ClearBackground(BLACK);
    DrawTexture(OVERWORLD_Screenshot,0,0, WHITE);
    DrawTexture(Pausescreen,0,0, WHITE);

    /** BUTTONS TITLESCREEN */
    Draw9Slice(Box, t_rec_start, thick, WHITE);
    Draw9Slice(Box, t_rec_settings, thick, WHITE);
    Draw9Slice(Box, t_rec_exit_game, thick, WHITE);
    Draw9Slice(Box_S, box_rec_titlescreen, thick, WHITE);

    //DrawText("RESUME GAME", Game::ScreenWidth / 2 - 117, Game::ScreenHeight / 2 - 30, 28, WHITE);
    //DrawText("FULLSCREEN", Game::ScreenWidth / 2 - 113, Game::ScreenHeight / 2 + 70, 30, WHITE);
    //DrawText("BACK TO MENU", Game::ScreenWidth / 2 - 117, Game::ScreenHeight / 2 + 170, 28, WHITE);
    DrawTextEx(textFont, "RESUME GAME", fontTextPosRESUME, fontSpecialSize, fontSpacing, WHITE);
    DrawTextEx(textFont, "FULLSCREEN", fontTextPosFULLSCREEN2, fontSpecialSize, fontSpacing, WHITE);
    DrawTextEx(textFont, "BACK TO MENU", fontTextPosMENU, fontSpecialSize, fontSpacing, WHITE);
    break;

  case GameScreen::PAUSEMENU_PYRAMID:

    ///UPDATE
    ///-----------------------------------------------------------------------------------------------------------------
    ///sounds
    if (IsSoundPlaying(GameAudio::titlescreenmusic)) { StopSound(GameAudio::titlescreenmusic); }
    if (IsSoundPlaying(GameAudio::outdungeon)) { StopSound(GameAudio::outdungeon); }
    if (IsSoundPlaying(GameAudio::indungeon)) { StopSound(GameAudio::indungeon); }

    if(!IsSoundPlaying(GameAudio::pausemenu))
    {
      PlaySound(GameAudio::pausemenu);
      SetSoundVolume(GameAudio::pausemenu, float(0.1));
    }
    if (IsSoundPlaying(GameAudio::pausemenu)){}

    /** BUTTON FUNCTIONS */
    if (IsKeyPressed(KEY_SPACE)) { //MUSIC ON/OFF
      if (t_rec_start.x == box_rec_titlescreen.x && t_rec_start.y == box_rec_titlescreen.y && t_rec_start.width == box_rec_titlescreen.width &&
          t_rec_start.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::PYRAMIDE;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
      }
      // FULLSCREEN
      if (t_rec_settings.x == box_rec_titlescreen.x && t_rec_settings.y == box_rec_titlescreen.y && t_rec_settings.width == box_rec_titlescreen.width &&
          t_rec_settings.height == box_rec_titlescreen.height) {
        std::cout << "Fullscreen on" << endl;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
        ToggleFullscreen();
      }
      // BACK
      if (t_rec_exit_game.x == box_rec_titlescreen.x && t_rec_exit_game.y == box_rec_titlescreen.y &&
          t_rec_exit_game.width == box_rec_titlescreen.width && t_rec_exit_game.height == box_rec_titlescreen.height) {
        currentscreen = GameScreen::TITLESCREEN;
        PlaySound(GameAudio::buttonpress);
        SetSoundVolume(GameAudio::buttonpress, float(0.6));
      }
    }

    /** MOVE THE BOX */
    if (IsKeyPressed(KEY_S)) {
      box_rec_titlescreen.y += 100;
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
    }

    if (IsKeyPressed(KEY_W)) {
      box_rec_titlescreen.y -= 100;
      PlaySound(GameAudio::dialoge);
      SetSoundVolume(GameAudio::dialoge, float(0.1));
    }

    if (box_rec_titlescreen.y < Game::ScreenHeight / 2 - 50) {
      box_rec_titlescreen.y = Game::ScreenHeight / 2 - 50;
    }
    else if (box_rec_titlescreen.y > Game::ScreenHeight / 2 + 150) {
      box_rec_titlescreen.y = Game::ScreenHeight / 2 + 150;
}

    ///DRAW
    ///-----------------------------------------------------------------------------------------------------------------
     ClearBackground(BLACK);
     DrawTexture(PYRAMID_Screenshot,0,0, WHITE);
     DrawTexture(Pausescreen,0,0, WHITE);

    /** BUTTONS TITLESCREEN */
    Draw9Slice(Box, t_rec_start, thick, WHITE);
    Draw9Slice(Box, t_rec_settings, thick, WHITE);
    Draw9Slice(Box, t_rec_exit_game, thick, WHITE);
    Draw9Slice(Box_S, box_rec_titlescreen, thick, WHITE);

    //DrawText("RESUME GAME", Game::ScreenWidth / 2 - 117, Game::ScreenHeight / 2 - 30, 28, WHITE);
    //DrawText("FULLSCREEN", Game::ScreenWidth / 2 - 113, Game::ScreenHeight / 2 + 70, 30, WHITE);
    //DrawText("BACK TO MENU", Game::ScreenWidth / 2 - 117, Game::ScreenHeight / 2 + 170, 28, WHITE);
    DrawTextEx(textFont, "RESUME GAME", fontTextPosRESUME, fontSpecialSize, fontSpacing, WHITE);
    DrawTextEx(textFont, "FULLSCREEN", fontTextPosFULLSCREEN2, fontSpecialSize, fontSpacing, WHITE);
    DrawTextEx(textFont, "BACK TO MENU", fontTextPosMENU, fontSpecialSize, fontSpacing, WHITE);

    break;

    case GameScreen::OVERWORLD:

      /** sounds */
      if (IsSoundPlaying(GameAudio::titlescreenmusic)) { StopSound(GameAudio::titlescreenmusic); }
      if (IsSoundPlaying(GameAudio::battlemusic)) { StopSound(GameAudio::battlemusic); }
      if (IsSoundPlaying(GameAudio::indungeon)) { StopSound(GameAudio::indungeon); }
      if (IsSoundPlaying(GameAudio::pausemenu)) { StopSound(GameAudio::pausemenu); }

      if (!IsSoundPlaying(GameAudio::outdungeon))
      {
        PlaySound(GameAudio::outdungeon);
        SetSoundVolume(GameAudio::outdungeon, float(0.1));
      }
      if (IsSoundPlaying(GameAudio::outdungeon)) {}

      /** update *//*
      if (IsKeyPressed(KEY_C))
      {
        std::cout << "X: " << nemo->NemoPosition.x << endl;
        std::cout << "Y: " << nemo->NemoPosition.y << endl;
      }*/
      if (IsKeyPressed(KEY_ESCAPE)) {
        level->currentscreen = Game::Level::GameScreen::PAUSEMENU_OVERWORLD;
      }

      //teleport conditions
      if (teleportcollisionOVERWORLDtoPYRAMID) { //if the collision bool is true, nemo is transported to PYRAMIDE
        PlaySound(GameAudio::teleport);
        SetSoundVolume(GameAudio::teleport, float(0.5));
        level->currentscreen = Game::Level::GameScreen::PYRAMIDE;
        nemo->NemoPosition.x = doorPositionX - 670;
        nemo->NemoPosition.y = doorPositionY + 700;
      }

      /** draw */
      break;

    case GameScreen::PYRAMIDE:
      ///sounds
      if (IsSoundPlaying(GameAudio::battlemusic)) { StopSound(GameAudio::battlemusic); }
      if (IsSoundPlaying(GameAudio::outdungeon)) { StopSound(GameAudio::outdungeon); }
      if (IsSoundPlaying(GameAudio::pausemenu)) { StopSound(GameAudio::pausemenu); }

      if (!IsSoundPlaying(GameAudio::indungeon))
      {
        PlaySound(GameAudio::indungeon);
        SetSoundVolume(GameAudio::indungeon, float(0.1));
      }
      if (IsKeyPressed(KEY_C))
      {
        std::cout << "X: " << nemo->NemoPosition.x << endl;
        std::cout << "Y: " << nemo->NemoPosition.y << endl;
      }
/*
      */

      //Teleport();

      //teleport conditions
      if (teleportcollisionPYRAMIDtoOVERWORLD) { //if the collision bool is true, nemo is transported to PYRAMIDE
        PlaySound(GameAudio::teleport);
        SetSoundVolume(GameAudio::teleport, float(0.5));
        level->currentscreen = Game::Level::GameScreen::OVERWORLD;
        nemo->NemoPosition.x = doorPositionX + 20;
        nemo->NemoPosition.y = doorPositionY + 60;
      }
      if (teleportcollisionPYRAMIDtoENDSCREEN) { //if the collision bool is true, nemo is transported to the ENDSCREEN
        level->currentscreen = Game::Level::GameScreen::ENDSCREEN;
      }
      if (IsKeyPressed(KEY_ESCAPE)){
        level->currentscreen = Game::Level::GameScreen::PAUSEMENU_PYRAMID;
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
     // DrawText(TextFormat("Time: %i", framescounter), player->set_rec().x + 100, player->set_rec().y, 20, GREEN);
     // DrawFPS(player->set_rec().x + 200, player->set_rec().y);

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
      //DrawText(TextFormat("ENERGY: %i", energy), 500, 300, 20, BLACK);
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

    case GameScreen::ENDSCREEN:

      ClearBackground(BLACK);

      if (IsKeyPressed(KEY_SPACE)) {
        //currentscreen = GameScreen::TITLESCREEN;
        exit(0);
      }

      endscreen.update();
      endscreen.draw();
      break;

//GameOver Screen
    case GameScreen::GAMEOVER:
      DrawTexture(gameover, GetScreenWidth() / 2 - 15, GetScreenHeight() / 2 - 20, WHITE);
      DrawText("GAME OVER!", GetScreenWidth() / 2 + 280, GetScreenHeight() / 2 + 100, 50, RED);
      DrawText("PRESS <<ENTER>> TO RESTART", GetScreenWidth()/ 2 + 280, GetScreenHeight() / 2 + 150, 20, YELLOW);
      if (IsKeyPressed(KEY_ENTER))
      {
        //currentscreen = GameScreen::TITLESCREEN;
        exit(0);
      }
    break;
    }
  }


//======================================================================================================================

void Game::Level::Teleport() {

  // teleport coordinates (JUST FOR DRAW)
  teleportrecOVERWORLDtoPYRAMID = { doorPositionX, doorPositionY, doortileX, doortileY }; // rectangle in overworld to pyramid
  teleportrecPYRAMIDtoOVERWORLD = { doorPositionX - 685, doorPositionY + 780, doortileX, doortileY }; //rectangle in pyramid to overworld
  teleportrecPYRAMIDtoENDSCREEN = { doorPositionX + 528 , doorPositionY - 168, doortileX, doortileY }; //rectangle in pyramid to endscreen

  // collision check with the door1 & nemo (RECTANGLES FOR COLLISION)
  teleportcollisionOVERWORLDtoPYRAMID = CheckCollisionRecs(teleportrecOVERWORLDtoPYRAMID, nemo->nemorec); //check collision between door1 and nemo
  teleportcollisionPYRAMIDtoOVERWORLD = CheckCollisionRecs(teleportrecPYRAMIDtoOVERWORLD, nemo->nemorec);
  teleportcollisionPYRAMIDtoENDSCREEN = CheckCollisionRecs(teleportrecPYRAMIDtoENDSCREEN, nemo->nemorec);
}

//Destructor
Game::Level::~Level()
{
  std::cout<<"Destructor Level\n";
  delete enemy;
  delete shadow;
  delete pharaoh;
}
/*
void Game::Level::BATTLESTART()
{

  startrec = {Startrec.x, Startrec.y, 1428, 144};
  DrawRectangleRec(startrec, Color {});
  DrawTextureRec(BattleStart,start_frameRec, {Startrec.x, Startrec.y}, WHITE);

  start_framesCounter++;

  if (start_framesCounter >= (60 / start_framesSpeed))
  {
    start_framesCounter = 0;
    start_currentFrame++;

    if (start_currentFrame > 7)
    {
      start_currentFrame = 0;
      //Level::currentscreen = GameScreen::COMBAT;
    }

    start_frameRec.x = (float)start_currentFrame * (float)BattleStart.width / 7;
  }
}*/