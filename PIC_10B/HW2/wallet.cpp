/* 
 *
 * Homework # 2
 *
 * Author: Daniel Ragsdale
 *
 * Email: danielr@ucla.edu
 *
 * Course: PIC 10B Lecture 1 Spring 2017
 *
 * Collaborators:
 *
 *
 *
 * Honesty Pledge: 
 *
 * I, Daniel Ragsdale, pledge that this is my independent work and abide by the guidelines of honesty 
 *
 * outlined in the syllabus. 
 *
 *
 *
 * User inputs: Follow prompts
 *
 * Output: Sorted list of cards
 *
 * List of known bugs: None. None compliant inputs can result in crashes. Tested with g++ and visual studio
 *
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

#include"card.h"

/**
 * Compare the card objects represented by the pointers
 * rather than the pointers themselves
 */
bool compCardPointers(Card* lhs, Card* rhs);

/**
 * 1. Prompt the user for input
 * 2. Format and print ordered list of cards
 */
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

	//Input loop
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

	//Output loop
	for(int i = 0; i < cards.size(); i++)
	{
		std::cout << cards[i]->toString();
		delete cards[i];
	}
}

bool compCardPointers( Card* lhs, Card* rhs)
{
	return (*lhs) < (*rhs);
}






