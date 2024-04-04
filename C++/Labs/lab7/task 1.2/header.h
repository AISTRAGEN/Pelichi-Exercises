#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

void inputData(int& a, int& b, int& h);

typedef double(*funcPtr)(int, int, int);
double findDerivative(int a, int b, int h);

double outputData(funcPtr funcPtr, int a, int b, int h);

#endif