#include "stdafx.h"
#include "ILink.h"
#include <ctime>
#include "defines.h"
//------------------------------------------------------------------------
double ILink::operator + (const ILink& rvl) {
	if (_output.get() != rvl._output.get()) {
		return 0;
	}
	return _weight * _input->GetWeight() + rvl._weight * rvl._input->GetWeight();

}

double ILink::operator + (const double& rvl) {
	return _weight * _input->GetWeight() + rvl;
}
int ILink::_randomInit = 0;
//------------------------------------------------------------------------
ILink::ILink(INeuronPtr input, INeuronPtr output):
_input(input), _output(output)
{
	srand(_randomInit);
	_randomInit += 2;
	_weight = double(rand() % 100) / 100.0;
}

double ILink::GetWeight() const {
	return _weight;
}

double ILink::CorrectWeight(const double& weight_delta) {
	_weight = _weight - _input->GetWeight() * weight_delta * LEARNING_RATE;
	return _weight;
}

double ILink::GetBackError(const double& weight_delta) const{
	return _weight * weight_delta; 	

}
INeuronPtr ILink::GetInputNeuron() {
	return _input;
}
//------------------------------------------------------------------------


 