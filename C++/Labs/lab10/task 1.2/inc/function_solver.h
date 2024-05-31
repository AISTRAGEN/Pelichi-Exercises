#ifndef FUNCTION_SOLVER_H
#define FUNCTION_SOLVER_H

#include <iostream>
#include <cmath>

class FunctionSolver 
{
public:
    virtual double findDerivative(int a, int b, int h);
    virtual double outputData(int a, int b, int h);
};

#endif
