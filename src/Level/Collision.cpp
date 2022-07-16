#include "Collision.h"

void Collision::update()
{
  rectangleObject = {400, 703 / 2, 32, 32};

  // Check collision between Nemo and Rectangle
  collisionObject = CheckCollisionRecs(rectangleObject, nemo->nemorec);


  // Get collision rectangleCollision (only on collision)
  if (collisionObject)
      rectangleCollision = GetCollisionRec(rectangleObject, nemo->nemorec);

    if (collisionObject) { //Change the Floats to Ints, that should solve the bugs
      if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { //Left
        nemo->NemoPosition.x += 10.0; //pushback
        PlaySound(GameAudio::collision); //play Collision Sound
        SetSoundVolume(GameAudio::collision, float(0.07)); //adjust its volume
        sleep_for(1s); // stunned for x sec
      }
      if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
        nemo->NemoPosition.x -= 10.0;
        PlaySound(GameAudio::collision);
        SetSoundVolume(GameAudio::collision, float(0.07));
        sleep_for(1s); // disable input -> (being stunned after colliding)
      }
      if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
        nemo->NemoPosition.y += 10.0;
        PlaySound(GameAudio::collision);
        SetSoundVolume(GameAudio::collision, float(0.07));
        sleep_for(1s); // disable input -> (being stunned after colliding)
      }
      if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
        nemo->NemoPosition.y -= 10.0;
        PlaySound(GameAudio::collision);
        SetSoundVolume(GameAudio::collision, float(0.07));
        sleep_for(1s); // disable input -> (being stunned after colliding)
      }
    }
}

void Collision::draw()
{
  rectangleObject = {400, 703 / 2, 32, 32};
  DrawRectangleRec(rectangleObject, YELLOW);
}

