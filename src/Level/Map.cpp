#include "Map.h"

/*
 void LevelMap::update() {
   // scavenging through the json file to collect the INFO we need
   // scavenging through the json file to collect the INFO we need
 for (auto const &layer : levelMap["layers"]) { std::cout << "layers found!";
   if (layer["name"] == "Ground") {
     for (auto const &tileID : layer["data"]) {
       mapData.layerGround.push_back(((int)tileID) - 1);
     }
   }


/**
* if (layer["name"] == "Object") {
for (auto const &tileID : layer["data"]) {
mapData.layerObject.push_back(((int)tileID) - 1);
}
}
* if (layer["name"] == "Interactables") {
 for (auto const& tileID : layer["data"]) {
   tilemapData.layerInteractables.push_back(((int)tileID)-1);
 }
}*/

// layerCollision, Collision_rectangles are created from the json file data
// TODO add a collision layer to the tilemap... on the "kachelebene"

/**if(layer["name"] == "Collision"){
 for (auto const& tileID : layer["data"]){
   if(tileID == 0)
   {
     tilemapData.layerCollision.push_back(false);
   }
   else
   {
     tilemapData.layerCollision.push_back (true);
   }
 }
}*/
/*
   if (layer["name"] == "Interactables") {
     for (auto const &tileID : layer["data"]) {
       if (tileID == 0) {
         mapData.layerInteractables.push_back(false);
       } else {
         mapData.layerInteractables.push_back(true);
       }
     }
   }
   for (int i = 0; i < mapData.layerInteractables.size(); i++) {
     if (mapData.layerInteractables[i]) {
       Rectangle createdRectangle = { static_cast<float>((i % this->mapData.mapWidth * 32)),
                                      static_cast<float>((i / this->mapData.mapWidth * 32)),
                                      32,
                                      32 };
       collisionRectangles.push_back(createdRectangle);
       TraceLog(LOG_INFO, "createdRectangle - element added");
     }
     TraceLog(LOG_INFO, "Walls were created");
   } //hier war eine klammer für kommentare (zu)

if (layer["name"] == "Object") { TraceLog(LOG_INFO, "object found");
 for (auto const &tileID : layer["data"]) {
   if (tileID == 0) {
     mapData.layerObject.push_back(false);
   } else {
     mapData.layerObject.push_back(true);
   }
 }
}
for (int i = 0; i < mapData.layerObject.size(); i++) {
 if (mapData.layerObject[i]) {
   Rectangle createdRectangle = { static_cast<float>((i % this->mapData.mapWidth * 32)),
                                  static_cast<float>((i / this->mapData.mapWidth * 32)),
                                  32,
                                  32 };
   collisionRectangles.push_back(createdRectangle);
   TraceLog(LOG_INFO, "createdRectangle - element added");
 }
 TraceLog(LOG_INFO, "Walls were created");
}

std::cout <<"INFO: All collision boxes were created" << std::endl;
}
}
 */



LevelMap::LevelMap() {

  std::cout << "open map infos" << std::endl;

  //Map stuff -> relocate this into map.h/ and .cpp
  std::ifstream tilesetDescriptionFile("assets/graphics/map/Level1/PhyramidSheet.json"); //Pyramiden_SheetJamey.json needed as json, pls do in tiled
  assert(tilesetDescriptionFile.is_open());
  nlohmann::json tilesetDescription = nlohmann::json::parse(tilesetDescriptionFile);
  tilesetDescriptionFile.close();

  /** Outside the Pyramid*/
  std::ifstream levelMapFile("assets/graphics/map/Level1/PhyramidEntry.json");
  assert(levelMapFile.is_open());
  nlohmann::json levelMap = nlohmann::json::parse(levelMapFile);
  levelMapFile.close();

  /** Inside the Pyramid*/
  std::ifstream levelMapFileDungeon("assets/graphics/map/Level1/PhyramidDungeon.json");
  assert(levelMapFileDungeon.is_open());
  nlohmann::json levelMapDungeon = nlohmann::json::parse(levelMapFileDungeon);
  levelMapFileDungeon.close();

  Texture2D tileAtlasTexture = LoadTexture("assets/graphics/map/Level1/Egypt-Sheet.png");
}


void LevelMap::draw() {

  switch (level.Game::Level::currentscreen) {
  case Game::Level::GameScreen::OVERWORLD:

    std::cout << "draw map overworld" << std::endl;

    ClearBackground(BLACK);

    //map
    Vector2 vec;
    Rectangle rec;

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
            DrawTextureRec(tileAtlasTexture, rec, vec, WHITE); //entkoppeln, 2 vektoren machen
          }
          vec.x += (float) levelMap["tilewidth"];
          if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) {
            vec.x = 0;
            vec.y += (float) levelMap["tileheight"];
          }
        }
      }
    }

    break;
  case Game::Level::GameScreen::PYRAMIDE:

    std::cout << "draw map pyramide" << std::endl;

    ClearBackground(BLACK);

    Vector2 vecDungeon;
    Rectangle recDungeon;

    vecDungeon = {0, 0};
    recDungeon = {0, 0, levelMapDungeon["tilewidth"], levelMapDungeon["tileheight"]};
    for (auto const &layer : levelMapDungeon["layers"]) {

      if (layer["type"] == "tilelayer" && layer["visible"]) {
        vecDungeon.y = 0;
        for (auto const &tileId : layer["data"]) {

          int counter = (int) tileId;
          counter--;
          if (counter != -1) {
            recDungeon.x = (float) ((int) counter % (int) tilesetDescription["columns"]) *
                           (float) levelMap["tilewidth"];
            recDungeon.y = (float) floor((float) counter / (float) tilesetDescription["columns"]) *
                           (float) levelMap["tileheight"];
            DrawTextureRec(tileAtlasTexture, recDungeon, vecDungeon, WHITE); //entkoppeln, 2 vektoren machen
          }
          vecDungeon.x += (float) levelMapDungeon["tilewidth"];
          if (vecDungeon.x >= (float) layer["width"] * (float) levelMapDungeon["tilewidth"]) {
            vecDungeon.x = 0;
            vecDungeon.y += (float) levelMapDungeon["tileheight"];
          }
        }
      }
    }

    break;
  }
}


void LevelMap::drawOVERWORLD() {

  std::cout << "draw map overworld" << std::endl;

  ClearBackground(BLACK);

  //map
  Vector2 vec;
  Rectangle rec;

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
          DrawTextureRec(tileAtlasTexture, rec, vec, WHITE); //entkoppeln, 2 vektoren machen
        }
        vec.x += (float) levelMap["tilewidth"];
        if (vec.x >= (float) layer["width"] * (float) levelMap["tilewidth"]) {
          vec.x = 0;
          vec.y += (float) levelMap["tileheight"];
        }
      }
    }
  }
}
void LevelMap::drawPYRAMID() {

  std::cout << "draw map pyramide" << std::endl;

  ClearBackground(BLACK);

  Vector2 vecDungeon;
  Rectangle recDungeon;

  vecDungeon = {0, 0};
  recDungeon = {0, 0, levelMapDungeon["tilewidth"], levelMapDungeon["tileheight"]};
  for (auto const &layer : levelMapDungeon["layers"]) {

    if (layer["type"] == "tilelayer" && layer["visible"]) {
      vecDungeon.y = 0;
      for (auto const &tileId : layer["data"]) {

        int counter = (int) tileId;
        counter--;
        if (counter != -1) {
          recDungeon.x = (float) ((int) counter % (int) tilesetDescription["columns"]) *
                         (float) levelMap["tilewidth"];
          recDungeon.y = (float) floor((float) counter / (float) tilesetDescription["columns"]) *
                         (float) levelMap["tileheight"];
          DrawTextureRec(tileAtlasTexture, recDungeon, vecDungeon, WHITE); //entkoppeln, 2 vektoren machen
        }
        vecDungeon.x += (float) levelMapDungeon["tilewidth"];
        if (vecDungeon.x >= (float) layer["width"] * (float) levelMapDungeon["tilewidth"]) {
          vecDungeon.x = 0;
          vecDungeon.y += (float) levelMapDungeon["tileheight"];
        }
      }
    }
  }
}

LevelMap::~LevelMap() {}