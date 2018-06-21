#pragma once
#include "defines.h"
#include "ILink.h"
#include <vector>
#include <map>

class INeuronet
{

public:
	INeuronet();
	double Read(const MatrixNumber& number) const;
	double GetError(double actual, double expected) const;
	void TrainNeuroNet(double actual, double expected);
	void PrintWeight() const;
private:
	typedef std::vector<INeuronPtr> NeuroLayer;
	typedef std::map<INeuron*, std::vector<ILinkPtr>>  LinkLayer;

	NeuroLayer _inputLayer;
	NeuroLayer _hiddenLayer;
	INeuronPtr _outputNeuron;
	
	LinkLayer _firstLinkLayer;
	LinkLayer _secondLinkLayer;

	static void initNeuroLayer(NeuroLayer& layer, const int& cnt);
	static void initLinkLayer(NeuroLayer& inNeuroLayer, NeuroLayer& outNeuroLayer, LinkLayer& linkLayer);
	static double neuronWeighSum(const std::vector<ILinkPtr>& links);
};

