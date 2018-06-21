#pragma once
#include "INeuronet.h"

class LearningEnvironment
{
public:
	LearningEnvironment();
	void LearnNeuronet(INeuronet& neuronet, const int& cntEpoñh);
	double MSE(INeuronet& neuronet);
private:
	const double ERROR_EPS = 0.1;
};

