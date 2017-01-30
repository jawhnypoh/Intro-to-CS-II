#pragma once
#include <iostream>
#include "events.h"

using namespace std;

// Bats publicly inherits Events
class Bats : public Events {
public:
  Bats();
  ~Bats();

  void event_happen();
};
