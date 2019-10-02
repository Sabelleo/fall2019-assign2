#include "setup.h"
#include <iostream>

using namespace std;

class nextState
{
  public:
    nextState();
    ~nextState();
    char ** nextBoard(char ** theBoard);
    char ** checkType(string gameType, char ** board, int row, int column);
    char ** newClassicBoard(char ** board, int row, int column);
    int doughnutColumn(int myColumn);
    int doughnutRow(int myRow);
    char ** newDoughnutBoard(char ** board, int row, int column);
    int mirrorSides(int myColumn);
    int mirrorTopBottom(int myRow);
    char ** newMirrorBoard(char ** board, int row, int column);


    char ** oldBoard;
    int row;
    int column;
    char ** theNewBoard;

    string gameType;

};
