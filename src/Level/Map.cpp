/*#include "Map.h"

for (auto const& layer : levelMap["layers"]) {
  if (layer["name"] == Ground) {
    for (auto const& tileID : layer["data"]) {
      mapData.layerGround.push_back(((int)tileID)-1);
    }
  }
  if (layer["name"] == "Interactables") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerObjects.push_back(((int)tileID)-1);
    }
  }
  if (layer["name"] == "Decoration") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerDecoration.push_back(((int)tileID)-1);
    }
  }
  if (layer["name"] == "Interactables") {
    for (auto const& tileID : layer["data"]) {
      mapData.layerObjects.push_back(((int)tileID)-1);
    }
  }
  //layerCollision
  if(layer["name"] == "Collision"){
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
  }
  for (int i = 0; i < mapData.layerCollision.size(); i++){
    if (mapData.layerCollision[i]){
      Rectangle createdRectangle = {i % this->mapData.mapWidth * 128, i % this->mapData.mapHeight* 128, 128, 128 };
      collisionRectangles.push_back(createdRectangle);
    }
  }
}*/
