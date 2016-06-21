#include "PerceptronLearn.h"
#include "Neuron.h"

#include <QtCore/qstring.h>

PerceptronLearn::PerceptronLearn(double constantScale)
{
	this->constantScale = constantScale;
}

PerceptronLearn::~PerceptronLearn()
{
}

NeuronWeights PerceptronLearn::learn(Neuron* neuron, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs)
{
	if (trainingInputs.count() != trainingOutputs.count())
	{
		throw QString("Input and output lists have different count!");
	}

	NeuronWeights newWeights = NeuronWeights();
	newWeights.second = QVector<double>(neuron->getInputCount());

	for (int s = 0; s < trainingInputs.count(); s++)
	{
		if (trainingInputs[s].count() != neuron->getInputCount())
		{
			throw QString("Some neuron training vectors have different number of input than trained neuron itself");
		}
		neuron->setInputs(trainingInputs[s]);
		for (int i = 0; i < neuron->getInputCount(); i++)
		{
			newWeights.second[i] = neuron->getWeight(i) +  (constantScale * (((double)trainingOutputs[s]) - ((double)neuron->calculateOutput())) * neuron->getInput(i));
		}
		newWeights.first = neuron->getThreshold() + (constantScale * (((double)trainingOutputs[s]) - ((double)neuron->calculateOutput())));

		neuron->setWeights(newWeights);
	}
	return newWeights;
}