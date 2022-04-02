#include <raylib.h>
#include <stdio.h>

#include <player.h>
#include <level.h>

#define MAX_COLUMNS 1

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

Camera playerCamera = { 0 };

void Init(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FPS Game");

    SetTargetFPS(60);

    InitPlayer(&playerCamera);
}

void GameUpdate(void){
    BeginDrawing();

        ClearBackground(GRAY);

        BeginMode3D(playerCamera);

            UpdatePlayerPos(&playerCamera);

            DrawLevel();

        EndMode3D();

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