#include "Collision.h"

void Collision::update() {
  /** Check collision between Nemo and Wall/ Interactables... */

  wallCollision = false;
  for (Rectangle rect : map->collisionRectangles) {
    if (CheckCollisionRecs(rect, nemo->nemorec)) {
      wallCollision = true;
      break;
    }
  }

  if (wallCollision) {

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
}/*

void Collision::checkForCollisions() {

}
*/
  /*
bool checkForCollisions(vector<Rectangle> walls)
{
  Rectangle playercollision = this->getCollision();
  for (int i = 0; i < walls.size(); ++i) {
    if(checkForCollisions(playercollision, walls[i]);
    return true;
  }
  return false;
}
*/

Rectangle Collision::getCollision()
{
  return{nemo->NemoPosition.x, nemo->NemoPosition.y, 32, 32};
}


void Collision::draw()// can be deleted
{
  //rectangleObject = {400, 703 / 2, 32, 32};
  //DrawRectangleRec(rectangleObject, YELLOW);
}
void Collision::epanoxCollision() {

  // Check collision between Nemo and Epanox
  EpanoxCollision = CheckCollisionRecs(EpanoxRec, nemo->nemorec);

  if (EpanoxCollision) {
    // std::cout << "Dialog start" << endl;

    fstream dialog_txt_file;
    dialog_txt_file.open("assets/dialog_test_text.txt", ios::in); // open a file to perform read operation using file object
    if (dialog_txt_file.is_open()) { // checking whether the file is open

      if (IsKeyPressed(KEY_SPACE)) {
        string tp;
        while (getline(dialog_txt_file, tp)) { // read data from file object and put it into string.

          // cout << tp << "\n"; //print the data of the string

          printf("%s\n", tp.c_str());
        }
        dialog_txt_file.close(); // close the file object.
      }
    }
  }
}

