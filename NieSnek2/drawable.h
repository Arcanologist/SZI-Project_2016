#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QImage>
#include <QPair>
#include <QPoint>

enum Direction
{
    upDir=0,rightDir=1,downDir=2,leftDir=3
};

enum Mode{
    car=0, helicopter=1, debug_null=2
};

enum FieldType{
    special=0, wall=1, puddle=2, fence=3, field=4
};

struct State{
    QPoint pos;
    Direction dir;
    Mode mode;
    int waga;

    bool operator!() const
    {
        return (mode==Mode::debug_null);
    }
};

//        bool operator==(const QueueElement& a) const
//{
//    return (Stan.pos == a.Stan.pos && Stan.dir == a.Stan.dir);
//}

class Drawable: public QObject
{
    Q_OBJECT
public:
    Drawable(int posX, int posY);
    QPoint position;
    QImage image;
    FieldType fieldtype =FieldType::special;
};

#endif // DRAWABLE_H
