#include "Neuron.h"
#include "INeuronLearn.h"
#include "SimpleNeuronActivationFunction.h"

#include <QtCore/qstring.h>

Neuron::Neuron(int numberOfInputs, double threshold)
{
    this->numberOfInputs = numberOfInputs;
    inputs.resize(numberOfInputs);
    weights.resize(numberOfInputs);
    this->threshold = threshold;
    activationFunction = new SimpleNeuronActivationFunction();
}

Neuron::Neuron(int numberOfInputs, INeuronActivationFunction* activationFunction, double threshold)
{
    this->numberOfInputs = numberOfInputs;
    inputs.resize(numberOfInputs);
    weights.resize(numberOfInputs);
    this->threshold = threshold;
    this->activationFunction = activationFunction;
}

Neuron::~Neuron()
{
}

int Neuron::getInputCount()
{
    return numberOfInputs;
}

double Neuron::getThreshold()
{
    return threshold;
}

void Neuron::setThreshold(double value)
{
    threshold = value;
}

double Neuron::getInput(int index)
{
    if (index < numberOfInputs)
    {
        return inputs[index];
    }
    else
    {
        throw QString("Couldn't get neuron input at index " + QString::number(index) + " as it have only " + QString::number(numberOfInputs) + "inputs.");
    }
}

void Neuron::setInput(int index, double value)
{
    if (index < numberOfInputs)
    {
        inputs[index] = value;
    }
    else
    {
        throw QString("Couldn't set neuron input at index " + QString::number(index) + " as it have only " + QString::number(numberOfInputs) + "inputs.");
    }
}

NeuronInputs Neuron::getInputs()
{
    return inputs;
}

void Neuron::setInputs(NeuronInputs& inputs)
{
    if (inputs.count() != numberOfInputs)
    {
        throw QString("Can't set input values because number of new values is different than number of neuron inputs");
    }
    else
    {
        this->inputs = inputs;
    }
}

double Neuron::getWeight(int index)
{
    if (index < numberOfInputs)
    {
        return weights[index];
    }
    else
    {
        throw QString("Couldn't get weight of neuron input at index " + QString::number(index) + " as it have only " + QString::number(numberOfInputs) + "inputs.");
    }
}

void Neuron::setWeight(int index, double value)
{
    if (index < numberOfInputs)
    {
        weights[index] = value;
    }
    else
    {
        throw QString("Couldn't set weight of neuron input at index " + QString::number(index) + " as it have only " + QString::number(numberOfInputs) + "inputs.");
    }
}

NeuronWeights Neuron::getWeights()
{
    NeuronWeights weights = NeuronWeights();
    weights.first = threshold;
    weights.second = this->weights;

    return weights;
}

void Neuron::setWeights(NeuronWeights& weights)
{
    threshold = weights.first;
    this->weights = weights.second;
}

double Neuron::calculateOutput()
{
    output = activationFunction->calculateOutput(this);
    return output;
}

double Neuron::getOutput()
{
    return output;
}

double Neuron::boolToSign(bool value)
{
    return (((double)value) - 0.5) * 2;
}

void Neuron::learnSteps(INeuronLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, int steps)
{
    for (int i = 0; i < steps; i++)
    {
        learningStrategy.learn(this, trainingInputs, trainingOutputs);
    }
}

int Neuron::learnErrorThreshold(INeuronLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, double errorThreshold)
{
    bool changed;
    int iterationCounter = 0;
    do
    {
        changed = false;
        iterationCounter++;
        NeuronWeights previousWeights = NeuronWeights();
        previousWeights.first = threshold;
        previousWeights.second = weights;
        learningStrategy.learn(this, trainingInputs, trainingOutputs);
        if (qAbs(threshold - previousWeights.first) > errorThreshold)
        {
            changed = true;
            continue;
        }
        for (int i = 0; i < numberOfInputs; i++)
        {
            if (qAbs(weights[i] - previousWeights.second[i]) > errorThreshold)
            {
                changed = true;
                continue;
            }
        }
    } while (changed == true);
    return iterationCounter - 1;
}
