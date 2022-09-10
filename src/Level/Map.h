#pragma once

#include "../INCLUDES.h"
#include "Level.h"

#include <fstream>
#include <nlohmann/json.hpp>

class LevelMap
{
public:
  Game::Level level;

std::vector<Rectangle> collisionRectangles;

nlohmann::json levelMap;
nlohmann::json levelMapDungeon;
nlohmann::json tilesetDescription;

Texture2D tileAtlasTexture = LoadTexture("assets/graphics/map/Level1/Egypt-Sheet.png");

/*
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
 //std::vector<int> layerObject;
 std::vector<bool> layerObject;
 std::vector<int> layerInteractables;
 //std::vector<bool> layerInteractables;
 //std::vector<int> layerCollision; //TODO make a Collision Layer on a Gridlayer aswell...
 int mapWidth;
 int mapHeight;
} mapData; //Wird nicht gelesen!
 */

LevelMap();
//void update();
void draw();
void drawOVERWORLD();
void drawPYRAMID();

~LevelMap();

};
