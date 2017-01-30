#include <iostream>

using namespace std;

struct Employee
{
   short id;
   int age;
   double wage;
};

void output(Employee employee)
{
  cout << employee << endl;
  cout <<"ID: " << employee.id << endl;
  cout <<"Age: " << employee.age << endl;
  cout <<"Wage: " << employee.wage << endl;

}

int main()
{
   Employee john;
   Employee abby;

   john.id = 20;
   john.age = 35;
   john.wage = 15.85;

   abby.id = 25;
   abby.age = 40;
   abby.wage = 12.45;

   int TotalAge = john.age + abby.age;
   cout <<"Ages added: " << TotalAge << endl;
   cout << endl;
   cout << endl;

   int TotalWage = john.wage + abby.wage;
   cout <<"Total Wages: " << TotalWage << endl;
   cout << endl;
   if(john.wage > abby.wage)
      cout <<"John's wage is higher " << endl;
   else
      cout <<"Abby's wage is higher " << endl;

   cout << endl;

   output(john);
   cout << endl;
   output(abby);


   return 0;
}
