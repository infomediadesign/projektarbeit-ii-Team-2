#include "Endscreen.h"

void Endscreen::update() {

  creditPosY -= 0.1;
}

void Endscreen::draw() {
  DrawTexture(Endscreen, 0,0, WHITE);

  DrawText("Thank You for playing Custodia", positionX, creditPosY + 40, Textsize, WHITE);

  DrawText("Names of the Developers:", positionX, creditPosY + 80, Textsize, WHITE);

  DrawText("Jamey Kamuf", positionX, creditPosY + 120, Textsize, WHITE);
  DrawText("Projektlead and Lead Artist", positionX, creditPosY + 150, Textsize, WHITE);

  DrawText("Görkem Akdeniz", positionX, creditPosY + 190, Textsize, WHITE);
  DrawText("Vice-Projektlead and Lead Programmer", positionX, creditPosY + 220, Textsize, WHITE);

  DrawText("Nicolas Vogt ", positionX, creditPosY + 260, Textsize, WHITE);
  DrawText("Programmer and Sound/Music", positionX, creditPosY + 290, Textsize, WHITE);

  DrawText("Michelle Geggier ", positionX, creditPosY + 330, Textsize, WHITE);
  DrawText("Artist and Animation", positionX, creditPosY + 360, Textsize, WHITE);

  DrawText("Mika Jürries", positionX, creditPosY + 400, Textsize, WHITE);
  DrawText("Level Designer and Game Designer", positionX, creditPosY + 430, Textsize, WHITE);

  DrawText("Press SPACE to Exit", positionX, creditPosY + 470, Textsize, WHITE);

}

