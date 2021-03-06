#include <iostream>
#include "Helper.h"
#include "INeuronet.h"
#include "LearningEnvironment.h"
#include "math.h";
int InputNumber() {	
	int res;
	std::cout << std::endl << "Input number [-1:9] : ";
	std::cin >> res;
	return res;
}


void PrintNumber(const int& n) {
	auto numb = Helper::numberToMatrix(n);
	for (auto line : numb) {
		for (bool b : line) {
			std::cout << (b ? '*' : ' ');
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	INeuronet neuronet;
	LearningEnvironment le;
	le.LearnNeuronet(neuronet, LEARN_EPOCHS);
	int n = InputNumber();
	while (n != -1) {
		if (n >= 0 && n <= 9){
			//PrintNumber(n);
			std::cout << "Neuronet's anwser: " << (int)round(neuronet.Read(Helper::numberToMatrix(n)));
		}
		n = InputNumber();
	}
	return 0;
}