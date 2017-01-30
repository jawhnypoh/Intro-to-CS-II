#pragma once
#include <iostream>
#include "animal.h"

using namespace std;

// Tiger publicly inherits Animal
class Tiger : public Animal {
private:
  int age;
  int cost;
  int num_babies;
public:
  Tiger();
  Tiger(int, int);
  ~Tiger();

  int get_age();
  int get_cost();
  int get_num_babies();
  int get_food_cost();

  void set_age(int);
  int add_age();
};
