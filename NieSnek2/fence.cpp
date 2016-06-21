#include "fence.h"
#include "scene.h"

Fence::Fence(int posX, int posY):Drawable(posX, posY)
{
    image=QImage(":/fence.png");
    fieldtype=FieldType::fence;
}
