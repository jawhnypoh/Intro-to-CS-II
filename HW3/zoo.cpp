#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "animal.h"
#include "tiger.h"
#include "pb.h"
#include "penguin.h"
#include "kangaroo.h"
#include "zoo.h"

using namespace std;

Zoo::Zoo() {
  player_money = 100000;
  day = 1;
}

Zoo::Zoo(Zoo &obj)
{
  player_money = obj.player_money;
  day = obj.day;
  array_tigers = new Tiger [obj.animals.get_num_tiger()];
  array_pbs = new PB [obj.animals.get_num_pb()];
  array_penguins = new Penguin [obj.animals.get_num_penguin()];
  for(int i = 0; i < obj.animals.get_num_tiger(); i++){
    array_tigers[i] = obj.array_tigers[i];
  }
  for(int i = 0; i < obj.animals.get_num_pb(); i++){
    array_pbs[i] = obj.array_pbs[i];
  }
  for(int i = 0; i < obj.animals.get_num_penguin(); i++){
    array_penguins[i] = obj.array_penguins[i];
  }
}

void Zoo::operator=(Zoo &obj){
  player_money = obj.player_money;
  day = obj.day;
  delete [] array_tigers;
  delete [] array_pbs;
  delete [] array_penguins;
  array_tigers = new Tiger [obj.animals.get_num_tiger()];
  array_pbs = new PB [obj.animals.get_num_pb()];
  array_penguins = new Penguin [obj.animals.get_num_penguin()];
  for(int i = 0; i < obj.animals.get_num_tiger(); i++){
    array_tigers[i] = obj.array_tigers[i];
  }
  for(int i = 0; i < obj.animals.get_num_pb(); i++){
    array_pbs[i] = obj.array_pbs[i];
  }
  for(int i = 0; i < obj.animals.get_num_penguin(); i++){
    array_penguins[i] = obj.array_penguins[i];
  }
}

Zoo::~Zoo()
{
  if(animals.get_num_tiger() != 0)
  {
    delete [] array_tigers;
    cout <<"Tiger deleted " << endl;
  }
  if(animals.get_num_pb() != 0)
  {
    delete [] array_pbs;
    cout <<"PB deleted " << endl;
  }
  if(animals.get_num_penguin() != 0)
  {
    delete [] array_penguins;
    cout <<"Penguins deleted " << endl;
  }
  if(animals.get_num_kangaroo() != 0)
  {
    delete [] array_kangaroos;
    cout <<"Kangaroos deleted " << endl;
  }
  cout << endl;
  cout <<"Arrays deleted! " << endl;
}

/*********************************************************************
Function: get_player_money
Description: Returns the player's money
Parameters: None
Pre-Conditions: Variable must exist
Post-Conditions: Player money will be returned
*********************************************************************/
int Zoo::get_player_money() {
  return player_money;
}

/*********************************************************************
Function: get_day
Description: Returns the day
Parameters: None
Pre-Conditions: Variables must exist
Post-Conditions: Day number will be returned
*********************************************************************/
int Zoo::get_day() {
  return day;
}

/*********************************************************************
Function: add_tiger
Description: Adds a tiger to the array
Parameters: boolean
Pre-Conditions: Tiger array must exist
Post-Conditions: Another tiger will be added to the array
*********************************************************************/
Tiger Zoo::add_tiger(bool born)
{
  Tiger* temp;
  if(animals.get_num_tiger() == 0){
    array_tigers = new Tiger[animals.get_num_tiger() + 1];
  }
  else{
    temp = new Tiger[animals.get_num_tiger() + 1];
    for(int i=0; i<animals.get_num_tiger(); i++)
    {
      temp[i] = array_tigers[i];
    }
    delete [] array_tigers;
    array_tigers = temp;
  }
  animals.set_num_tiger(animals.get_num_tiger() + 1);
  if(born)
  {
      array_tigers[animals.get_num_tiger() - 1].set_age(0);
  }
}

/*********************************************************************
Function: remove_tiger
Description: Removes a tiger from the array
Parameters: boolean
Pre-Conditions: Tiger array must exist
Post-Conditions: Another tiger will be removed from the array
*********************************************************************/
void Zoo::remove_tiger()
{
  Tiger* temp;
  if(animals.get_num_tiger() == 0)
  {
    cout <<"There are no tigers to kill. " << endl;
  }
  else if(animals.get_num_tiger() == 1)
  {
    animals.set_num_tiger(0);
    delete [] array_tigers;
  }
  else
  {
    animals.set_num_tiger(animals.get_num_tiger() - 1);
  }
}

/*********************************************************************
Function: add_pb
Description: Adds a polar bear to the array
Parameters: boolean
Pre-Conditions: Polar Bear array must exist
Post-Conditions: Another polar bear will be added to the array
*********************************************************************/
PB Zoo::add_pb(bool born)
{
  PB* temp;
  if(animals.get_num_pb() == 0)
  {
    array_pbs = new PB[animals.get_num_pb() + 1];
  }
  else
  {
    temp = new PB[animals.get_num_pb() + 1];
    for(int i=0; i<animals.get_num_pb(); i++)
    {
      temp[i] = array_pbs[i];
    }
    delete [] array_pbs;
    array_pbs = temp;
  }
  animals.set_num_pb(animals.get_num_pb() + 1);
  if(born)
  {
      array_pbs[animals.get_num_pb() - 1].set_age(0);
  }
}

/*********************************************************************
Function: remove_pb
Description: Removes a polar bear from the array
Parameters: boolean
Pre-Conditions: Polar Bear array must exist
Post-Conditions: Another polar bear will be removed from the array
*********************************************************************/
void Zoo::remove_pb()
{
  PB* temp;
  if(animals.get_num_pb() == 0)
  {
    cout <<"There are no polar bears to kill. " << endl;
  }
  else if(animals.get_num_pb() == 1)
  {
    animals.set_num_pb(0);
    delete [] array_pbs;
  }
  else
  {
    animals.set_num_pb(animals.get_num_pb() - 1);
  }
}
/*********************************************************************
Function: add_penguin
Description: Adds a penguin to the array
Parameters: boolean
Pre-Conditions: Penguin array must exist
Post-Conditions: Another penguin will be added to the array
*********************************************************************/
Penguin Zoo::add_penguin(bool born)
{
  Penguin* temp;
  if(animals.get_num_penguin() == 0)
  {
    array_penguins = new Penguin[animals.get_num_penguin() + 1];
  }
  else
  {
    temp = new Penguin[animals.get_num_penguin() + 1];
    for(int i=0; i<animals.get_num_penguin(); i++)
    {
      temp[i] = array_penguins[i];
    }
    delete [] array_penguins;
    array_penguins = temp;
  }
  animals.set_num_penguin(animals.get_num_penguin() + 1);
  if(born)
  {
      array_penguins[animals.get_num_penguin() - 1].set_age(0);
  }
}

/*********************************************************************
Function: remove_penguin
Description: Removes a penguin from the array
Parameters: boolean
Pre-Conditions: Penguin array must exist
Post-Conditions: Another penguin will be removed to the array
*********************************************************************/
void Zoo::remove_penguin()
{
  Penguin* temp;
  if(animals.get_num_penguin() == 0)
  {
    cout <<"There are no penguins to kill. " << endl;
  }
  else if(animals.get_num_penguin() == 1)
  {
    animals.set_num_penguin(0);
    delete [] array_penguins;
  }
  else
  {
    animals.set_num_tiger(animals.get_num_tiger() - 1);
  }
}

/*********************************************************************
Function: add_kangaroo
Description: Adds a kangaroo to the array
Parameters: boolean
Pre-Conditions: Kangaroo array must exist
Post-Conditions: Another kangaroo will be added to the array
*********************************************************************/
Kangaroo Zoo::add_kangaroo(bool born)
{
  Kangaroo* temp;
  if(animals.get_num_kangaroo() == 0)
  {
    array_kangaroos = new Kangaroo[animals.get_num_kangaroo() + 1];
  }
  else
  {
    temp = new Kangaroo[animals.get_num_kangaroo() + 1];
    for(int i=0; i<animals.get_num_kangaroo(); i++)
    {
      temp[i] = array_kangaroos[i];
    }
    delete [] array_kangaroos;
    array_kangaroos = temp;
  }
  animals.set_num_kangaroo(animals.get_num_kangaroo() + 1);
  if(born)
  {
      array_kangaroos[animals.get_num_kangaroo() - 1].set_age(0);
  }
}

/*********************************************************************
Function: remove_kangaroo
Description: Removes a kangaroo from the array
Parameters: boolean
Pre-Conditions: Kangaroo array must exist
Post-Conditions: Another kangaroo will be removed from the array
*********************************************************************/
void Zoo::remove_kangaroo()
{
  Kangaroo* temp;
  if(animals.get_num_kangaroo() == 0)
  {
    cout <<"There are no kangaroos to kill. " << endl;
  }
  else if(animals.get_num_kangaroo() == 1)
  {
    animals.set_num_kangaroo(0);
    delete [] array_kangaroos;
  }
  else
  {
    animals.set_num_kangaroo(animals.get_num_kangaroo() - 1);
  }
}

/*********************************************************************
Function: play_game
Description: Plays the game
Parameters: None
Pre-Conditions: All variables must exist
Post-Conditions: Zoo Tycoon game will be played
*********************************************************************/
void Zoo::play_game()
{
  srand(time(NULL));

  cout << endl;
  cout <<" ___________________________________________ " << endl;
  cout <<"|                                           |" << endl;
  cout <<"|       Welcome to your Very own Zoo!       |" << endl;
  cout <<"|                                           |" << endl;
  cout <<"|___________________________________________|" << endl;
  cout << endl;
  cout << endl;
  cout <<"You get $" << get_player_money() << " to start off! " << endl;
  cout << endl;

  buy_animal();
  feeding();
  random_event();
  for(int i=0; i<10; i++)
  {
    cout << endl;
  }
  cout <<"================================================" << endl;

  ask_repeat();

}

/*********************************************************************
Function: new_day
Description: Plays a new day to the Zoo Tycoon game
Parameters: None
Pre-Conditions: All variables must exist, play_game must've been played
Post-Conditions: A new day will be added and played
*********************************************************************/
void Zoo::new_day()
{
  day++;

  cout << endl;
  cout <<" ___________________________________________ " << endl;
  cout <<"|                                           |" << endl;
  cout <<"|           Welcome to a new Day!           |" << endl;
  cout <<"|                                           |" << endl;
  cout <<"|___________________________________________|" << endl;
  cout << endl;
  cout << endl;
  cout <<"It is now Day " << get_day() << endl;
  cout <<"Your current amount of money: $" << get_player_money() << endl;
  cout << endl;
  cout <<"Your Zoo currently holds: " << endl;
  cout <<"Tigers: " << animals.get_num_tiger() << endl;
  cout <<"Polar Bears: " << animals.get_num_pb() << endl;
  cout <<"Penguins: " << animals.get_num_penguin() << endl;
  cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
  cout << endl;
  add_ages();

  cout <<"================================================" << endl;
  cout << endl;

  buy_animal();
  feeding();
  random_event();
  ask_repeat();

}

/*********************************************************************
Function: add_ages
Description: Adds the ages of the animals
Parameters: None
Pre-Conditions: All variables must exist
Post-Conditions: Animal ages will all be added
*********************************************************************/
void Zoo::add_ages()
{
  int tiger_age;
  for(int i=0; i<animals.get_num_tiger(); i++)
  {
    tiger_age = array_tigers[i].add_age();
  }

  int pb_age;
  for(int i=0; i<animals.get_num_pb(); i++)
  {
    pb_age = array_pbs[i].add_age();
  }

  int penguin_age;
  for(int i=0; i<animals.get_num_penguin(); i++)
  {
    penguin_age = array_penguins[i].add_age();
  }

  int kangaroo_age;
  for(int i=0; i<animals.get_num_kangaroo(); i++)
  {
    kangaroo_age = array_kangaroos[i].add_age();
  }
}

/*********************************************************************
Function: buy_animal
Description: Function that buys an animal
Parameters: None
Pre-Conditions: All variables must exist
Post-Conditions: Animals will be bought
*********************************************************************/
void Zoo::buy_animal()
{
  bool buying = true;
  int buy_choice;

  while(buying)
  {
    if(get_player_money() >= 1000)
    {
      cout <<"You have enough money to buy at least one animal! " << endl;
      cout <<"What animal would you like to buy (You can buy 2 of each at a time)? " << endl;
      cout <<"   1. Tigers are $10,000 " << endl;
      cout <<"   2. Polar Bears are $5,000 " << endl;
      cout <<"   3. Penguins are $1,000 " << endl;
      cout <<"   4. Kangaroos are $30,000 " << endl;
      cout <<"   5. I don't want to spend money. " << endl;
      cout << endl;
      cout <<"================================================" << endl;
      cout <<"Enter your choice: ";
      cin >> buy_choice;

      if(buy_choice == 1)
      {
        int num;
        int temp_money;

        cout <<"How many Tigers do you want to buy? ";
        cin >> num;

        while(num > 2)
        {
          cout <<"You can only buy a max of 2 animals at a time! " << endl;
          buying = false;
          cout <<"Try again: ";
          cin >> num;
        }

        for(int i = 0; i < num; i++)
        {
          add_tiger(false);
          temp_money = get_player_money() - 10000;
          player_money = temp_money;
          cout << endl;
        }

        cout << num <<" Tiger(s) has been added to your collection! " << endl;
        cout <<"Your current amount is: $" << get_player_money() << endl;
        cout << endl;

      }
      else if(buy_choice == 2)
      {
        int num;
        int temp_money;

        cout <<"How many Polar Bears do you want to buy? ";
        cin >> num;
        while(num > 2)
        {
          cout <<"You can only buy a max of 2 animals at a time! " << endl;
          buying = false;
          cout <<"Try again: ";
          cin >> num;
        }

        for(int i=0; i<num; i++)
        {
          add_pb(false);
          temp_money = get_player_money() - 5000;
          player_money = temp_money;
          cout << endl;
        }

        cout << num <<" Polar Bear(s) has been added to your collection! " << endl;
        cout <<"Your current amount is: $" << get_player_money() << endl;
        cout << endl;

      }
      else if(buy_choice == 3)
      {
        int num;
        int temp_money;

        cout <<"How many Penguins do you want to buy? ";
        cin >> num;
        while(num > 2)
        {
          cout <<"You can only buy a max of 2 animals at a time! " << endl;
          buying = false;
          cout <<"Try again: ";
          cin >> num;
        }

        cout << endl;
        for(int i=0; i<num; i++)
        {
          add_penguin(false);
          temp_money = get_player_money() - 1000;
          player_money = temp_money;
          cout << endl;
        }

        cout << num <<" Penguin(s) has been added to your collection! " << endl;
        cout <<"Your current amount is: $" << get_player_money() << endl;
        cout << endl;

      }

      else if(buy_choice == 4)
      {
        int num;
        int temp_money;

        cout <<"How many Kangaroos do you want to buy? ";
        cin >> num;
        while(num > 2)
        {
          cout <<"You can only buy a max of 2 animals at a time! " << endl;
          buying = false;
          cout <<"Try again: ";
          cin >> num;
        }

        cout << endl;
        for(int i=0; i<num; i++)
        {
          add_kangaroo(false);
          temp_money = get_player_money() - 30000;
          player_money = temp_money;
          cout << endl;
        }

        cout << num <<" Kangaroo(s) has been added to your collection! " << endl;
        cout <<"Your current amount is: $" << get_player_money() << endl;
        cout << endl;

      }

      else if(buy_choice == 5)
      {
        buying = false;
        break;
      }
      else
      {
        cout <<"You have entered a bad input, please try again. " << endl;
        cout << endl;
      }

      int repeat_choice;
      cout <<"Do you want to buy another animal? (Yes = 1, No = 2): ";
      cin >> repeat_choice;
      if(repeat_choice == 1)
      {
        buying = true;
      }
      else if(repeat_choice == 2)
      {
        buying = false;
        cout <<"Okay, continuing on. " << endl;
        cout << endl;
        break;
      }
      else
      {
        while(repeat_choice > 2)
        {
          cout <<"Bad input, please try again! ";
          cin >> repeat_choice;
          cout << endl;
          buying = false;
        }
      }
    }
    else
    {
      buying = false;
      cout <<"Your current amount: $" << get_player_money() << endl;
      cout <<"Sorry, you don't have enough money! " << endl;
      cout << endl;
    }
  }
}

/*********************************************************************
Function: feeding
Description: Feeds the animals
Parameters: All animals must exist and be working
Pre-Conditions: None
Post-Conditions: Animals will be fed
*********************************************************************/
void Zoo::feeding()
{
  cout <<"================================================" << endl;
  cout <<"Now it's time to feed your animals! " << endl;
  cout <<"It costs $800 to feed Kangaroos, $500 to feed Tigers, $300 to feed Polar Bears, and $100 to feed Penguins " << endl;
  cout << endl;

  int feed_cost = 0;

  if(animals.get_num_tiger() > 0)
  {
    for(int i=0; i<animals.get_num_tiger(); i++)
    {
      feed_cost += animals.get_food_tiger();
    }
  }
  else if(animals.get_num_pb() > 0)
  {
    for(int i=0; i<animals.get_num_pb(); i++)
    {
      feed_cost += animals.get_food_pb();
    }
  }
  else if(animals.get_num_penguin() > 0)
  {
    for(int i=0; i<animals.get_num_penguin(); i++)
    {
      feed_cost += animals.get_food_penguin();
    }
  }
  else if(animals.get_num_kangaroo() > 0)
  {
    for(int i=0; i<animals.get_num_kangaroo(); i++)
    {
      feed_cost += animals.get_food_kangaroo();
    }
  }

  player_money -= feed_cost;
  cout <<"It costs you $" << feed_cost <<" to feed all your animals today. " << endl;
  cout << endl;

  if(player_money < feed_cost)
  {
    cout <<"You don't have enough money to feed all your animals!! " << endl;
    cout << endl;
    game_lose();
  }
  else
  {
    cout <<"You now have: $" << player_money << endl;
  }
}

/*********************************************************************
Function: random_event
Description: Randomizes events
Parameters: None
Pre-Conditions: All variables must exist
Post-Conditions: Randomized events will be made
*********************************************************************/
void Zoo::random_event()
{
  cout <<"================================================" << endl;

  int rand_value = (rand()%4)+1;

  if(rand_value == 1)
  {
    sickness();
  }
  else if(rand_value == 2)
  {
    boom();
  }
  else if(rand_value == 3)
  {
    baby();
  }
  else if(rand_value == 4)
  {
    nothing();
  }
}

/*********************************************************************
Function: sickness
Description: Sickness to an animal
Parameters: None
Pre-Conditions: Animals must exist
Post-Conditions: An animal will be sick and be killed
*********************************************************************/
void Zoo::sickness()
{
  cout <<"Oh no! A sickness has occured! " << endl;
  cout << endl;
  bool incorrect = true;
  int death_choice;


  while(incorrect)
  {
    cout << endl;
    cout <<"Your Zoo currently has: " << endl;
    cout <<"Tigers: " << animals.get_num_tiger() << endl;
    cout <<"Polar Bears: " << animals.get_num_pb() << endl;
    cout <<"Penguins: " << animals.get_num_penguin() << endl;
    cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
    cout << endl;
    cout << endl;
    cout <<"Which animal do you want to kill? (Tiger = 1, Polar Bear = 2, Penguin = 3, Kangaroo = 4) ";
    cin >> death_choice;
    cout << endl;
    cout << endl;
    if(death_choice == 1 && animals.get_num_tiger() >= 1)
    {
      cout <<"A tiger has died. " << endl;
      incorrect = false;
      // Delete tiger
      remove_tiger();
    }
    else if(death_choice == 2 && animals.get_num_pb() >= 1)
    {
      cout <<"A Polar Bear has died. " << endl;
      incorrect = false;
      // Delete polar bear
      remove_pb();
    }
    else if(death_choice == 3 && animals.get_num_penguin() >= 1)
    {
      cout <<"A Penguin has died. " << endl;
      incorrect  = false;
      // Delete penguin
      remove_penguin();
    }
    else if(death_choice == 4 && animals.get_num_kangaroo() >= 1)
    {
      cout <<"A Kangaroo has died. " << endl;
      incorrect = false;
      // Delete kangaroo
      remove_kangaroo();
    }
    else
    {
      cout << endl;
      cout <<"Bad input, or your input isn't an animal in the zoo! " << endl;
      cout <<"Let's try this again. " << endl;
      cout << endl;
      cout <<"Your Zoo currently holds: " << endl;
      cout <<"Tigers: " << animals.get_num_tiger() << endl;
      cout <<"Polar Bears: " << animals.get_num_pb() << endl;
      cout <<"Penguins: " << animals.get_num_penguin() << endl;
      cout << endl;
      cout <<"================================================" << endl;
    }
  }
  cout <<"================================================" << endl;

}

/*********************************************************************
Function: boom
Description: Adds boom to zoo's bank
Parameters: None
Pre-Conditions: Tigers must exist
Post-Conditions: Randomized boom $$ added to bank
*********************************************************************/
void Zoo::boom()
{
  cout <<"Hooray!! A boom in zoo attendance has occured! " << endl;
  cout <<"Those Tigers are pretty popular! " << endl;
  int boom_random = rand()%251 + 250;

  int temp_money;
  temp_money = get_player_money() + boom_random;
  player_money = temp_money;
  cout << endl;
  cout <<"$" << boom_random <<" has been added to your bank, thanks to the Tigers! " << endl;
  cout <<"Your current amount is: $" << get_player_money() << endl;
  cout << endl;
}

/*********************************************************************
Function: baby
Description: Adds a baby to an animal class
Parameters: None
Pre-Conditions: Animal must exist
Post-Conditions: Baby will be added to that animal class
*********************************************************************/
void Zoo::baby()
{
  bool incorrect = true;

  cout <<"A baby animal is born, yay! " << endl;
  cout << endl;
  cout << endl;
  cout <<"Your Zoo currently has: " << endl;
  cout <<"Tigers: " << animals.get_num_tiger() << endl;
  cout <<"Polar Bears: " << animals.get_num_pb() << endl;
  cout <<"Penguins: " << animals.get_num_penguin() << endl;
  cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
  cout << endl;
  cout << endl;
  int baby_choice;

  while(incorrect)
  {
    cout <<"Which animal do you want to have a baby? (Tiger = 1, Polar Bear = 2, Penguin = 3, Kangaroo = 4) ";
    cin >> baby_choice;
    cout << endl;
    if(baby_choice == 1 && animals.get_num_tiger() >= 1)
    {
      cout <<"Yay! A Tiger just had a baby! " << endl;
      add_tiger(true);
      cout << endl;
      cout <<"A baby tiger with age " << array_tigers[animals.get_num_tiger() - 1].get_age() <<
      " has been added to your collection! " << endl;
      cout << endl;
      break;

    }
    else if(baby_choice == 2 && animals.get_num_pb() >= 1)
    {
      cout <<"Yay! A Polar Bear just had a baby! " << endl;
      add_pb(true);
      cout << endl;
      cout <<"A baby polar bear with age " << array_pbs[animals.get_num_pb() - 1].get_age() <<
      " has been added to your collection! " << endl;
      cout << endl;
      break;

    }
    else if(baby_choice == 3 && animals.get_num_penguin() >= 1)
    {
      cout <<"Yay! A Penguin just had a baby! " << endl;
      add_penguin(true);
      cout << endl;
      cout <<"A baby penguin with age " << array_penguins[animals.get_num_penguin() - 1].get_age() <<
      " has been added to your collection! " << endl;
      cout << endl;
      break;

    }
    else if(baby_choice == 4 && animals.get_num_kangaroo() >= 1)
    {
      cout <<"Yay! A Kangaroo just had a baby! " << endl;
      add_kangaroo(true);
      cout << endl;
      cout <<"A baby kangaroo with age " << array_kangaroos[animals.get_num_kangaroo() - 1].get_age() <<
      " has been added to your collection! " << endl;
      cout << endl;
      break;

    }
    else
    {
      cout <<"Bad input, or your animal of choice doesn't exist yet! "<< endl;
      cout << endl;
      cout << endl;
      cout <<"Someone must have a child! " << endl;
      cout <<"Okay again, who do you want to have a baby? ";
      cout << endl;
      cout << endl;
      cout <<"Your Zoo currently holds: " << endl;
      cout <<"Tigers: " << animals.get_num_tiger() << endl;
      cout <<"Polar Bears: " << animals.get_num_pb() << endl;
      cout <<"Penguins: " << animals.get_num_penguin() << endl;
      cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
      cout << endl;
    }
  }
  cout <<"================================================" << endl;

}

/*********************************************************************
Function: nothing
Description: Nothing happens
Parameters: None
Pre-Conditions: Everything must exist
Post-Conditions: Nothing happens
*********************************************************************/
void Zoo::nothing()
{
  cout <<"Nothing's happened today, sorry. Better luck tomorrow! " << endl;
  cout << endl;
  cout << endl;
}

/*********************************************************************
Function: set_payoff
Description: Sets payoffs
Parameters: None
Pre-Conditions: All animal classes must exist
Post-Conditions: Animal payoffs will be added to bank
*********************************************************************/
void Zoo::set_payoff() {
  payoff = 0;
  payoff += animals.get_num_tiger() * 1000;
  payoff += animals.get_num_pb() * 250;
  payoff += animals.get_num_penguin() * 50;
  payoff += animals.get_num_kangaroo() * 3000;

  cout << endl;
  cout <<"Your total Payoff for the day is: $" << payoff << endl;
  int temp_money;
  temp_money = player_money + payoff;
  player_money = temp_money;
  cout << endl;
}

/*********************************************************************
Function: ask_repeat
Description: Asks to repeat to second day
Parameters: None
Pre-Conditions: Everything must exist
Post-Conditions: User will be asked to go on to next time or quit
*********************************************************************/
void Zoo::ask_repeat()
{
  int repeat_game;

  cout << endl;
  cout <<"The day is now over, finally! " << endl;
  cout << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"Your Payoffs: " << endl;
  cout <<"Tigers give $1,000 " << endl;
  cout <<"Polar Bears give $250 " << endl;
  cout <<"Penguins give $50 " << endl;
  cout <<"Kangaroos give $3,000 " << endl;
  cout << endl;
  set_payoff();

  cout <<"================================================" << endl;
  cout <<"Your current amount of money is: $" << get_player_money() << endl;
  cout <<"================================================" << endl;
  cout << endl;
  cout << endl;
  cout <<"What would you like to do now? " << endl;
  cout <<"1. Continue on to the next day " << endl;
  cout <<"2. End the game " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"Enter your choice: ";
  cin >> repeat_game;

  if(repeat_game == 1)
  {
    system("clear");
    new_day();

  }
  else if(repeat_game == 2)
  {
    cout <<"Thank you for playing! Have a nice day :) " << endl;
    cout << endl;
    cout << endl;
    cout <<"You ended the game with: " << endl;
    cout <<"Tigers: " << animals.get_num_tiger() << endl;
    cout <<"Polar Bears: " << animals.get_num_pb() << endl;
    cout <<"Penguins: " << animals.get_num_penguin() << endl;
    cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
    cout << endl;
  }
  else
  {
    while(repeat_game < 1 || repeat_game > 2)
    {
      cout <<"Bad input, try again! " << endl;
      cout << endl;
      cout <<"What would you like to do now? " << endl;
      cout <<"1. Continue on to the next day " << endl;
      cout <<"2. End the game " << endl;
      cout << endl;
      cout <<"================================================" << endl;
      cout <<"Enter your choice: ";
      cin >> repeat_game;

      if(repeat_game == 1)
      {
        system("clear");
        new_day();
      }
      else if(repeat_game == 2)
      {
        cout << endl;
        cout <<"Thank you for playing! Have a nice day :) " << endl;
        cout << endl;
        cout <<"You ended the game with: " << endl;
        cout <<"Tigers: " << animals.get_num_tiger() << endl;
        cout <<"Polar Bears: " << animals.get_num_pb() << endl;
        cout <<"Penguins: " << animals.get_num_penguin() << endl;
        cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
        cout << endl;
      }
    }
  }
}

/*********************************************************************
Function: game_lose
Description: Lose the game
Parameters: None
Pre-Conditions: User must lose the game
Post-Conditions: User will lose the game
*********************************************************************/
void Zoo::game_lose()
{
  int repeat_game;
  cout <<"Sorry, you lost. Better luck next time! " << endl;
  cout << endl;
  cout <<"================================================" << endl;
  cout <<"You ended the game with: " << endl;
  cout <<"================================================" << endl;
  cout <<"                  Money: $" << get_player_money() << endl;
  cout <<"================================================" << endl;
  cout << endl;
  cout <<"Tigers: " << animals.get_num_tiger() << endl;
  cout <<"Polar Bears: " << animals.get_num_pb() << endl;
  cout <<"Penguins: " << animals.get_num_penguin() << endl;
  cout <<"Kangaroos: " << animals.get_num_kangaroo() << endl;
  cout << endl;
  cout <<"Do you want to play again (Yes = 1, No = 2)? ";
  cin >> repeat_game;
  cout << endl;
  if(repeat_game == 1)
  {
    system("clear");
    player_money = 100000;
    play_game();
  }
  else if(repeat_game == 2)
  {
    cout <<"Have a nice day! :) " << endl;
    cout << endl;
    exit(1);
  }
}
