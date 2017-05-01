#ifndef __player_h__
#define __player_h__

#include<string>

class Player
{
	private:
		std::string name;
		int score;

	public:
		Player(std::string n) : name(n) {}

		const std::string& getName();
		int getScore();
		void setScore(int score);
		void incScore();
};
#endif
