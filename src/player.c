#include <player.h>

Object playerObjects[MAX_PLAYER_OBJ];

void InitPlayer(Camera *playerCamera){
    playerCamera->position = (Vector3){ 4.0f, 2.0f, 4.0f };
    playerCamera->target = (Vector3){ 0.0f, 1.8f, 0.0f };
    playerCamera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
    playerCamera->fovy = 100.0f;
    playerCamera->projection = CAMERA_PERSPECTIVE;

    SetCameraMode(*playerCamera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    playerObjects[0].isValid = true;
    playerObjects[0].positionIfPlayerObj = (Vector3){0.5f, 0.5f, 1.0f};
    playerObjects[0].size = (Vector3){1.0f, 1.0f, 1.0f};
    playerObjects[0].type = CUBE;
    playerObjects[0].color = BLUE;
}

void UpdatePlayerPos(Camera *playerCamera){
    
    //add deltatime something here

    Vector3 OldPos = playerCamera->position;

    UpdateCamera(playerCamera);

    if(CheckLevelCollision(playerCamera))
        playerCamera->position = OldPos;
}

void UpdatePlayerObjects(Camera *playerCamera){
    for(int i = 0; playerObjects[i].isValid; i++){
        playerObjects[i].position.x = playerObjects[i].positionIfPlayerObj.x + playerCamera->position.x;
        playerObjects[i].position.y = playerObjects[i].positionIfPlayerObj.y + playerCamera->position.y;
        playerObjects[i].position.z = playerObjects[i].positionIfPlayerObj.z + playerCamera->position.z;
    }
}