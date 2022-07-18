#include "Map.h"
/*
void Map::mapDraw()
{
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
*/