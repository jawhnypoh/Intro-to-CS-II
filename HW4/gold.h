#pragma once
#include <iostream>
#include "events.h"

using namespace std;

// Gold publicly inherits Events
class Gold : public Events {
public:
  Gold();
  ~Gold();

  void event_happen();
};
