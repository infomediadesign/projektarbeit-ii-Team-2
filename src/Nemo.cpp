#include "Nemo.h"

void Game::Nemo::Update() 
{  
    /*there are many "or" stuff and it makes the code look like Spaghetti Bolognese, 
    but this Code allows the user to press only one Key while walking. It is also a lazy way to prevent the user
    to run fast while running vertically.*/ 

   if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D) //
      || IsKeyDown(KEY_W) && IsKeyDown(KEY_A) 
      || IsKeyDown(KEY_S) && IsKeyDown(KEY_D) 
      || IsKeyDown(KEY_S) && IsKeyDown(KEY_A)
      || IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) 
   {
     walkspeed = 0;
     framesCounter = 0;
   }  
   else if (IsKeyDown(KEY_LEFT_SHIFT)) // Sprinting with Shift is so Giga Chad
   {
     walkspeed = 2.0;
   } 
   else 
   {
     walkspeed = 1.5;
   }

  // animation and movement
  if (IsKeyDown(KEY_W)) 
  {
    position.y -= walkspeed; // run forwards

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
    position.x -= walkspeed; // run left ->needs change
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
    position.y += walkspeed; // run backwards
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
    position.x += walkspeed; // run right
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
