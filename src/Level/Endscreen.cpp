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
  const char *msgCredits2 = "Names of Custodias Developers:";
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
  DrawTextEx(textFont, msgCredits2  , { textPosTitle2.x, static_cast<float>(creditPosY + add40*3) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits3  , { textPos.x, static_cast<float>(creditPosY + add40*4) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits4  , { textPos.x, static_cast<float>(creditPosY + add40*5) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits5  , { textPos.x, static_cast<float>(creditPosY + add40*6) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits6  , { textPos.x, static_cast<float>(creditPosY + add40*7) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits7  , { textPos.x, static_cast<float>(creditPosY + add40*8) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits8  , { textPos.x, static_cast<float>(creditPosY + add40*10) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits9  , { textPos.x, static_cast<float>(creditPosY + add40*11) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits10 , { textPos.x, static_cast<float>(creditPosY + add40*12) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits11 , { textPosTitle3.x, static_cast<float>(creditPosY + add40*13) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits12 , { textPosTitle3.x, static_cast<float>(creditPosY + add40*13) }, fontSize, fontSpacing, RED);
}
void Endscreen::thankyoudraw() {
  ///ANIMATIONS
  ///Monster1
  Monster1rec = {760, 945, 20, 28};
  DrawRectangleRec(Monster1rec, Color{});
  DrawTextureRec(Monster1, Monster1FrameRec, {Monster1rec.x, Monster1rec.y}, WHITE);

  monster1_framescounter++;

  if (monster1_framescounter >= (60 / monster1_framesspeed)) {
    monster1_framescounter = 0;
    monster1_currentFrame++;

    if (monster1_currentFrame > 5)
      monster1_currentFrame = 0;

    Monster1FrameRec.x = (float)monster1_currentFrame * (float)Monster1.width / 6;
  }

  ///Monster2
  Monster2rec = {760, 945, 20, 28};
  DrawRectangleRec(Monster2rec, Color{});
  DrawTextureRec(Monster2, Monster2FrameRec, {Monster2rec.x, Monster2rec.y}, WHITE);

  monster2_framescounter++;

  if (monster2_framescounter >= (60 / monster2_framesspeed)) {
    monster2_framescounter = 0;
    monster2_currentFrame++;

    if (monster2_currentFrame > 1)
      monster2_currentFrame = 0;

    Monster2FrameRec.x = (float)monster2_currentFrame * (float)Monster2.width / 2;
  }

  ///Monster3
  Monster3rec = {760, 945, 20, 28};
  DrawRectangleRec(Monster3rec, Color{});
  DrawTextureRec(Monster3, Monster3FrameRec, {Monster3rec.x, Monster3rec.y}, WHITE);

  monster3_framescounter++;

  if (monster3_framescounter >= (60 / monster3_framesspeed)) {
    monster3_framescounter = 0;
    monster3_currentFrame++;

    if (monster3_currentFrame > 3)
      monster3_currentFrame = 0;

    Monster3FrameRec.x = (float)monster3_currentFrame * (float)Monster3.width / 4;
  }

  ///Epanox
  Epanoxrec = {760, 945, 20, 28};
  DrawRectangleRec(Epanoxrec, Color{});
  DrawTextureRec(Epanox, EpanoxFrameRec, {Epanoxrec.x, Epanoxrec.y}, WHITE);

  epanox_framescounter++;

  if (epanox_framescounter >= (60 / epanox_framesspeed)) {
    epanox_framescounter = 0;
    epanox_currentFrame++;

    if (epanox_currentFrame > 19)
      epanox_currentFrame = 0;

    EpanoxFrameRec.x = (float)epanox_currentFrame * (float)Epanox.width / 20;
  }

  ///Nemo
  Nemorec = {760, 945, 20, 28};
  DrawRectangleRec(Nemorec, Color{});
  DrawTextureRec(Nemo, NemoFrameRec, {Nemorec.x, Nemorec.y}, WHITE);

  nemo_framescounter++;

  if (nemo_framescounter >= (60 / nemo_framesspeed)) {
    nemo_framescounter = 0;
    nemo_currentFrame++;

    if (nemo_currentFrame > 3)
      nemo_currentFrame = 0;

    NemoFrameRec.x = (float)nemo_currentFrame * (float)Nemo.width / 4;
  }
}
