#pragma once
#include "INeuron.h"
class ILink
{
public:
	ILink(INeuronPtr input, INeuronPtr output);
	double GetWeight() const;
	double CorrectWeight(const double& weight_delta);
	double operator + (const ILink& rvl);
	double operator + (const double& rvl);
	double GetBackError(const double& weight_delta) const;
	INeuronPtr GetInputNeuron();

private:
	INeuronPtr _input;
	INeuronPtr _output;
	
	double _weight;
	static int _randomInit;
};
typedef std::shared_ptr<ILink> ILinkPtr;

