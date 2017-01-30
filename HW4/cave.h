#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "events.h"
#include "room.h"

using namespace std;

class Cave {
private:
  int w_randr, w_randc;
  int g_randr, g_randc;
  int p_randr, p_randc;
  int b_randr, b_randc;

public:
  vector< vector<Room> > room_array;

  Cave();
  ~Cave();

  void create_cave(int);
  void set_events(int);
  bool check_wumpus(int);
  void move_wumpus(int);
  void wumpus_is_dead();
  void print_cave(int);
};
