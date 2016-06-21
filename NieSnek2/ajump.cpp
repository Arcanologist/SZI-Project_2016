#include <QKeyEvent>
#include "AJump.h"

#include "snake.h"
#include "scene.h"

AJump::AJump()
{
    trigger = Qt::Key_S;

}

void AJump::Execute(){
    Snake *snake = Scene::SceneInstance->MainSnake;

    switch(snake->CurrentState.dir){
    case Direction::upDir:
        snake->CurrentState.pos.setY(snake->CurrentState.pos.y()-2);
        break;
    case Direction::rightDir:
        snake->CurrentState.pos.setX(snake->CurrentState.pos.x()+2);
        break;
    case Direction::downDir:
        snake->CurrentState.pos.setY(snake->CurrentState.pos.y()+2);
        break;
    case Direction::leftDir:
        snake->CurrentState.pos.setX(snake->CurrentState.pos.x()-2);
        break;
    }

    foreach(Farm* f, Scene::SceneInstance->FarmList){
        f->HumidityDecrease();
    }

    Scene::SceneInstance->repaint();
}


State AJump::Plan(State a){
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
            if(o->fieldtype==FieldType::wall)
            b.mode=Mode::debug_null;
        }
    }

    switch(a.dir){
    case Direction::upDir:
        b.pos.setY(b.pos.y()-1);
        break;
    case Direction::rightDir:
        b.pos.setX(b.pos.x()+1);
        break;
    case Direction::downDir:
        b.pos.setY(b.pos.y()+1);
        break;
    case Direction::leftDir:
        b.pos.setX(b.pos.x()-1);
        break;
    }


    foreach(Drawable* o, Scene::SceneInstance->Objects){
        if(o->position.x() == b.pos.x() && o->position.y() == b.pos.y()){
            if(o->fieldtype==FieldType::wall || o->fieldtype==FieldType::fence)
            b.mode=Mode::debug_null;
        }
    }

    b.waga=b.waga+5; //+5 / +1
    return b;


}
