
#include <iostream>

int main() 
{
  const double pi = 3.14159;

  double R;

  std::cout << "Enter Radius:" << std::endl;
  std::cin >> R;
  double S = pi * (R * R);

  std::cout << "Result" << " " << S << std::endl;
  
  return 0;
}
