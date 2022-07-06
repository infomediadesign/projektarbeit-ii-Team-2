#include "TextureManager.h"

namespace GameTextures {
  Texture outside_pyramide_mapsheet, Stand, Front, Back, Left, Right;

void Load()
{
  //map
  outside_pyramide_mapsheet = LoadTexture("Map Files/Außenbereich_Pyramide_Sheet.png");
  //nemo
  Stand = LoadTexture("assets/graphics/Nemo_StandingMutze.png");
  Front = LoadTexture("assets/graphics/Character/Nemo_Walkfront.png");
  Back  = LoadTexture("assets/graphics/Character/Nemo_Walkback.png");
  Left  = LoadTexture("assets/graphics/Character/Nemo_Walkleft.png");
  Right = LoadTexture("assets/graphics/Character/Nemo_Walkright.png");
  //monster
}

void Unload()
{
  UnloadTexture(outside_pyramide_mapsheet);
  UnloadTexture(Stand);
  UnloadTexture(Front);
  UnloadTexture(Back);
  UnloadTexture(Left);
  UnloadTexture(Right);
}

} // namespace Game

