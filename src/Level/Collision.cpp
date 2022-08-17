#include "Collision.h"

//TODO better stun

void Collision::update() {
  // Collision with a drawn Rectangle... this was a test

  rectangleObject = { 400, 703 / 2, 32, 32 };

  // Check collision between Nemo and Rectangle
  collisionObject = CheckCollisionRecs(rectangleObject, nemo->nemorec);

  // Get collision rectangleCollision (only on collision)
  if (collisionObject)
    rectangleCollision = GetCollisionRec(rectangleObject, nemo->nemorec);

  if (collisionObject) {                                 // Change the Floats to Ints, that should solve the bugs
    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {       // Left
      nemo->NemoPosition.x += 10.0;                      // pushback
      PlaySound(GameAudio::collision);                   // play Collision Sound
      SetSoundVolume(GameAudio::collision, float(0.07)); // adjust its volume
      // sleep_for(1s); // stunned for x sec
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
  /**-----------------------------------------------------------------------------------------------------------------*/
/*

    // Check collision between Nemo and Wall/ Interactables...

    wallCollision = CheckCollisionRecs(map->collisionRectangles, nemo->nemorec);
    //wallCollision = CheckCollisionRecs(map->vector <Rectangle> collisionRectangles, nemo->nemorec);

    if (wallCollision) { //Change the Floats to Ints, that should solve the bugs
      if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { //Left
        nemo->NemoPosition.x += 10.0; //pushback
        PlaySound(GameAudio::collision); //play Collision Sound
        SetSoundVolume(GameAudio::collision, float(0.07)); //adjust its volume
      }
      if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
        nemo->NemoPosition.x -= 10.0;
        PlaySound(GameAudio::collision);
        SetSoundVolume(GameAudio::collision, float(0.07));
      }
      if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
        nemo->NemoPosition.y += 10.0;
        PlaySound(GameAudio::collision);
        SetSoundVolume(GameAudio::collision, float(0.07));
      }
      if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
        nemo->NemoPosition.y -= 10.0;
        PlaySound(GameAudio::collision);
        SetSoundVolume(GameAudio::collision, float(0.07));
      }
    }
}

void Collision::checkForCollisions() {}


bool checkForCollisions(vector<Rectangle> walls)
{
  Rectangle playercollision = this->getCollision();
  for (int i = 0; i < walls.size(); ++i) {
    if(checkForCollisions(playercollision, walls[i]);
    return true;
  }
  return false;
}

bool checkForCollisions(vector<Rectangle> walls)
{
  Rectangle playercollision = this->getCollision();
  for (int i = 0; i < walls.size(); ++i) {
    if(checkForCollisions(playercollision, walls[i]);
    return true;
  }
  return false;
}

/**Rectangle nemo::getCollision()
{
  return{nemo->NemoPosition.x, nemo->NemoPosition.y, 32, 32}
}*/

Rectangle Collision::getCollision()
{
  return{nemo->NemoPosition.x, nemo->NemoPosition.y, 32, 32};
}


void Collision::draw()
{
  rectangleObject = {400, 703 / 2, 32, 32};
  DrawRectangleRec(rectangleObject, YELLOW);
}
