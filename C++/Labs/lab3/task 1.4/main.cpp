#include <iostream>

int main()
{
  double eps, y = 0;
  std::cout << "Input value eps: " << std::endl;
  std::cin >> eps;
  if (eps<=0)
  {
    std::cout << "The value cannot be less than or equal to zero.";
  }
  else
  {
    if (eps < 0 && eps >= 1)
    {
      std::cout << "The eps value must be less than 0.5 and greater than 0\n";
      return 0;
    }
   else
   {
     for (double i = 0.5; i >= eps; i /= 2)
      {
        y += i;
      }
     std::cout << "Value y " << y << std::endl;
    }
  }
  return 0;
}
