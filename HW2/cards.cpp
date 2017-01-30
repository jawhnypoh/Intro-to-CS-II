#include "cards.h"

/*********************************************************************
Function: Card::Card
Description: Constructor
Parameters: c_value, c_suit
Pre-Conditions: Variables must exist
Post-Conditions: Card object will be made
*********************************************************************/
Card::Card(string c_value, string c_suit) {
	value = c_value;
	suit = c_suit;

}

/*********************************************************************
Function: print_card()
Description: Returns "value of suit"
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: "Value of suit" will be returned
*********************************************************************/
string Card::print_card() {
	return (value + " of " + suit);
}

/*********************************************************************
Function: get_card_value
Description: Returns the card value
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: Value will be returned 
*********************************************************************/
string Card::get_card_value() {

	return value;
}
