#include "Endscreen.h"

void Endscreen::update() {

  creditPosY -= 1;
}

void Endscreen::draw() {

  DrawText("Credits", 400, creditPosY, 40, WHITE);

  DrawText("Thank You for playing Custodia", 400, creditPosY + 40, 20, WHITE);

  DrawText("Game Producers:", 400, creditPosY + 80, 20, WHITE);

  DrawText("Nicolas Vogt (Programmer)", 400, creditPosY + 120, 20, WHITE);

  DrawText("Görkem (Lead Programmer)", 400, creditPosY + 160, 20, WHITE);

  DrawText("other names (occupations)", 400, creditPosY + 200, 20, WHITE);

}

