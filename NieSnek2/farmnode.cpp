#include "farmnode.h"
#include "Neuron.h"

#include "scene.h"
//meanwhile
#include <QMessageBox>

FarmNode::FarmNode(int posX, int posY, FarmNodeType farmtype)
{
    this->farmtype = farmtype;
    this->position = QPoint(posX,posY);
    if(farmtype == FarmNodeType::Zyto)
        image=QImage(":/farmZyto.png");
    if(farmtype == FarmNodeType::Pszenica)
        image=QImage(":/farmPszenica.png");
    if(farmtype == FarmNodeType::Kukurydza)
        image=QImage(":/farmKukurydza.png");
    if(farmtype == FarmNodeType::Slonecznik)
        image=QImage(":/farmSlonecznik.png");

    Scene::SceneInstance->FarmNodeList.append(this);
}

void FarmNode::TuraRobaliCheck()
{
    this->sasiedziRobale = 0;
    foreach(FarmNode *f, Scene::SceneInstance->FarmNodeList)
    {
        if(((this->position.x()==f->position.x() ||
             this->position.x()==f->position.x()+1 ||
             this->position.x()==f->position.x()-1)  &&
            (this->position.y()==f->position.y() ||
             this->position.y()==f->position.y()+1 ||
             this->position.y()==f->position.y()-1)))
        {
            if(f->saRobale)
            {
                this->sasiedziRobale++;
            }
        }


    }
    /*if(this->sasiedziRobale >0)
    {
        QMessageBox msgBox;
        QString a = QString::number(this->sasiedziRobale);
        msgBox.setText(a);
        msgBox.exec();
    }*/
}

void FarmNode::TuraRobaliSpawn()
{
    //wymieranie
    if(this->sasiedziRobale <2 && this->saRobale)
    {
        this->saRobale = false;
        if(this->farmtype == FarmNodeType::Zyto)
            image=QImage(":/farmZyto.png");
        if(this->farmtype == FarmNodeType::Pszenica)
            image=QImage(":/farmPszenica.png");
        if(this->farmtype == FarmNodeType::Kukurydza)
            image=QImage(":/farmKukurydza.png");
        if(this->farmtype == FarmNodeType::Slonecznik)
            image=QImage(":/farmSlonecznik.png");

    }





    //spawn
    if(rand()%100 == 0)
    {
        saRobale = true;
        image = QImage(":/bug.png");
    }
}

void FarmNode::ClassTest()
{
    Neuron jakkolwiek = Neuron(9);

}
