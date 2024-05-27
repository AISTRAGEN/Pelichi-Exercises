#include "header.h"

// Определение функции inputData
void inputData(int &a, int &b, int &h)
{
    std::cout << "Enter value for a(min): ";
    std::cin >> a;
    std::cout << "Enter value for b(max): ";
    std::cin >> b;
    std::cout << "Enter value for h: ";
    std::cin >> h;
}

// Определение функции outputData
double outputData(double (*funcPtr)(int, int, int), int a, int b, int h)
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