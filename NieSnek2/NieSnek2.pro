#-------------------------------------------------
#
# Project created by QtCreator 2014-08-17T14:51:02
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snek
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawable.cpp \
    snake.cpp \
    wall.cpp \
    scene.cpp \
    action.cpp \
    aforward.cpp \
    aturnleft.cpp \
    aturnright.cpp \
    puddle.cpp \
    fence.cpp \
    ajump.cpp \
    farm.cpp \
    farmnode.cpp \
    decision.cpp \
    genetyczny_main.cpp \
    genetyczny_result.cpp \
    Neuron.cpp \
    SimpleNeuronActivationFunction.cpp \
    neuronhandler.cpp \
    PerceptronLearn.cpp

HEADERS  += mainwindow.h \
    drawable.h \
    snake.h \
    wall.h \
    scene.h \
    action.h \
    aforward.h \
    aturnleft.h \
    aturnright.h \
    puddle.h \
    fence.h \
    ajump.h \
    farm.h \
    farmnode.h \
    genetyczny_main.h \
    genetyczny_result.h \
    INeuronActivationFunction.h \
    INeuronLearn.h \
    Neuron.h \
    SimpleNeuronActivationFunction.h \
    neuronhandler.h \
    PerceptronLearn.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
