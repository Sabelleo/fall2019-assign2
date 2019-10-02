#include <iostream>

using namespace std;

class board
{
  public:
    //definitions for functions, etc.
    board();
    ~board();

    char newRand();
    char ** randBoard(int row, int column);
    char ** fileBoard(int row, int column);
    char ** emptyBoard(int row, int column);
    void show(char **board, int row, int column);

    char** theBoard;
};
