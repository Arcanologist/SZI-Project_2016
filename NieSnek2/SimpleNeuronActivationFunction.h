#ifndef SIMPLENEURONACTIVATIONFUNCTION_H
#define SIMPLENEURONACTIVATIONFUNCTION_H

#include "INeuronActivationFunction.h"

/**
  * Class for unipolar threshold activation function of neuron.
  */
class SimpleNeuronActivationFunction : public INeuronActivationFunction
{
public:
    // TODO figure out if it should be a singleton.

    /**
      * Default Constructor.
      */
    SimpleNeuronActivationFunction();

    /**
      * Default Destructor.
      */
    ~SimpleNeuronActivationFunction();

    /**
      * Calculates unipolar threshold activation function output.
      * @param neuron pointer to neuron for which it output will be calculated.
      * @return calculated output value.
      */
    double calculateOutput(Neuron* neuron) override;
};

#endif
