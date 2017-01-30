#include "cave.h"

Cave::Cave() {

}

Cave::~Cave() {

}

/*********************************************************************
Function: create_cave
Description: Creates the cave
Parameters: Size
Pre-Conditions: Array of rooms must exist
Post-Conditions: Cave will be created
*********************************************************************/
void Cave::create_cave(int size)
{
  srand(time(NULL));

  // 2D array of rooms
  room_array.resize(size);
  for(int i=0; i<size; i++)
  {
    room_array[i].resize(size);
  }

  // Print out 2D array of rooms
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      cout <<" " << room_array[i][j].get_message();
    }
    cout <<" " << endl;
  }
  cout << endl;

}

/*********************************************************************
Function: set_events
Description: Sets the events in random rooms of the cave
Parameters: Size
Pre-Conditions: Cave must be created
Post-Conditions: Events will be randomly set in the cave
*********************************************************************/
void Cave::set_events(int size)
{
  // Set for Wumpus
  w_randr = (rand()%size); // Randomly assign for Row
  w_randc = (rand()%size); // Randomly assign for Columns

  room_array[w_randr][w_randc].has_wumpus = true;
  room_array[w_randr][w_randc].has_event = true;

  room_array[w_randr][w_randc].set_message('W');
  cout << endl;

  // Set for Gold
  g_randr = (rand()%size); // Randomly assign for Row
  g_randc = (rand()%size); // Randomly assign for Columns

  // If room has an event already, randomize again
  if(room_array[g_randr][g_randc].has_event == true)
  {
    g_randr = (rand()%size); // Randomly assign for Row
    g_randc = (rand()%size); // Randomly assign for Columns
    room_array[g_randr][g_randc].has_gold = true;
    room_array[g_randr][g_randc].has_event = true;
    room_array[g_randr][g_randc].set_message('G');
  }
  else
  {
    room_array[g_randr][g_randc].has_gold = true;
    room_array[g_randr][g_randc].has_event = true;
    room_array[g_randr][g_randc].set_message('G');
  }


  // Set for Pits
  for(int i=1; i<=2; i++)
  {
    p_randr = (rand()%size); // Randomly assign for Row
    p_randc = (rand()%size); // Randomly assign for Columns

    // If room has an event already, randomize again
    if(room_array[p_randr][p_randc].has_event == true)
    {
      p_randr = (rand()%size); // Randomly assign for Row
      p_randc = (rand()%size); // Randomly assign for Columns
      room_array[p_randr][p_randc].has_pit = true;
      room_array[p_randr][p_randc].has_event = true;
      room_array[p_randr][p_randc].set_message('P');
    }
    else
    {
      room_array[p_randr][p_randc].has_pit = true;
      room_array[p_randr][p_randc].has_event = true;
      room_array[p_randr][p_randc].set_message('P');
    }
  }

  // Set for Bats
  for(int i=1; i<=2; i++)
  {
    b_randr = (rand()%size); // Randomly assign for Row
    b_randc = (rand()%size); // Randomly assign for Columns

    // If room has an event already, randomize again
    if(room_array[b_randr][b_randc].has_event == true)
    {
      b_randr = (rand()%size); // Randomly assign for Row
      b_randc = (rand()%size); // Randomly assign for Columns
      room_array[b_randr][b_randc].has_bats = true;
      room_array[b_randr][b_randc].has_event = true;
      room_array[b_randr][b_randc].set_message('B');
    }
    else
    {
      room_array[b_randr][b_randc].has_bats = true;
      room_array[b_randr][b_randc].has_event = true;
      room_array[b_randr][b_randc].set_message('B');
    }
  }

}

bool Cave::check_wumpus(int size)
{
  // Check to see if Wumpus exists
  if(room_array[w_randr][w_randc].has_wumpus == false)
  {
    // There is no Wumpus that exists
    return false;
  }
  else
  {
    // A Wumpus exists
    return true;
  }
}

/*********************************************************************
Function: move_wumpus
Description: Moves the wumpus
Parameters: Size
Pre-Conditions: Function to move the wumpus must be called
Post-Conditions: Wumpus will be moved to new location
*********************************************************************/
void Cave::move_wumpus(int size)
{
  // Set old location to false
  room_array[w_randr][w_randc].set_message('O');
  room_array[w_randr][w_randc].has_wumpus = false;

  // Move the Wumpus to new Random Room
  w_randr = (rand()%size); // Randomly assign for Row
  w_randc = (rand()%size); // Randomly assign for Columns
  if(room_array[w_randr][w_randc].has_event == true)
  {
    w_randr = (rand()%size); // Randomly assign for Row
    w_randc = (rand()%size); // Randomly assign for Columns

    // Set for new Room
    room_array[w_randr][w_randc].has_wumpus = true;
    room_array[w_randr][w_randc].has_event = true;
  }

  // Set for new Room
  room_array[w_randr][w_randc].has_wumpus = true;
  room_array[w_randr][w_randc].has_event = true;

  room_array[w_randr][w_randc].set_message('W');
  cout << endl;
}

/*********************************************************************
Function: wumpus_is_dead
Description: Sets the wumpus event to false if wumpus is dead
Parameters: None
Pre-Conditions: Wumpus must be dead
Post-Conditions: Location in which Wumpus is at will be set to false
*********************************************************************/
void Cave::wumpus_is_dead()
{
  // If the Wumpus is dead, set it's location to false
  room_array[w_randr][w_randc].has_wumpus = false;
  room_array[w_randr][w_randc].has_event = false;
  room_array[w_randr][w_randc].set_message('O');

}

/*********************************************************************
Function: print_cave
Description: Prints the cave (For debugging)
Parameters: Size
Pre-Conditions: Cave must exist
Post-Conditions: Cave will be printed 
*********************************************************************/
void Cave::print_cave(int size)
{
  cout << endl;

  // Print out the cave (For debugging purposes)
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      cout <<" " << room_array[i][j].get_message();
    }
    cout <<" " << endl;
  }
  cout << endl;

}
