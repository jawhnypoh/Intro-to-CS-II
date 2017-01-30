#include "game.h"
#include "hand.h"
#include <stdlib.h>
#include <string>

using namespace std;

/*********************************************************************
Function: get_deck_cards
Description: Gets the deck cards
Parameters: None
Pre-Conditions: Deck must exist
Post-Conditions: Returns the deck
*********************************************************************/
Deck Game::get_deck_cards() {
  return deck;
}

/*********************************************************************
Function: play_game
Description: Plays the game
Parameters: None
Pre-Conditions: All variables and everything must exist
Post-Conditions: Game will be played...mostly
*********************************************************************/
void Game::play_game() {
  cout << endl;
  cout <<"        Welcome to BlackJack!       " << endl;
  cout << endl;
  cout << endl;

  set_num_players();
  array_players = get_players();
  cout << endl;
  int player_bets;
  cout << endl;

  deck.shuffle_cards();
  game_dealer = Dealer(deck);
  game_dealer.print_card();

  int dealer_value;
  int cards_value;


  // First Card
  if(game_dealer.dealer_hand.d_card1.value == "J" ||
    game_dealer.dealer_hand.d_card1.value == "Q" ||
    game_dealer.dealer_hand.d_card1.value == "K")
    {
      game_dealer.dealer_hand.card_1.value = "10";
      cout <<"Face Card converted to 10 " << endl;
      cout << endl;
    }

    // Second Card
    if(game_dealer.dealer_hand.d_card2.value == "J" ||
      game_dealer.dealer_hand.d_card2.value == "Q" ||
      game_dealer.dealer_hand.d_card2.value == "K")
      {
        game_dealer.dealer_hand.card_2.value = "10";
        cout <<"Face Card converted to 10 " << endl;
        cout << endl;
      }

  // For First Card
  if(game_dealer.dealer_hand.d_card1.value == "A")
  {
    if(game_dealer.dealer_hand.d_card2.value >= "11")
    {
      game_dealer.dealer_hand.d_card1.value == "1";
    }
    else if(game_dealer.dealer_hand.d_card2.value <= "10")
    {
      game_dealer.dealer_hand.d_card1.value == "11";
    }
    cout << game_dealer.dealer_hand.d_card1.value << endl;
  }

  // For Second Card
  if(game_dealer.dealer_hand.d_card2.value == "A")
  {
    if(game_dealer.dealer_hand.d_card1.value >= "11")
    {
      game_dealer.dealer_hand.d_card2.value == "1";
    }
    else if(game_dealer.dealer_hand.d_card1.value <= "10")
    {
      game_dealer.dealer_hand.d_card2.value == "11";
    }
    cout << game_dealer.dealer_hand.d_card2.value << endl;
  }

  dealer_value = atoi(game_dealer.dealer_hand.d_card1.value.c_str()) +
                 atoi(game_dealer.dealer_hand.d_card2.value.c_str());

  // Run through array of players and play the game
  for(int i=0; i<num_players; i++)
  {
    array_players[i].set_playing_total();

    cout <<"Player " << (i+1) <<": ";
    player_bets = array_players[i].get_player_bet();
    array_players[i].player_bet = player_bets;

    cout <<"Your Current Card Values are: " << endl;
    array_players[i].player_hand.create_cards(deck.get_card(), deck.get_card());

    if(array_players[i].player_hand.card_1.value == "J" ||
      array_players[i].player_hand.card_1.value == "Q" ||
      array_players[i].player_hand.card_1.value == "K")
      {
        cout <<"Face Card detected, converting to 10..." << endl;
        array_players[i].player_hand.card_1.value = "10";
      }

      if(array_players[i].player_hand.card_2.value == "J" ||
        array_players[i].player_hand.card_2.value == "Q" ||
        array_players[i].player_hand.card_2.value == "K")
        {
          cout <<"Face Card detected, converting to 10..." << endl;
          array_players[i].player_hand.card_2.value = "10";
        }

    string ace_choice;
    if(array_players[i].player_hand.card_1.value == "A")
    {
      cout <<"You have an Ace in your hand! " << endl;
      cout <<"Would you like it to be 1 or 11? ";
      cin.ignore();
      getline (cin, ace_choice);

      array_players[i].player_hand.card_1.value = ace_choice;
    }

    if(array_players[i].player_hand.card_2.value == "A")
    {
      cout <<"You have an Ace in your hand! " << endl;
      cout <<"Would you like it to be 1 or 11? ";
      cin.ignore();
      getline (cin, ace_choice);

      array_players[i].player_hand.card_2.value = ace_choice;
    }

      cards_value = atoi(array_players[i].get_player_hand().card_1.value.c_str()) +
                    atoi(array_players[i].get_player_hand().card_2.value.c_str());
      cout << endl;
      cout <<"Your current Card Value is: " << cards_value << endl;

    check_value(cards_value, i);
  }

  cout <<"Dealer's Value: " << dealer_value << endl;
  int new_dealer_value;
  while(dealer_value <= 17)
  {
    cout <<"Dealer's new card: " << endl;
    game_dealer.dealer_hand.add_cards(deck.get_card());

    if(game_dealer.dealer_hand.added_card.value == "J" ||
      game_dealer.dealer_hand.added_card.value == "Q" ||
      game_dealer.dealer_hand.added_card.value == "K")
      {
        cout <<"Face Card detected, converting to 10..." << endl;
        game_dealer.dealer_hand.added_card.value = "10";
      }

    if(game_dealer.dealer_hand.added_card.value == "A")
    {
      if(dealer_value >= 11)
      {
        game_dealer.dealer_hand.added_card.value == "1";
      }
    }
    new_dealer_value = dealer_value + atoi(game_dealer.dealer_hand.added_card.value.c_str());

    cout << endl;
    cout <<"Dealer's card value: " << new_dealer_value << endl;

    dealer_value = new_dealer_value;
  }

  compare_values(array_players, cards_value, dealer_value, num_players);
  repeat_game();
}

/*********************************************************************
Function: get_players
Description: Creates the array of players
Parameters: None
Pre-Conditions: Players class and object must exist
Post-Conditions: Players array will be created
*********************************************************************/
Player* Game::get_players() {
  array_players = new Player[num_players];

  return array_players;
}

/*********************************************************************
Function: get_num_players
Description: Returns the number of players
Parameters: None
Pre-Conditions: num_players must exist
Post-Conditions: Number of players will be returned
*********************************************************************/
int Game::get_num_players() {
  return num_players;
}

/*********************************************************************
Function: set_num_players
Description: Sets the number of players
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: Number of players will be set
*********************************************************************/
int Game::set_num_players() {
  int amount_players;

  cout <<"How many players? ";
  cin >> amount_players;
  while(amount_players > 9)
  {
    cout <<"ERROR: Too many players (Only 9 is allowed)! " << endl;
    cout <<"New Input: ";
    cin >> amount_players;
  }

  num_players = amount_players;


  return num_players;
}

/*********************************************************************
Function: hit_stay
Description: Asks user to hit or stay and acts accordingly
Parameters: cards_value, i
Pre-Conditions: Everything should exist
Post-Conditions: User will be asked to hit or stay, program will act accordingly
*********************************************************************/
void Game::hit_stay(int &cards_value, int i) {
  int hit_choice;
  int new_cards_value;

  cout <<"Do you want to Hit(0), or Stay(1)? ";
  cin >> hit_choice;

  if(hit_choice == 0)
  {
    cout <<"Your new card: " << endl;
    array_players[i].player_hand.add_cards(deck.get_card());

    if(array_players[i].player_hand.added_card.value == "J" ||
      array_players[i].player_hand.added_card.value == "Q" ||
      array_players[i].player_hand.added_card.value == "K")
      {
        cout <<"Face Card detected, converting to 10..." << endl;
        array_players[i].player_hand.added_card.value = "10";
      }

    if(array_players[i].player_hand.added_card.value == "A")
    {
      string ace_choice_added;
      cout <<"You have an Ace in your hand! " << endl;
      cout <<"Would you like it to be 1 or 11? ";
      cin.ignore();
      getline (cin, ace_choice_added);

      array_players[i].player_hand.added_card.value = ace_choice_added;
    }
    new_cards_value = cards_value + atoi(array_players[i].player_hand.added_card.value.c_str());

    cout << endl;
    cout <<"Your cards value: " << new_cards_value << endl;

    cards_value = new_cards_value;
    check_value(cards_value, i);

    array_players[i].card_total = cards_value;
  }

  else if(hit_choice == 1)
  {
    cout <<"Good choice, my son. " << endl;
    cout << endl;
  }
  else
  {
    if(hit_choice < 0 || hit_choice > 1)
    {
      cout <<"Invalid choice! " << endl;
      hit_stay(cards_value, i);
    }
  }
}

/*********************************************************************
Function: check_value
Description: Checks the value of cards
Parameters: cards_value, i
Pre-Conditions: Everything must exist
Post-Conditions: Checks the values of cards
*********************************************************************/
void Game::check_value(int &cards_value, int i) {
  if(cards_value == 21)
  {
    cout <<"Player " << i+1 << " got 21! " << endl;
  }
  else if(cards_value > 21)
  {
    cout <<"Player " << i+1 << " has busted, tough luck. " << endl;
    cout << endl;
  }
  else
  {
    hit_stay(cards_value, i);
  }
}

/*********************************************************************
Function: compare_values
Description: Compares the values of the cards
Parameters: array_players, cards_value, dealer_value, num_players
Pre-Conditions: Everything must exist
Post-Conditions: Values will be compared
*********************************************************************/
void Game::compare_values(Player* array_players, int cards_value, int dealer_value, int num_players) {
  if(dealer_value > 21)
  {
    for(int i=0; i<num_players; i++)
    {
      if(array_players[i].card_total < 21)
      {
        // Call add money function
        array_players[i].add_money();
        cout <<"Player " << i+1 <<"'s money: " << array_players[i].get_playing_total() << endl;
      }
      else if(array_players[i].card_total > 21)
      {
        // Call lose money function
        array_players[i].lose_money();
        cout <<"Player " << i+1 <<"'s money: " << array_players[i].get_playing_total() << endl;
      }
    }
  }

  else if(dealer_value == 21)
  {
    for(int i=0; i<num_players; i++)
    {
      if(array_players[i].card_total != 21)
      {
        // Call lose money function
        array_players[i].lose_money();
        cout <<"Player " << i+1 <<"'s money: " << array_players[i].get_playing_total() << endl;
      }
    }
  }

  else if(dealer_value < 21)
  {
    for(int i=0; i<num_players; i++)
    {
      if(cards_value < 21 && cards_value > dealer_value)
      {
        array_players[i].add_money();
        cout <<"Player " << i+1 <<"'s money: " << array_players[i].get_playing_total() << endl;
      }
    }
  }

}

/*********************************************************************
Function: repeat_game
Description: Repeats the game
Parameters: None
Pre-Conditions: Everything must exist
Post-Conditions: Game will be repeated
*********************************************************************/
void Game::repeat_game() {
  int choice;
  cout <<"Do you want to play another round (0 = No, 1 = Yes)? ";
  cin >> choice;

  if(choice == 0)
  {
    cout <<"Okay, goodbye. " << endl;
    cout << endl;
    exit(1);
  }
  else if(choice == 1)
  {
    cout <<"Okay, setting up new round. " << endl;
    play_game();
  }

  else{
    while(choice < 0 || choice > 2)
    {
      cout <<"Please enter a valid choice! " << endl;
      cout <<"Do you want to play another round (0 = No, 1 = Yes)? ";
      cin >> choice;
    }
  }
}
