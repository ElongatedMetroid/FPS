#include <player.h>

void InitPlayer(Camera *playerCamera){
    playerCamera->position = (Vector3){ 4.0f, 2.0f, 4.0f };
    playerCamera->target = (Vector3){ 0.0f, 1.8f, 0.0f };
    playerCamera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
    playerCamera->fovy = 100.0f;
    playerCamera->projection = CAMERA_PERSPECTIVE;

    SetCameraMode(*playerCamera, CAMERA_FIRST_PERSON); // Set a first person camera mode
}

void UpdatePlayerPos(Camera *playerCamera){
    Vector3 OldPos = playerCamera->position;

    UpdateCamera(playerCamera);

    if(CheckLevelCollision(playerCamera))
        playerCamera->position = OldPos;
}