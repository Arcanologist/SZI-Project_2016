#include <QKeyEvent>
#include "AForward.h"

#include "snake.h"
#include "scene.h"

AForward::AForward()
{
    trigger = Qt::Key_W;

}

void AForward::Execute(){
    Snake *snake = Scene::SceneInstance->MainSnake;

    switch(snake->CurrentState.dir){
    case Direction::upDir:
        snake->CurrentState.pos.setY(snake->CurrentState.pos.y()-1);
        break;
    case Direction::rightDir:
        snake->CurrentState.pos.setX(snake->CurrentState.pos.x()+1);
        break;
    case Direction::downDir:
        snake->CurrentState.pos.setY(snake->CurrentState.pos.y()+1);
        break;
    case Direction::leftDir:
        snake->CurrentState.pos.setX(snake->CurrentState.pos.x()-1);
        break;
    }

    foreach(Farm* f, Scene::SceneInstance->FarmList){
        f->HumidityDecrease();
    }

    Scene::SceneInstance->repaint();
}


State AForward::Plan(State a){
    State b = a;
    switch(a.dir){
    case Direction::upDir:
        b.pos.setY(a.pos.y()-1);
        break;
    case Direction::rightDir:
        b.pos.setX(a.pos.x()+1);
        break;
    case Direction::downDir:
        b.pos.setY(a.pos.y()+1);
        break;
    case Direction::leftDir:
        b.pos.setX(a.pos.x()-1);
        break;
    }

    foreach(Drawable* o, Scene::SceneInstance->Objects){
        if(o->position.x() == b.pos.x() && o->position.y() == b.pos.y()){
            if(o->fieldtype==FieldType::wall || o->fieldtype==FieldType::fence)
            b.mode=Mode::debug_null;
            else if (o->fieldtype==FieldType::puddle)
                b.waga=b.waga+5; //oraz ten poza pętlą - razem 6
        }
    }

    b.waga++;
    return b;


}
