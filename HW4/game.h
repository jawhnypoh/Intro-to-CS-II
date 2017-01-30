#pragma once
#include <iostream>
#include "cave.h"

using namespace std;

class Game {
private:
  Cave cave;

  int num_arrows;
  int randr;
  int randc;

  int startx;
  int starty;

  bool playing;

public:
  Game();
  ~Game();

  int get_num_arrows();

  void play_game(int);
  void intro(int);
  void check_status(int);
  void place_user(int);
  void move_user(int);
  void shoot_arrow(int);
  void move_ze_wumpus(int);
  void wumpus_killed(int);
  void check_surrounding(int);
  void teleport(int);
  void return_back(int);
  void ask_repeat(int);
  void new_game();
};
