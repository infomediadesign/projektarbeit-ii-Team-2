#pragma once

#include "raylib.h"

namespace GameAudio {
  extern Sound collision, walking, attack, chest, dialoge, trapdoor, unlockdoor, pickupitem, titlescreenmusic;

  void Load();
  void Unload();
} // namespace GameAudio