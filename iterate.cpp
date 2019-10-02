#include "iterate.h"
#include <iostream>

using namespace std;

iterate::iterate()
{
  nextState n;
  int num = 1;
  cout << "iteration " << num++ << endl;
  oldBoard = n.nextBoard(n.oldBoard);
  //newBoard = n.nextBoard(oldBoard);
  while (num < 100 || oldBoard != newBoard)
  {
    cout << "iteration " << num << endl;
    newBoard = n.nextBoard(oldBoard);
    num++;
    cout << endl;
    oldBoard = newBoard;
  }
}

iterate::~iterate()
{
  //destructor
  //cout << "iterate Program exited." << endl;
}
