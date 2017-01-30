#pragma once
#include <iostream>
#include "events.h"
#include "room.h"

class State {
private:
  Room rooms;
  /*Events *event;
  Wumpus wumpus;
  Pit pit;
  Bats bats;
  Gold gold;*/

  Room **room_array;

  int num_arrows;
  bool is_dead;
public:
  State();
  ~State();

  int get_num_arrows();

  void play_game(int);

};
