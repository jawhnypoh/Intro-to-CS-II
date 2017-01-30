#include "dealer.h"

using namespace std;

/*********************************************************************
Function: get_dealer_hand
Description: Returns the dealer hand
Parameters: None
Pre-Conditions: Varables must exist
Post-Conditions: Dealer hand will be returned
*********************************************************************/
Hand Dealer::get_dealer_hand() {
  dealer_hand.create_dealer_cards(deck.get_card(), deck.get_card());

  return dealer_hand;
}

/*********************************************************************
Function: get_card_total
Description: Returns the card total
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: Card total will be returned
*********************************************************************/
int Dealer::get_card_total() {
  return card_total;
}

/*********************************************************************
Function: print_card
Description: Prints out the dealer's cards
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: Dealer's cards will be printed out 
*********************************************************************/
void Dealer::print_card() {
  cout <<"Dealer's cards: " << endl;
  dealer_hand.create_dealer_cards(deck.get_card(), deck.get_card());

}
