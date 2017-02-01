#include<iostream>

using namespace std;

int main()
{
	long long in;
	cout << "Input a nonnegative integer:" << endl;	
	cin >> in;
	
	long long shrinkVal = in;	
	long long growVal = 0;

	while(shrinkVal)
	{
		growVal *= 10;	
		growVal += shrinkVal % 10;	

		shrinkVal /= 10;
	}

	if(in == growVal)
	{
		cout << in << " is a palindromic number." << endl;
	}
	else
	{
		cout << in << " is not a palindromic number." << endl;
	}
}
