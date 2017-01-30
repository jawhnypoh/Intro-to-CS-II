#include <iostream>
#include "kangaroo.h"

using namespace std;

Kangaroo::Kangaroo() {
  age = 3;
  cost = 30000;
}

Kangaroo::Kangaroo(int age, int cost) {
  this->age = age;
  this->cost = cost;
}

Kangaroo::~Kangaroo() {

}

/*********************************************************************
Function: get_age
Description: Gets age
Parameters: None
Pre-Conditions: Age must exist
Post-Conditions: Age returned
*********************************************************************/
int Kangaroo::get_age() {
  return age;
}

/*********************************************************************
Function: get_cost
Description: Gets cost
Parameters: None
Pre-Conditions: Cost must exist
Post-Conditions: Cost returned
*********************************************************************/
int Kangaroo::get_cost() {
  return cost;
}

/*********************************************************************
Function: get_num_babies
Description: Gets number of babies
Parameters: None
Pre-Conditions: Number of babies must exist
Post-Conditions: Number of babies returned
*********************************************************************/
int Kangaroo::get_num_babies() {
  return num_babies;
}

/*********************************************************************
Function: get_food_cost
Description: Gets food cost
Parameters: None
Pre-Conditions: Food cost must exist
Post-Conditions: Returns food cost
*********************************************************************/
int Kangaroo::get_food_cost() {
  return food_cost;
}

/*********************************************************************
Function: set_age
Description: Sets the age
Parameters: None
Pre-Conditions: Age must exist
Post-Conditions: Age will be set
*********************************************************************/
void Kangaroo::set_age(int) {
  this->age = age;
}

/*********************************************************************
Function: add_age
Description: Increments age
Parameters: None
Pre-Conditions: Age must exist
Post-Conditions: Age will be incremented 
*********************************************************************/
int Kangaroo::add_age() {
  age++;
  return age;
}
