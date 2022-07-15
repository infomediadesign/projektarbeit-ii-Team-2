#pragma once

#include "../INCLUDES.h"

#include "TextureManager.h"
/*
class Map{
public:
  std::ifstream tilesetDescriptionFile("assets/graphics/map/PhyramidenEingangNeu.json");
  nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
  tilesetDescriptionFile.close();

  std::ifstream levelMapFile("assets/graphics/map/PhyramidenEingangNeu.json");
  nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
  levelMapFile.close();

  Texture2D tileAtlasTexture = LoadTexture("assets/graphics/Tiles-Atlas/Pyramiden_SheetJamey.png");
  //Texture2D tileAtlasTexture = LoadTexture((tilesetDescription["image"].get<std::string>()).c_str());

  Vector2 vec;
  Rectangle rec;
};
*/

/*
//schwieriger als gedacht, hier sind ansätze von Olis Gruppe, und von Christoph


//----Oli map.h---------------------------------------------------------------------------------------------------------
std::vector<Rectangle> collisionRectangles;

nlohmann::json levelMap;
Texture2D tileAtlasTexture;
nlohmann::json tilesetDescription;

//structs for tilemaps
struct {
  Texture2D tilemap;
  int tileWidth;
  int tileMapWidth;
  int rowLength;
}tilemapData;

struct {
  std::vector<int> layerGround;
  std::vector<int> layerObjects;
  std::vector<int> layerDecoration;
  std::vector<int> layerForegroundTransparent;
  std::vector<int> layerForegroundOpaque;
  std::vector<int> layerCollision;
  int mapWidth;
  int mapHeight;
}mapData;
//----Oli map.h---------------------------------------------------------------------------------------------------------


//----Oli map.cpp-------------------------------------------------------------------------------------------------------
//goes through all the infos of the layers
for (auto const& layer : levelMap["layers"]) {
  if(layer["name"] == "Ground") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerGround.push_back(((int)tileID)-1);
    }
  }
  if(layer["name"] == "Interactables") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerObjects.push_back(((int)tileID)-1);
    }
  }
  if(layer["name"] == "Decoration") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerDecoration.push_back(((int)tileID)-1);
    }
  }
  if(layer["name"] == "Interactables") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerObjects.push_back(((int)tileID)-1);
    }
  }
  //layer ForegroundTransparent
  if(layer["name"] == "Foreground transparent") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerForegroundTransparent.push_back(((int)tileID)-1);
    }
  }
  //layer ForegroundOpaque
  if(layer["name"] == "Foreground") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerForegroundOpaque.push_back(((int)tileID)-1);
    }
  }
  //layer collision
  if (layer["name"] == "Collision") {
    for (auto const& tileID : layer["data"]) {
      if (tileID == 0)
      {
        mapData.layerCollision.push_back(false);
      }
      else
      {
        mapData.layerCollision.push_back(true);
      }
    }
  }

}
for (int i = 0; i < mapData.layerCollision.size(); i++){
  if(mapData.layerCollision[i]) {
    Rectangle createdRectangle = {i % this->mapData.mapWidth * 128, i % this->mapData.mapWidth * 128, 128, 128 };
    collisionRectangles.push_back(createdRectangle);
  }
}
//std::cout <<"INFO: All collision boxes were created "<< std::endl;
//----Oli map.cpp-------------------------------------------------------------------------------------------------------

//----Oli main----------------------------------------------------------------------------------------------------------

#include "config.h"
//#include "GameObject.h"
//#include "CharacterBase.h"
//#include "CharacterEnemy.h"
//#include "CharacterPlayer.h"
//#include "CharacterNPC.h"



int main()
{
  // Raylib initialization
  // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
  InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
  SetTargetFPS(60);

  InitAudioDevice();
  SetMasterVolume(0.02);


  ToggleFullscreen();
// Your own initialization code here
//CharacterPlayer player({ Game::ScreenWidth / 2/4,Game::ScreenHeight / 2/4 }, LoadTexture("assets/graphics/actors/Enemies/FemaleGhostSheetnew.png"), 24, 0, 1, 8, 16);
//CharacterEnemy ghost({ 20, 20 }, LoadTexture("assets/graphics/actors/Enemies/FemaleGhostSheetnew.png"), 24, 0, 1, 8, 16, &player);
//CharacterNPC playerNPC ({ player.getPos().x + 60,player.getPos().y}, LoadTexture("assets/graphics/actors/Enemies/FemaleGhostSheetnew.png"),24, 0, 1, 8, 16, &player);

std::ifstream tilesetDescriptionfile("assets/graphics/map/Level1/PhyramidenEingangNeu.json");
nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionfile);
tilesetDescriptionfile.close();

//std::ifstream tilesetDescriptionfile1("assets/graphics/map/Level1/_tilesets/TileAtlasProps1_1.json");
//nlohmann::json tilesetDescription1 = nlohmann::json::parse(tilesetDescriptionfile1);
//tilesetDescriptionfile.close();

std::ifstream levelMapfile("assets/graphics/map/Level1/PhyramidenEingangNeu.json");
nlohmann::json levelMap = nlohmann::json::parse(levelMapfile);
levelMapfile.close();

//std::ifstream levelMapPropfile("assets/graphics/map/Level1/loungeroom/loungeroom_props.json");
//nlohmann::json levelMapProp = nlohmann::json::parse(levelMapPropfile);
//levelMapPropfile.close();

Texture2D spritesheet = LoadTexture("assets/graphics/Tiles-Atlas/Pyramiden_SheetJamey.png");
//Texture2D spritesheet1 = LoadTexture("assets/graphics/map/Level1/_tilesets/TileAtlasProps1_1.png");

Vector2 vec;
Rectangle rec;

//Camera2D roomCamera{};

// Main game loop
while (!WindowShouldClose())
{
  //Updates that are made by frame are coded here
  //roomCamera.zoom = 4.f;
  //ghost.update();
  //playerNPC.update();
  //player.update();

  BeginDrawing();

  ClearBackground(WHITE);
  //BeginMode2D(roomCamera);

  vec = {0, 0};

  rec = {0, 0, levelMap["tilewidth"], levelMap["tileheight"]};
  for (auto const &layer : levelMap["layers"]) {

    if (layer["type"] == "tilelayer" && layer["visible"]) {
      vec.y = 0;
      for (auto const &tileId : layer["data"]) {

        int counter = (int) tileId;
        counter--;
        if (counter != -1) {
          rec.x = (float) ((int) counter % (int) tilesetDescription["columns"]) *
                  (float) levelMap["tilewidth"];
          rec.y = (float) floor((float) counter / (float) tilesetDescription["columns"]) *
                  (float) levelMap["tileheight"];
          DrawTextureRec(spritesheet, rec, vec, WHITE);
        }
        vec.x += (float) levelMap["tilewidth"];
        if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) {
          vec.x = 0;
          vec.y += (float) levelMap["tileheight"];
        }
      }
    }
  }
  vec = {0, 0};
  rec = {0, 0, levelMapProp["tilewidth"], levelMap["tileheight"]};
  for (auto const &layer : levelMapProp["layers"]) {
    if (layer["type"] == "tilelayer" && layer["visible"]) {
      vec.y = 0;
      for (auto const &tileId : layer["data"]) {
        int counter = (int) tileId;
        counter--;
        if (counter != -1) {
          rec.x = (float) ((int) counter % (int) tilesetDescription1["columns"]) *
                  (float) levelMapProp["tilewidth"];
          rec.y = (float) floor((float) counter / (float) tilesetDescription1["columns"]) *
                  (float) levelMapProp["tileheight"];
          DrawTextureRec(spritesheet1, rec, vec, WHITE);
        }
        vec.x += (float) levelMapProp["tilewidth"];
        if (vec.x >= (float) layer["width"] * (float) levelMapProp["tilewidth"]) {
          vec.x = 0;
          vec.y += (float) levelMapProp["tileheight"];
        }
      }
    }
  }


  //ghost.draw();
  //playerNPC.draw();
  //player.draw();
  //EndMode2D();

  EndDrawing();

  // Main game loop end
}
// De-initialization here


// Close window and OpenGL context
CloseAudioDevice();
CloseWindow();

return EXIT_SUCCESS;
}
//----Oli main----------------------------------------------------------------------------------------------------------
*/
/*
//----Christoph Map Ansatz----------------------------------------------------------------------------------------------

namespace Game {
  class Map {
  public:

    void draw();

    const float tile_size   = 32.0;
    const int tiles_per_row = 40;

    // 2D Array
    const std::array<std::array<int, 100>, 100> levelAnimation {
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };
    const std::array<std::array<int, 10>, 10> levelBackgroundSandWeg {
      2,5,1,
      2,5,1,
      2,5,1,
      2,5,1,
      2,5,1,
      2,5,1,
      2,5,1,
      3,4,6,
    };
    const std::array<std::array<int, 100>, 100> levelDecorationStones {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,
        -1,18,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,18,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };
    const std::array<std::array<int, 10>, 10> levelCollisionDoor {
      3,4,7,
      2,5,6
    };
    const std::array<std::array<int, 100>, 100> levelCollisionWallsStones {
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,1610612749,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,1610612748,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,-1,1610612747,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,11,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,
      1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1
    };

    // 1D Array
    // const std::array<int, 100> levelDecoration {};
    // const std::array<int, 100> levelCollision {};

    // Level Structure:
    // Level Background
    // Level Animation
    // Level Decoration
    // Level Collision
  };
}

//----Christoph Map Ansatz----------------------------------------------------------------------------------------------
*/