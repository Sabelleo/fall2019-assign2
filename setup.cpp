#include "setup.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

board b;

setup::setup()
{

  initialB = typeInput();

/*
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      cout << "row: " << i << " column: " << j << " value: " << initialB[j][i] << endl;
    }
  }
  */

  //constructor
}

setup::~setup()
{
  //destructor
  //cout << "Setup Program exited." << endl;
}

char ** setup::typeInput()
{
  type = " ";
  gameType = " ";
  outputType = " ";
  cout << "Welcome to the Game of Life! " << endl;
  while (gameType != "c" && gameType != "d" && gameType != "m")
  {
    cout << "Please choose a game version to play: Classic (c), Doughnut (d), or Mirror (m). " << endl;
    getline(cin, gameType);
  }
  while (outputType != "p" && outputType != "k" && outputType != "f")
  {
    cout << "Please choose an output type for generations: brief pause (p), enter key (k), output to a file (f). " << endl;
    getline(cin, outputType);
  }
  while(type != "r" && type != "f")
  {
    cout << "Would you like to make a random board (r) or use a file (f)?" << endl;
    getline(cin, type);
  }
  initialB = boardBuild(type);
  return initialB;
}

char ** setup::boardBuild(string type)
{
  if (type == "r")
  {
    initialB = randBuild();
  }
  else //if (typeInput() == "f")
  {
    initialB = fileBuild();
  }
  cout << "show initial board" << endl;
  b.show(initialB, column, row);

  return initialB;
}

char ** setup::randBuild()
{
  //error check for not int???
  cout << "Please enter the number of columns you would like to generate: " << endl;
  cin >> column;
  cout << "Please enter the number of rows you would like to generate: " << endl;
  cin >> row;

  b.randBoard(column, row);
  initialB = b.theBoard;
  return initialB;
}

char ** setup::fileBuild()
{
  string fileName = " ";
  cout << "Please enter the name of the file you would like to use: " << endl;
  cin >> fileName;

  ifstream file;
  file.open(fileName);
  string line;

  if (file.is_open())
  {
      cout << "File ./" << fileName << " has been opened." << endl;

      getline(file, line, '\n');
      row = stoi(line);
      cout << row << " rows" << endl;
      getline(file, line, '\n');
      column = stoi(line);
      cout << column << " columns" << endl;

      b.fileBoard(column, row);
      initialB = b.theBoard;

      char xDash;
      for (int i = 0 ; i < row ; i++)
      {
        getline(file, line, '\n');
        for (int j = 0 ; j < column ; j++)
        {
          xDash = line[j];
          if(xDash == '-')
          {
            initialB[j][i] = '-';
          }
          else if (xDash == 'X')
          {
            initialB[j][i] = 'X';
          }
          else
          {
            cout << "Your file contains ineligable values. Not a valid format." << endl;
          }
        }
      }
      file.close();
  }
  return initialB;
}

// https://www.includehelp.com/cpp-tutorial/passing-dynamically-allocated-two-dimensional-array-to-a-function.aspx
