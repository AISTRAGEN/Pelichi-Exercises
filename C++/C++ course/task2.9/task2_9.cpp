#include <iostream>

int main() 
{
  int value = 20;
  int &ref = value;

  value = 25;
  std::cout << &ref << std::endl;
  std::cin >> ref;

  return 0;
}
