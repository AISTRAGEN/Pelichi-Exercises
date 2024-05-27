#include "header.h"

// Заданная функция
double func(double x) 
{
    return 3 * (-x * x * x) + 1;
}

// Обертка для функции findDerivative
double derivativeWrapper(int x, int b, int h) 
{
    return findDerivative(func, x, b, h); // Вызываем findDerivative с заданной функцией и аргументами
}

int main() 
{
    int a, b, h;
    inputData(a, b, h);
    
    // Вызов функции outputData с оберткой для findDerivative
    double result = outputData(derivativeWrapper, a, b, h);
    std::cout << "Result is: " << result << std::endl;

    return 0;
}