#ifndef ACTION_H
#define ACTION_H
#include <QKeyEvent>

#include <drawable.h>


class Action: public QObject
{
    Q_OBJECT
public:
    Action();
    Qt::Key trigger;
    int weight=1;
    virtual void Execute()=0;
    virtual State Plan(State)=0;

};

#endif // ACTION_H
