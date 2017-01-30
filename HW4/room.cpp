#include "room.h"

Room::Room() {
  has_event = false;
  has_gold = false;
  has_wumpus = false;
  has_bats = false;
  has_pit = false;

  var = 'O';
}

Room::~Room() {

}

/*********************************************************************
Function: get_message
Description: Returns var
Parameters: None
Pre-Conditions: Var must exist
Post-Conditions: Returns var
*********************************************************************/
char Room::get_message() {

  return var;
}

/*********************************************************************
Function: set_message
Description: Sets var
Parameters: None
Pre-Conditions: Var must exist
Post-Conditions: Sets var
*********************************************************************/
void Room::set_message(char var) {
  this->var = var;

}

/*********************************************************************
Function: wumpus_event
Description: Polymorphism for wumpus
Parameters: None
Pre-Conditions: All classes must exist
Post-Conditions: Wumpus funciton works
*********************************************************************/
void Room::wumpus_event() {
  event = &wumpus;
  event->event_happen();
}

/*********************************************************************
Function: pit_event
Description: Polymorphism for pit
Parameters: None
Pre-Conditions: All classes must exist
Post-Conditions: Pit funciton works
*********************************************************************/
void Room::pit_event() {
  event = &pit;
  event->event_happen();
}

/*********************************************************************
Function: bats_event
Description: Polymorphism for bats
Parameters: None
Pre-Conditions: All classes must exist
Post-Conditions: Bats funciton works
*********************************************************************/
void Room::bats_event() {
  event = &bats;
  event->event_happen();
}

/*********************************************************************
Function: gold_event
Description: Polymorphism for gold
Parameters: None
Pre-Conditions: All classes must exist
Post-Conditions: Gold funciton works
*********************************************************************/
void Room::gold_event() {
  event = &gold;
  event->event_happen();
}
