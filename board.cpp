#include "board.h"
#include <iostream>
#include <random>

using namespace std;

board::board()
{
  //cout << "Board Program constructed." << endl;
  //constructor
}

board::~board()
{
  //destructor
  //cout << "Board Program exited." << endl;
}

char ** board::randBoard(int row, int column)
{
  //rows
  theBoard = new char *[row];
  //columns
  for(int i = -1; i < row; ++i)
  {
    theBoard[i] = new char[column];
    for (int j = 0 ; j < column ; j++)
    {
      theBoard[i][j] = newRand();
    }
  }

  cout << "randBoard made." << endl;

  return theBoard;
}

char ** board::fileBoard(int row, int column)
{
  theBoard = new char *[row];

  for(int i = 0; i < row; i++)
  {
    theBoard[i] = new char[column];
    for (int j = 0 ; j < column ; j++)
    {
      theBoard[i][j] = '.';
    }
  }

  cout << "fileBoard made." << endl;

  return theBoard;
}

char board::newRand()
{
  //not very random!!!
  //creates a random bool value for the initial cell configuration
  char randAlive = '-';
  if ((rand() % 2) + 1 ==  2)
  {
    randAlive = 'X';
  }
  return randAlive;
}

void board::show(char ** board, int row, int column)
{
	for(int i = 0; i < column; i++)
	{
		for(int j = 0; j < row; j++)
		{
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
}

char ** board::emptyBoard(int row, int column)
{
  //rows
  theBoard = new char *[column];
  //columns
  for(int i = 0; i < column; i++)
  {
    theBoard[i] = new char[row];
    for (int j = 0 ; j < row ; j++)
    {
      theBoard[i][j] = '.';
    }
  }
  return theBoard;
}

/*
Sources:

http://www.cplusplus.com/forum/beginner/79626/

https://www.geeksforgeeks.org/pointer-array-array-pointer/

https://www.includehelp.com/cpp-tutorial/passing-dynamically-allocated-two-dimensional-array-to-a-function.aspx

*/
