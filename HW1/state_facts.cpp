/******************************************************
** Program: states.exe
** Author: Johnny Po
** Date: 4/10/2016
** Description: Runs through text file, finds info on States and Counties
** Input: integer numbers, file.txt input
** Output: State and county information will be read through and sorted
******************************************************/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

#include "state_facts.h"

/***********************************************************************************************************
Function: is_valid_arguments
Description: Checks if arguments are valid
Return: True or False
Pre-Conditions: Command line arguments must've been made
Post-Conditions: Will check if inputs are valid, will run through rest of program
************************************************************************************************************/
bool is_valid_arguments(int argc, char *argv [])
{
  if(argc != 5)
  {
    cout <<"Error, not enough arguments! " << endl;
    cout <<"Usage: a.out -s # -f filename.txt " << endl;
  }

    int state_num, county_num;
    state* state_table;

    state_num = atoi(argv[2]);
    cout <<"Number of states: " << state_num << endl;
    cout << endl;

    ifstream file_states;

    file_states.open(argv[4], ios::in);
    if(!file_states)
    {
      cout <<"Error, file does not exist! " << endl;
      exit(1);
    }
    else
    {
      run_program(state_table, state_num, file_states);
      cout << endl;
    }
}

/***********************************************************************************************************
Function: run_program
Description: Runs the program
Return: Nothing
Pre-Conditions: Command line arguments must've been made
Post-Conditions: Runs through the rest of the program
************************************************************************************************************/
void run_program(state* state_table, int state_num, ifstream& file_states)
{
  cout <<"Gathering states data . . . " << endl;
  cout << endl;

  state_table = create_states(state_table, state_num, file_states);
  get_state_data(state_table, state_num, file_states);
  cout <<" . . .  " << endl;
  cout <<" . . . .  " << endl;
  cout <<" . . . . . " << endl;
  cout <<" . . . . . . " << endl;
  cout << endl;
  cout <<"Data gathering complete. " << endl;
  cout << endl;

  largest_pop_state(state_table, state_num);
  largest_pop_county(state_table, state_num);
  county_income(state_table, state_num);
  avg_house_cost(state_table, state_num);
  states_by_name(state_table, state_num);
  states_by_pop(state_table, state_num);
  counties_by_name(state_table, state_num);
  counties_by_pop(state_table, state_num);
  delete_info(state_table, state_num);
  repeat_program(state_table, state_num, file_states);
}

/***********************************************************************************************************
Function: create_states
Description: Creates struct array for states
Return: state_table
Pre-Conditions: Arguments must've been called and made
Post-Conditions: State struct arrays wil have been made
************************************************************************************************************/
state * create_states(state* state_table, int state_num, ifstream& file_states)
{
  state_table = new state[state_num];

  return state_table;
}

/***********************************************************************************************************
Function: get_state_data
Description: Gets state's data from the txt file
Return: Nothing
Pre-Conditions: States arrays must've been made, file must exist
Post-Conditions: Data will be taken in from the text file
************************************************************************************************************/
void get_state_data(state *state_table, int state_num, ifstream& file_states)
{
  for(int i=0; i<state_num; i++)
  {
    // Read through and Print
    file_states >> state_table[i].name >> state_table[i].population >> state_table[i].counties;
    //cout << state_table[i].name <<" " << state_table[i].population <<" " << state_table[i].counties << endl;
    if(state_table[i].counties > 0)
    {
      state_table[i].c = create_counties(state_table[i].counties);
      get_county_data(state_table[i].c, state_table[i].counties, file_states);
    }
  }
}

/***********************************************************************************************************
Function: create_counties
Description: Creates struct arrays for Counties
Return: county_table
Pre-Conditions: State array structs must've been made already, counties must exist
Post-Conditions: County array structs will be made
************************************************************************************************************/
county * create_counties(int county_num)
{
  county* county_table;
  county_table = new county[county_num];

  return county_table;
}

/***********************************************************************************************************
Function: get_county_data
Description: Gets county data from text file
Return: Nothing
Pre-Conditions: Text file must exist and have info in it, county_table must exist
Post-Conditions: Data will be taken in from text file and put into structs
************************************************************************************************************/
void get_county_data(county *county_table, int county_num, ifstream& file_states)
{
  int cities_num;
  for(int i=0; i<county_num; i++)
  {
    // Read through and Print
    file_states >> county_table[i].name >> county_table[i].population >> county_table[i].avg_income;
    file_states >> county_table[i].avg_house >> county_table[i].cities;
    //cout << county_table[i].name <<" " << county_table[i].population <<" " << county_table[i].avg_income << endl;
    //cout << county_table[i].avg_house <<" " << county_table[i].cities <<" " << endl;
    if(county_table[i].cities > 0)
    {
      cities_num = county_table[i].cities;
      county_table[i].city = new string[cities_num];
      for(int j=0; j<cities_num; j++)
      {
        file_states >> county_table[i].city[j];
        //cout << county_table[i].city[j] << endl;
      }
    }
  }
}

/***********************************************************************************************************
Function: largest_pop_state
Description: Finds the state with the largest population
Return: Nothing
Pre-Conditions: Structs must exit and have info in them
Post-Conditions: State with largest population will be found and cout'ed
************************************************************************************************************/
void largest_pop_state(state *state_table, int state_num)
{
  state biggest = state_table[0];
  for(int i=0; i<state_num; i++)
  {
    if(state_table[i].population > biggest.population)
    {
      biggest = state_table[i];
    }
  }
  cout <<"The largest State by population is: " << biggest.name <<", with a population of " << biggest.population << endl;
  cout << endl;
}

/***********************************************************************************************************
Function: largest_pop_county
Description: Finds the county with the largest population
Return: Nothing
Pre-Conditions: Structs must exist and have info in them
Post-Conditions: State with largest population will be found and cout'ed
************************************************************************************************************/
void largest_pop_county(state *state_table, int state_num)
{
  county biggest = state_table[0].c[0];

  for(int i=0; i<state_num; i++)
  {
    for(int j=0; j<state_table[i].counties; j++)
    {
      if(state_table[i].c[j].population > biggest.population)
      {
        biggest = state_table[i].c[j];
      }
    }
  }
  cout <<"The largest County by population is: " << biggest.name <<", with a population of " << biggest.population << endl;
  cout << endl;
}

/***********************************************************************************************************
Function: county_income
Description: Asks user for a number, compares county incomes to that number
Return: Nothing
Pre-Conditions: Structs must exist and have info in them
Post-Conditions: Counties with incomes higher than specified number will be found and printed out
************************************************************************************************************/
void county_income(state *state_table, int state_num)
{
  int income;
  bool above = false;
  cout <<"Enter income to search for (Counties with income above this amount will be printed): ";
  cin >> income;
  cin.ignore();

  for(int i=0; i<state_num; i++)
  {
    for(int j=0; j<state_table[i].counties; j++)
    {
      if(state_table[i].c[j].avg_income >= income)
      {
        cout <<"County: " << state_table[i].c[j].name << " has an Average Income of " << state_table[i].c[j].avg_income << endl;
        cout << endl;
        above = true;
      }
    }
  }
  if(above != true)
  {
    cout <<"No counties are greater than the specified income. " << endl;
    cout << endl;
  }
  cout << endl;
}

/***********************************************************************************************************
Function: avg_house_cost
Description: Prints out each county and it's average house costs
Return: Nothing
Pre-Conditions: Structs must exist and have info in them
Post-Conditions: Counties and their average house costs will be found and printed out
************************************************************************************************************/
void avg_house_cost(state *state_table, int state_num)
{
  cout <<"Average Household Incomes: " << endl;
  for(int i=0; i< state_num; i++)
  {
    for(int j=0; j<state_table[i].counties; j++)
    {
      cout <<"County " << state_table[i].c[j].name << " has an Average Household Cost of " << state_table[i].c[j].avg_house << endl;
      cout << endl;
    }
  }
  cout << endl;
}

/***********************************************************************************************************
Function: states_by_name
Description: States will be sorted by Name
Return: Nothing
Pre-Conditions: Structs must exist, must have info in them
Post-Conditions: States will be ordered and printed out by their names
************************************************************************************************************/
void states_by_name(state *state_table, int state_num)
{
  // Sorted in Descending Order
  state temp;
  for(int i=0; i<state_num-1; i++)
  {
    if(state_table[i].name.at(0) - 'A' > state_table[i+1].name.at(0) - 'A')
    {
      cout <<"hello! " << endl;
      temp = state_table[i];
      state_table[i] = state_table[i+1];
      state_table[i+1] = temp;
    }
  }
  cout <<"States sorted by Name (Descending): " << endl;
  for(int i=0; i<state_num; i++)
  {
    cout << state_table[i].name << endl;
  }
  cout << endl;
  cout << endl;
}

/***********************************************************************************************************
Function: states_by_pop
Description: Sorts states by population
Return: Nothing
Pre-Conditions: Structs must exist and must have info in them
Post-Conditions: States will be printed out by order of their populations
************************************************************************************************************/
void states_by_pop(state *state_table, int state_num)
{
  state temp;
  // Sorted in Descending Order
  for(int i=0; i<state_num-1; i++)
  {
    if(state_table[i].population < state_table[i+1].population)
    {
      temp = state_table[i];
      state_table[i] = state_table[i+1];
      state_table[i+1] = temp;
    }
  }

  cout <<"States sorted by Population Size (Descending): " << endl;
  for(int i=0; i<state_num; i++)
  {
    cout << state_table[i].name << ": " << state_table[i].population << endl;
  }
  cout << endl;
  cout << endl;
}

/***********************************************************************************************************
Function: counties_by_name
Description: Counties will be sorted by Name
Return: Nothing
Pre-Conditions: Structs must exist, must have info in them
Post-Conditions: Counties will be ordered and printed out by their names
************************************************************************************************************/
void counties_by_name(state *state_table, int state_num)
{
  // Sorting in Descending Order
  county temp;
  for(int i=0; i<state_num; i++)
  {
    for(int j=0; j<state_table[i].counties - 1; j++)
    {
      if(state_table[i].c[j].name.at(0) - 'A' > state_table[i].c[j+1].name.at(0) - 'A' )
      {
        temp = state_table[i].c[j];
        state_table[i].c[j] = state_table[i].c[j+1];
        state_table[i].c[j+1] = temp;
      }
    }
  }

  cout <<"Counties sorted by Name (Descending): " << endl;
  for(int i=0; i<state_num; i++)
  {
    for(int j=0; j<state_num; j++)
    {
      cout << state_table[i].c[j].name << endl;
    }
  }
  cout << endl;
  cout << endl;
}

/***********************************************************************************************************
Function: counties_by_pop
Description: Sorts counties by population
Return: Nothing
Pre-Conditions: Structs must exist and must have info in them
Post-Conditions: counties will be printed out by order of their populations
************************************************************************************************************/
void counties_by_pop(state *state_table, int state_num)
{
  county temp;
  for(int i=0; i<state_num; i++)
  {
    for(int j=0; j<state_table[i].counties - 1; j++)
    {
      if(state_table[i].c[j].population > state_table[i].c[j+1].population)
      {
        temp = state_table[i].c[j];
        state_table[i].c[j] = state_table[i].c[j+1];
        state_table[i].c[j+1] = temp;
      }
    }
  }

  cout <<"Counties sorted by Population (Descending): " << endl;
  for(int i=0; i<state_num; i++)
  {
    for(int j=0; j<state_num; j++)
    {
      cout << state_table[i].c[j].name << ": " << state_table[i].c[j].population << endl;
    }
  }
  cout << endl;
  cout << endl;
}

/***********************************************************************************************************
Function: delete_info
Description: Deletes the arrays and structs
Return: Nothing
Pre-Conditions: Structs and arrays must exist and have something in them
Post-Conditions: A new fresh start!
************************************************************************************************************/
void delete_info(state *state_table, int state_num)
{
  delete [] state_table;

  cout << endl;
  cout <<" . . . " << endl;
  cout <<"Tables have been deleted. " << endl;
}

/***********************************************************************************************************
Function: repeat_program
Description: Asks user if they want to repeat the program
Return: Nothing
Pre-Conditions: Program must've already ran through at least once
Post-Conditions: Asks user if they want to repeat program and acts accordingly
************************************************************************************************************/
void repeat_program(state* state_table, int state_num, ifstream& file_states)
{
  int choice;
  cout <<"Would you like to find info for more States (0 = No, 1 = Yes)? ";
  cin >> choice;

  if(choice == 0)
  {
    cout <<"Thank you, have a nice day! :) " << endl;
    cout << endl;
    exit(1);
  }
  else if(choice == 1)
  {
    cout <<"Program will be repeated. " << endl;
    cout << endl;
    user_input(state_table, state_num, file_states);
  }
  else
  {
    while(choice != 0 || choice > 1)
    {
      cout <<"Not a valid choice! " << endl;
      cout << endl;
      repeat_program(state_table, state_num, file_states);
    }
  }
}

/***********************************************************************************************************
Function: user_input
Description: Takes in user input if user chooses to repeat the program
Return: Nothing
Pre-Conditions: User must've chosen to repeat the program
Post-Conditions: User input will be taken in
************************************************************************************************************/
void user_input(state* state_table, int state_num, ifstream& file_states)
{
  char file_name[256];
  cout <<"How many states would you like to find info for? ";
  cin >> state_num;
  cin.ignore();
  cout << endl;

  cout <<"Enter the filename containing the state information: ";
  cin.getline(file_name, 256);
  file_states.open(file_name, ios::in);
  if(file_states.fail())
  {
    cout <<"Opening file failed. " << endl;
    cout <<"Enter filename: ";
    cin.getline(file_name, 256);
  }

  cout << endl;
  cout <<"Number of States: " << state_num << endl;
  cout <<"Filename: " << file_name << endl;

  run_program(state_table, state_num, file_states);
}
