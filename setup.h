#include "board.h"
#include <iostream>

using namespace std;

class setup
{
  public:
    //definitions for functions, etc.
    setup();
    ~setup();
    char ** typeInput();
    char ** boardBuild(string type);
    char ** randBuild();
    char ** fileBuild();

    string type;
    string gameType;
    string outputType;
    char ** initialB;
    int row;
    int column;

};
