#include <raylib.h>
#include <stdio.h>

#define MAX_COLUMNS 1

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - 3d camera first person");

    // Define the camera to look into our 3d world (position, target, up vector)
    Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Generates some random columns
    float heights[MAX_COLUMNS] = { 0 };
    Vector3 positions[MAX_COLUMNS] = { 0 };
    Color colors[MAX_COLUMNS] = { 0 };

    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){ (float)GetRandomValue(-15, 15), heights[i]/2.0f, (float)GetRandomValue(-15, 15) };
        colors[i] = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
    }

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Vector3 playerSize = { 1.0f, 3.0f, 1.0f};
    Vector3 collisionTestCubePos = {0.0f, 3.0f, 0.0f};

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        //printf("%f %f %f\n", camera.position.x, camera.position.y, camera.position.z);

        if (CheckCollisionBoxes(
            (BoundingBox){(Vector3){ camera.position.x - playerSize.x/2,
                                     camera.position.y - playerSize.y/2,
                                     camera.position.z - playerSize.z/2 },
                          (Vector3){ camera.position.x + playerSize.x/2,
                                     camera.position.y + playerSize.y/2,
                                     camera.position.z + playerSize.z/2 }},
            (BoundingBox){(Vector3){ collisionTestCubePos.x - 3.0f/2,       //3.0f just for testing since I used it for the size when drawing the cube
                                     collisionTestCubePos.y - 3.0f/2,
                                     collisionTestCubePos.z - 3.0f/2 },
                          (Vector3){ collisionTestCubePos.x + 3.0f/2,
                                     collisionTestCubePos.y + 3.0f/2,
                                     collisionTestCubePos.z + 3.0f/2 }})) printf("Obama Care\n");

        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);                  // Update camera
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

                //cube to test collision
                DrawCube(collisionTestCubePos, 3.0f, 3.0f, 3.0f, GREEN);

                // Draw some cubes around
                for (int i = 0; i < MAX_COLUMNS; i++)
                {
                    DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
                    DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, BLACK);
                }

            EndMode3D();

            DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 220, 70, BLUE);

            DrawText("First person camera default controls:", 20, 20, 10, BLACK);
            DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
            DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}