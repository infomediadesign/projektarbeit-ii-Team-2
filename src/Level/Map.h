/*#pragma once

#include "../INCLUDES.h"

class Map
{
public:
std::vector<Rectangle> collisionRectangles;

nlohmann::json levelMap;
nlohmann::json tilesetDescription;
Texture2D tileAtlasTexture;

//structs for tilemaps
struct
{
  Texture2D tilemap;
  int tileWidth;
  int tileMapWidth;
  int rowLength;
} tilemapData;

struct
{
  std::vector<int> layerGround;
  std::vector<int> layerObjects;
  std::vector<int> animation;
  std::vector<int> layerCollision;
};
};*/