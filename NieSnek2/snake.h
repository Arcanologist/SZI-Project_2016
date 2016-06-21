#ifndef SNAKE_H
#define SNAKE_H
#include <QList>
#include <QPair>
#include "drawable.h"




class Snake : public Drawable
{
    Q_OBJECT

private:
    QPoint a = this->position;
public:
    int snakeSpeed;
    QImage tailimage;

    Snake(int posX, int posY);
    void LoadSpeed();
    void UpdateSnake();

    //QPoint pos;
    //Direction dir;
    //Mode mode;



    //this->position

    State CurrentState;



    //QPair<QPoint, Direction> snake;

    //Direction HeadDirection;


};


#endif // SNAKE_H
