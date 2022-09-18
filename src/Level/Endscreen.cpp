#include "Endscreen.h"

void Endscreen::update() {

  creditPosY -= 1;

  if(creditPosY == 0){
    creditPosY += 1;
  }

}

void Endscreen::draw() {

  ///The text to be printed
  const auto *msgCredits  = "Credits";
  const char *msgCredits1 = "Thank You for playing Custodia";
  const char *msgCredits2 = "Names of the Custodia Developers:";
  const char *msgCredits3 = "Jamey Kamuf - Projektlead and Lead Artist";
  const char *msgCredits4 = "Goerkem Akdeniz - Vice-Projektlead and Lead Programmer";
  const char *msgCredits5 = "Nicolas Vogt - Programmer and Sound/Music";
  const char *msgCredits6 = "Michelle Geggier - Artist and Animation";
  const char *msgCredits7 = "Mika Juerries - Level Designer and Game Designer";
  const char *msgCredits8 = "In cooperation with the SRH Hochschule Heidelberg";
  const char *msgCredits9 = "For more Infos about Custodia go to ";
  const char *msgCredits10 = "tranor.itch.io/custodia-trap";
  const char *msgCredits11 = "Press          to Exit";
  const char *msgCredits12 = "        [SPACE] ";

  ///clear background
  ClearBackground(BLACK);

  ///Draw the background picture...
  DrawTexture(Endscreen, 0,0, WHITE);

  ///Draw the Credits...
  DrawTextEx(textFont, msgCredits   , { textPosTitle.x, static_cast<float>(creditPosY) }, fontTitleSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits1  , { textPosTitle2.x, static_cast<float>(creditPosY + add40) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits2  , { textPos.x, static_cast<float>(creditPosY + add40*2) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits3  , { textPos.x, static_cast<float>(creditPosY + add40*3) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits4  , { textPos.x, static_cast<float>(creditPosY + add40*4) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits5  , { textPos.x, static_cast<float>(creditPosY + add40*5) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits6  , { textPos.x, static_cast<float>(creditPosY + add40*6) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits7  , { textPos.x, static_cast<float>(creditPosY + add40*7) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits8  , { textPos.x, static_cast<float>(creditPosY + add40*9) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits9  , { textPos.x, static_cast<float>(creditPosY + add40*10) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits10 , { textPos.x, static_cast<float>(creditPosY + add40*11) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits11 , { textPosTitle3.x, static_cast<float>(creditPosY + add40*12) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits12 , { textPosTitle3.x, static_cast<float>(creditPosY + add40*12) }, fontSize, fontSpacing, RED);
}

