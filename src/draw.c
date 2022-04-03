#include <draw.h>

void DrawObjects(Object *objects){
    for(int i = 0; objects[i].isValid; i++){
        switch(objects[i].type){
            case CUBE:
                DrawCube(objects[i].position, objects[i].size.x, objects[i].size.y, objects[i].size.z, objects[i].color);
                DrawCubeWires(objects[i].position, objects[i].size.x, objects[i].size.y, objects[i].size.z, BLACK);
                break;
            case PLANE:
                DrawPlane(objects[i].position, (Vector2){objects[i].size.x, objects[i].size.z}, objects[i].color);
                DrawCubeWires(objects[i].position, objects[i].size.x, 0,objects[i].size.z, BLACK);
                break;
            case SPHERE:
                DrawSphere(objects[i].position, objects[i].radius, objects[i].color);
                break;
            case CUSTOM:
                break;
        }
    }
}