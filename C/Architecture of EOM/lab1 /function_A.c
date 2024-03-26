#include "header.h"

double function_A(double x, double y)
{
    double root = fabs(x + y); 
    double result_A = pow(M_E, root) + pow(fabs(x - y), x + y); 
    return result_A;
}