/*********************************************************************  *
Program Filename: hw2.exe
Author: JOHNNY PO
Date: 4.24.16
Description: Plays the Casino game BlackJack
Input: User Inputs
Output: The Game will be played
*********************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "deck.h"
#include "game.h"

using namespace std;

int main()
{
  srand(time(NULL));

  Deck game_deck;
  Game game;

  game.play_game();
  cout << endl;

  cout << endl;
  cout << endl;

  return 0;
}
