#include "Nemo.h"
#include "Level.h"
#include <iostream>

void Game::Nemo::Update() 
{ 
    /*there are many "or" stuff and it makes the code look like Spaghetti Bolognese,
    but this Code allows the user to press only one Key while walking. It is also a lazy way to prevent the user
    to run fast while running vertically.*/
  if (active) {
    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D) //
        || IsKeyDown(KEY_W) && IsKeyDown(KEY_A) || IsKeyDown(KEY_S) && IsKeyDown(KEY_D) ||
        IsKeyDown(KEY_S) && IsKeyDown(KEY_A) || IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) {
      walkspeed     = 0;
      framesCounter = 0;
    } else if (IsKeyDown(KEY_LEFT_SHIFT)) // Sprinting with Shift is so Giga Chad
    {
      walkspeed = 2.0;
    } else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D) ||
               IsKeyDown(KEY_A)) // Better alternative than else walkspeed 1.5
    {
      walkspeed = 1.5;
    } else if (!IsKeyDown(KEY_W) || !IsKeyDown(KEY_S) || !IsKeyDown(KEY_D) ||
               !IsKeyDown(KEY_A)) // when No Key is pressed, the Walkspeed is set to 0;
    {
      walkspeed = 0;
    }

    std::cout << walkspeed << "\n";

    // std::cout << walkspeed << "\n"; //This is a test to see Nemos current Walkspeed

    // animation and movement
    if (IsKeyDown(KEY_W)) {
      NemoPosition.y -= walkspeed; // run forwards

      PlaySound(fxMp3); // play sfx

      Direction = direction::UP;

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 2)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Front.width / 3;
      }
    }
    if (IsKeyDown(KEY_A)) {
      NemoPosition.x -= walkspeed; // run left ->needs change
      PlaySound(fxMp3);            // play sfx
      Direction = direction::LEFT;

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 2)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Left.width / 3;
      }
    }
    if (IsKeyDown(KEY_S)) {
      NemoPosition.y += walkspeed; // run backwards
      PlaySound(fxMp3);            // play sfx
      Direction = direction::DOWN;

      // animtaion
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 2)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Right.width / 3;
      }
    }
    if (IsKeyDown(KEY_D)) {
      NemoPosition.x += walkspeed; // run right
      PlaySound(fxMp3);            // play sfx
      Direction = direction::RIGHT;

      // animataion
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 2)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Right.width / 3;
      }
    }
  }
}

void Game::Nemo::Draw() {
  if (active) {

    nemorec = { NemoPosition.x + 8, NemoPosition.y + 8, nemowidth, nemoheight }; // The Attributes are set here.
    DrawRectangleRec(nemorec, Color(00));
    // Draw nemo walking animation

    switch (Direction) // A simple Enum and a Switch case solved all the problem before... I swear me beeing Retarded is
                       // such a nuisance :(
    {
    case direction::UP:

      DrawTextureRec(Back, frameRec, NemoPosition, WHITE); // Draw nemo animation backwards
      nemorec;
      break;

    case direction::DOWN:

      DrawTextureRec(Front, frameRec, NemoPosition, WHITE); // Draw nemo animation forwards
      break;

    case direction::LEFT:

      DrawTextureRec(Left, frameRec, NemoPosition, WHITE); // Draw nemo animation left
      break;

    case direction::RIGHT:

      DrawTextureRec(Right, frameRec, NemoPosition, WHITE); // Draw nemo animation right
      break;
    }
  }
}
  Game::Nemo::~Nemo() 
{
  UnloadTexture(Front);
  UnloadTexture(Back);
  UnloadTexture(Right);
  UnloadTexture(Left);
}
