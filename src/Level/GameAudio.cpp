#include "GameAudio.h"

namespace GameAudio {
  Sound collision, walking, attack, openchest, dialoge, trapdoor, unlockdoor, pickupitem, buttonpress, titlescreenmusic,
    pausemenu, indungeon, outdungeon, battlemusic, epanoxsfx, teleport;

  void Load() {
    // sfx
    collision   = LoadSound("assets/audio/sfx/41_Cling_climb_02_.wav");
    //walking     = LoadSound("assets/audio/sfx/12_Step_wood_03.wav");
    walking     = LoadSound("assets/audio/sfx/nemowaling4.wav");
    attack      = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    openchest   = LoadSound("assets/audio/sfx/openchest.wav");
    dialoge     = LoadSound("assets/audio/sfx/038_Dialogue_02_Single.wav"); // not right sound yet
    trapdoor    = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    unlockdoor  = LoadSound("assets/audio/sfx/doorunlock.mp3"); // not right sound yet
    pickupitem  = LoadSound("assets/audio/sfx/046_Pick_item_01.wav"); // not right sound yet
    buttonpress = LoadSound("assets/audio/sfx/020_Confirm_10.wav"); // not right sound yet
    epanoxsfx   = LoadSound("assets/audio/sfx/greeting_10_karen.wav");
    teleport    = LoadSound("assets/audio/sfx/SciFiThinBeaming PE1081103.mp3");

    // music
    titlescreenmusic = LoadSound("assets/audio/sfx/Forever Lost.wav");    
    pausemenu        = LoadSound("assets/audio/tracks/Hair-Trigger-WST011601.mp3"); // not right sound yet
    indungeon        = LoadSound("assets/audio/sfx/cave_theme_2.wav");    
    outdungeon       = LoadSound("assets/audio/sfx/Beginning of time.wav");
    battlemusic      = LoadSound("assets/audio/sfx/chibi-robot-b.ogg");   
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
    UnloadSound(buttonpress);
    UnloadSound(titlescreenmusic);
    UnloadSound(pausemenu);
    UnloadSound(indungeon);
    UnloadSound(outdungeon);
    UnloadSound(battlemusic);
    UnloadSound(epanoxsfx);
    UnloadSound(teleport);
  }
} // namespace GameAudio
