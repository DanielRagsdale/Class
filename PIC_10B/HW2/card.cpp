#include<iostream>
#include"card.h"

std::string toDateString(const std::string& inString)
{
	if(inString == "0")
	{
		return "0";
	}
 	
	return inString.substr(0, 2) + "/" + inString.substr(2,2) + "/" + inString.substr(4);
}


Card* Card::create()
{
	std::cout << "Institution name : ";
	std::getline(std::cin, instName);

	std::cout << "Card holder name : ";
	std::getline(std::cin, holderName);

	std::string expDateIn;
	std::cout << "Expiration date mmddyyyy (0 if none) : ";
	std::getline(std::cin, expDateIn);
	
	expDate = toDateString(expDateIn);

	return this;
}

std::string Card::toString()
{
	std::string outp;
	outp += " ----------------------------\n";
	outp += "| " + instName + "\n";
	outp += "|         name  : " + holderName + "\n";
	outp += "|          exp  : " + expDate + "\n";
	outp += "|\n";

	return outp;
}

Card* IDCard::create()
{
	Card::create();

	std::cout << "ID number : ";
	std::getline(std::cin, idNum);

	std::string dobIn;
	std::cout << "DOB mmddyyyy : ";
	std::getline(std::cin, dobIn);
	
	dob = toDateString(dobIn);	

	return this;
}

std::string IDCard::toString()
{
	std::string outp = Card::toString();

	outp += "|          ID#  : " + idNum + "\n";
	outp += "|          DOB  : " + dob + "\n";
	outp += "|\n";

	return outp;
}

Card* BankCard::create()
{
	Card::create();

	std::cout << "Account number : ";
	std::getline(std::cin, accountNum);
		
	std::cout << "Security code : ";
	std::getline(std::cin, secCode);	

	return this;
}

std::string BankCard::toString()
{
	std::string outp = Card::toString();

	outp += "|     Account#  : " + accountNum + "\n";
	outp += "| Security code : " + secCode + "\n";
	outp += "|\n";

	return outp;
}











