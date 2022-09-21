#include "GameAudio.h"

namespace GameAudio {
  Sound collision, walking, attack, openchest, dialoge, trapdoor, unlockdoor, pickupitem, buttonpress, titlescreenmusic,
    pausemenu, indungeon, outdungeon, battlemusic, epanoxsfx, teleport, dooropen, dooropen2;

  void Load() {
    // sfx
    collision   = LoadSound("assets/audio/sfx/41_Cling_climb_02_.wav");
    walking     = LoadSound("assets/audio/sfx/nemowaling4.wav");
    attack      = LoadSound("assets/audio/sfx/Attack02.wav");
    openchest   = LoadSound("assets/audio/sfx/openchest.wav");
    dialoge     = LoadSound("assets/audio/sfx/038_Dialogue_02_Single.wav");
    trapdoor    = LoadSound("assets/audio/sfx/Drop.mp3");
    unlockdoor  = LoadSound("assets/audio/sfx/doorunlock.mp3");
    pickupitem  = LoadSound("assets/audio/sfx/046_Pick_item_01.wav");
    buttonpress = LoadSound("assets/audio/sfx/020_Confirm_10.wav");
    epanoxsfx   = LoadSound("assets/audio/sfx/greeting_10_karen.wav");
    teleport    = LoadSound("assets/audio/sfx/SciFiThinBeaming PE1081103.mp3");
    dooropen    = LoadSound("assets/audio/sfx/DoorOpens.wav");
    dooropen2    = LoadSound("assets/audio/sfx/DoorOpens.wav");

    // music
    titlescreenmusic = LoadSound("assets/audio/sfx/Forever Lost.wav");    
    pausemenu        = LoadSound("assets/audio/tracks/Hair-Trigger-WST011601.mp3");
    indungeon        = LoadSound("assets/audio/sfx/cave_theme_2.wav");
    outdungeon       = LoadSound("assets/audio/sfx/arpegio01_loop-45094.mp3");
    //outdungeon       = LoadSound("assets/audio/sfx/Beginning of time.wav");
    battlemusic      = LoadSound("assets/audio/sfx/chibi-robot-b.ogg");   
  }

  void StopMusic() {
    StopSound(GameAudio::collision);
    StopSound(GameAudio::walking);
    StopSound(GameAudio::attack);
    StopSound(GameAudio::openchest);
    StopSound(GameAudio::dialoge);
    StopSound(GameAudio::trapdoor);
    StopSound(GameAudio::unlockdoor);
    StopSound(GameAudio::pickupitem);
    StopSound(GameAudio::buttonpress);
    StopSound(GameAudio::titlescreenmusic);
    StopSound(GameAudio::pausemenu);
    StopSound(GameAudio::indungeon);
    StopSound(GameAudio::outdungeon);
    StopSound(GameAudio::battlemusic);
    StopSound(GameAudio::epanoxsfx);
    StopSound(GameAudio::teleport);
    StopSound(GameAudio::dooropen);
    StopSound(GameAudio::dooropen2);
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
    UnloadSound(dooropen);
    UnloadSound(dooropen2);
  }
} // namespace GameAudio
