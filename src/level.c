#include <level.h>

Object levelData[MAX_OBJ];

void InitLevel(void){
    levelData[0].isValid = true;
    levelData[0].position = (Vector3){0.0f, 3.0f, 0.0f};
    levelData[0].size = (Vector3){3.0f, 3.0f, 3.0f};
    levelData[0].type = CUBE;
    levelData[0].color = GREEN;

    levelData[1].isValid = true;
    levelData[1].position = (Vector3){5.0f, 3.0f, 0.0f};
    levelData[1].radius = 3.0f;
    levelData[1].type = SPHERE;
    levelData[1].color = GREEN;

    levelData[2].isValid = true;
    levelData[2].position = (Vector3){ 0.0f, 0.0f, 0.0f };
    levelData[2].size.x = 32.0f;
    levelData[2].size.z = 32.0f;
    levelData[2].type = PLANE;
    levelData[2].color = LIGHTGRAY;

    levelData[3].isValid = true;
    levelData[3].position = (Vector3){ -16.0f, 2.5f, 0.0f };
    levelData[3].size = (Vector3){1.0f, 5.0f, 32.0f};
    levelData[3].type = CUBE;
    levelData[3].color = BLUE;

    levelData[4].isValid = true;
    levelData[4].position = (Vector3){ 16.0f, 2.5f, 0.0f };
    levelData[4].size = (Vector3){1.0f, 5.0f, 32.0f};
    levelData[4].type = CUBE;
    levelData[4].color = LIME;

    levelData[5].isValid = true;
    levelData[5].position = (Vector3){ 0.0f, 2.5f, 16.0f };
    levelData[5].size = (Vector3){32.0f, 5.0f, 1.0f};
    levelData[5].type = CUBE;
    levelData[5].color = GOLD;

    levelData[6].isValid = true;
    levelData[6].model = LoadModel("/media/Stuff500GB/repos/FPS/assets/mario/scene.gltf");
    levelData[6].scale = 0.25f;
    levelData[6].size = (Vector3){-2.0f, 2.0f, 2.0f};
    levelData[6].position = (Vector3){-3.0f, 1.5f, 3.0f};
    levelData[6].type = CUSTOM;
    levelData[6].color = WHITE;
}

bool CheckLevelCollision(Camera *playerCamera){
    Vector3 playerSize = { 1.0f, 3.0f, 1.0f};

    BoundingBox PlayerBB = MakeBoundingBox(playerCamera->position, playerSize);
    BoundingBox ObjectBB = {0};

    for(int i = 0; levelData[i].isValid; i++){
        ObjectBB = MakeBoundingBox(levelData[i].position, levelData[i].size);

        if (CheckCollisionBoxes(PlayerBB, ObjectBB))
            return true;
    }
    
    return false;
}