#include<iostream>
#include<string>

using namespace std;

const unsigned short VAL_M = 1000;
const unsigned short VAL_CM = 900;
const unsigned short VAL_D = 500;
const unsigned short VAL_CD = 400;
const unsigned short VAL_C = 100;
const unsigned short VAL_XC = 90;
const unsigned short VAL_L = 50;
const unsigned short VAL_XL = 40;
const unsigned short VAL_X = 10;
const unsigned short VAL_IX = 9;
const unsigned short VAL_V = 5;
const unsigned short VAL_IV = 4;
const unsigned short VAL_I = 1;

const unsigned short valueCount = 13;
const unsigned short values[valueCount] = {VAL_M, VAL_CM, VAL_D, VAL_CD, VAL_C, VAL_XC, VAL_L, VAL_XL, VAL_X, VAL_IX, VAL_V, VAL_IV, VAL_I};
const string representations[valueCount] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

int main()
{
	unsigned short val;
	cout << "Input a number in Arabic numerals:" << endl;
	cin >> val;

	string output = "";

	short curValue = 0;	

	while(val > 0)
	{
		short dividedVal = val / values[curValue];

		if(dividedVal != 0)
		{
			output += representations[curValue];
			val -= values[curValue];
		}
		else
		{
			curValue++;
		}
	}

	cout << output << " is your number in Roman numerals" << endl;
}
