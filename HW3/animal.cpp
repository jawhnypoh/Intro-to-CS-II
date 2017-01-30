#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal(int food_cost) {
  this->food_cost = food_cost;

}

Animal::~Animal() {

}

// Get food costs

/*********************************************************************
Function: get_food_tiger
Description: Gets tiger's food
Parameters: None
Pre-Conditions: Food cost must exist
Post-Conditions: Food cost for tiger returned
*********************************************************************/
int Animal::get_food_tiger() {
  return food_cost*5;
}

/*********************************************************************
Function: get_food_pb
Description: Gets polar bear's food
Parameters: None
Pre-Conditions: Food cost must exist
Post-Conditions: Food cost for polar bear returned
*********************************************************************/
int Animal::get_food_pb() {
  return food_cost*3;
}

/*********************************************************************
Function: get_food_penguin
Description: Gets penguin's food
Parameters: None
Pre-Conditions: Food cost must exist
Post-Conditions: Food cost for penguin returned
*********************************************************************/
int Animal::get_food_penguin() {
  return food_cost;
}

/*********************************************************************
Function: get_food_kangaroo
Description: Gets kangaroo's food
Parameters: None
Pre-Conditions: Food cost must exist
Post-Conditions: Food cost for kangaroo returned
*********************************************************************/
int Animal::get_food_kangaroo() {
  return food_cost*8;
}

// Get number of animals

/*********************************************************************
Function: get_num_tiger
Description: Gets tiger's num
Parameters: None
Pre-Conditions: num_tiger must exist
Post-Conditions: num_tiger returned
*********************************************************************/
int Animal::get_num_tiger() {
  return num_tiger;
}

/*********************************************************************
Function: get_num_pb
Description: Gets polar bear's num
Parameters: None
Pre-Conditions: num_pb must exist
Post-Conditions: num_pb returned
*********************************************************************/
int Animal::get_num_pb() {
  return num_pb;
}

/*********************************************************************
Function: get_num_penguin
Description: Gets penguin's num
Parameters: None
Pre-Conditions: num_penguin must exist
Post-Conditions: num_penguin returned
*********************************************************************/
int Animal::get_num_penguin() {
  return num_penguin;
}

/*********************************************************************
Function: get_num_kangaroo
Description: Gets kangaroo's num
Parameters: None
Pre-Conditions: num_kangaroo must exist
Post-Conditions: num_kangaroo returned
*********************************************************************/
int Animal::get_num_kangaroo() {
  return num_kangaroo;
}

// Set number of animals

/*********************************************************************
Function: set_num_tiger
Description: Sets tiger's num
Parameters: None
Pre-Conditions: num_tiger must exist
Post-Conditions: num_tiger returned
*********************************************************************/
void Animal::set_num_tiger(int num_tiger) {
  this->num_tiger = num_tiger;
}

/*********************************************************************
Function: set_num_pb
Description: Sets polar bear's num
Parameters: None
Pre-Conditions: num_pb must exist
Post-Conditions: num_pb returned
*********************************************************************/
void Animal::set_num_pb(int num_pb) {
  this->num_pb = num_pb;
}

/*********************************************************************
Function: set_num_penguin
Description: Sets penguin's num
Parameters: None
Pre-Conditions: num_penguin must exist
Post-Conditions: num_penguin returned
*********************************************************************/
void Animal::set_num_penguin(int num_penguin) {
  this->num_penguin = num_penguin;
}

/*********************************************************************
Function: set_num_kangaroo
Description: Sets kangaroo's num
Parameters: None
Pre-Conditions: num_kangaroo must exist
Post-Conditions: num_kangaroo returned
*********************************************************************/
void Animal::set_num_kangaroo(int num_kangaroo) {
  this->num_kangaroo = num_kangaroo;
}
