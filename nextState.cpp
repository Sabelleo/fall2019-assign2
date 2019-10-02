#include "nextState.h"
#include <iostream>

using namespace std;
setup s;

nextState::nextState()
{
  oldBoard = s.initialB;
  theNewBoard = nextBoard(oldBoard);
}

nextState::~nextState()
{
  //destructor
  //cout << "nextState Program exited." << endl;
}

char ** nextState::nextBoard(char ** theBoard)
{
  board b;

   //does this work?
  column = s.column;
  row = s.row;
  gameType = s.gameType;
  theNewBoard = b.emptyBoard(row, column);
  theNewBoard = checkType(gameType, theBoard, row, column);
  cout << endl;
  b.show(theNewBoard, column, row);
  return theNewBoard;
}

char ** nextState::checkType(string gameType, char ** theBoard, int row, int column)
{
  if (gameType == "c") //classic
  {
    theNewBoard = newClassicBoard(theBoard, row, column);
  }
  else if (gameType == "d") //doughnut
  {
    theNewBoard = newDoughnutBoard(theBoard, row, column);
  }
  else //mirror
  {
    theNewBoard = newMirrorBoard(theBoard, row, column);
  }
  return theNewBoard;
}

char ** nextState::newClassicBoard(char ** theBoard, int row, int column)
{
  int neighbors = 0;
  for (int i = 0; i < column; i++)
  {
    for (int j = 0; j < row; j++)
    {
      neighbors = 0;
      if ((i + 1) < column && theBoard[i + 1][j] == 'X')
      {
        //cout << "E neighbor " << endl;
				neighbors++; //east
			}
      if ((i - 1) >= 0 && theBoard[i - 1][j] == 'X')
      {
        //cout << "W neighbor " << endl;
				neighbors++; //west
			}
      if ((j + 1) < row && theBoard[i][j + 1] == 'X')
      {
        //cout << "S neighbor " << endl;
				neighbors++; //south
			}
      if ((j - 1) >= 0 && theBoard[i][j - 1] == 'X')
      {
        //cout << "N neighbor " << endl;
				neighbors++; //north
			}
      if ((i + 1) < column && (j - 1) >= 0 && theBoard[i + 1][j - 1] == 'X')
      {
        //cout << "NE neighbor " << endl;
				neighbors++; //north east
			}
      if ((i - 1) >= 0 && (j - 1) >= 0 && theBoard[i - 1][j - 1] == 'X')
      {
        //cout << "NW neighbor " << endl;
				neighbors++; //north west
			}
      if ((i + 1) < column && (j + 1) < row && theBoard[i + 1][j + 1] == 'X')
      {
        //cout << "SE neighbor " << endl;
        neighbors++; //south east
      }
      if ((i - 1) >= 0 && (j + 1) < row && theBoard[i - 1][j + 1] == 'X')
      {
        //cout << "SW neighbor " << endl;
				neighbors++; //south west
			}

      if (neighbors < 2 || neighbors > 3) //no cell there
      {
        theNewBoard[i][j] = '-';
      }
      else if (neighbors == 2) //same
      {
        if (theBoard[i][j] == 'X') //previous cell -> new cell
        {
          theNewBoard[i][j] = 'X';
        }
        else //no previous -> no new
        {
          theNewBoard[i][j] = '-';
        }
      }
      else //neighbors == 3, new cell no matter what
      {
        theNewBoard[i][j] = 'X';
      }
      //cout << "cell column " << i << " and row " << j << " has neighbors: " << neighbors << endl;
      //cout << "old value: " << theBoard[i][j] << " new value: " << theNewBoard[i][j] << endl;
    }
  }
  return theNewBoard;
}

int nextState::doughnutColumn(int myColumn)
{
  return (myColumn % column + column) % column;
  //negative values possible for myColumn
  // + column makes sure positive index value is returned
  // ) % column makes sure value is not bigger than column
}

int nextState::doughnutRow(int myRow)
{
  return (myRow % row + row) % row;
  //negative values possible for myRow
  // + row makes sure positive index value is returned
  // ) % row makes sure value is not bigger than row
}

char ** nextState::newDoughnutBoard(char ** theBoard, int row, int column)
{
  int neighbors = 0;
  for (int i = 0; i < column; i++)
  {
    for (int j = 0; j < row; j++)
    {
      neighbors = 0;
      //if (theBoard[doughnutRow(int myRow)][doughnutColumn(int myColumn)] == 'X')
      if (theBoard[doughnutColumn(i + 1)][doughnutRow(j)] == 'X')
      {
        //cout << "E neighbor " << endl;
				neighbors++; //east
			}
      if (theBoard[doughnutColumn(i - 1)][doughnutRow(j)] == 'X')
      {
        //cout << "W neighbor " << endl;
				neighbors++; //west
			}
      if (theBoard[doughnutColumn(i)][doughnutRow(j + 1)] == 'X')
      {
        //cout << "S neighbor " << endl;
				neighbors++; //south
			}
      if (theBoard[doughnutColumn(i)][doughnutRow(j - 1)] == 'X')
      {
        //cout << "N neighbor " << endl;
				neighbors++; //north
			}
      if (theBoard[doughnutColumn(i + 1)][doughnutRow(j - 1)] == 'X')
      {
        //cout << "NE neighbor " << endl;
				neighbors++; //north east
			}
      if (theBoard[doughnutColumn(i - 1)][doughnutRow(j - 1)] == 'X')
      {
        //cout << "NW neighbor " << endl;
				neighbors++; //north west
			}
      if (theBoard[doughnutColumn(i + 1)][doughnutRow(j + 1)] == 'X')
      {
        //cout << "SE neighbor " << endl;
        neighbors++; //south east
      }
      if (theBoard[doughnutColumn(i - 1)][doughnutRow(j + 1)] == 'X')
      {
        //cout << "SW neighbor " << endl;
				neighbors++; //south west
			}

      if (neighbors < 2 || neighbors > 3) //no cell there
      {
        theNewBoard[i][j] = '-';
      }
      else if (neighbors == 2) //same
      {
        if (theBoard[i][j] == 'X') //previous cell -> new cell
        {
          theNewBoard[i][j] = 'X';
        }
        else //no previous -> no new
        {
          theNewBoard[i][j] = '-';
        }
      }
      else //neighbors == 3, new cell no matter what
      {
        theNewBoard[i][j] = 'X';
      }
      //cout << "cell column " << i << " and row " << j << " has neighbors: " << neighbors << endl;
      //cout << "old value: " << theBoard[i][j] << " new value: " << theNewBoard[i][j] << endl;
    }
  }
  return theNewBoard;
}

int nextState::mirrorSides(int myColumn)
{
	if (myColumn < 0) //mirror the left/west side
  {
		return 0;
	}
	else if (myColumn == column) //mirror the right/east side
  {
		return (column - 1);
	}
	else // not a side edge
  {
		return myColumn;
	}
}

int nextState::mirrorTopBottom(int myRow)
{
	if (myRow < 0) //mirror the top
  {
		return 0;
	}
	else if (myRow == row) //mirror the bottom
  {
		return (row - 1);
	}
	else
  {
		return myRow; //not a top/bottom edge
	}
}

char ** nextState::newMirrorBoard(char ** theBoard, int row, int column)
{
  int neighbors = 0;
  for (int i = 0; i < column; i++)
  {
    for (int j = 0; j < row; j++)
    {
      neighbors = 0;
      if (theBoard[mirrorSides(i + 1)][mirrorTopBottom(j)] == 'X')
      {
        //cout << "E neighbor " << endl;
				neighbors++; //east
			}
      if (theBoard[mirrorSides(i - 1)][mirrorTopBottom(j)] == 'X')
      {
        //cout << "W neighbor " << endl;
				neighbors++; //west
			}
      if (theBoard[mirrorSides(i)][mirrorTopBottom(j + 1)] == 'X')
      {
        //cout << "S neighbor " << endl;
				neighbors++; //south
			}
      if (theBoard[mirrorSides(i)][mirrorTopBottom(j - 1)] == 'X')
      {
        //cout << "N neighbor " << endl;
				neighbors++; //north
			}
      if (theBoard[mirrorSides(i + 1)][mirrorTopBottom(j - 1)] == 'X')
      {
        //cout << "NE neighbor " << endl;
				neighbors++; //north east
			}
      if (theBoard[mirrorSides(i - 1)][mirrorTopBottom(j - 1)] == 'X')
      {
        //cout << "NW neighbor " << endl;
				neighbors++; //north west
			}
      if (theBoard[mirrorSides(i + 1)][mirrorTopBottom(j + 1)] == 'X')
      {
        //cout << "SE neighbor " << endl;
        neighbors++; //south east
      }
      if (theBoard[mirrorSides(i - 1)][mirrorTopBottom(j + 1)] == 'X')
      {
        //cout << "SW neighbor " << endl;
				neighbors++; //south west
			}

      if (neighbors < 2 || neighbors > 3) //no cell there
      {
        theNewBoard[i][j] = '-';
      }
      else if (neighbors == 2) //same
      {
        if (theBoard[i][j] == 'X') //previous cell -> new cell
        {
          theNewBoard[i][j] = 'X';
        }
        else //no previous -> no new
        {
          theNewBoard[i][j] = '-';
        }
      }
      else //neighbors == 3, new cell no matter what
      {
        theNewBoard[i][j] = 'X';
      }
      //cout << "cell column " << i << " and row " << j << " has neighbors: " << neighbors << endl;
      //cout << "old value: " << theBoard[i][j] << " new value: " << theNewBoard[i][j] << endl;
    }
  }
  return theNewBoard;
}
