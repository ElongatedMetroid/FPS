#include <level.h>

Object levelData[MAX_OBJ];

// GROUND MUST BE THE LAST OBJECT IN THE DATA
void InitLevel(void){
    levelData[0].isValid = true;
    levelData[0].position = (Vector3){0.0f, 3.0f, 0.0f};
    levelData[0].size = (Vector3){3.0f, 3.0f, 3.0f};
    levelData[0].model = LoadModelFromMesh(GenMeshCube(3.0f, 3.0f, 3.0f));
    levelData[0].scale = 1.0f;
    levelData[0].color = GREEN;

    levelData[1].isValid = true;
    levelData[1].position = (Vector3){5.0f, 3.0f, 0.0f};
    levelData[1].model = LoadModelFromMesh(GenMeshSphere(1.0f, 5, 5));
    levelData[1].scale = 1.0f;
    levelData[1].color = GREEN;

    levelData[2].isValid = true;
    levelData[2].position = (Vector3){ -16.0f, 2.5f, 0.0f };
    levelData[2].size = (Vector3){1.0f, 5.0f, 32.0f};
    levelData[2].model = LoadModelFromMesh(GenMeshCube(1.0f, 5.0f, 32.0f));
    levelData[2].scale = 1.0f;
    levelData[2].color = BLUE;

    levelData[3].isValid = true;
    levelData[3].position = (Vector3){ 16.0f, 2.5f, 0.0f };
    levelData[3].size = (Vector3){1.0f, 5.0f, 32.0f};
    levelData[3].model = LoadModelFromMesh(GenMeshCube(1.0f, 5.0f, 32.0f));
    levelData[3].scale = 1.0f;
    levelData[3].color = LIME;

    levelData[4].isValid = true;
    levelData[4].position = (Vector3){ 0.0f, 2.5f, 16.0f };
    levelData[4].size = (Vector3){32.0f, 5.0f, 1.0f};
    levelData[4].model = LoadModelFromMesh(GenMeshCube(32.0f, 5.0f, 1.0f));
    levelData[4].scale = 1.0f;
    levelData[4].color = GOLD;

    levelData[5].isValid = true;
    levelData[5].model = LoadModel("assets/mario/scene.gltf");
    levelData[5].scale = 0.25f;
    levelData[5].size = (Vector3){-2.0f, 2.0f, 2.0f};
    levelData[5].position = (Vector3){-3.0f, 1.5f, 3.0f};
    levelData[5].color = WHITE;

    levelData[6].isValid = true;
    levelData[6].isGround = true;
    levelData[6].position = (Vector3){ 0.0f, 0.0f, 0.0f };
    levelData[6].size = (Vector3){64.0f, 1.0f, 64.0f};
    levelData[6].model = LoadModelFromMesh(GenMeshPlane(64.0f, 64.0f, 20, 20));
    levelData[6].scale = 1.0f;
    levelData[6].color = LIGHTGRAY;
}

int CheckLevelCollision(Camera *playerCamera){
    Vector3 playerSize = { 1.0f, 3.0f, 1.0f};

    BoundingBox PlayerBB = MakeBoundingBox(playerCamera->position, playerSize);
    BoundingBox ObjectBB = {0};

    for(int i = 0; levelData[i].isValid; i++){
        ObjectBB = MakeBoundingBox(levelData[i].position, levelData[i].size);

        if(CheckCollisionBoxes(PlayerBB, ObjectBB) && levelData[i].isGround){
            printf("Collision With Ground");
            return COLLISION_WITH_GROUND;
        }

        if(CheckCollisionBoxes(PlayerBB, ObjectBB)){
            printf("colliding");
            return true;
        }
    }
    
    return false;
}