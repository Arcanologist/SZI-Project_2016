#include "wall.h"
#include "scene.h"

Wall::Wall(int posX, int posY):Drawable(posX, posY)
{
    image=QImage(":/wall.png");
    fieldtype=FieldType::wall;
}

