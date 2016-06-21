#include "scene.h"
#include "drawable.h"
#include "wall.h"
#include "puddle.h"
#include "fence.h"
//#include "farm.h"
#include <QKeyEvent>
#include<QtCore/QDebug>

#include "action.h"
#include "aforward.h"
#include "aturnleft.h"
#include "aturnright.h"
#include "ajump.h"

#include <QMessageBox>

#include "decision.cpp"

#include "genetyczny_main.h"



QString conv(FarmNodeType x){
    if(x == FarmNodeType::Zyto) return "Z";
    if(x == FarmNodeType::Pszenica) return "P";
    if(x == FarmNodeType::Kukurydza) return "K";
    if(x == FarmNodeType::Slonecznik) return "S";
}



Scene* Scene::SceneInstance = 0;


Scene::Scene(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{
    Objects = QList<Drawable*>();
    FarmList = QList<Farm*>();
    FarmNodeList = QList<FarmNode*>();
    Actions = QList<Action*>();
    BugDetector = NeuronHandler();
    SceneInstance = this;
    MainSnake = new Snake(-1,-1);
    width = 33;
    height = 33;


    AF = new AForward();
    AL = new ATurnLeft();
    AR = new ATurnRight();
    //AJ = new AJump();

    std::priority_queue <QueueElement,std::vector<QueueElement>,Compare> fringe;

    connect(this, SIGNAL(moveSnake()), MainSnake, SLOT(moveSnake()));
    connect(this, SIGNAL(rotateSnake(bool)), MainSnake, SLOT(rotateSnake(bool)));

    //Ramka
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(i==0 || i == width -1 || j==0 || j == height -1)
            {
                new Wall(i,j);
            }
        }
    }


    //Poprzeczki
    for(int i=2; i<=12;i++){
        new Wall(i,16);
        new Wall(width-i-1,16);
        new Wall(16,i);
        new Wall(16,height-i-1);
    }

    //Kałuże
    new Puddle(1,16);
    new Puddle(width-2,16);
    new Puddle(16,1);
    new Puddle(16,height-2);
    new Puddle(16,16);

    //Krzyż
    for(int i = 13; i <= 19; i++)
    {
        for(int j = 13; j <= 19; j++)
        {
            if((i==13 || i==19 || j==13 || j==19)/* && */)
            {
                if(!(i==15&&j==19) && !(i==19&&j==17) && !(i==13&&j==15) && !(i==17&&j==13)){
                    new Wall(i,j);
                }
            }
        }
    }

    //Płotki
    for(int i=2; i<=12; i++){
        new Fence(i,13);
    }
    for(int i=20; i<=width-3; i++){
        new Fence(i,19);
    }
    for(int j=2; j<=12; j++){
        new Fence(19,j);
    }

    for(int j=20; j<=height-3; j++){
        new Fence(13,j);
    }


    genetyczny_main* gmain = new genetyczny_main;
    std::vector<int> a = gmain->execute();

    //Pola-węzły
    FarmList.append(new Farm(1,12,15,1,(FarmNodeType)a[0],Direction::upDir));
    FarmList.append(new Farm(20,1,31,15,(FarmNodeType)a[1],Direction::rightDir));
    FarmList.append(new Farm(12,31,1,17,(FarmNodeType)a[2],Direction::leftDir));
    FarmList.append(new Farm(31,20,17,31,(FarmNodeType)a[3],Direction::downDir));

    //Testy granic
    new Wall(31,31);
    //new Wall(1,1);

    grabKeyboard();

    timerId=0;
    timerAlive=false;
    automatic=true;
}


void Scene::keyPressEvent(QKeyEvent *keyEvent){

    foreach(Action* a, Actions){
        if(a->trigger == keyEvent->key()){
            a->Execute();
            break;
        }
    }

    QMessageBox msgBox;
    QString a;

    State x;
    QueueElement y;
    QueueElement z;
    bool dokonano = false;

    switch (keyEvent->key()) {
    case Qt::Key_P:
        if(!timerAlive){
            timerId= startTimer(200);
            timerAlive=true;
        } else {
            killTimer(timerId);
            timerAlive=false;
        }
        break;

    case Qt::Key_O:
        if(automatic=false){
            automatic=true;
        } else {
            automatic=false;
        }
        break;

    case Qt::Key_Space:
        a = "Rozmiar Fringe: " + QString::number(fringe.size());
        msgBox.setText(a);
        msgBox.exec();
        break;
    case Qt::Key_Q:
        x = {QPoint(1,1), Direction(Direction::downDir), Mode(Mode::car),1};
        y ={x};
        fringe.push(y);
        x = {QPoint(1,1), Direction(Direction::downDir), Mode(Mode::car),3};
        y ={x};
        fringe.push(y);
        x = {QPoint(1,1), Direction(Direction::downDir), Mode(Mode::car),2};
        y ={x};
        fringe.push(y);
        break;

    case Qt::Key_E:
        if(fringe.size() != 0){
            z = fringe.top();
            fringe.pop();
            int i = z.Stan.waga; //mmm?

            a ="Waga: " + QString::number(i);
            msgBox.setText(a);
            msgBox.exec();

            a = "pozycja X: " + QString::number(z.Stan.pos.x());
            msgBox.setText(a);
            msgBox.exec();

            a = "pozycja Y: " + QString::number(z.Stan.pos.y());
            msgBox.setText(a);
            msgBox.exec();

            a = "Kierunek (enum, 0-up): " +  QString::number(z.Stan.dir);
            msgBox.setText(a);
            msgBox.exec();

            a = "Parent:" +  QString::number(z.parent);
            msgBox.setText(a);
            msgBox.exec();
        } else {
            a = "Fringe jest pusty!";
            msgBox.setText(a);
            msgBox.exec();
        }
        break;

    case Qt::Key_R:
        cel = MainSnake->CurrentState;
        break;

    case Qt::Key_T:
        if(ActionQueue.size()==0){
            SceneInstance->AStarAlgorithm(MainSnake->CurrentState, cel);
        } else {
            a = "Jestem w trakcie wykonywania innych akcji!";
            msgBox.setText(a);
            msgBox.exec();
        }
        break;

    case Qt::Key_F:
        if(ActionQueue.size()!=0){
            ActionQueue.first()->Execute();
            ActionQueue.removeFirst();
        } else {
            a = "ActionQueue jest pusty!";
            msgBox.setText(a);
            msgBox.exec();
        }
        break;

    case Qt::Key_Z:

        foreach(Farm* f, FarmList){
            if(MainSnake->CurrentState.pos == f->position && MainSnake->CurrentState.dir == f->dir){
                SceneInstance->FarmField();
                f->Hydrate();
                dokonano = true;
                break;
            }
        }
        if(!dokonano)
        {
            a = "Nie stoisz na polu do podlania lub nie jesteś odpowiednio obrócony!";
            msgBox.setText(a);
            msgBox.exec();
        }
        break;

    case Qt::Key_F1:
        foreach(FarmNode* f, FarmNodeList){
            f->TuraRobaliCheck();
        }

        foreach(FarmNode* f, FarmNodeList){
            f->TuraRobaliSpawn();
        }

        repaint();
        break;

    case Qt::Key_F2:
    {
        foreach (FarmNode* f, FarmNodeList)
        {
            QVector<QVector<double>> dangerZone = QVector<QVector<double>>();
            dangerZone << QVector<double>(3);
            dangerZone << QVector<double>(3);
            dangerZone << QVector<double>(3);
            foreach(FarmNode* g, FarmNodeList)
            {
                QPoint diff = f->position - g->position;
                if(qAbs(diff.x())<=1 && qAbs(diff.y())<=1 )
                {
                    diff+=QPoint(1,1);
                    dangerZone[diff.x()][diff.y()] = double(g->saRobale);

                }

            }

            NeuronInputs dangerInputs = NeuronInputs();
            for(int x = 0; x < 3; x++ )
            {
                for(int y = 0; y < 3; y++ )
                {
                    dangerInputs << dangerZone[x][y];
                }
            }
            BugDetector.perceptron->setInputs(dangerInputs);
            if(BugDetector.perceptron->calculateOutput()==1.0)
            {
                if(f->saRobale){
                    f->image = QImage(":/bugcured.png");
                    f->saRobale = false;

                }else{
                    f->image = QImage(":/snakehead.png");
                }
                qDebug() << f->position.x() << " " <<f->position.y();
                repaint();
            }
        }
        break;

    case Qt::Key_F3:
            foreach(FarmNode* f, FarmNodeList){
                if(f->farmtype == FarmNodeType::Zyto)
                    f->image=QImage(":/farmZyto.png");
                if(f->farmtype == FarmNodeType::Pszenica)
                    f->image=QImage(":/farmPszenica.png");
                if(f->farmtype == FarmNodeType::Kukurydza)
                    f->image=QImage(":/farmKukurydza.png");
                if(f->farmtype == FarmNodeType::Slonecznik)
                    f->image=QImage(":/farmSlonecznik.png");
                if(f->saRobale)
                    f->image=QImage(":/bug.png");
            }

            repaint();
            break;
        }
    }

}

bool AStarDone = false;
bool intimer = false;
void Scene::timerEvent(QTimerEvent* timerEvent){
    QMessageBox msgBox;
    QString a;
    if(!intimer){
        intimer=true;

        if(!ActionQueue.empty()){
            ActionQueue.first()->Execute();
            ActionQueue.removeFirst();

        } else if(!AStarDone  && automatic){

            int x = MainSnake->CurrentState.pos.x();
            int y = MainSnake->CurrentState.pos.y();
            int position;
            FarmNodeType type;
            QString TypeB,TypeC,TypeD,HumidityB,HumidityC,HumidityD;
            if(y>0 && y<=15 && x>0 && x<=16){//lewo góra
                position = 1;
                foreach(Farm* f, FarmList){
                    if(f->dir == rightDir){
                        type=f->farmType;
                        TypeB=conv(type);
                        HumidityB=f->status;
                    }
                    if(f->dir == downDir){
                        type=f->farmType;
                        TypeD=conv(type);
                        HumidityD=f->status;
                    }
                    if(f->dir == leftDir){
                        type=f->farmType;
                        TypeC=conv(type);
                        HumidityC=f->status;
                    }
                }
            }
            else if(y>0 && y<=14 && x>=17 && x<32){ //prawo góra
                position = 2;
                foreach(Farm* f, FarmList){
                    if(f->dir == downDir){
                        type=f->farmType;
                        TypeB=conv(type);
                        HumidityB=f->status;
                    }
                    if(f->dir == leftDir){
                        type=f->farmType;
                        TypeD=conv(type);
                        HumidityD=f->status;
                    }
                    if(f->dir == upDir){
                        type=f->farmType;
                        TypeC=conv(type);;
                        HumidityC=f->status;
                    }
                }
            } else if(y<32 && y>=17 && x>=16 && x<32){//prawo dół-/
                position = 3;
                foreach(Farm* f, FarmList){
                    if(f->dir == leftDir){
                        type=f->farmType;
                        TypeB=conv(type);;
                        HumidityB=f->status;
                    }
                    if(f->dir == upDir){
                        type=f->farmType;
                        TypeD=conv(type);;
                        HumidityD=f->status;
                    }
                    if(f->dir == rightDir){
                        type=f->farmType;
                        TypeC=conv(type);;
                        HumidityC=f->status;
                    }
                }
            }
            else{ //lewo dół
                position = 4;
                foreach(Farm* f, FarmList){
                    if(f->dir == upDir){
                        type=f->farmType;
                        TypeB=conv(type);
                        HumidityB=f->status;
                    }
                    if(f->dir == rightDir){
                        type=f->farmType;
                        TypeD=conv(type);
                        HumidityD=f->status;
                    }
                    if(f->dir == downDir){
                        type=f->farmType;
                        TypeC=conv(type);
                        HumidityC=f->status;
                    }
                }
            }
            State A = {QPoint(1,12), Direction(Direction::upDir), Mode(Mode::car),1};
            State B = {QPoint(20,1), Direction(Direction::rightDir), Mode(Mode::car),1};
            State C = {QPoint(31,20), Direction(Direction::downDir), Mode(Mode::car),1};
            State D = {QPoint(12,31), Direction(Direction::leftDir), Mode(Mode::car),1};
            State goat;
            a = "Parametry: " + TypeB + ", " + TypeC + ", " + TypeD + ", " + HumidityB + ", " + HumidityC + ", " + HumidityD;
            msgBox.setText(a);
            msgBox.exec();
            QString dec = decision(TypeB,TypeC,TypeD,HumidityB,HumidityC,HumidityD);
            a = "Jesteśmy na pozycji " + QString::number(position) + " .Jedziemy do " + dec + "!";
            msgBox.setText(a);
            msgBox.exec();
            if (dec == "B"){
                if(position == 1) {goat = B;}
                else if(position == 2) {goat = C;}
                else if(position == 3) {goat = D;}
                else {goat = A;}
            }
            else if (dec == "C"){
                if(position == 1) {goat = D;}
                else if(position == 2) {goat = A;}
                else if(position == 3) {goat = B;}
                else {goat = C;}
            }
            else {
                if(position == 1) {goat = C;}
                else if(position == 2) {goat = D;}
                else if(position == 3) {goat = A;}
                else {goat = B;}
            };

            SceneInstance->AStarAlgorithm(MainSnake->CurrentState, goat);
            AStarDone = true;
        } else if (automatic) {
            bool dokonano = false;
            foreach(Farm* f, FarmList){
                if(MainSnake->CurrentState.pos == f->position && MainSnake->CurrentState.dir == f->dir){
                    SceneInstance->FarmField();
                    f->Hydrate();
                    dokonano = true;
                    break;
                }
            }
            if(!dokonano)
            {
                a = "Nie stoisz na polu do podlania lub nie jesteś odpowiednio obrócony!";
                msgBox.setText(a);
                msgBox.exec();
            }
            AStarDone = false;
        }
        repaint();
        intimer=false;
    }
}

void Scene::FarmField(){
    ActionQueue.append(AR);
    for(int i=0; i<=11; i++){
        for(int j=0; j<=13; j++)
            ActionQueue.append(AF);
        if(i%2==0){
            ActionQueue.append(AL);
            ActionQueue.append(AF);
            ActionQueue.append(AL);
        } else {
            ActionQueue.append(AR);
            ActionQueue.append(AF);
            ActionQueue.append(AR);
        }
    }
    for(int i=1; i<=3;i++){
        ActionQueue.removeLast();
    }
}


void Scene::paintEvent(QPaintEvent *paintEvent)
{
    QPainter painter(this);

    //QTransform up;
    //QTransform down;
    //down.rotate(180);
    //QTransform left;
    //left.rotate(90);
    //QTransform right;
    //right.rotate(270);

    foreach(FarmNode* f, FarmNodeList){
        painter.drawImage(f->position * 16, f->image);
    }

    foreach(Drawable* o, Objects)
    {
        painter.drawImage(o->position * 16, o->image);
    }

    painter.drawImage(MainSnake->CurrentState.pos * 16, MainSnake->image);
}





void Scene::AStarAlgorithm(State StartState, State StanDocelowy){

    QueueElement z;
    State stan;
    int wskaznik;

    //Graphsearch
    //Umieść Stan początkowy na Fringe
    fringe.push({StartState,-1}); //parent=-1 oznacza korzeń, brak akcji oznacza wylanie się z kodu


    //Dopóki kolejka niejest pusta
    while(fringe.size() != 0){
        //Pobierz element z fringe
        z = fringe.top();
        fringe.pop();
        stan = z.Stan;

        //Jeżeli nie ma danego stanu w explored
        if(!explored.contains({stan})){
            //Jeżeli stan jest stanem doceolowym
            if( stan.pos == StanDocelowy.pos &&
                    stan.dir == StanDocelowy.dir){

                //Utwórz ścieżkę ActionQueue przy pomocy parentów elementów explored
                while(z.parent != -1){
                    ActionQueue.push_front(z.akcja);
                    z = explored[z.parent];
                }

                explored.clear();
                fringe = std::priority_queue <QueueElement,std::vector<QueueElement>,Compare>(); //priority_queue.clear() nie istnieje?
                return;
            }

            //Dodaj stan do explored
            explored.push_back(z);
            wskaznik = explored.size()-1;

            foreach(Action* a, Actions){
                if(!a->Plan(stan)){} //Jeżeli stan nie jest stanem o Mode::debug_null
                else
                    fringe.push({a->Plan(stan),wskaznik,a});
            }
        }
    }

    //Jeżeli fringe jest pusty i nie znaleźliśmy przejścia:
    QMessageBox msgBox;
    QString a = "Nie ma przejścia!";
    msgBox.setText(a);
    msgBox.exec();
    explored.clear();
    fringe = std::priority_queue <QueueElement,std::vector<QueueElement>,Compare>(); //priority_queue.clear() nie istnieje?
    return;
}
