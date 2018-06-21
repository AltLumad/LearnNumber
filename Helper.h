#pragma once
#include "defines.h"

class Helper {
	public:
		static MatrixNumber numberToMatrix(const int& n);
	private:
		static void setLine(MatrixNumber& mnumber, const int& nline, const bool& vert = true);
		static void setThreeHorzLine(MatrixNumber& mnumber);
		static void setTwoVertLine(MatrixNumber& mnumber);
		static void setEight(MatrixNumber& mnumber);
};
