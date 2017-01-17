#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	long double a, b, c;
	long double s;

	cout << "What is the length of the first side?" << endl;
	cin >> a;
	cout << "What is the length of the second side?" << endl;
	cin >> b;
	cout << "What is the length of the third side?" << endl;
	cin >> c;
	
	s = (a + b + c) / 2;

	long double unsquared = s*(s-a)*(s-b)*(s-c);

	long double area = sqrt(unsquared);

	cout << "The area of triangle is " << area << "." << endl;
}
