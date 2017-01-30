#include <iostream>

using namespace std;

class DateClass
{
public:
  int month;
  int day;
  int year;

  void print_date()
  {
    cout << month << "/" << day << "/" << year << endl;
  }
};

int main()
{
  DateClass today {4, 12, 2016}; // Declare a variable of class DateClass

  DateClass tomorrow {4, 13, 2016};

  //tomorrow.month = 4;
  //tomorrow.day = 13;
  //tomorrow.year = 2016;

  today.day = 12;
  today.print_date();
  cout << endl;

  cout <<"Tomorrow's date is: ";
  tomorrow.print_date();

  return 0;
}
