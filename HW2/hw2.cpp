#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Card {
public:
  enum value {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
           JACK, QUEEN, KING};
  enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

  Card(value v = ACE, suit s = SPADES, bool flip = true);

  int get_value() const;

private:
  value c_value;
  suit c_suit;
  bool flip;

};
