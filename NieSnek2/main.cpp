#include "mainwindow.h"
#include "scene.h"
#include <QApplication>
#include <QBoxLayout>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime::currentTime().msec());
    MainWindow w;
    w.show();

    return a.exec();
}
