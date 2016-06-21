#ifndef FARMNODE_H
#define FARMNODE_H

#include <QObject>

#include <QPoint>
#include <QImage>


enum FarmNodeType{
    Zyto=0, Pszenica=1, Kukurydza=2, Slonecznik=3,
};

class FarmNode : public QObject
{
    Q_OBJECT
public:
    FarmNode(int posX, int posY, FarmNodeType farmtype);
    void TuraRobaliCheck();
    void TuraRobaliSpawn();
    static void ClassTest();

    QPoint position;
    QImage image;
    FarmNodeType farmtype;
    bool saRobale=false;
    int sasiedziRobale;
};
#endif // FARMNODE_H
