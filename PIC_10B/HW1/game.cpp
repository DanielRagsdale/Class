#include<iostream>
#include<string>

#include"player.h"
#include"game.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::getline;


void clearConsole();




Game::Game(int n, const string& s1, const string& s2)
{
	gameCount = n;
	p1 = new Player(s1);
	p2 = new Player(s2);
}

void Game::run()
{

	for(int i = 0; i < gameCount; i++)
	{
		for(int i = 0; i < 9; i++)
		{
			tiles[i] = '\0';
		}

		char currentPlayer = 'X';
		while(!boardFull())
		{	
			clearConsole();
			cout << "   " << p1->getName() << " (X) - " << p2->getName() << " (O)" << endl;
			drawBoard();

			if(currentPlayer == 'X')
			{
				cout << p1->getName() << " (X) make a move:"; 
			}
			else
			{
				cout << p2->getName() << " (O) make a move:"; 
			}
			
			int xCoord;
			int yCoord;

			do
			{
				cin >> xCoord;
				cin >> yCoord;
			}while(!tryMakeMove(xCoord, yCoord, currentPlayer));

			if(winner() != '\0')
			{
				break;
			}

			if(currentPlayer == 'X')
			{
				currentPlayer = 'Y';
			}
			else
			{
				currentPlayer = 'X';
			}
		}

		if(winner() == 'X')
		{
			cout << p1->getName() << " wins this round!" << endl;
			p1->incScore();
		}
		else if(winner() == 'Y')
		{
			cout << p2->getName() << " wins this round!" << endl;
			p2->incScore();
		}
		else
		{
			cout << "The game is a draw." << endl;
		}

		cout << p1->getName() << " : " << p1->getScore() << endl;
		cout << p2->getName() << " : " << p2->getScore() << endl;

		cout << "Press ENTER to continue." << endl;
		cin.ignore();
		cin.ignore();
	}
		
	if(p1->getScore() > p2->getScore())
	{
		cout << "Congratulations " <<  p1->getName() << ". You won!" << endl;
	}
	else if(p1->getScore() < p2->getScore())
	{
		cout << "Congratulations " <<  p2->getName() << ". You won!" << endl;
	}
	else
	{
		cout << "The match is a tie." << endl;
	}
}

char Game::winner()
{
	//Check Rows
	
	for(int i = 0; i < 3; i++)
	{
		if(tiles[3*i + 0] == tiles[3*i + 1] && tiles[3*i + 1] == tiles[3*i + 2])
		{
			if(tiles[3*i] != '\0')
			{
				return tiles[3*i];
			}
		}
	}
	
	//Check Columns
	for(int i = 0; i < 3; i++)
	{
		if(tiles[0 + i] == tiles[3 + i] && tiles[3 + i] == tiles[6 + i])
		{
			if(tiles[0 + i])
			{
				return tiles[0 + i];
			}
		}
	}
	
	//Check Diagonals

	if(tiles[0] == tiles[3+1] && tiles[3+1] == tiles[6+2])
	{
		if(tiles[0] != '\0')
		{
			return tiles[0];
		}
	}

	if(tiles[2] == tiles[3+1] && tiles[3+1] == tiles[6+0])
	{
		if(tiles[2] != '\0')
		{
			return tiles[2];
		} 
	}

	return '\0';
}

bool Game::tryMakeMove(int x, int y, char currP)
{
	if(x > 3 || y > 3 || x < 1 || y < 1)
	{
		cout << "Move is out of range. Please make a valid move." << endl;
		return false;
	}
	
	int offset = (x-1) + 3*(y-1);

	if(tiles[offset] != '\0')
	{
		cout << "Square has already been played. Please make a valid move." << endl;
		return false;
	}
	
	tiles[offset] = currP;
	return true;
}

bool Game::boardFull()
{
	for(int i = 0; i < 9; i++)
	{
		if(tiles[i] == '\0')
		{
			return false;
		}
	}

	return true;
}

void Game::drawBoard()
{
	string b = BOARD;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(tiles[j + 3*i] != '\0')
			{
				b[2 + 18 + 6*j + 3*18*i] = tiles[j + 3*i];
			}
		}
	}


	cout << "      1     2     3" << endl;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(j == 1)
			{
				cout << " " << (i+1) << "  ";
			}
			else
			{
				cout << "    ";
			}
			cout << b.substr(i*(3*18) + j*18, (18));
		}
		
		if(i != 2)
		{
			cout << "    -----------------" << endl;
		}
	}
}

int main()
{
	int gameNum;

	string p1Name;
	string p2Name;

	cout << "Number of games: ";
	cin >> gameNum;

	cout << "Player 1 Name: ";
	getline(cin, p1Name);	
	getline(cin, p1Name);	

	cout << "Player 2 Name: ";
	getline(cin, p2Name);	

	cout << "\tTic Tac Toe\n";

	Game g(gameNum, p1Name, p2Name);
	g.run();
}

void clearConsole()
{
	for(int i = 0; i < 100; i++)
	{
		cout << endl;
	}
}

