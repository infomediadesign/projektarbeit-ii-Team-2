#include "../INCLUDES.h"
#include "../Level/Level.h"
#include "../Level/Map.h"
#include "../Player/Nemo.h"

class Collision {
private:
public:
  Game::Nemo * nemo;
  Game::Level * level;
  Map * map;

  Rectangle rectangleObject    = {};
  Rectangle rectangleCollision = {};
  Rectangle  EpanoxRec = {961, 458, 16, 20}; //EpanoxRec

  bool collisionObject = false; // Collision detection
  bool wallCollision = false;
  bool EpanoxCollision = false;

  void epanoxCollision();
  void update();
  void draw();
  void checkForCollisions();
  Rectangle getCollision();
};