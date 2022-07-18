#pragma once

#include "../INCLUDES.h"

class Map
{
public:
  /*
  //initialization
  std::ifstream tilesetDescriptionFile("assets/graphics/map/Level1/PhyramidSheet.json");
  assert(tilesetDescriptionFile.is_open());
  nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
  tilesetDescriptionFile.close();

  std::ifstream levelMapFile("assets/graphics/map/Level1/PhyramidEntry.json");
  assert(levelMapFile.is_open());
  nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
  levelMapFile.close();

  Texture2D tileAtlasTexture = LoadTexture("assets/graphics/Tiles-Atlas/Pyramiden_SheetJamey.png"); //needs to be updated
  */

  void mapDraw();
};