#include "stdafx.h"
#include "INeuron.h"
#include <math.h>

INeuron::INeuron()
{
}

double INeuron::GetError(double actual, double expected) {
	return actual - expected;
}

double INeuron::GetWeight() {
	return _weight;
}

double INeuron::GetWeightDelta(double error) {
	return error* ActivationFuncDx();
}

double INeuron::SetWeight(double weight) {
	return _weight = weight;
}

double INeuron::ActivationFunc() {
	return (1 / (1 + exp(-1*_weight) ));
}

double INeuron::ActivationFuncDx() {
	return _weight * (1 - _weight);
}


double INeuron::ActivateNeuron(double weigth) {
	SetWeight(weigth);
	double actualValue = ActivationFunc();
	SetWeight(actualValue);
	return _weight;
}