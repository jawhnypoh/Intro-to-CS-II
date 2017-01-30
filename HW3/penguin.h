#pragma once
#include <iostream>
#include "animal.h"

using namespace std;

// Penguin inherits Animal class
class Penguin : public Animal {
private:
  int age;
  int cost;
  int num_babies;
public:
  Penguin();
  Penguin(int, int);
  ~Penguin();

  int get_age();
  int get_cost();
  int get_num_babies();
  int get_food_cost();

  void set_age(int);
  int add_age();
};
