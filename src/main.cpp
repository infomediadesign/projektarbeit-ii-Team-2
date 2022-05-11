#include <iostream>
#include <memory>
#include <cstdlib>

#include "raylib.h"
#include "config.h"
#include "Sprite.h"
#include "Nemo.h"
#include "UI.h"



int main() {
    // Raylib initialization
    // Project name = Custodia, 16:9, 640p : 360p res (screen size), fullscreen mode -> etc. can be specified in the config.h.in file


    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);


    Vector2 NemoPosition = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };

    /*#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
    if (IsKeyPressed(KEY_K)) {
        ToggleFullscreen();
    }
    //ToggleFullscreen(); not working @todo when press K it changes from fullscreen to windowed mode
#endif */

#ifdef HIDE_CURSOR   
    RLAPI void HideCursor(void);  //HideCursor; not working @todo 
#endif


    // *** Your own initialization code here ***

    Texture2D Map = LoadTexture("assets/graphics/wintermap.png");

    Game::UI ui;
    Game::Nemo nemo; //Initializing the Nemo (Player) Class

    Texture2D StandStil = LoadTexture("assets/graphics/Charakter_Vorschlag_vorne_laufen1.png");
    Game::Sprite spr(NemoPosition.x, NemoPosition.y, nemo.Front);
    Game::Sprite NPC(100, 100, StandStil);

    //Camera settings 
    Camera2D camera = { 0 };
    camera.target = Vector2{ spr.pos_x + 20.0f, spr.pos_y + 20.0f };
    camera.offset = Vector2{ Game::ScreenWidth / 2.0f, Game::ScreenHeight / 2.0f };
    camera.zoom = 2.0f;

    //devide spritesheet into frames 
    Vector2 position = { Game::ScreenWidth / 2, Game::ScreenHeight / 2 };
    Rectangle frameRec = { 0.0f, 0.0f, (float)nemo.Front.width / 3, (float)nemo.Front.height }; // NemoFr -> nemo in the future
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;            // animtation fps 


    // *** Main game loop ***

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        if (IsKeyDown(KEY_D)) {                     //run right
            spr.pos_x += 2.0f;

            framesCounter++;

            if (framesCounter >= (60 / framesSpeed))
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) currentFrame = 0;

                frameRec.x = (float)currentFrame * (float)nemo.Right.width / 3;
            }
        }

        if (IsKeyDown(KEY_A)) {                     //run left
            spr.pos_x -= 2.0f;

            framesCounter++;

            if (framesCounter >= (60 / framesSpeed))
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) currentFrame = 0;

                frameRec.x = (float)currentFrame * (float)nemo.Left.width / 3;
            }
        }

        if (IsKeyDown(KEY_W)) {                     //run forwards
            spr.pos_y -= 2.0f;

            framesCounter++;

            if (framesCounter >= (60 / framesSpeed))
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) currentFrame = 0;

                frameRec.x = (float)currentFrame * (float)nemo.Front.width / 3;
            }
        }

        if (IsKeyDown(KEY_S)) {                     //run backwards
            spr.pos_y += 2.0f;

            framesCounter++;

            if (framesCounter >= (60 / framesSpeed))
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 2) currentFrame = 0;

                frameRec.x = (float)currentFrame * (float)nemo.Back.width / 3;
            }
        }

        camera.target = Vector2{ spr.pos_x + 20.0f, spr.pos_y + 20.0f };


        BeginDrawing();

        ClearBackground(WHITE);

        BeginMode2D(camera);
        DrawTexture(Map, 0, 0, WHITE);
        DrawTexture(NPC.texture_, NPC.pos_x, NPC.pos_y, WHITE);
        EndMode2D();

        //@todo when WASD not pressed display nemo standing, when WASD pressed delete nemo standing and draw animation

        bool move = false;

            if (IsKeyDown(KEY_W))
            {
                DrawTextureRec(nemo.Back, frameRec, position, WHITE);    // Draw nemo animation backwards 
                move = true;
            }
            if (IsKeyDown(KEY_S))
            {
                DrawTextureRec(nemo.Front, frameRec, position, WHITE);    // Draw nemo animation forwards
                move = true;
            }
            if (IsKeyDown(KEY_D))
            {
                DrawTextureRec(nemo.Right, frameRec, position, WHITE);      // Draw nemo animation right 
                move = true;
            }
            if (IsKeyDown(KEY_A))
            {
                DrawTextureRec(nemo.Left, frameRec, position, WHITE);      // Draw nemo animation left
                move = true;
            }

            if (move == false)
            {
                DrawTextureRec(nemo.Front, frameRec, position, WHITE);        // standing animation i dont have that yet
                
            }


        // controlls description
       
            ui.Draw();

        EndDrawing();
    } // Main game loop end

    // *** De-initialization here ***     

    UnloadTexture(nemo.Front);
    UnloadTexture(nemo.Back);
    UnloadTexture(nemo.Right);
    UnloadTexture(nemo.Left);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
