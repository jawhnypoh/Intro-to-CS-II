#include <iostream>
#include "hand.h"

using namespace std;

/*********************************************************************
Function: Hand::Hand
Description: Constructor
Parameters: None
Pre-Conditions: Everything must exist
Post-Conditions: Hand object will be created
*********************************************************************/
Hand::Hand() {
  array_hand = NULL;
  num_cards = 0;
}

/*********************************************************************
Function: create_dealer_cards
Description: Creates the dealer cards
Parameters: card1, card2
Pre-Conditions: Cards must exist
Post-Conditions: Dealer cards will be shown
*********************************************************************/
void Hand::create_dealer_cards(Card d_card1, Card d_card2) {
  this->d_card1 = d_card1;
  this->d_card2 = d_card2;
  cout << this->d_card1.print_card() << endl;
  cout << this->d_card2.print_card() << endl;
}

/*********************************************************************
Function: create_cards
Description: Creates the cards
Parameters: card_1, card_2
Pre-Conditions: Everything must exist
Post-Conditions: Cards will be created
*********************************************************************/
void Hand::create_cards(Card card_1, Card card_2) {
  // Create card array for hand
  this->card_1 = card_1;
  this->card_2 = card_2;
  cout << this->card_1.print_card() << endl;
  cout << this->card_2.print_card() << endl;
}

/*********************************************************************
Function: add_cards
Description: Adds cards
Parameters: added_card
Pre-Conditions: Everything must exist
Post-Conditions: Added card will be created
*********************************************************************/
void Hand::add_cards(Card added_card) {
  this->added_card = added_card;
  cout << this->added_card.print_card() << endl;
}

/*********************************************************************
Function: get_num_cards
Description: Gets the number of cards
Parameters: None
Pre-Conditions: Num_cards must exist
Post-Conditions: Returns num_cards 
*********************************************************************/
int Hand::get_num_cards() {
  return num_cards;
}
