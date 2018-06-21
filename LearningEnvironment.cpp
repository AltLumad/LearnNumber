//#include "stdafx.h"
#include "LearningEnvironment.h"
#include <iostream>
#include <vector>
#include "Helper.h"
#include <numeric>
#include <math.h>
LearningEnvironment::LearningEnvironment()
{
	
}

void LearningEnvironment::LearnNeuronet(INeuronet& neuronet, const int& cntEpoñhs) {
	for (int e = 0; e < cntEpoñhs; e++) {
		if (MSE(neuronet) < ERROR_EPS) {
			return;
		}

		for (int i = 0; i < 10; i++) {
			double result = neuronet.Read(Helper::numberToMatrix(i));

			neuronet.TrainNeuroNet(result, static_cast<double>(i));
		}
		if (e % 100 == 0) {
			double err = MSE(neuronet);
			std::cout <<"\r epoch: " << e << " error: " << err << " learned: " <<  (ERROR_EPS / err)*100 << "%  ";
		}
	}
	
}

double LearningEnvironment::MSE(INeuronet& neuronet) {
	std::vector<double> errors;
	for (int i = 0; i < 10; i++) {
		double result = neuronet.Read(Helper::numberToMatrix(i));
		double error = neuronet.GetError(result, static_cast<double>(i));
		errors.push_back(error);
	}
	double avgerr = std::accumulate(errors.begin(), errors.end(), 0.0) / errors.size();
	double res = 0;
	for (auto e : errors) {
		res += pow(e - avgerr , 2);
	}
	return sqrt(res / errors.size());
}