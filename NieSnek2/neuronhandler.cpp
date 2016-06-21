#include "neuronhandler.h"

NeuronHandler::NeuronHandler()
{
    perceptron = new Neuron(9);
    this->Learn();
}

void NeuronHandler::Learn()
{
    QList<NeuronInputs> trainingInputs = QList<NeuronInputs>();
    QList<bool> trainingOutputs = QList<bool>();

    NeuronInputs tf = NeuronInputs();

    tf << 1 << 1 << 1
       << 1 << 1 << 1
       << 1 << 1 << 1;

    trainingInputs << tf;
    trainingOutputs << true;


    NeuronInputs t1 = NeuronInputs();

    t1 << 0 << 0 << 1
       << 0 << 1 << 0
       << 0 << 0 << 0;

    trainingInputs << t1;
    trainingOutputs << true;

    NeuronInputs t2 = NeuronInputs();

    t2 << 1 << 0 << 0
       << 0 << 1 << 0
       << 0 << 0 << 0;

    trainingInputs << t2;
    trainingOutputs << true;

    NeuronInputs t3 = NeuronInputs();

    t3 << 0 << 0 << 0
       << 1 << 1 << 0
       << 0 << 0 << 0;

    trainingInputs << t3;
    trainingOutputs << true;

    NeuronInputs t4 = NeuronInputs();

    t4 << 0 << 1 << 0
       << 0 << 1 << 0
       << 0 << 0 << 0;

    trainingInputs << t4;
    trainingOutputs << true;

    NeuronInputs t5 = NeuronInputs();

    t5 << 0 << 0 << 0
       << 0 << 1 << 0
       << 0 << 0 << 0;

    trainingInputs << t5;
    trainingOutputs << false;

    NeuronInputs t6 = NeuronInputs();

    t6 << 1 << 0 << 0
       << 0 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t6;
    trainingOutputs << false;

    NeuronInputs t7 = NeuronInputs();

    t7 << 0 << 1 << 0
       << 0 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t7;
    trainingOutputs << false;

    NeuronInputs t8 = NeuronInputs();

    t8 << 0 << 0 << 1
       << 0 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t8;
    trainingOutputs << false;

    NeuronInputs t9 = NeuronInputs();

    t9 << 0 << 0 << 0
       << 1 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t9;
    trainingOutputs << false;

    NeuronInputs t10 = NeuronInputs();

    t10 << 0 << 0 << 0
       << 0 << 0 << 1
       << 0 << 0 << 0;

    trainingInputs << t10;
    trainingOutputs << false;

    NeuronInputs t11 = NeuronInputs();

    t11 << 0 << 0 << 0
       << 0 << 0 << 0
       << 1 << 0 << 0;

    trainingInputs << t11;
    trainingOutputs << false;

    NeuronInputs t12 = NeuronInputs();

    t12 << 0 << 0 << 0
       << 0 << 0 << 0
       << 0 << 1 << 0;

    trainingInputs << t12;
    trainingOutputs << false;

    NeuronInputs t13 = NeuronInputs();

    t13 << 0 << 0 << 0
       << 0 << 0 << 0
       << 0 << 0 << 1;

    trainingInputs << t13;
    trainingOutputs << false;

    NeuronInputs t14 = NeuronInputs();

    t14 << 0 << 0 << 0
       << 0 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t14;
    trainingOutputs << false;

    NeuronInputs t15 = NeuronInputs();

    t15 << 0 << 0 << 0
       << 1 << 0 << 1
       << 0 << 0 << 0;

    trainingInputs << t15;
    trainingOutputs << false;

    NeuronInputs t16 = NeuronInputs();

    t16 << 0 << 0 << 1
       << 1 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t16;
    trainingOutputs << false;

    NeuronInputs t17 = NeuronInputs();

    t17 << 1 << 0 << 1
       << 0 << 0 << 0
       << 0 << 0 << 0;

    trainingInputs << t17;
    trainingOutputs << false;


    NeuronInputs t18 = NeuronInputs();

    t18 << 1 << 0 << 0
       << 0 << 0 << 0
       << 0 << 0 << 1;

    trainingInputs << t18;
    trainingOutputs << false;


    NeuronInputs t19 = NeuronInputs();

    t19 << 0 << 0 << 0
       << 1 << 0 << 0
       << 0 << 0 << 1;

    trainingInputs << t19;
    trainingOutputs << false;

    NeuronInputs t20 = NeuronInputs();

    t20 << 0 << 0 << 0
       << 0 << 0 << 0
       << 1 << 0 << 1;

    trainingInputs << t20;
    trainingOutputs << false;


    NeuronInputs t21 = NeuronInputs();

    t21 << 0 << 0 << 1
       << 0 << 0 << 0
       << 1 << 0 << 0;

    trainingInputs << t21;
    trainingOutputs << false;

    NeuronInputs t22 = NeuronInputs();

        t22 << 1 << 0 << 0
           << 0 << 0 << 1
           << 0 << 0 << 0;

        trainingInputs << t22;
        trainingOutputs << false;

    NeuronInputs t23 = NeuronInputs();

        t23 << 0 << 1 << 0
           << 0 << 0 << 0
           << 0 << 1 << 0;

        trainingInputs << t23;
        trainingOutputs << false;

    perceptron->learnSteps(PerceptronLearn(0.08),trainingInputs,trainingOutputs,100);


}

