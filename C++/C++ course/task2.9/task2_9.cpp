#include <iostream>

using namespace std;

int main() {
  /*int x = 10;
  int* px = &x;
  cout << *px << endl;

  x = 20;
  cout << *px << endl;

*px = 15;
cout << *px << endl;
   */
  int value = 20;
  int &ref = value;

  value = 25;
  cout << &ref << endl;
  cin >> ref;
}
