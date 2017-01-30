#pragma once
#include <iostream>
#include "events.h"

using namespace std;

// Wumpus publicly inherits Events
class Wumpus : public Events {
public:
  Wumpus();
  ~Wumpus();

  void event_happen();
};
