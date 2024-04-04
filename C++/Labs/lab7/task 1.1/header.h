#ifndef HEADER_H
#define HEADER_H

#include <iostream>

extern int n;

typedef double (*functionPtr)(double);

void inputData(int& a,int& b, int& h, int& n);
double function(double x);

double outputData(int& a, int& b, int& h, functionPtr function);

#endif
