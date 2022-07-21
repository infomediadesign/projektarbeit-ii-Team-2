#pragma once

#include "raylib.h"
#include <vector>
#include <iostream>

namespace Game {

  class Combat_Button
  {
      public:
        Texture2D texture_active;
        Texture2D texture_inactive;

        int pos_x;
        int pos_y;

        Combat_Button() = default;
        Combat_Button(Texture2D texture_active, Texture2D texture_inactive, int pos_x, int pos_y, bool active);

        void update();

        ~Combat_Button();

        bool active;
        Texture2D getTexture();


  };

}