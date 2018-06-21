#pragma once
#include <memory>
class INeuron
{
public:
	INeuron();
	virtual double GetWeight();
	virtual double SetWeight(double weigth);
	static double GetError(double actual, double expected);
	double GetWeightDelta(double error);
	double ActivateNeuron(double weigth);
protected:
	virtual double ActivationFunc();
	virtual double ActivationFuncDx();
	double _weight;
};


typedef std::shared_ptr<INeuron> INeuronPtr;
