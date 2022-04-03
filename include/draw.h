#ifndef DRAW_H_
#define DRAW_H_

#include <raylib.h>

#define MAX_OBJ 100

typedef struct object{
    bool isValid;
    Vector3 position;
    Vector3 positionIfPlayerObj;
    Vector3 size;
    float radius;
    Model model;
    #define CUBE 0
    #define PLANE 1
    #define SPHERE 2
    #define CUSTOM 3
    int type;
    Color color;
} Object;

void DrawObjects(Object *objects);

#endif