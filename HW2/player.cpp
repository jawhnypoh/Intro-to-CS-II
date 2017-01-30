#include "player.h"

using namespace std;

/*********************************************************************
Function: get_player_hand
Description: Gets the player hand
Parameters: None
Pre-Conditions: Player_hand must exist
Post-Conditions: Returns the player_hand
*********************************************************************/
Hand Player::get_player_hand() {
  return player_hand;
}

/*********************************************************************
Function: get_playing_total
Description: Gets the playing total
Parameters: None
Pre-Conditions: Playing total must exist
Post-Conditions: Returns playing total
*********************************************************************/
int Player::get_playing_total() {
  return playing_total;
}

/*********************************************************************
Function: set_playing_total
Description: Sets the playing total
Parameters: None
Pre-Conditions: Playing total must exist
Post-Conditions: Playing total will be set
*********************************************************************/
int Player::set_playing_total() {
  playing_total = 1000;
  cout <<"Each player starts with: " << "$" << playing_total << endl;

  return playing_total;
}

/*********************************************************************
Function: get_card_total
Description: Gets the card total
Parameters: None
Pre-Conditions: Card total must exist
Post-Conditions: Returns the card total
*********************************************************************/
int Player::get_card_total() {
  return card_total;
}

/*********************************************************************
Function: get_player_bet
Description: Gets the player bet
Parameters: None
Pre-Conditions: Everything must exist
Post-Conditions: Returns player_bet
*********************************************************************/
int Player::get_player_bet() {
  int bet;
  cout <<"How much do you want to bet? $";
  cin >> bet;

  return player_bet;
}

/*********************************************************************
Function: add_money
Description: Adds money to player bank
Parameters: None
Pre-Conditions: Money and bet must exist
Post-Conditions: New playig total will be returned
*********************************************************************/
int Player::add_money() {
  playing_total += player_bet;

  return playing_total;
}

/*********************************************************************
Function: lose_money
Description: Takes away money to player bank
Parameters: none
Pre-Conditions: Money and bet must exist
Post-Conditions: New playing total will be returned 
*********************************************************************/
int Player::lose_money() {
  playing_total -= player_bet;

  return playing_total;
}
