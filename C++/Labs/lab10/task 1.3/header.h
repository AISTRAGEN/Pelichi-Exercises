#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

// Объявление шаблонной функции для вычисления производной
template<typename Func>
double findDerivative(Func func, int x, int b, int h) 
{
    double y_x = func(x);
    double y_x_plus_delta = func(x + h);
    double derivative = (y_x_plus_delta - y_x) / h;
    return derivative;
}

// Остальные объявления
void inputData(int& a, int& b, int& h);
double outputData(double (*funcPtr)(int, int, int), int a, int b, int h);

#endif