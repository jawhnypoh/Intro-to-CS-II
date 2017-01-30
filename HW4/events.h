#pragma once
#include <iostream>

using namespace std;

class Events {
public:
  Events();
  ~Events();

  virtual void event_happen() = 0;
};
