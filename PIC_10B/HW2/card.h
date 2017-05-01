#ifndef __card_h__
#define __card_h__

#include<string>

class Card
{
private:
	std::string instName;
	std::string holderName;
	std::string expDate;

public:
	virtual Card* create();
	virtual std::string toString();

	bool operator<(const Card& rhs);
};

class IDCard : public Card
{
private:
	std::string idNum;
	std::string dob;

public:
	Card* create();
	std::string toString();
}; 

class BankCard : public Card
{
private:
	std::string accountNum;
	std::string secCode;
public:
	Card* create();
	std::string toString();
};

#endif
