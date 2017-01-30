#include <iostream>
#include <vector>
#include "state.h"

using namespace std;

State::State() {
  num_arrows = 3;
  // 2D array of rooms
}

State::~State() {

}

int State::get_num_arrows() {
  return num_arrows;
}

void State::play_game(int size)
{
  int num_rooms;
  num_rooms = size * size;

  cout << endl;
  cout <<" ___________________________________________ " << endl;
  cout <<"|                                           |" << endl;
  cout <<"|         Welcome to Hunt the Wumpus!       |" << endl;
  cout <<"|                                           |" << endl;
  cout <<"|___________________________________________|" << endl;
  cout << endl;
  cout << endl;
  cout <<"There are " << num_rooms << " rooms in this cave! " << endl;
  cout << endl;
  cout <<"Your name is Jeremy Cole! Your job is to find the gold and escape alive! " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"You start the game with " << get_num_arrows() <<" arrows, use them wisely. " << endl;
  cout << endl;
  cout << endl;
  cout <<"================================================" << endl;


  // 2D array of rooms
  vector<vector<Room> > room_array;
  room_array.resize(size);
  for(int i=0; i<size; i++)
  {
    room_array[i].resize(size);
  }

  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      cout <<" " << room_array[i][j].message();
    }
    cout <<" " << endl;
  }
  cout << endl;

  /*event = &wumpus;
  event->event_happen();

  cout << endl;

  event = &pit;
  event->event_happen();

  cout << endl;

  event = &bats;
  event->event_happen();

  cout << endl;

  event = &gold;
  event->event_happen();*/

}
