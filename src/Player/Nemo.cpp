#include "Nemo.h"

void Game::Nemo::Update() {

  ///NEMO WALKING SOUND
  while (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) {
    if (!IsSoundPlaying(GameAudio::walking)){
      PlaySound(GameAudio::walking);
      SetSoundVolume(GameAudio::walking, float(0.4));
      break;
    }break;
  }

  ///NEMOS MOVEMENT
  if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D) || IsKeyDown(KEY_LEFT_SHIFT))
  { keypressed = true;}
  else { keypressed = false; }

  //if (IsKeyReleased(KEY_W)) { DrawTexture(FrontStil, NemoPosition.x, NemoPosition.y, WHITE); }
  //if (IsKeyReleased(KEY_A)) { DrawTexture(LeftStil, NemoPosition.x, NemoPosition.y, WHITE); }
  //if (IsKeyReleased(KEY_S)) { DrawTexture(BackStil, NemoPosition.x, NemoPosition.y, WHITE); }
  //if (IsKeyReleased(KEY_D)) { DrawTexture(RightStil, NemoPosition.x, NemoPosition.y, WHITE); }

  if (!keypressed){
    timesinceIdle += GetFrameTime();
    if (timesinceIdle >= 10){
      Direction = direction::STAND;

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        //Framecounter
        if (currentFrame > 3){
          timesinceIdle = 0;
          currentFrame = 0;
        }
        StandframeRec.x = (float)currentFrame * (float)Stand.width / 4;
      }
    }
  }

  if (active) {

      if (IsKeyDown(KEY_LEFT_SHIFT)) // Sprinting
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

      ///WALKING DIRECTIONS
    // animation and movement
    if (IsKeyDown(KEY_W)) {
      NemoPosition.y -= walkspeed; // run forwards
      Direction = direction::UP;      

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Front.width / 4;
      }
    }
    if (IsKeyDown(KEY_A)) {
      NemoPosition.x -= walkspeed; // run left ->needs change
      Direction = direction::LEFT;      

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Left.width / 4;
      }
    }
    if (IsKeyDown(KEY_S)) {
      NemoPosition.y += walkspeed; // run backwards
      Direction = direction::DOWN;      

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Right.width / 4;
      }
    }
    if (IsKeyDown(KEY_D)) {
      NemoPosition.x += walkspeed; // run right
      Direction = direction::RIGHT;

      // animation
      framesCounter++;

      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        //Framecounter
        if (currentFrame > 3)
          currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)Right.width / 4;
      }
    }else{};
  }
}

  void Game::Nemo::Draw() {
    if (active) {
      nemorec = { NemoPosition.x + 8, NemoPosition.y + 16, nemowidth, nemoheight }; // The Attributes are set here.
      if (IsKeyDown(KEY_R)){
        DrawRectangleRec(nemorec, GREEN);
      }

      // Draw nemo walking animation
      switch (Direction)
      {
      case direction::UP:

        DrawTextureRec(Back, frameRec, NemoPosition, WHITE); // Draw nemo animation backwards
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

      case direction::STAND:
        DrawTextureRec(Stand, StandframeRec, NemoPosition, WHITE); // Draw nemo animation right
        break;
      }      
    } 
  }
 

Game::Nemo::~Nemo() {
  UnloadTexture(Stand);
  UnloadTexture(Front);
  UnloadTexture(Back);
  UnloadTexture(Right);
  UnloadTexture(Left);
 }


