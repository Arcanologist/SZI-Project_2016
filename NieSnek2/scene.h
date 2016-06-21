#ifndef SCENE_H
#define SCENE_H
#include <QList>
#include <QWidget>
#include <QPainter>

#include "snake.h"

#include "farm.h"
#include "farmnode.h"

#include "action.h"
#include "aforward.h"
#include "aturnleft.h"
#include "aturnright.h"
#include "ajump.h"

#include <queue>
#include <deque>
#include <iostream>
#include "neuronhandler.h"

class Scene:public QWidget
{
    Q_OBJECT
public:
    Scene(QWidget* parent = 0, Qt::WindowFlags f = 0);

    static Scene* SceneInstance;

    QList<Drawable*> Objects;
    QList<class Farm*> FarmList;
    QList<FarmNode*> FarmNodeList;
    QList<Action*> Actions;
    QList<Action*> ActionQueue;
    NeuronHandler BugDetector;
    void CheckAllCollisions();
    void AStarAlgorithm(State, State);
    //QPainter painter;
    Snake* MainSnake;

    AForward* AF;
    ATurnLeft* AL;
    ATurnRight* AR;
    AJump* AJ;

    struct QueueElement{
        State Stan;
        int parent;
        Action* akcja;

        bool operator==(const QueueElement& a) const
        {
            return (Stan.pos == a.Stan.pos && Stan.dir == a.Stan.dir);
        }
    };

        struct Compare{
            bool operator()(const struct QueueElement& s1,  const struct QueueElement& s2) const
            {
                return s2.Stan.waga < s1.Stan.waga;
            }
        };

        std::priority_queue <QueueElement,std::vector<QueueElement>,Compare> fringe;
        QList<QueueElement> explored;

        State cel;

        int timerId;
        bool timerAlive;
        bool automatic;
    private:
        void FarmField();
        //Snake* MainSnake;
        int height;
        int width;
    protected:
        void keyPressEvent(QKeyEvent* keyEvent);
        void timerEvent(QTimerEvent* timerEvent);
        void paintEvent(QPaintEvent* paintEvent);
    signals:
        void moveSnake();
        void rotateSnake(bool left); //trollcode
    };

#endif // SCENE_H
