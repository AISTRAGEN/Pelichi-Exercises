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
            return x; 
        }
    }

    return -1;
}

double outputData(funcPtr funcPtr, int a, int b, int h)
{
    for (int x = a; x < b; x += h)
    {
        double result = funcPtr(x, x + h, 1); 
        if (result == 0.0)
        {
            std::cout << "At x = " << x << ", y = 0" << std::endl;
        }
    }

    return 0;
}
