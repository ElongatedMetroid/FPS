#include <raylib.h>
#include <player.h>
#include <level.h>
#include <draw.h>
#include <audio.h>
#define RLIGHTS_IMPLEMENTATION
#include <lighting.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

Camera playerCamera = { 0 };

float deltaTime = 0.0f;

void Init(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FPS Game");

    SetTargetFPS(120);

    InitPlayer(&playerCamera);
    InitLevel();
    InitLighting();
    InitAudio();
}

float lastFrame = 0.0f, currentFrame = 0.0f;
void GameUpdate(void){
    lastFrame = currentFrame;
    currentFrame = GetTime();
    deltaTime = (currentFrame - lastFrame) * 100;

    ClearBackground(GRAY);

        BeginMode3D(playerCamera);

            UpdatePlayerPos(&playerCamera);
            UpdatePlayerObjects(&playerCamera);

            DrawObjects(levelData);
            DrawObjects(playerObjects);

            UpdateLighting(&playerCamera);
            UpdateAudio();
            
        EndMode3D();

    char FPS[255];
    sprintf(FPS, "%d\n%f\n", GetFPS(), GetFrameTime());
    DrawText(FPS, 10, 10, 50, BLACK);

    EndDrawing();
}

int main(void)
{
    Init();

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        GameUpdate();
    }

    CloseWindow();

    return 0;
}