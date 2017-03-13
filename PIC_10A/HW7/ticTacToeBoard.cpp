#include "ticTacToeBoard.h"
#include <iostream>
using namespace std;

void initBoard(ticTacToeBoard& board)
{
	board.curr_player = 1;

	for(int i = 0; i < 4*4; i++)
	{	
		board.points[i] = 0;
	}
}

bool isEmpty(ticTacToeBoard board, int x, int y)
{
	return board.points[(x-1) + 4*(y-1)] == 0;
}

void mark(ticTacToeBoard& board, int x, int y)
{
	board.points[(x-1) + 4*(y-1)] = board.curr_player;

	//board.curr_player *= -1;
}

bool boardFull(ticTacToeBoard board)
{
	for(int i = 0; i < 4*4; i++)
	{	
		if(board.points[i] == 0)
		{
			return false;
		}
	}
	
	return true;
}

int winner(ticTacToeBoard board)
{
	//Check Rows
	for(int y = 0; y < 4; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if(board.points[x + 4*y] != board.points[(x+1) + 4*y])
			{
				break;
			}
			else if(x == 2 && board.points[x + 4*y] != 0)
			{
				cout << "Win 1" << endl;
				return board.points[x + 4*y];
			}
		}
	}
	
	//Check Columns
	for(int x = 0; x < 4; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(board.points[x + 4*y] != board.points[x + 4*(y+1)])
			{
				break;
			}
			else if(y == 2 && board.points[x + 4*y] != 0)
			{
				return board.points[x + 4*y];
			}
		}
	}
	
	//Check Diagonals
	for(int i = 0; i < 3; i++)
	{
		if(board.points[i + 4*i] != board.points[(i+1) + 4*(i+1)])
		{
			break;
		}
		else if(i == 2 && board.points[0] != 0)
		{
			return board.points[0];
		}
	}
	for(int i = 0; i < 3; i++)
	{
		if(board.points[(i) + 4*(3-i)] != board.points[(i+1) + 4*(2-i)])
		{
			break;
		}
		else if(i == 2 && board.points[3] != 0)
		{
			return board.points[3];
		}
	}
	return 0;
}

void printBoard(ticTacToeBoard board) {
  for (int y=0; y<4; y++) {
    cout << "|";
    for (int x=0; x<4; x++) {
      if (board.points[x+4*y]==0)
	cout << " ";
      else if (board.points[x+4*y]==1)
	cout << "X";
      else if (board.points[x+4*y]==-1)
	cout << "O";

      cout << "|";
    }
    cout << endl;
  }
}
