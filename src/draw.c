#include <draw.h>

void DrawObjects(Object *objects){
    for(int i = 0; objects[i].isValid; i++){
        DrawModel(objects[i].model, objects[i].position, objects[i].scale, objects[i].color);
    }
}