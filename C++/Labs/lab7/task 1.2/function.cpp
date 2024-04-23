#include "header.h"

double findDerivative(int a, int b, int h)
{
    for (int x = a; x < b; x += h)
    {
        double deltaX = 0.0000001;
        double y_x = 3 * (-x * x * x) + 1;
        double y_x_plus_delta = 3 * (-(x + deltaX) * (x + deltaX) * (x + deltaX)) + 1;
        double derivative = (y_x_plus_delta - y_x) / deltaX;

        if (derivative == 0.0)
        {
            return x; // Знайдено значення x, при якому похідна дорівнює нулю.
        }
    }

    return -1; // Похідна не дорівнює нулю для жодного x.
}

double outputData(funcPtr funcPtr, int a, int b, int h)
{
    for (int x = a; x < b; x += h)
    {
        double result = funcPtr(x, x + h, 1); // Виклик функції через вказівник
        if (result == 0.0)
        {
            std::cout << "At x = " << x << ", y = 0" << std::endl;
        }
    }

    return 0;
}



//double y = 3 * (x * x) + 1;
//  for(double x = 0; x != 0; --x)
//  {
//  double y = 3 * (x * x) + 1;
//  if(y == 0)
//  {
//   return y;
//  }
//  else
//  {
//    continue;
//  }
//  }