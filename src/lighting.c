#include <lighting.h>

#define GLSL_VERSION 330

Shader shader = {0};
Light light = {0};
void InitLighting(void){
    shader = LoadShader(TextFormat("assets/shaders/base_lighting.vs", GLSL_VERSION), TextFormat("assets/shaders/lighting.fs", GLSL_VERSION));

    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");

    int ambientLoc = GetShaderLocation(shader, "ambient");
    SetShaderValue(shader, ambientLoc, (float[4]){0.1f, 0.1f, 0.1f, 1.0f}, SHADER_UNIFORM_VEC4);

    for(int i = 0; levelData[i].isValid; i++){
        levelData[i].model.materials[0].shader = shader;
    }

    light = CreateLight(LIGHT_DIRECTIONAL, (Vector3){0.0f, 64.0f, 0.0f}, (Vector3){10.0f, 0.0f, 0.0f}, WHITE, shader);
}

void UpdateLighting(Camera *playerCamera){
    UpdateLightValues(shader, light);

    float cameraPos[3] = {playerCamera->position.x, playerCamera->position.y, playerCamera->position.z};
    SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
}