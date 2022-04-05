#ifndef LEVEL_H_
#define LEVEL_H_

#include <raylib.h>
#include <stdbool.h>
#include <util.h>
#include <draw.h>
#include <stddef.h>

extern Object levelData[MAX_OBJ];

void InitLevel(void);

#define COLLISION_WITH_GROUND 2
int CheckLevelCollision(Camera *playerCamera);

#endif