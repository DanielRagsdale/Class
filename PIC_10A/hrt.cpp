#include<iostream>

using namespace std;

int main()
{
	unsigned long long seconds;

	const unsigned int secPerMin = 60;
	const unsigned int secPerHour = secPerMin * 60;
	const unsigned int secPerDay = secPerHour * 24;
	const unsigned int secPerYear = secPerDay * 365;

	cout << "Input time in seconds" << endl;
	cin >> seconds;
	
	unsigned long long rollover;

	unsigned int years = seconds / secPerYear;
	rollover = seconds % secPerYear;	

	unsigned int days = rollover / secPerDay;
	rollover = rollover % secPerDay;

	unsigned int hours = rollover / secPerHour;
	rollover = rollover % secPerHour;

	unsigned int minutes = rollover / secPerMin;
	rollover = rollover % secPerMin;

	cout << "The Time is " << years << " year(s), " << days << " day(s), "
		 << hours << " hour(s), " << minutes << " minute(s), and "
		 << rollover << " second(s)." << endl;




}
