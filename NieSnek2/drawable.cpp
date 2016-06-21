#include "drawable.h"
#include "scene.h"

Drawable::Drawable(int posX, int posY)
{
    this->position = QPoint(posX, posY);
    Scene::SceneInstance->Objects.append(this);
}
