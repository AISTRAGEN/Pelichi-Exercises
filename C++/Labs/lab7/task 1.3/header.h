#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cmath>

namespace mySpace
{
    typedef double (*functionPtr)(double, double);
    void print(double a, double b, functionPtr function)
    {
        std::cout << "Arguments: a = " << a << ", b = " << b << std::endl;
        std::cout << "Function result: " << function(a, b) << std::endl;
    }
}
#endif