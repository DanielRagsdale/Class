#include"player.h"

#include<string>

using std::string;

const string& Player::getName()
{
	return name;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int s)
{
	score = s;
}

void Player::incScore()
{
	score++;
}
