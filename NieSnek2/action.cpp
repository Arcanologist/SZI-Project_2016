#include "action.h"
#include "scene.h"

Action::Action()
{
    Scene::SceneInstance->Actions.append(this);
}
