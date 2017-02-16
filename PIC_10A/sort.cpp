#include<iostream>

using namespace std;

int main()
{
	unsigned long size;

	cout << "How many numbers do you have?" << endl;
	cin >> size;

	long* inputs = new long[size];
	
	//Input Block	
	for(int i = 0; i < size; i++)
	{
		cout << "Input number (count " << (i + 1) << "):" << endl;
		cin >> inputs[i];
	}

	//Sort Block
	for(int i = 0; i < size; i++)
	{
		int j = i;
		unsigned long indexSmallest = i;
		for(; j < size; j++)
		{
			if(inputs[j] < inputs[indexSmallest])
			{
				indexSmallest = j;
			}
		}

		//Swap
		long holder = inputs[indexSmallest];
		inputs[indexSmallest] = inputs[i];
		inputs[i] = holder;
		

		//Output
		cout << holder << " (count " << (i + 1) << ")" << endl;
	}

	delete[] inputs;	
}
