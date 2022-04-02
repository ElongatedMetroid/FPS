#include <player.h>

#include <level.h>

void InitPlayer(Camera *playerCamera){
    playerCamera->position = (Vector3){ 4.0f, 2.0f, 4.0f };
    playerCamera->target = (Vector3){ 0.0f, 1.8f, 0.0f };
    playerCamera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
    playerCamera->fovy = 60.0f;
    playerCamera->projection = CAMERA_PERSPECTIVE;

    SetCameraMode(*playerCamera, CAMERA_FIRST_PERSON); // Set a first person camera mode
}
Vector3 playerSize = { 1.0f, 3.0f, 1.0f};
void UpdatePlayerPos(Camera *playerCamera){
        Vector3 OldPos = playerCamera->position;
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(playerCamera);                  // Update camera
        //----------------------------------------------------------------------------------

        if (CheckCollisionBoxes(
            (BoundingBox){(Vector3){ playerCamera->position.x - playerSize.x/2,
                                     playerCamera->position.y - playerSize.y/2,
                                     playerCamera->position.z - playerSize.z/2 },
                          (Vector3){ playerCamera->position.x + playerSize.x/2,
                                     playerCamera->position.y + playerSize.y/2,
                                     playerCamera->position.z + playerSize.z/2 }},
            (BoundingBox){(Vector3){ collisionTestCubePos.x - 3.0f/2,       //3.0f just for testing since I used it for the size when drawing the cube
                                     collisionTestCubePos.y - 3.0f/2,
                                     collisionTestCubePos.z - 3.0f/2 },
                          (Vector3){ collisionTestCubePos.x + 3.0f/2,
                                     collisionTestCubePos.y + 3.0f/2,
                                     collisionTestCubePos.z + 3.0f/2 }})){ 
                                         playerCamera->position = OldPos;
                                    }
}