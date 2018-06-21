#include "Helper.h"


void Helper::setLine(MatrixNumber& mnumber, const int& nline, const bool& vert) {
	int constant = nline;
	int variable = 0;
	int& x = (vert? constant : variable);
	int& y = (vert ? variable : constant);
	auto length = (vert ? mnumber.size(): mnumber[0].size());
	for (;variable < length; variable++) 
		mnumber[y][x] = true;
}

void Helper::setThreeHorzLine(MatrixNumber& mnumber) {
	setLine(mnumber, 0, false);
	setLine(mnumber, 2, false);
	setLine(mnumber, 4, false);
}

void Helper::setTwoVertLine(MatrixNumber& mnumber) {
	setLine(mnumber, 0);
	setLine(mnumber, 2);
}

void Helper::setEight(MatrixNumber& mnumber) {
	setThreeHorzLine(mnumber);
	setTwoVertLine(mnumber);
}

MatrixNumber Helper::numberToMatrix(const int& n) {
	MatrixNumber mnumber(5);
	for (auto& line: mnumber)
		line = std::vector<bool>{false, false, false};
	switch (n)
	{
	case 0: 
		setEight(mnumber);
		mnumber[2][1] = false;
		break;
	case 1:
		setLine(mnumber, 1);
		break;
	case 2:
		setThreeHorzLine(mnumber);
		mnumber[1][2] = true;
		mnumber[3][0] = true;
		break;
	case 3:
		setLine(mnumber, 2);
		setThreeHorzLine(mnumber);
		break;
	case 4:
		setLine(mnumber, 2);
		setLine(mnumber, 2, false);
		mnumber[0][0] = true;
		mnumber[1][0] = true;
		break;
	case 5:
		setThreeHorzLine(mnumber);
		mnumber[1][0] = true;
		mnumber[3][2] = true;
		break;
	case 6:
		setLine(mnumber, 0);
		setThreeHorzLine(mnumber);
		mnumber[3][2] = true;
		break;
	case 7:
		setLine(mnumber, 2);
		setLine(mnumber, 0, false);
		break;
	case 8:
		setEight(mnumber);

		break;
	case 9:
		setLine(mnumber, 2);
		setThreeHorzLine(mnumber);
		mnumber[1][0] = true;
		break;
	default:
		break;
	}
	return mnumber;
}