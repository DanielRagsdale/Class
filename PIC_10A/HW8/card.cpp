#include"card.h"
#include<cassert>
#include<string>

using namespace std;

void card::setNum(int n)
{
	assert(n > 0 && n <= 13);
	num = n;
}

void card::setSuit(char s)
{
	assert(s == 'C' || s == 'D' || s == 'H' || s == 'S');
	suit = s;
}

int card::getNum()
{
	assert(num > 0 && num <= 13);
	return num;
}

char card::getSuit()
{
	assert(suit == 'C' || suit == 'D' || suit == 'H' || suit == 'S');
	return suit;
}

string card::read()
{
	string outStr = "";

	if(num == 1)
	{
	outStr += "Ace";
	}
	else if(num == 11)
	{
		outStr += "Jack";
	}
	else if(num == 12)
	{
		outStr += "Queen";
	}
	else if(num == 13)
	{
		outStr += "King";
	}
	else
	{
		outStr += to_string(num);
	}

	outStr += " of ";

	if(suit == 'C')
	{
		outStr += "Clubs";
	}
	else if(suit == 'D')
	{
		outStr += "Diamonds";
	}
	else if(suit == 'H')
	{
		outStr += "Hearts";
	}
	else if(suit == 'S')
	{
		outStr += "Spades";
	}

	return outStr;
}

card::card()
{
	num = 0;
	suit = 'X';
}

card::card(int n, char s)
{
	setNum(n);
	setSuit(s);
}






