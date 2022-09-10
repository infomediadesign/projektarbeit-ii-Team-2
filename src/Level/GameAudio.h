#pragma once

#include "../INCLUDES.h"

namespace GameAudio {
  extern Sound collision, walking, attack, openchest, dialoge, trapdoor, unlockdoor, pickupitem, buttonpress,
    titlescreenmusic, pausemenu, indungeon, outdungeon, battlemusic, epanoxsfx, teleport;

  void Load();
  void Unload();
} // namespace GameAudio
