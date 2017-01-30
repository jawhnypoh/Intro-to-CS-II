#pragma once
#include <iostream>
#include "animal.h"

// Kangaroo inherits Animal class
class Kangaroo : public Animal {
private:
  int age;
  int cost;
  int num_babies;
public:
  Kangaroo();
  Kangaroo(int, int);
  ~Kangaroo();

  int get_age();
  int get_cost();
  int get_num_babies();
  int get_food_cost();

  void set_age(int);
  int add_age();
};
