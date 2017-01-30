#pragma once
#include <iostream>
#include "animal.h"
#include "tiger.h"
#include "pb.h"
#include "penguin.h"
#include "kangaroo.h"


using namespace std;

class Zoo {
private:
  int player_money;
  int day;
  int payoff;

  Animal animals;

  Tiger* array_tigers;
  PB* array_pbs;
  Penguin* array_penguins;
  Kangaroo* array_kangaroos;

public:
  Zoo();
  Zoo(Zoo&);
  void operator=(Zoo&);
  ~Zoo();
  int get_player_money();
  int get_day();

  Tiger add_tiger(bool);
  PB add_pb(bool);
  Penguin add_penguin(bool);
  Kangaroo add_kangaroo(bool);

  void remove_tiger();
  void remove_pb();
  void remove_penguin();
  void remove_kangaroo();

  void play_game();
  void new_day();
  void add_ages();
  void buy_animal();
  void feeding();
  void random_event();
  void sickness();
  void boom();
  void baby();
  void nothing();
  void set_payoff();
  void ask_repeat();
  void game_lose();
};
