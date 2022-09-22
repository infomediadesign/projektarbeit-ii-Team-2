#include "Endscreen.h"

void Endscreen::update() {

  creditPosY -= 1;

  //if(creditPosY + add40*25){
    //creditPosY += 1;
  //}

}

void Endscreen::draw() {

  ///The text to be printed
  const auto *msgCredits  = "Credits";
  const char *msgCredits1 = "Thank You for playing Custodia";
  const char *msgCredits2 = "Names of Custodias Developers:";
  const char *msgCredits3 = "Jamey Kamuf - Projectlead and Lead Artist";
  const char *msgCredits4 = "Goerkem Akdeniz - Vice-Projectlead and Lead Programmer";
  const char *msgCredits5 = "Nicolas Vogt - Programmer and Sound/Music";
  const char *msgCredits6 = "Michelle Geggier - Artist and Animation";
  const char *msgCredits7 = "Mika Juerries - Level Designer and Game Designer";
  const char *msgCredits8 = "In cooperation with the SRH Hochschule Heidelberg";
  const char *msgCredits9 = "For more Infos about Custodia go to ";
  const char *msgCredits10 = "Battle music - made by Luis Zuno";
  const char *msgCredits11 = "https://ansimuz.itch.io/adventure-music-collection-pack-1";
  const char *msgCredits12 = "Inside and Outside the Dungeon music and Game Over music";
  const char *msgCredits13 = "https://svl.itch.io/rpg-music-pack-svl";
  const char *msgCredits14 = "Teleport, Door, Movement and Button sounds";
  const char *msgCredits15 = "https://leohpaz.itch.io/100-retro-rpg-ui-sound-effects";
  const char *msgCredits16 = "Titlescreen and Pausemenu music";
  const char *msgCredits17 = "https://joshuuu.itch.io/short-loopable-background-music";
  const char *msgCredits18 = "Honable mentions of Sfx and music used";
  const char *msgCredits19 = "https://abduldahir7002.itch.io/dark-moody-chiptune-song";
  const char *msgCredits20 = "https://canarigames.itch.io/canaripack-8bit-topdown";
  const char *msgCredits21 = "Press          to Exit";
  const char *msgCredits22 = "        [SPACE] ";

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
  DrawTextEx(textFont, msgCredits11 , { textPos.x, static_cast<float>(creditPosY + add40*14) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits12 , { textPos.x, static_cast<float>(creditPosY + add40*15) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits13 , { textPos.x, static_cast<float>(creditPosY + add40*16) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits14 , { textPos.x, static_cast<float>(creditPosY + add40*17) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits15 , { textPos.x, static_cast<float>(creditPosY + add40*18) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits16 , { textPos.x, static_cast<float>(creditPosY + add40*19) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits17 , { textPos.x, static_cast<float>(creditPosY + add40*20) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits18 , { textPos.x, static_cast<float>(creditPosY + add40*21) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits19 , { textPos.x, static_cast<float>(creditPosY + add40*22) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits20 , { textPos.x, static_cast<float>(creditPosY + add40*23) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits21 , { textPosTitle3.x, static_cast<float>(creditPosY + add40*25) }, fontSize, fontSpacing, WHITE);
  DrawTextEx(textFont, msgCredits22 , { textPosTitle3.x, static_cast<float>(creditPosY + add40*25) }, fontSize, fontSpacing, RED);
}
void Endscreen::thankyoudraw() {
  ///clear background
  ClearBackground(BLACK);

  ///Draw the background picture...
  DrawTexture(ThankYou, 0,0, WHITE);

  //const char *msgCredits1 = "Thank You for playing Custodia";

  //DrawTextEx(textFont, msgCredits1 , { Monster1rec.x - 255, Monster1rec.y - 40 }, fontSize, fontSpacing, WHITE);

/*
   ///ANIMATIONS
   ///Monster1
   DrawRectangleRec(Monster1rec, Color{});
   DrawTextureRec(Monster1, Monster1FrameRec, {Monster1rec.x, Monster1rec.y}, WHITE);

 monster1_framescounter++;

 if (monster1_framescounter >= (60 / monster1_framesspeed)) {
   monster1_framescounter = 0;
   monster1_currentFrame++;

   if (monster1_currentFrame > 3)
     monster1_currentFrame = 0;

   Monster1FrameRec.x = (float)monster1_currentFrame * (float)Monster1.width / 4;
 }

 ///Monster2
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
 DrawRectangleRec(Monster3rec, Color{});
 DrawTextureRec(Monster3, Monster3FrameRec, {Monster3rec.x, Monster3rec.y}, WHITE);

 monster3_framescounter++;

 if (monster3_framescounter >= (60 / monster3_framesspeed)) {
   monster3_framescounter = 0;
   monster3_currentFrame++;

   if (monster3_currentFrame > 5)
     monster3_currentFrame = 0;

   Monster3FrameRec.x = (float)monster3_currentFrame * (float)Monster3.width / 6;
 }

 ///Epanox
 DrawRectangleRec(Epanoxrec, Color{});
 DrawTextureRec(Epanox, EpanoxFrameRec, {Epanoxrec.x, Epanoxrec.y}, WHITE);

 epanox_framescounter++;

 if (epanox_framescounter >= (60 / epanox_framesspeed)) {
   epanox_framescounter = 0;
   epanox_currentFrame++;

   if (epanox_currentFrame > 16)
     epanox_currentFrame = 0;

   EpanoxFrameRec.x = (float)epanox_currentFrame * (float)Epanox.width / 17;
 }

 ///Nemo
 DrawRectangleRec(Nemorec, Color{});
 DrawTextureRec(Nemo, NemoFrameRec, {Nemorec.x, Nemorec.y}, WHITE);

 nemo_framescounter++;

 if (nemo_framescounter >= (60 / nemo_framesspeed)) {
   nemo_framescounter = 0;
   nemo_currentFrame++;

   if (nemo_currentFrame > 7)
     nemo_currentFrame = 0;

   NemoFrameRec.x = (float)nemo_currentFrame * (float)Nemo.width / 8;
 }
 */

}
