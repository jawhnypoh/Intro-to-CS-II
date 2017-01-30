#include "game.h"

Game::Game() {
  num_arrows = 3;
  playing = true;
}

Game::~Game() {

}

int Game::get_num_arrows() {
  return num_arrows;
}

/*********************************************************************
Function: intro
Description: Introduces the game
Parameters: Size
Pre-Conditions: Driver must've called this function
Post-Conditions: Game will be introduced
*********************************************************************/
void Game::intro(int size)
{
  int choice;
  system("clear");
  // Introduction to the game!
  cout <<"There once was a boy, who's name we shall call. . . Jeremy Cole. " << endl;
  cout << endl;
  cout <<"He was a very curious boy, and one day he found a cave. " << endl;
  cout << endl;
  cout <<"Like any other curious boy, he decides enter the cave. " << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout <<"Press 1 to continue. . . ";
  cin >> choice;

  if(choice == 1)
  {
    system("clear");
    play_game(size);
  }
  else
  {
    cout <<"Try again, and follow directions this time. " << endl;
    cout << endl;
    exit(1);
  }
}

/*********************************************************************
Function: check_status
Description: Checks the status of the game
Parameters: Size
Pre-Conditions: Game must be running
Post-Conditions: Game status will be checked
*********************************************************************/
void Game::check_status(int size)
{
  while(playing == true)
  {
      // Check if has Wumpus
      if(cave.room_array[randr][randc].has_wumpus == true)
      {
        cave.room_array[randr][randc].wumpus_event();
        ask_repeat(size);
        playing = false;
      }

      // Check if has Gold
      else if(cave.room_array[randr][randc].has_gold == true)
      {
        cave.room_array[randr][randc].gold_event();
        cave.room_array[randr][randc].has_gold = false;

        return_back(size);
        playing = false;
      }

      // Check if has Pit
      else if(cave.room_array[randr][randc].has_pit == true)
      {
        cave.room_array[randr][randc].pit_event();
        ask_repeat(size);
        playing = false;

      }

      // Check if has Bats
      else if(cave.room_array[randr][randc].has_bats == true)
      {
        cave.room_array[randr][randc].bats_event();
        playing = true;

        // Function for teleportation
        teleport(size);
      }
      else
      {
        // Continue on
        move_user(size);
      }
  }
}

/*********************************************************************
Function: play_game
Description: Plays the game
Parameters: Size
Pre-Conditions: All variables and objects must exist
Post-Conditions: Game will be played
*********************************************************************/
void Game::play_game(int size)
{
  int num_rooms;
  int cont;
  num_rooms = size * size;

  cout <<"Plot twist! YOU are Jeremy Cole!!! " << endl;
  cout << endl;
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
  cout <<"There's a dangerous Wumpus that's sleeping in one of these rooms. . . " << endl;
  cout <<"Your job is to find the gold and escape alive! " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout << endl;
  cout <<"You start the game with " << get_num_arrows() <<" arrows, use them wisely. " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"Press any number key to continue . . . ";
  cin >> cont;

  cout <<"================================================" << endl;
  cout << endl;
  cout <<"                You're in a room. " << endl;
  cout << endl;
  cout <<"================================================" << endl;

  cout <<"For reference, here's an idea of what the cave's layout looks like: " << endl;
  cout << endl;
  cave.create_cave(size);
  cave.set_events(size);
  place_user(size);

  cout <<"Here's what your map looked like: " << endl;
  cave.print_cave(size);
}

/*********************************************************************
Function: place_user
Description: Places the user somewhere in the cave
Parameters: Size
Pre-Conditions: Cave must've been made
Post-Conditions: User will be placed in the cave
*********************************************************************/
void Game::place_user(int size)
{
  randr = (rand()%size); // Randomly assign for Row
  randc = (rand()%size); // Randomly assign for Columns

  if(cave.room_array[randr][randc].has_event == true)
  {
    randr = (rand()%size); // Randomly assign for Row
    randc = (rand()%size); // Randomly assign for Columns

    cave.room_array[randr][randc].set_message('X');

    startx = randr;
    starty = randc;
  }

  cave.room_array[randr][randc].set_message('X');

  startx = randr;
  starty = randc;

  //cave.print_cave(size);
  check_surrounding(size);
  move_user(size);
  check_status(size);
}

/*********************************************************************
Function: move_user
Description: Moves the user
Parameters: Size
Pre-Conditions: User and Cave must exist
Post-Conditions: User will be moved
*********************************************************************/
void Game::move_user(int size)
{
  int choice;
  bool incorrect = true;
  // Ask user what they want to do

  while(incorrect)
  {
    cout <<"================================================" << endl;
    cout <<"What do you want to do? " << endl;
    cout <<"1. Move Forward " << endl;
    cout <<"2. Move Backward " << endl;
    cout <<"3. Move Left " << endl;
    cout <<"4. Move Right " << endl;
    cout <<"5. Shoot Arrows " << endl;
    cout <<"Enter your choice: ";
    cin >> choice;

    while((randr == size-1 && choice == 1) ||
          (randr == 0 && choice == 2 ) ||
          (randc == 0 && choice == 3 ) ||
          (randc == size-1 && choice == 4))
          {
            cout << endl;
            cout <<"You've hit a wall, can't go move forward! " << endl;
            cout <<"Try again: ";
            cin >> choice;
          }

    if(choice == 1)
    {
      // Move Forward
      randr++;
      cave.room_array[randr][randc].set_message('X');
      incorrect = false;

    }
    else if(choice == 2)
    {
      // Move Backward
      randr--;
      cave.room_array[randr][randc].set_message('X');
      incorrect = false;

    }
    else if(choice == 3)
    {
      // Move Left
      randc--;
      cave.room_array[randr][randc].set_message('X');
      incorrect = false;

    }
    else if(choice == 4)
    {
      // Move Right
      randc++;
      cave.room_array[randr][randc].set_message('X');
      incorrect = false;

    }
    else if(choice == 5)
    {
      // Shoot Arrow
      cout << endl;
      shoot_arrow(size);

      incorrect = false;

    }
    else
    {
      cout << endl;
      cout <<"Bad input, please try again! " << endl;
    }

    check_surrounding(size);
    move_ze_wumpus(size);
    //cave.print_cave(size);
  }
}

/*********************************************************************
Function: shoot_arrow
Description: Shoots the arrow
Parameters: Size
Pre-Conditions: User, Cave, Arrows must exist
Post-Conditions: Arrow will be shot
*********************************************************************/
void Game::shoot_arrow(int size)
{
  int arrow_choice;
  bool incorrect = true;

  // Ask user where they want to shoot the arrow
  cout <<"You chose to shoot an Arrow. " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"You currently have " << num_arrows << " Arrows. " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"Where would you like to shoot it? " << endl;
  while(incorrect)
  {
    bool event = false;

    cout <<"================================================" << endl;
    cout <<"1. Shoot Forward " << endl;
    cout <<"2. Shoot Backward " << endl;
    cout <<"3. Shoot Left " << endl;
    cout <<"4. Shoot Right " << endl;
    cout <<"5. Don't shoot " << endl;
    cout <<"Enter your choice: ";
    cin >> arrow_choice;

    if(arrow_choice == 1)
    {
      num_arrows--;
      // Shoot arrow Forward
      if(randr == size-1)
      {
        cout <<"Your arrow hit a wall. " << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
        event = true;
        break;

      }

      for(int i=1; i<=3; i++)
      {
        if(cave.room_array[randr+i][randc].has_wumpus == true)
        {
          // Wumpus killed
          wumpus_killed(size);
          event = true;
          break;

        }
        else if(randr+i == size-1)
        {
          cout <<"Your arrow hit a wall. " << endl;
          cout << endl;
          cout <<"You now have " << num_arrows << " Arrows left. " << endl;
          event = true;
          break;

        }
      }

      if(event == false)
      {
        cout <<"Your arrow travelled 3 rooms and didn't hit anything. " << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
        cout << endl;
      }

      incorrect = false;
    }

    else if(arrow_choice == 2)
    {
      num_arrows--;
      // Shoot arrow Backward
      if(randr == 0)
      {
        cout <<"Your arrow hit a wall. " << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
        event = true;
        break;
      }

      for(int i=1; i<=3; i++)
      {
        if(cave.room_array[randr-i][randc].has_wumpus == true)
        {
          // Wumpus killed
          wumpus_killed(size);
          event = true;
          break;
        }
        else if(randr-i == 0)
        {
          cout <<"Your arrow hit a wall. " << endl;
          cout << endl;
          cout <<"You now have " << num_arrows << " Arrows left. " << endl;
          event = true;
          break;
        }
      }
      if(event == false)
      {
        cout <<"Your arrow travelled 3 rooms and didn't hit anything. " << endl;
        cout << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
      }

      incorrect = false;

    }
    else if(arrow_choice == 3)
    {
      num_arrows--;
      // Shoot arrow Left
      if(randc == 0)
      {
        cout <<"Your arrow hit a wall. " << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
        event = true;
        break;
      }

      for(int i=1; i<=3; i++)
      {
        if(cave.room_array[randr][randc-i].has_wumpus == true)
        {
          // Wumpus killed
          wumpus_killed(size);
          event = true;
          break;
        }
        else if(randc-i == 0)
        {
          cout <<"Your arrow hit a wall. " << endl;
          cout << endl;
          cout <<"You now have " << num_arrows << " Arrows left. " << endl;
          event = true;
          break;
        }
      }
      if(event == false)
      {
        cout <<"Your arrow travelled 3 rooms and didn't hit anything. " << endl;
        cout << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
      }

      incorrect = false;

    }
    else if(arrow_choice == 4)
    {
      num_arrows--;
      // Shoot arrow Right
      if(randc == size-1)
      {
        cout <<"Your arrow hit a wall. " << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
        event = true;
        break;
      }

      for(int i=1; i<=3; i++)
      {
        if(cave.room_array[randr][randc+i].has_wumpus == true)
        {
          // Wumpus killed
          wumpus_killed(size);
          event = true;
          break;
        }
        else if(randc+i == size-1)
        {
          cout <<"Your arrow hit a wall. " << endl;
          cout << endl;
          cout <<"You now have " << num_arrows << " Arrows left. " << endl;
          event = true;
          break;
        }
      }
      if(event == false)
      {
        cout <<"Your arrow travelled 3 rooms and didn't hit anything. " << endl;
        cout << endl;
        cout << endl;
        cout <<"You now have " << num_arrows << " Arrows left. " << endl;
      }

      incorrect = false;

    }
    else if(arrow_choice == 5)
    {
      // Nothing is Shot
      cout <<"No arrows were shot. " << endl;
      cout << endl;
      cout <<"You now have " << num_arrows << " Arrows left. " << endl;
      incorrect = false;
    }
    else
    {
      cout <<"Bad input, please try again. " << endl;
    }

  }
  if(num_arrows == 0)
  {
    cout <<"You don't have anymore arrows left, you didn't use them wisely. " << endl;
    cout << endl;
    cout <<"Since you can't defend yourself, you automatically die. Tough luck. " << endl;
    cout << endl;
    ask_repeat(size);
    playing = false;
  }
}

/*********************************************************************
Function: move_ze_wumpus
Description: Moves the wumpus
Parameters: Size
Pre-Conditions: Wumpus and Cave must exist already
Post-Conditions: Wumpus will have a 25% chance of moving
*********************************************************************/
void Game::move_ze_wumpus(int size)
{
  // There's a 25% chance that the Wumpus will move to a random location
  if(cave.check_wumpus(size) == false)
  {
    // Nothing happens, Wumpus doesn't exist
  }
  else
  {
    int rand_num;
    rand_num = (rand()%6 + 1);
    if(rand_num == 1)
    {
      cave.move_wumpus(size);
      cout << endl;
      cout <<"The Wumpus has awoken and moved to a new location! " << endl;
      cout << endl;
    }
  }

}

/*********************************************************************
Function: wumpus_killed
Description: Shows that wumpus is killed
Parameters: Size
Pre-Conditions: Wumpus must exist and be killed
Post-Conditions: Wumpus will be killed
*********************************************************************/
void Game::wumpus_killed(int size)
{
  cout << endl;
  cout <<"The arrow pierces the Wumpus' heart, and it lets out a loud, painful roar. " << endl;
  cout <<"Then it falls over. . .and dies. " << endl;
  cout << endl;
  cout << endl;
  cave.wumpus_is_dead();

  cout <<"================================================" << endl;
  cout <<"Now find the gold and escape! " << endl;
  cout << endl;
}

/*********************************************************************
Function: check_surrounding
Description: Checks the surroundings of the user
Parameters: Size
Pre-Conditions: User must be in the cave
Post-Conditions: User's surroundings will be checked
*********************************************************************/
void Game::check_surrounding(int size)
{
  // Check the surroundings of the user

  // Top, Bottom, Right
  if(randc == 0 && randr > 0 && randr < size-1)
  {
    // Check behind the user location
    if(cave.room_array[randr-1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr-1][randc].has_wumpus == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
      }

      // Check for gold
      else if(cave.room_array[randr-1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
      }

      // Check for pit
      else if(cave.room_array[randr-1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr-1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }

    // Check in front of user location
    else if(cave.room_array[randr+1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr+1][randc].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for gold
      else if(cave.room_array[randr+1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for pit
      else if(cave.room_array[randr+1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr+1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }

    // Check to the right of user location
    else if(cave.room_array[randr][randc+1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc+1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc+1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc+1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc+1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

  }

  // Right, Bottom
  else if(randc == 0 && randr == 0 && randr <size-1)
  {
    // Check to the right of user location
    if(cave.room_array[randr][randc+1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc+1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc+1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc+1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc+1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check in front of user location
    else if(cave.room_array[randr+1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr+1][randc].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr+1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr+1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr+1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }
  }

  // Left, Bottom
  else if(randc == size-1 && randc > 0 && randr == 0)
  {
    // Check to the left of user location
    if(cave.room_array[randr][randc-1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc-1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc-1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc-1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc-1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check in front of user location
    else if(cave.room_array[randr+1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr+1][randc].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr+1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr+1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr+1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }
  }

  // Top, Bottom, Left
  else if(randc == size-1 && randr > 0 && randr < size-1)
  {
    // Check behind the user location
    if(cave.room_array[randr-1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr-1][randc].has_wumpus == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for gold
      else if(cave.room_array[randr-1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for pit
      else if(cave.room_array[randr-1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr-1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }

    // Check in front of user location
    else if(cave.room_array[randr+1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr+1][randc].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr+1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr+1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr+1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check to the left of user location
    else if(cave.room_array[randr][randc-1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc-1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc-1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc-1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc-1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }
  }

  // Left, Top
  else if(randc == size -1 && randr == size-1)
  {
    // Check to the left of user location
    if(cave.room_array[randr][randc-1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc-1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc-1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc-1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc-1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check behind the user location
    if(cave.room_array[randr-1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr-1][randc].has_wumpus == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for gold
      else if(cave.room_array[randr-1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for pit
      else if(cave.room_array[randr-1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr-1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }
  }

  // Top, Right
  else if(randc == 0 && randr == size-1)
  {
    // Check behind the user location
    if(cave.room_array[randr-1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr-1][randc].has_wumpus == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for gold
      else if(cave.room_array[randr-1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for pit
      else if(cave.room_array[randr-1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr-1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }

    // Check to the right of user location
    else if(cave.room_array[randr][randc+1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc+1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc+1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc+1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc+1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }
  }

  // Left, Right, Bottom
  else if(randc > 0 && randc < size-1 && randr == 0)
  {
    // Check to the left of user location
    if(cave.room_array[randr][randc-1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc-1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc-1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc-1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc-1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check to the right of user location
    else if(cave.room_array[randr][randc+1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc+1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc+1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc+1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc+1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check in front of user location
    else if(cave.room_array[randr+1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr+1][randc].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr+1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr+1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr+1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }
  }

  // Left, Right, Top
  else if(randc > 0 && randc < size-1 && randr == size-1)
  {
    // Check to the left of user location
    if(cave.room_array[randr][randc-1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc-1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc-1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc-1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc-1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check to the right of user location
    else if(cave.room_array[randr][randc+1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc+1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc+1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc+1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc+1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check behind the user location
    if(cave.room_array[randr-1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr-1][randc].has_wumpus == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for gold
      else if(cave.room_array[randr-1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for pit
      else if(cave.room_array[randr-1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr-1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }
  }

  else
  {
    // Check behind the user location
    if(cave.room_array[randr-1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr-1][randc].has_wumpus == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for gold
      else if(cave.room_array[randr-1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for pit
      else if(cave.room_array[randr-1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }

      // Check for bats
      else if(cave.room_array[randr-1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;

      }
    }

    // Check in front of user location
    else if(cave.room_array[randr+1][randc].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr+1][randc].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr+1][randc].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr+1][randc].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr+1][randc].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check to the left of user location
    else if(cave.room_array[randr][randc-1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc-1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc-1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc-1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc-1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }

    // Check to the right of user location
    else if(cave.room_array[randr][randc+1].has_event == true)
    {
      // Check for wumpus
      if(cave.room_array[randr][randc+1].has_wumpus == true)
      {
        cout << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You smell a terrible stench. "          << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for gold
      else if(cave.room_array[randr][randc+1].has_gold == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"        You see a glimmer of hope nearby. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for pit
      else if(cave.room_array[randr][randc+1].has_pit == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"               You feel a breeze. "               << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }

      // Check for bats
      else if(cave.room_array[randr][randc+1].has_bats == true)
      {
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;
        cout <<"          You hear the flapping of wings. "       << endl;
        cout << endl;
        cout <<"================================================" << endl;
        cout << endl;


      }
    }
  }
}

/*********************************************************************
Function: teleport
Description: Teleports the user if bats are called
Parameters: Size
Pre-Conditions: Bats must be called
Post-Conditions: User will be moved to a new place in cave
*********************************************************************/
void Game::teleport(int size)
{
  // If user meets bats, they teleport him somewhere else
  int new_randr, new_randc;
  new_randr = (rand()%size); // Randomly assign for Row
  new_randc = (rand()%size); // Randomly assign for Columns

  while(new_randr == randr && new_randc == randc)
  {
    new_randr = (rand()%size); // Randomly assign for Row
    new_randc = (rand()%size); // Randomly assign for Columns
  }

  randr = new_randr; // Set User Row to new randomized #
  randc = new_randc; // Set User Column to new randomized #

  cave.room_array[randr][randc].set_message('X');

  //cave.print_cave(size);
  check_surrounding(size);
  check_status(size);
}

/*********************************************************************
Function: return_back
Description: Checks if user is back to where they started
Parameters: Size
Pre-Conditions: User must've already found the gold
Post-Conditions: If user finds their way back, they win!
*********************************************************************/
void Game::return_back(int size)
{
  cout <<"Now find your way back to win! " << endl;
  while(randr != startx || randc != starty)
  {
    move_user(size);
    if(randr == startx && randc == starty)
    {
      cout <<"Congratulations, you beat the game!!! " << endl;
      cout << endl;
      ask_repeat(size);
      break;
    }
  }
}

/*********************************************************************
Function: ask_repeat
Description: Asks user if they want to repeat the game
Parameters: Size
Pre-Conditions: User must've either won or lost the game
Post-Conditions: User will be asked if they want to repeat the game
*********************************************************************/
void Game::ask_repeat(int size)
{
  // Ask the user if they'd like to repeat the game
  bool incorrect = true;
  while(incorrect)
  {
    int choice;
    cout <<"================================================" << endl;
    cout <<"Do you want to play again? " << endl;
    cout <<"1. Yes " << endl;
    cout <<"2. No " << endl;
    cout <<"Enter your choice: ";
    cin >> choice;
    cout << endl;

    if(choice == 1)
    {
      int config_choice;
      cout << endl;
      cout <<"Do you want the same configurations? " << endl;
      cout <<"1. Yes, I want everything to be the same. " << endl;
      cout <<"2. No, I want to restart everything " << endl;
      cout <<"Choice: ";
      cin >> config_choice;
      cout << endl;
      incorrect = false;

      if(config_choice == 1)
      {
        // Repeat with same configurations
        cave.room_array.clear();
        intro(size);
      }
      else if(config_choice == 2)
      {
        // Repeat with new everything
        cave.room_array.clear();
        new_game();
      }
    }
    else if(choice == 2)
    {
      cout << endl;
      cout <<"Okay, have a nice day! :) " << endl;
      cout << endl;
      cave.room_array.clear();
      incorrect = false;
    }
    else
    {
      cout <<"Bad input, please try again! " << endl;
      cout <<"Choice: ";
      cin >> choice;
    }
  }
}

/*********************************************************************
Function: new_game
Description: New game will be made
Parameters: None
Pre-Conditions: Only called if ask_repeat asks for this function
Post-Conditions: New game will be created with new size
*********************************************************************/
void Game::new_game()
{
  int size;

  // Initialize new game with the new size that the user specifies
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"What size do you want your new Cave to be? (Cannot be less than 4) ";
  cin >> size;
  while(size < 4)
  {
    cout <<"You can't have a Cave less than 4, try again. " << endl;
    cout <<"Size: ";
    cin >>size;
  }
  intro(size);
}
