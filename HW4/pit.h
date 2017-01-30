#pragma once
#include <iostream>
#include "events.h"

using namespace std;

// Pit publicly inherits Events
class Pit : public Events {
public:
  Pit();
  ~Pit();

  void event_happen();
};
