#ifndef LIGHTING_H_
#define LIGHTING_H_

#include <raylib.h>
#include <level.h>
#include <rlights.h>

extern Shader shader;

void InitLighting(void);
void UpdateLighting(Camera *playerCamera);

#endif