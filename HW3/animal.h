#pragma once
#include <iostream>

using namespace std;

class Animal {
protected:
  int food_cost;
  int num_tiger;
  int num_pb;
  int num_penguin;
  int num_kangaroo;

public:
  Animal() {
    food_cost = 100;
    num_tiger = 0;
    num_pb = 0;
    num_penguin = 0;
    num_kangaroo = 0;
  }
  ~Animal();

  Animal(int);

  int get_food_tiger();
  int get_food_pb();
  int get_food_penguin();
  int get_food_kangaroo();

  int get_num_tiger();
  int get_num_pb();
  int get_num_penguin();
  int get_num_kangaroo();

  void set_num_tiger(int);
  void set_num_pb(int);
  void set_num_penguin(int);
  void set_num_kangaroo(int);
};
