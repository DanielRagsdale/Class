#include<iostream>

using namespace std;

int main()
{
	unsigned long long numCount; 
	
	cout << "How many numbers do you have?" << endl;
	cin >> numCount;
	
	long double currentHighest = -1. / 0.;
	for(int i = 1; i <= numCount; i++)
	{
		long double temp;
		cout << "Input number (count " << i << "):" << endl;
		cin >> temp;

		if(temp > currentHighest)
		{
			currentHighest = temp;	
		}
	}

	cout << "The maximum is " << currentHighest << "." << endl;
}
