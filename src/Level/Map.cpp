#include "Map.h"

void Map::update() { // scavenging through the json file to collect the INFO we need
  // scavenging through the json file to collect the INFO we need
  for (auto const &layer : levelMap["layers"]) {
    if (layer["name"] == "Ground") {
      for (auto const &tileID : layer["data"]) {
        mapData.layerGround.push_back(((int)tileID) - 1);
      }
    }
    if (layer["name"] == "Object") {
      for (auto const &tileID : layer["data"]) {
        mapData.layerObject.push_back(((int)tileID) - 1);
      }
    }

    /**if (layer["name"] == "Interactables") {
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
      }
      // TraceLog(LOG_INFO, "Walls were created");
    }
    std::cout <<"INFO: All collision boxes were created" << std::endl;
  }
}
