#ifndef INEURONACTIVATIONFUNCTION_H
#define INEURONACTIVATIONFUNCTION_H
/**
  * Abstract class for unipolar threshold activation function of neuron.
  */
class INeuronActivationFunction
{
public:

    /**
      * abstract method of calculating activation function output.
      * @param neuron pointer to neuron for which it output will be calculated.
      * @return calculated output value.
      */
    virtual double calculateOutput(class Neuron* neuron) = 0;
};

#endif //INEURONACTIVATIONFUNCTION_H
