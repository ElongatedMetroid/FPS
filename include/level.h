#ifndef LEVEL_H_
#define LEVEL_H_

#include <raylib.h>
#include <stdbool.h>
#include <util.h>
#include <stddef.h>

typedef struct levelObject{
    Vector3 position;
    Vector3 size;
    float radius;
    Model model;
    #define CUBE 0
    #define PLANE 1
    #define SPHERE 2
    #define CUSTOM 3
    int type;
    Color color;
} LevelObject;

extern LevelObject levelData[100];

void InitLevel(void);
void DrawLevel(void);
bool CheckLevelCollision(Camera *playerCamera);

#endif