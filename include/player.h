#ifndef PLAYER_H_
#define PLAYER_H_

#include <raylib.h>
#include <level.h>

void InitPlayer(Camera *playerCamera);
void UpdatePlayerPos(Camera *playerCamera);

#endif