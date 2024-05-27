#include "function.h"
#include "header.h"
#include "function.cpp" 

#include <iostream>

int main() 
{
    FunctionSolver *solver = new MyFunctionSolver();
    double result = solver->solve();
    std::cout << "Результат: " << result << std::endl;
    delete solver;

    return 0;
}
