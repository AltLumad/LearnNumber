#pragma once
#include "INeuronet.h"

class LearningEnvironment
{
public:
	LearningEnvironment();
	void LearnNeuronet(INeuronet& neuronet, const int& cntEpo�h);
	double MSE(INeuronet& neuronet);
private:
	const double ERROR_EPS = 0.1;
};

