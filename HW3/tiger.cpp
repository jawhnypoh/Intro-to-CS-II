#include <iostream>
#include "tiger.h"

using namespace std;

Tiger::Tiger() {
  age = 3;
  cost = 10000;
}

Tiger::Tiger(int age, int cost) {
  this->age = age;
  this->cost = cost;
}

Tiger::~Tiger() {

}

/*********************************************************************
Function: get_age
Description: Gets age
Parameters: None
Pre-Conditions: Age must exist
Post-Conditions: Age returned
*********************************************************************/
int Tiger::get_age() {
  return age;
}

/*********************************************************************
Function: get_cost
Description: Gets cost
Parameters: None
Pre-Conditions: Cost must exist
Post-Conditions: Cost returned
*********************************************************************/
int Tiger::get_cost() {
  return cost;
}

/*********************************************************************
Function: get_num_babies
Description: Gets number of babies
Parameters: None
Pre-Conditions: Number of babies must exist
Post-Conditions: Number of babies returned
*********************************************************************/
int Tiger::get_num_babies() {
  return num_babies;
}

/*********************************************************************
Function: get_food_cost
Description: Gets food cost
Parameters: None
Pre-Conditions: Food cost must exist
Post-Conditions: Returns food cost
*********************************************************************/
int Tiger::get_food_cost() {
  return food_cost;
}

/*********************************************************************
Function: set_age
Description: Sets the age
Parameters: None
Pre-Conditions: Age must exist
Post-Conditions: Age will be set
*********************************************************************/
void Tiger::set_age(int age) {
  this->age = age;
}

/*********************************************************************
Function: add_age
Description: Increments age
Parameters: None
Pre-Conditions: Age must exist
Post-Conditions: Age will be incremented
*********************************************************************/
int Tiger::add_age() {
  age++;
  return age;
}
