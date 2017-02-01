#include<iostream>

using namespace std;

int main()
{
	long long in;
	cout << "Input a positive integer:" << endl;
	cin >> in;

	cout << "Starting from " << in << "." << endl;
	
	long long workingVal = in;
	long long counter = 0;

	do
	{
		counter++;

		if(workingVal % 2 == 0) //if is even
		{
			workingVal /= 2;
		}
		else
		{
			workingVal *= 3;
			workingVal++;
		}
		cout << "Step " << counter << ": " << workingVal << endl;
	} while(workingVal != 1);

	cout << "Starting from " << in << ", it took " << counter << " steps." << endl;
}
