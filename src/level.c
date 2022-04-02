#include <level.h>

#define MAX_OBJ 100

LevelObject levelData[MAX_OBJ];

void InitLevel(void){
    levelData[0].position = (Vector3){0.0f, 3.0f, 0.0f};
    levelData[0].size = (Vector3){3.0f, 3.0f, 3.0f};
    levelData[0].type = CUBE;
    levelData[0].color = GREEN;

    levelData[1].position = (Vector3){5.0f, 3.0f, 0.0f};
    levelData[1].radius = 3.0f;
    levelData[1].type = SPHERE;
    levelData[1].color = GREEN;

    levelData[2].position = (Vector3){ 0.0f, 0.0f, 0.0f };
    levelData[2].size.x = 32.0f;
    levelData[2].size.z = 32.0f;
    levelData[2].type = PLANE;
    levelData[2].color = LIGHTGRAY;

    levelData[3].position = (Vector3){ -16.0f, 2.5f, 0.0f };
    levelData[3].size = (Vector3){1.0f, 5.0f, 32.0f};
    levelData[3].type = CUBE;
    levelData[3].color = BLUE;

    levelData[4].position = (Vector3){ 16.0f, 2.5f, 0.0f };
    levelData[4].size = (Vector3){1.0f, 5.0f, 32.0f};
    levelData[4].type = CUBE;
    levelData[4].color = LIME;

    levelData[5].position = (Vector3){ 0.0f, 2.5f, 16.0f };
    levelData[5].size = (Vector3){32.0f, 5.0f, 1.0f};
    levelData[5].type = CUBE;
    levelData[5].color = GOLD;
}

void DrawLevel(void){
    for(int i = 0; i != MAX_OBJ; i++){
        switch(levelData[i].type){
            case CUBE:
                DrawCube(levelData[i].position, levelData[i].size.x, levelData[i].size.y, levelData[i].size.z, levelData[i].color);
                DrawCubeWires(levelData[i].position, levelData[i].size.x, levelData[i].size.y, levelData[i].size.z, BLACK);
                break;
            case PLANE:
                DrawPlane(levelData[i].position, (Vector2){levelData[i].size.x, levelData[i].size.z}, levelData[i].color);
                DrawCubeWires(levelData[i].position, levelData[i].size.x, 0,levelData[i].size.z, BLACK);
                break;
            case SPHERE:
                DrawSphere(levelData[i].position, levelData[i].radius, levelData[i].color);
                break;
            case CUSTOM:
                break;
        }
    }
}

bool CheckLevelCollision(Camera *playerCamera){
    Vector3 playerSize = { 1.0f, 3.0f, 1.0f};

    BoundingBox PlayerBB = MakeBoundingBox(playerCamera->position, playerSize);
    BoundingBox ObjectBB = {0};

    for(int i = 0; i != MAX_OBJ; i++){
        ObjectBB = MakeBoundingBox(levelData[i].position, levelData[i].size);

        if (CheckCollisionBoxes(PlayerBB, ObjectBB))
            return true;
    }
    
    return false;
}