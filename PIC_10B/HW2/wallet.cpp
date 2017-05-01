#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

#include"card.h"

bool compCardPointers( Card* lhs, Card* rhs)
{
	return (*lhs) < (*rhs);
}

int main()
{
	std::cout << "*******************\n";
	std::cout << "* Wallet Printer! *\n";
	std::cout << "*******************\n";

	std::cout << "Print Cards by selecting the type (0 when done):)\n";
	std::cout << "\n";
	std::cout << "1. Basic Card\n";
	std::cout << "2. ID Card\n";
	std::cout << "3. Bank Card\n";
	std::cout << "\n";

	std::vector<Card*> cards; 

	std::string cType = "0";


	while(true)
	{
		Card* c;
		
		std::cout << "\nCard type : ";
		std::getline(std::cin, cType);	
		if(cType == "1")
		{
			c = new Card();
		}
		else if(cType == "2")
		{
			c = new IDCard();
		}
		else if(cType == "3")
		{
			c = new BankCard();
		}
		else
		{
			break;
		}

		c->create();

		cards.push_back(c);
	} 

	std::sort (cards.begin(), cards.end(), compCardPointers);
	

	std::cout << "\n";

	for(int i = 0; i < cards.size(); i++)
	{
		std::cout << cards[i]->toString();
		delete cards[i];
	}
}







