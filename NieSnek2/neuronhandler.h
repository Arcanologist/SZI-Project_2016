#ifndef NEURONHANDLER_H
#define NEURONHANDLER_H


#include "PerceptronLearn.h"
#include "Neuron.h"
#include <QtCore/QList>

class NeuronHandler
{
public:
    NeuronHandler();
    Neuron *perceptron;

private:
    void Learn();
};

#endif // NEURONHANDLER_H
