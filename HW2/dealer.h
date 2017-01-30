#pragma once
#include "cards.h"
#include "deck.h"
#include "hand.h"

class Dealer {
private:
  //Hand dealer_hand;
  int card_total;
  Deck deck;

public:
  Dealer() {

  }

  Dealer(Deck dealers_deck) {
    deck = dealers_deck;
  }

  Hand dealer_hand;
  Hand get_dealer_hand();
  int get_card_total();
  void print_card();

};
