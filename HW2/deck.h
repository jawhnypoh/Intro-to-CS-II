#pragma once
#include "cards.h"

using namespace std;

class Deck {
private:
  Card cards[52];
  int num_cards;
  Card *array_deck;
  Card *fill_cards;

public:
  Deck();                   // Constructor
  void shuffle_cards();     // Mutator
  Card get_card();
  void print_deck();

};
