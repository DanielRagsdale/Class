#ifndef __game_h__
#define __game_h__

#include<string>

class Game
{
	private:
		int gameCount;
		char tiles[9];
		Player* p1;
		Player* p2;

		const std::string BOARD =
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n"
			"     |     |     \n";

	public:
		Game(int gameCount, const std::string& p1N, const std::string& p2N);
		void run();

		bool boardFull();
		char winner();

		bool tryMakeMove(int x, int y, char player);

		void drawBoard();
};

#endif
