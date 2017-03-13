struct ticTacToeBoard {
  int curr_player;
  int points[4*4];
};

void printBoard(ticTacToeBoard board);
void initBoard(ticTacToeBoard& board);
bool isEmpty(ticTacToeBoard board, int x, int y);
void mark(ticTacToeBoard& board, int x, int y);
bool boardFull(ticTacToeBoard board);
int winner(ticTacToeBoard board);


