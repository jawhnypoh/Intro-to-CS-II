#include <iostream>
#include <vector>

using namespace std;

class Test {
private:
  int foo = 5;
public:
  Test() {
    cout <<"Constructor built! " << endl;
  }

  int get_foo() {
    return foo;
  }

};


int main() {
  vector<vector<Test> > test_array;

  int row = 5;
  int col = 5;

  test_array.resize(row);
  for(int i =0; i<row; i++)
  {
    test_array[i].resize(col);
    //cout << test_array[i].get_foo() << endl;
  }

  return 0;
}
