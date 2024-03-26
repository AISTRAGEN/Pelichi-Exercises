#include <iostream>

int main() 
{
  int temperature;
  std::cout << "Enter the temperature" << std::endl;
  std::cin >> temperature;

  if (temperature < 0) 
  {
    std::cout << "Ice" << std::endl;
  } 
  else if (temperature > 100) 
  {
    std::cout << "Gas" << std::endl;
  }
  if (temperature >= 0 && temperature <= 100) 
  {
    std::cout << "Water" << std::endl;
  }

  return 0;
}
