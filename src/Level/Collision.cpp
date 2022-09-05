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
    DrawText("[F]", nemo->NemoPosition.x + 10, nemo->NemoPosition.y - 10, 2, BLACK);
    if (IsKeyPressed(KEY_F)) {
      dialogbox = true;
      break;
    }
    if (dialogbox) {
      //DrawRectangle(nemo->NemoPosition.x - 190, nemo->NemoPosition.y + 100, 400, 100, DARKGRAY);
      DrawRectangle(827,561, 400, 100, DARKGRAY);
      std::cout << "Dialog start" << endl;
      dialog.DialogStart();
      break;
    }
    break;

    /*
     fstream dialog_txt_file;
 dialog_txt_file.open("assets/dialog_test_text.txt", ios::in); // open a file to perform read operation using file
 object if (dialog_txt_file.is_open()) { // checking whether the file is open

 if (IsKeyPressed(KEY_SPACE)) {
  string tp;
  while (getline(dialog_txt_file, tp)) { // read data from file object and put it into string.

    // cout << tp << "\n"; //print the data of the string

    printf("%s\n", tp.c_str());
  }
  dialog_txt_file.close(); // close the file object.
 }
 }
     */
  }
}

void Collision::draw() {

}


