#pragma once
#include "cards.h"

using namespace std;

class Hand {
private:
  Card *array_hand;
  int num_cards;

public:
  Hand();
  Card d_card1;
  Card d_card2;

  Card card_1;
  Card card_2;
  Card added_card;
  void create_dealer_cards(Card, Card);
  void create_cards(Card, Card);
  void add_cards(Card);
  int get_num_cards();
  void set_cards(int, Card);

};
