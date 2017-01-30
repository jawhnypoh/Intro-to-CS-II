#pragma once
#include "dealer.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

using namespace std;

class Game {
private:
  Deck deck;
  Player* array_players;
  int num_players;

public:
  Game() {
    //deck = game_deck;
  }

  Dealer game_dealer;

  Deck get_deck_cards();  // Accessor
  void play_game();
  Player* get_players();   // Accessor
  int get_num_players();  // Accessor
  int set_num_players();  // Mutator
  void hit_stay(int&, int);
  void check_value(int&, int);
  void compare_values(Player*, int, int, int);
  void repeat_game();

};
