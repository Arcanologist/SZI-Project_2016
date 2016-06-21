#include "SimpleNeuronActivationFunction.h"
#include "Neuron.h"


SimpleNeuronActivationFunction::SimpleNeuronActivationFunction()
{
}


SimpleNeuronActivationFunction::~SimpleNeuronActivationFunction()
{
}

double SimpleNeuronActivationFunction::calculateOutput(Neuron* neuron)
{
	double value = neuron->getThreshold();

	for (int i = 0; i < neuron->getInputCount(); i++)
	{
		value += neuron->getInput(i) * neuron->getWeight(i);
	}

	return (double)(value >= 0);
}