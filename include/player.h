#ifndef PLAYER_H_
#define PLAYER_H_

#include <raylib.h>
#include <level.h>
#include <util.h>

#define MAX_PLAYER_OBJ 3

// array positions of player objects
#define PISTOL 0
#define RIFFLE 1

extern Object playerObjects[MAX_PLAYER_OBJ];

void InitPlayer(Camera *playerCamera);
void UpdatePlayerPos(Camera *playerCamera);
void UpdatePlayerObjects(Camera *playerCamera);

#endif