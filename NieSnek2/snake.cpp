#include "snake.h"
#include "scene.h"
#include <QFile>
#include <QTextStream>

Snake::Snake(int posX, int posY):Drawable(posX, posY)
{
    CurrentState.pos = QPoint(16,16);
    CurrentState.dir = Direction::downDir;
    CurrentState.waga = 0;
    image=QImage(":/dirdown");
}

void Snake::UpdateSnake(){
    switch(this->CurrentState.dir){
    case Direction::upDir:
        image=QImage(":/dirup");
        break;
    case Direction::rightDir:
        image=QImage(":/dirright");
        break;
    case Direction::downDir:
        image=QImage(":/dirdown");
        break;
    case Direction::leftDir:
        image=QImage(":/dirleft");
        break;
    }
}




