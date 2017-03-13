#include"hand.h"

using namespace std;

int calculateValue(hand cards)
{
	//0001 0001 1111 1111
	//num  suit high low
	
	int value = 0;	

	if(cards.c1.getNum() == cards.c2.getNum())
	{
		value += 0x01000000;
	}
	if(cards.c1.getSuit() == cards.c2.getSuit())
	{
		value += 0x00010000;
	}
	if(cards.c1.getNum() > cards.c2.getNum())
	{
		value += cards.c1.getNum() * 0x00000100;
		value += cards.c2.getNum();
	}
	else
	{
		value += cards.c2.getNum() * 0x00000100;
		value += cards.c1.getNum();
	}

	return value;
}

bool hand::operator<(hand rhs)
{
	return calculateValue(*this) < calculateValue(rhs);	
}
bool hand::operator>(hand rhs)
{
	return calculateValue(*this) > calculateValue(rhs);	
}
bool hand::operator<=(hand rhs)
{
	return calculateValue(*this) <= calculateValue(rhs);	
}
bool hand::operator>=(hand rhs)
{
	return calculateValue(*this) >= calculateValue(rhs);	
}
bool hand::operator==(hand rhs)
{
	return calculateValue(*this) == calculateValue(rhs);	
}
