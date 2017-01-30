#include <iostream>
#include <stdlib.h>
#include "deck.h"

/*********************************************************************
Function: Deck::Deck
Description: Constructor
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: array of 52 cards will be created with suit and value
*********************************************************************/
Deck::Deck() {

  string values[13] = {"A", "2", "3", "4", "5", "6", "7", "8" ,"9", "10", "J", "Q", "K"};
  string suits[4] = {"Diamonds", "Hearts", "Clubs", "Spades"};
  num_cards = 52;

  array_deck = new Card[52];
  fill_cards = new Card[num_cards];
  for(int i=0; i<52; i++)
  {
    array_deck[i] = Card(values[i%13], suits[i/13]);
  }
}

/*********************************************************************
Function: shuffle_cards
Description: Shuffles the card array
Parameters: None
Pre-Conditions: Card array must exist already
Post-Conditions: Card array will be shuffled
*********************************************************************/
void Deck::shuffle_cards() {
  cout <<"Shuffling deck... " << endl;
  for(int i=0; i<52; i++)
  {
    int random = (rand()%52);
    Card new_card = array_deck[i];
    array_deck[i] = array_deck[random];
    array_deck[random] = new_card;
  }
}

/*********************************************************************
Function: get_card
Description: Gets a card from the deck, returns it
Parameters: None
Pre-Conditions: Deck array must exist
Post-Conditions: New card will be added
*********************************************************************/
Card Deck::get_card() {
  Card new_card;

  new_card = array_deck[num_cards - 1];
  num_cards--;

  return new_card;
}

/*********************************************************************
Function: print_deck
Description: Prints the deck
Parameters: None
Pre-Conditions: Deck must exist
Post-Conditions: Deck will be printed out
*********************************************************************/
void Deck::print_deck() {
  for(int i=0; i<num_cards; i++)
  {
    cout << array_deck[i].print_card() << endl;
  }
}
