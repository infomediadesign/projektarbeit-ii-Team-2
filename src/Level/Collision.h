#include "../INCLUDES.h"

#include "../Player/Nemo.h"
#include "../Level/Level.h"

class Collision {

private:

public:
  Game::Nemo nemo;
  Game::Level level;

 Rectangle rectangleObject = {};
 Rectangle rectangleCollision = {};

  bool collisionObject = false; // Collision detection

  void update();
  void draw();
};