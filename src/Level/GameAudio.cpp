#include <raylib.h>

namespace GameAudio {
  Sound collision, walking, attack, openchest, dialoge, trapdoor, unlockdoor, pickupitem;

  void Load() {
    collision = LoadSound("assets/audio/sfx/41_Cling_climb_02_.wav");
    walking = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");    
    attack = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");
    openchest = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");
    dialoge = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");
    trapdoor = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");
    unlockdoor = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");
    pickupitem = LoadSound("assets/audio/sfx / 12_Step_wood_03.wav");
  }

  void Unload() {
    UnloadSound(collision);
    UnloadSound(walking);
    UnloadSound(attack);
    UnloadSound(openchest);
    UnloadSound(dialoge);
    UnloadSound(trapdoor);
    UnloadSound(unlockdoor);
    UnloadSound(pickupitem);
  }
} // namespace GameAudio