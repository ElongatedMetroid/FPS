#include <util.h>

BoundingBox MakeBoundingBox(Vector3 position, Vector3 size){
    BoundingBox b = (BoundingBox){(Vector3){position.x - size.x / 2,
                                             position.y - size.y / 2,
                                             position.z - size.z / 2},
                                   (Vector3){position.x + size.x / 2,
                                             position.y + size.y / 2,
                                             position.z + size.z / 2}};
    return b;
}