#ifndef SPECIFIC_FUNCTION_SOLVER_H
#define SPECIFIC_FUNCTION_SOLVER_H

#include "function_solver.h"

class SpecificFunctionSolver : public FunctionSolver 
{
public:
    double findDerivative(int a, int b, int h) override;
};

#endif
