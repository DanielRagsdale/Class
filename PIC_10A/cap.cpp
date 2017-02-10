#include<iostream>
#include<string>

using namespace std;

int main()
{
	cout << "Input a sentence:" << endl;

	string s;
	getline(cin, s);

	bool doCapitalize = true;

	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] & 0x40) //Bitmask with b01000000 to ensure it is a letter that can be capitalized
		{
			if(doCapitalize)
			{
				s[i] = s[i] & 0x5f; //Bitmask with b01011111
				doCapitalize = false;
			}
			else
			{
				s[i] = s[i] | 0x20; //Bitmask with b00100000
			}
		}
		else
		{
			doCapitalize = true;		
		}
	}

	cout << "The correct capitalization is:" << endl;
	cout << s << endl;
}
