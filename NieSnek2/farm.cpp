#include "farm.h"

#include <scene.h>

Farm::Farm(int posX, int posY, int farmEdgeX, int farmEdgeY, FarmNodeType farmType, Direction dir) : Drawable(posX, posY)
{
    image=QImage(":/farm.png");
    //fieldtype=FieldType::fence;
    this->farmType = farmType;

    int CornerXA;
    int CornerXB;
    int CornerYA;
    int CornerYB;

    if(posX < farmEdgeX){
        CornerXA = posX; CornerXB = farmEdgeX;
    }
    else{
        CornerXA = farmEdgeX; CornerXB = posX;
    }
    if(posY < farmEdgeY){
        CornerYA = posY; CornerYB = farmEdgeY;
    }
    else{
        CornerYA = farmEdgeY; CornerYB = posY;
    }

    for(int x = CornerXA; x <= CornerXB; x++){
        for(int y = CornerYA; y<= CornerYB; y++){
            if(!(x==posX&&y==posY)){
                new FarmNode(x,y,farmType);
            }

        }
    }
    Humidity=3000;
    Value = 1000;
    this->dir = dir;
}

void Farm::HumidityDecrease(){
    switch(this->farmType){
    case FarmNodeType::Zyto:
        this->Humidity-=4;
    break;
    case FarmNodeType::Pszenica:
        this->Humidity-=3;
    break;
    case FarmNodeType::Kukurydza:
        this->Humidity-=2;
    break;
    case FarmNodeType::Slonecznik:
        this->Humidity-=1;
    break;
    }

    if(Humidity <=800){
        image=QImage(":/farmCritical");
        status = "CRIT";
    } else if (Humidity <= 2000){
        image=QImage(":/farmNormal");
        status = "NORM";
    } else {
        image=QImage(":/farmExcellent.png");
        status = "NORM";
    }
    if(Value>0){
        Value -= (1000-Humidity)/1000;
    }
}

void Farm::Hydrate(){
    Humidity = 3000;
}
