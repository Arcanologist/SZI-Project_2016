#pragma once

#include "INeuronLearn.h"

/**
  * Strategy of learning perceptron neuron.
  */
class PerceptronLearn : public INeuronLearn
{
public:
	/**
	  * Constructor for learning strategy.
	  * @param constantScale scalar modifying size of step modifying weights of neuron.
	  */
	PerceptronLearn(double constantScale);

	/**
	  * Default Destructor.
	  */
	~PerceptronLearn();

	/**
	  * Single interation of learning a neuron.
	  * @param neuron pointer to neuron which will be learnt.
	  * @param trainingInputs list of training input vectors.
	  * @param trainingOutputs list of expected outputs for given input vectors.
	  * @return new weights after single iteration of learning.
	  */
	NeuronWeights learn(Neuron* neuron, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs) override;

private:
	double constantScale;
};

