#include "Map.h"

void Map::update()
{
  for (auto & layer : levelMap["layers"]) {
    if (layer["name"] == "Ground") {
      for (auto & tileID : layer["data"]) {
        layerManager.layerGround.push_back(((int)tileID)-1);
      }
    }
    if (layer["name"] == "Objects") {
      for (auto & tileID : layer["data"]) {
        layerManager.layerObject.push_back(((int)tileID)-1);
      }
    }
    /**if (layer["name"] == "Interactables") {
      for (auto const& tileID : layer["data"]) {
        mapData.layerInteractables.push_back(((int)tileID)-1);
      }
    }*/

    //layerCollision
    /**if(layer["name"] == "Collision"){
      for (auto const& tileID : layer["data"]){
        if(tileID == 0)
        {
          mapData.layerCollision.push_back(false);
        }
        else
        {
          mapData.layerCollision.push_back (true);
        }
      }
    }*/
    if(layer["name"] == "Interactables"){
      for (auto & tileID : layer["data"]){
        if(tileID == 0)
        {
          layerManager.layerInteractables.push_back(false);
        }
        else
        {
          layerManager.layerInteractables.push_back(true);
        }
      }
    }
    for (int i = 0; i < layerManager.layerInteractables.size(); i++){
      if (layerManager.layerInteractables[i]){
        Rectangle createRectangle = {static_cast<float>(i % this->mapData.tileMapWidth * 32), static_cast<float>(i / this->mapData.tileMapWidth* 32), 32, 32 };
        collisionRectangles.push_back(createRectangle);
        TraceLog(LOG_INFO, "Walls were created");
      }

    }
  }
}

