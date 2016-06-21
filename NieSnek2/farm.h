#ifndef FARM_H
#define FARM_H
#include <drawable.h>
#include <scene.h>

#include <farmnode.h>


class Farm : public Drawable
{
    Q_OBJECT
public:
    Farm(int posX, int posY, int farmEdgeX, int farmEdgeY, FarmNodeType farmType, Direction dir);
    void HumidityDecrease();
    void Hydrate();
    int Humidity;
    int Value;
    Direction dir;
    FarmNodeType farmType;
    QString status;
};

#endif // FARM_H
