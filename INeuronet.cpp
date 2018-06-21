#include "stdafx.h"
#include "INeuronet.h"
#include <iostream>
#include <string>

INeuronet::INeuronet()
{
	initNeuroLayer(_inputLayer, 15);
	initNeuroLayer(_hiddenLayer, 15);
	_outputNeuron = std::make_shared<INeuron>();
	initLinkLayer(_inputLayer, _hiddenLayer, _firstLinkLayer);
	for (auto& hiddenNeuron : _hiddenLayer) {
			std::vector<ILinkPtr>& veclink = _secondLinkLayer[_outputNeuron.get()];
			auto link = std::make_shared<ILink>(hiddenNeuron, _outputNeuron);
			veclink.push_back(link);
	}
}

void INeuronet::initNeuroLayer(NeuroLayer& layer, const int& cnt) {
	for (int i = 0; i < cnt; i++) {
		layer.push_back(std::make_shared<INeuron>());
	}
}



void INeuronet::initLinkLayer(NeuroLayer& inNeuroLayer, NeuroLayer& outNeuroLayer, LinkLayer& linkLayer) {
	for (auto& inNeuron : inNeuroLayer) {
		for (auto& outNeuron : outNeuroLayer) {
			auto link = std::make_shared<ILink>(inNeuron, outNeuron);
			linkLayer[outNeuron.get()].push_back(link);
		}
	}
}

double INeuronet::Read(const MatrixNumber& number) const{
	int neuron_counter = 0;
	for (const auto& line : number) {
		for (const auto& cell : line) {
			double n = static_cast<double>(cell);
			_inputLayer[neuron_counter]->SetWeight(n);
			neuron_counter++;
		}
	}
	
	for (auto& link : _firstLinkLayer) {
		link.first->ActivateNeuron(neuronWeighSum(link.second));
	}
	
	for (auto& link : _secondLinkLayer) {
		link.first->ActivateNeuron(neuronWeighSum(link.second));
	}
	
	return _outputNeuron->GetWeight()*10;
}

double INeuronet::neuronWeighSum(const std::vector<ILinkPtr>& links) {
	double sum = 0;
	for (ILinkPtr link : links) {
			sum = (*link) + sum;
	}
	return sum;
}

void INeuronet::TrainNeuroNet(double actual, double expected) {
	double error = INeuron::GetError(actual, expected);
	double deltaError = _outputNeuron->GetWeightDelta(error);
	for (auto& links : _secondLinkLayer) {
		for (auto& link : links.second) {
			link->CorrectWeight(deltaError);
			double backError = link->GetBackError(deltaError);
			auto linkInputNeuron =  link->GetInputNeuron();
			double backDeltaError = linkInputNeuron->GetWeightDelta(backError);
			for (auto& flink : _firstLinkLayer[linkInputNeuron.get()]) {
				flink->CorrectWeight(backDeltaError);
			}
		}
	}
}

double INeuronet::GetError(double actual, double expected) const {
	return INeuron::GetError(actual, expected);
}

void INeuronet::PrintWeight() const {
	auto PrintLayer = [&](const LinkLayer& layer, const std::string& msg){
		std::cout << msg << std::endl;
		for (auto& flink : layer) {
			for (auto& l : flink.second) {
				std::cout << l->GetWeight() << " ";
			}
		}
	};
	PrintLayer( _firstLinkLayer, "First link layer:");
	PrintLayer(_secondLinkLayer, "Second link layer:");
}