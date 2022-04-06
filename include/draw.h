#ifndef DRAW_H_
#define DRAW_H_

#include <raylib.h>

typedef struct object{
    bool isValid;
    bool isGround;
    Vector3 position;
    Vector3 positionIfPlayerObj;
    float scale;
    Vector3 size;
    Model model;
    Color color;
} Object;

void DrawObjects(Object *objects);

#endif