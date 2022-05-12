#include "Nemo.h"

void Game::Nemo::Update() 
{  

  // animation and movement
  if (IsKeyDown(KEY_W)) 
  {
    position.y -= 2.0f; // run forwards

    PlaySound(fxMp3);  // play sfx

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
  if (IsKeyDown(KEY_A)) 
  {
    position.x -= 2.0f; // run left ->needs change
    PlaySound(fxMp3);  // play sfx
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
  if (IsKeyDown(KEY_S)) 
  {
    position.y += 2.0f; // run backwards
    PlaySound(fxMp3);  // play sfx
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
  if (IsKeyDown(KEY_D)) 
  {
    position.x += 2.0f; // run right
    PlaySound(fxMp3);  // play sfx
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

void Game::Nemo::Draw() {
  // Draw nemo walking animation

  switch (Direction) //A simple Enum and a Switch case solved all the problem before... I swear me beeing Retarded is such a nuisance :(
  { 
    case direction::UP: 
      
    DrawTextureRec(Back, frameRec, position, WHITE); // Draw nemo animation backwards
    break;

    case direction::DOWN: 
       
    DrawTextureRec(Front, frameRec, position, WHITE); // Draw nemo animation forwards
    break;

    case direction::LEFT: 

    DrawTextureRec(Left, frameRec, position, WHITE); // Draw nemo animation left
    break;

    case direction::RIGHT: 

    DrawTextureRec(Right, frameRec, position, WHITE); // Draw nemo animation right
    break;
  }
}
  Game::Nemo::~Nemo() 
{
  UnloadTexture(Front);
  UnloadTexture(Back);
  UnloadTexture(Right);
  UnloadTexture(Left);
}
