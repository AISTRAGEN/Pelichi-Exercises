#include "math_header.h"
#include <iostream>

int main() 
{
  // обчислення відстані s = v*t

  int v;
  std::cout << "Enter speed (v)" << std::endl;
  std::cin >> v;
  int t = 0;
  std::cout << "Enter time (t)" << std::endl;
  std::cin >> t;

  // Обчислення  m = (x+y)/2

  int x, y;
  std::cout << "Enter x" << std::endl;
  std::cin >> x;
  std::cout << "Enter y" << std::endl;
  std::cin >> y;

  // Обчислення дискримінанту d = b^2 -4ac

  int a, b, c;
  std::cout << "Enter the value a > 0" << std::endl; // тут просто порахувати не треба робити тернарним оператором чи
                // if else
  std::cin >> a;
  std::cout << "Enter the value b" << std::endl;
  std::cin >> b;
  std::cout << "Enter the value c" << std::endl;
  std::cin >> c;

  std::cout << "value (s)" << speed(v, t) << std::endl;
  std::cout << "value (m)" << equation(x, y) << std::endl;
  std::cout << "value (d)" << discriminant(a, b, c) << std::endl;

  return 0;
}
