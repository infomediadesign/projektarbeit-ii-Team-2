#include "Collision.h"

void Collision::update() { ;

  /** Check collision between Nemo and Wall/ Interactables... */
  wallCollision = false;
  for (auto &rect : map->collisionRectangles) { //change the vector into a rectangle
    if (CheckCollisionRecs(rect, nemo->nemorec)) { //check the collision between said rectangle and nemo
      wallCollision = true; //set the wallcollision to true...
      break;
    }
  }

  if (wallCollision) { //if wallcollision true then nemo does...

    std::cout << "HIT!";

    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) { // Left
      //nemo->NemoPosition.x += 10.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
    if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) { // Right
      //nemo->NemoPosition.x -= 10.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
    if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) { // Up
      //nemo->NemoPosition.y += 10.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
    if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) { // Down
      //nemo->NemoPosition.y -= 10.0;
      PlaySound(GameAudio::collision);
      SetSoundVolume(GameAudio::collision, float(0.07));
    }
  }
}

void Collision::epanoxCollision() { // Epanox collision

  // Check collision between Nemo and Epanox
  EpanoxCollision = CheckCollisionRecs(EpanoxRec, nemo->nemorec);


  while (EpanoxCollision) {
    nemo->walkspeed = 0;
    nemo->Update();
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)) {
      text = true;
      //nemo->active = false;

      break;
    }

    if (!EpanoxCollision){text = false;}

    if (text) {
      DrawRectangle(827, 561, 400, 100, DARKGRAY);
      if (IsKeyPressed(KEY_SPACE)){
        textState + 1;
      }

      if (IsKeyPressed(KEY_SPACE) && textState == 0) {
        textState = 1;
      } else if (IsKeyPressed(KEY_SPACE) && textState == 1) {
        textState = 2;
      } else if (IsKeyPressed(KEY_SPACE) && textState == 2) {
        textState = 3;
      } else if (IsKeyPressed(KEY_SPACE) && textState == 3) {
        textState = 4;
      }

      switch (textState) {
      default: break;
      case 1: DrawText("Welcome traveller", 850, 600, 10, WHITE); break;
      case 2: DrawText("Having Fun? ", 850, 600, 10, WHITE); break;
      case 3: DrawText("Well i dont care what think, so fuck off!", 850, 600, 10, WHITE); break;
      case 4: textState = 1;
        text = false; break;
      }
    }
    break;
  }

}


void Collision::draw() {

}


