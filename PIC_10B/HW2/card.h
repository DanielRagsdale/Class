#ifndef __card_h__
#define __card_h__

#include<string>

/**
 * Parent class representing a generic card.
 * Is subclassed for more specific types of cards.
 */
class Card
{
private:
	/**
	 * The institution's name
	 */
	std::string instName;

	/**
	 * The cardholder's name
	 */
	std::string holderName;

	/**
	 * The card's expiration date
	 */
	std::string expDate;

public:
	/**
	 * Take user input from std::cin to populate member fields
	 * Should be overrided to take input for subclasses
	 */
	virtual Card* create();
	
	/**
	 * Create a formated string representing this card
	 *
	 * @return string formated to display this card
	 */
	virtual std::string toString();
	
	/**
	 * Compare this object with another Card.
	 * Used for sorting cards.
	 * Objects are compared by their exipration dates.
	 */
	bool operator<(const Card& rhs);
};

/**
 * Subclass of card with additional fields for identification number and date of birth
 */
class IDCard : public Card
{
private:
	/**
	 * ID number associated with this card
	 */
	std::string idNum;

	/**
	 * Date of Birth associated with cardholder
	 */
	std::string dob;

public:
	Card* create();
	std::string toString();
}; 

/**
 * Subclass of card with additional fields for bank account number and card security code
 */
class BankCard : public Card
{
private:
	/**
	 * Account number associated with this card
	 */
	std::string accountNum;

	/**
	 * Security code associated with this card
	 */
	std::string secCode;
public:
	Card* create();
	std::string toString();
};

#endif








