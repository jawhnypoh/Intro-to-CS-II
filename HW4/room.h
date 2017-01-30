#pragma once
#include <iostream>
#include "events.h"
#include "wumpus.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"
#include "room.h"

using namespace std;


class Room {
private:
  Events *event;
  Wumpus wumpus;
  Pit pit;
  Bats bats;
  Gold gold;

  char var;

public:
  bool has_event;
  bool has_gold;
  bool has_wumpus;
  bool has_bats;
  bool has_pit;

  Room();
  ~Room();

  char get_message();
  void set_message(char);

  void wumpus_event();
  void pit_event();
  void bats_event();
  void gold_event();

};
