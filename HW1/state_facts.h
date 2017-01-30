// Structs
struct county {
        string name;  //name of county
        string *city;  //name of cities in county
        int cities;  //number of cities in county
        int population;  //total population of county
        float avg_income;  //avg household income
        float avg_house;  //avg household price
};

struct state {
       string name;  //name of state
       struct county *c;  //name of counties
       int counties;  //number of counties in state
       int population;  //total population of state
};

// Functions
bool is_valid_arguments(int, char *[]);
void run_program(state *, int, ifstream&);
state * create_states(state *, int, ifstream&);
void get_state_data(state *, int, ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void largest_pop_state(state *, int);
void largest_pop_county(state *, int);
void county_income(state *, int);
void avg_house_cost(state *, int);
void states_by_name(state *, int);
void states_by_pop(state *, int);
void counties_by_name(state *, int);
void counties_by_pop(state *, int);
void delete_info(state *, int);
void repeat_program(state *, int, ifstream&);
void user_input(state *, int, ifstream&);
