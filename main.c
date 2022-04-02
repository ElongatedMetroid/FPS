#include <raylib.h>
#include <player.h>
#include <level.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

Camera playerCamera = { 0 };

void Init(void){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "FPS Game");

    SetTargetFPS(60);

    InitPlayer(&playerCamera);
    InitLevel();
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