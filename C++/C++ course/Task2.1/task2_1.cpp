#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  cout << "Enter the name" << endl;
  cin >> name;
  cout << "Hello"
       << " " << name << " "
       << "World"
       << "!" << endl;
  return 0;
}
