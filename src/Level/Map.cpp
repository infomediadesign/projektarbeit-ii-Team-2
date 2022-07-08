#include "Map.h"
#include "raylib.h"



/*
void Game::Map::draw() {

  Texture2D texture = LoadTexture("assets/graphics/Tiles-Atlas/Pyramiden_SheetJamey.png");

  Vector2 vec = {0,0};
  Rectangle rec = {0,0, tile_size, tile_size};

  //For-loop mit 2D Array
  for(auto const& outer : levelBackgroundSandWeg)
  {
    for(auto const & inner : outer)
    {
      rec.x = tile_size * (float) ((inner-1) & tiles_per_row);
      rec.y = tile_size * (float) floor((inner-1) / tiles_per_row); // floor: gibt den größten ganzzahligen Wert kleiner oder gleich x zurück.
      DrawTextureRec(texture, rec, vec, WHITE);

      vec.x += tile_size;
    }
    vec.x = 0;
    vec.y += tile_size;
  }

  for(auto const& outer : levelAnimation)
  {
    for(auto const & inner : outer)
    {
      rec.x = tile_size * (float) ((inner-1) & tiles_per_row);
      rec.y = tile_size * (float) floor((inner-1) / tiles_per_row); // floor: gibt den größten ganzzahligen Wert kleiner oder gleich x zurück.
      DrawTextureRec(texture, rec, vec, WHITE);

      vec.x += tile_size;
    }
    vec.x = 0;
    vec.y += tile_size;
  }

  for(auto const& outer : levelDecorationStones)
  {
    for(auto const & inner : outer)
    {
      rec.x = tile_size * (float) ((inner-1) & tiles_per_row);
      rec.y = tile_size * (float) floor((inner-1) / tiles_per_row); // floor: gibt den größten ganzzahligen Wert kleiner oder gleich x zurück.
      DrawTextureRec(texture, rec, vec, WHITE);

      vec.x += tile_size;
    }
    vec.x = 0;
    vec.y += tile_size;
  }

  for(auto const& outer : levelCollisionDoor)
  {
    for(auto const & inner : outer)
    {
      rec.x = tile_size * (float) ((inner-1) & tiles_per_row);
      rec.y = tile_size * (float) floor((inner-1) / tiles_per_row); // floor: gibt den größten ganzzahligen Wert kleiner oder gleich x zurück.
      DrawTextureRec(texture, rec, vec, WHITE);

      vec.x += tile_size;
    }
    vec.x = 0;
    vec.y += tile_size;
  }

  for(auto const& outer : levelCollisionWallsStones)
  {
    for(auto const & inner : outer)
    {
      rec.x = tile_size * (float) ((inner-1) & tiles_per_row);
      rec.y = tile_size * (float) floor((inner-1) / tiles_per_row); // floor: gibt den größten ganzzahligen Wert kleiner oder gleich x zurück.
      DrawTextureRec(texture, rec, vec, WHITE);

      vec.x += tile_size;
    }
    vec.x = 0;
    vec.y += tile_size;
  }



  //For-loop mit 1D Array
  /*
  //For-loop mit 1D Array
  vec = {0,0};
  int val = 0;
  for(int c = 0; c < 10; c++) {
    for(int r = 0; r < 10; r++){
      val = levelCollision[r * 10 + c];
      val--;
      if (val != -1){
        rec.x = tile_size * (float) ((val) & tiles_per_row);
        rec.y = tile_size * (float) (floor(val) / tiles_per_row);
        DrawTextureRec(texture, rec, vec, WHITE);
      }
      vec.x += tile_size;
    }
    vec.x = 0;
    vec.y += tile_size;
  }

}
*/