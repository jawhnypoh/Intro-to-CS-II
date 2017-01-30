#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    cout <<"Error, not enough or too many arguments! " << endl;
    cout <<"USAGE: hw4 -s # of size " << endl;
    cout << endl;
  }
  else
  {
    int size = atoi(argv[2]);
    if(size < 4)
    {
      cout <<"ERROR: Caves with less than 4 rooms on one side are not allowed. " << endl;
      cout << endl;
      exit(1);
    }

    // Create Game objeect
    Game game;
    game.intro(size);
  }

  return 0;
}
