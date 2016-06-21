#include <QKeyEvent>
#include "aturnleft.h"

#include "snake.h"
#include "scene.h"

ATurnLeft::ATurnLeft()
{
    trigger = Qt::Key_A;

}

void ATurnLeft::Execute(){
    Snake *snake = Scene::SceneInstance->MainSnake;
    snake->CurrentState.dir= static_cast<Direction>((snake->CurrentState.dir+3)%4);
    snake->UpdateSnake();  //kolejność zmiany dira i update'a jest istotna ;P

    foreach(Farm* f, Scene::SceneInstance->FarmList){
        f->HumidityDecrease();
    }

    Scene::SceneInstance->repaint();
}

State ATurnLeft::Plan(State a){
    State b = a;
    b.dir = static_cast<Direction>((a.dir+3)%4);
    b.waga++;
    return b;
}
