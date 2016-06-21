#include "puddle.h"
#include "scene.h"

Puddle::Puddle(int posX, int posY):Drawable(posX, posY)
{
    image=QImage(":/puddle.png");
    fieldtype=FieldType::puddle;
}
