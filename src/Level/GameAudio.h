#pragma once

#include "raylib.h"

namespace GameAudio {
  extern Sound collision, walking, attack, chest, dialoge, trapdoor, unlockdoor, pickupitem;

  void Load();
  void Unload();
} // namespace GameAudio