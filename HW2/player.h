#pragma once
#include "cards.h"
#include "hand.h"

using namespace std;

class Player {
private:
  int playing_total;
  //int player_bet;

public:
  Hand player_hand;
  Player() { // Constructor

  }
  int card_total;
  int player_bet;

  Hand get_player_hand();   // Accessor
  int get_playing_total();  // Accessor
  int set_playing_total();  // Mutator
  int get_card_total();     // Accessor
  int get_player_bet();     // Accessor
  int add_money();
  int lose_money();

};
