#ifndef NEURON_H
#define NEURON_H

#include <QtCore\qvector.h>
#include <QtCore\qpair.h>

/**
  * Pair of threshold and vector of weights.
  */
typedef QPair<double, QVector<double>> NeuronWeights;

/**
  * Vector of neuron inputs.
  */
typedef QVector<double> NeuronInputs;

/**
  * Class for single neuron. Has threshold weight separated from input weight parameters.
  */
class Neuron
{
public:
    /**
      * Neuron constructor with unipolar thresholding as activation function ("SimpleNeuronActivationFunction").
      * @param numberOfInputs number of neuron inputs for the neuron.
      * @param threshold threshold weight of neuron. 1.0 by default.
      */
    Neuron(int numberOfInputs, double threshold = 1.0);

    /**
      * Neuron constructor with custom activation function.
      * @param numberOfInputs number of neuron inputs for the neuron.
      * @param activationFunction pointer to object of class implementing activation function which will be used for this neuron.
      * @param threshold threshold weight of neuron. 1.0 by default.
      */
    Neuron(int numberOfInputs, class INeuronActivationFunction* activationFunction, double threshold = 1.0);

    /**
      * Default destructor.
      */
    ~Neuron();

    /**
      * Gets number of neuron inputs.
      * @return number of neuron inputs.
      */
    int getInputCount();

    /**
    * Gets threshold value of neuron.
    * @return threshold value of neuron.
    */
    double getThreshold();

    /**
      * Sets threshold value of neuron.
      * @param value threshold value to be set for neuron.
      */
    void setThreshold(double value);

    /**
      * Gets value of asked input.
      * @param index index of asked input.
      * @return value of asked input.
      */
    double getInput(int index);

    /**
      * Sets value for given input.
      * @param index index of input to change.
      * @param value value of asked input.
      */
    void setInput(int index, double value);

    /**
      * Gets values of all neuron inputs in form of a vector.
      * @return vector of neuron inputs.
      */
    NeuronInputs getInputs();

    /**
      * Sets values of all neuron inputs.
      * @param inputs vector of neuron input values to be set.
      */
    void setInputs(NeuronInputs& inputs);

    /**
      * Gets weight of asked input.
      * @param index index of asked input.
      * @return weight of asked input.
      */
    double getWeight(int index);

    /**
      * Sets weight for given input.
      * @param index index input.
      * @param value weight of asked input.
      */
    void setWeight(int index, double value);

    /**
      * Gets threshold and all weights of neuron in form of a pair of threshold and vector of weights.
      * @return pair of threshold and vector of weights.
      */
    NeuronWeights getWeights();

    /**
      * Sets threshold and all weights of neuron.
      * @param weights pair of threshold and vector of weights to be set for neuron.
      */
    void setWeights(NeuronWeights& weights);

    /**
      * Calculates and returns output.
      * @return output of neuron.
      */
    double calculateOutput();

    /**
      * Gets previously calculated output.
      * @return output of neuron.
      */
    double getOutput();

    // TODO figure out if it is worth replacing this with bipolar activation function class.
    /**
      * Usefull to convert unipolar thresholding output to bipolar thresholding output. False -> -1.0, True -> 1.0 .
      * @param value boolean value to be converted.
      * @result result of conversion in form of double.
      */
    static double boolToSign(bool value);

    /**
      * Learns the Neuron using given learning strategy, input sets and expected outputs. Makes number of learning iterations given by parameter.
      * @param learningStrategy reference to object of class implementing learning method we want to use for this neuron.
      * @param trainingInputs list of training input vectors.
      * @param trainingOutputs list of expected outputs for given input vectors.
      * @param steps number of learning iterations to make.
      */
    void learnSteps(class INeuronLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, int steps);

    /**
      * Learns the Neuron using given learning strategy, input sets and expected outputs untill error is lower than error threshold.
      * @param learningStrategy reference to object of class implementing learning method we want to use for this neuron.
      * @param trainingInputs list of training input vectors.
      * @param trainingOutputs list of expected outputs for given input vectors.
      * @param errorThreshold all errors in iterations have to be lower than this to stop learning.
      * @return number of iterations made.
      */
    int learnErrorThreshold(class INeuronLearn& learningStrategy, QList<NeuronInputs>& trainingInputs, QList<bool>& trainingOutputs, double errorThreshold);

private:
    double threshold;
    QVector<double> inputs;
    QVector<double> weights;
    int numberOfInputs;
    double output;
    class INeuronActivationFunction* activationFunction;
};

#endif
