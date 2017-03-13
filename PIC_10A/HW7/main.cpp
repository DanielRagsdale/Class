#include <iostream>
#include <cassert>
#include "ticTacToeBoard.h"
using namespace std;

int main() {
  ticTacToeBoard b1;
  initBoard(b1);
  printBoard(b1);
  int x, y;
  bool madeMove;
  //while board is not full
  while (!boardFull(b1)) {
    //Ask for current player to make move
    if (b1.curr_player == 1) cout << "Player X";
    else cout << "Player O";
    cout << ", what is your move?\n";
    
    //loop to get valid move.
    do {
      cin >> x; cin >> y;
      //if move out of bound, get input agin
      if ( !((1<=x)&&(x<=4)&&(1<=y)&&(y<=4)) ) {
	cout << "Out of bounds.\n";
	continue;
      }
      //If empty make move
      if (isEmpty(b1,x,y)) {
	mark(b1,x,y);
	break; //done with this move
      } else {
	cout << "You can't play there.\n";//get input again
      }
    } while(true);
   
    printBoard(b1);
    if (winner(b1)!=0) break;//if there is a winner, exit
    
    //Swap player
    b1.curr_player *= -1;

  }
  
  //We're done either because there's a winner
  //or because the board is full.
  if (winner(b1)==1)
    cout << "X is the winner!\n";
  else if (winner(b1)==-1)
    cout << "O is the winner!\n";
  else
    cout << "The game is a tie!\n";
}
