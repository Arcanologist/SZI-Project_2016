#include <QKeyEvent>
#include "aturnright.h"

#include "snake.h"
#include "scene.h"

ATurnRight::ATurnRight()
{
   trigger = Qt::Key_D;

}

void ATurnRight::Execute(){
    Snake *snake = Scene::SceneInstance->MainSnake;
    snake->CurrentState.dir= static_cast<Direction>((snake->CurrentState.dir+1)%4);
    snake->UpdateSnake();  //kolejność zmiany dira i update'a jest istotna ;P

    foreach(Farm* f, Scene::SceneInstance->FarmList){
        f->HumidityDecrease();
    }

    Scene::SceneInstance->repaint();
}

State ATurnRight::Plan(State a){
    State b = a;
    b.dir = static_cast<Direction>((a.dir+1)%4);
    b.waga++;
    return b;
}
