#ifndef FUNCTION_H
#define FUNCTION_H

#include "header.h" // Включення файлу з оголошенням inputData() та findDerivative()

class FunctionSolver {
public:
    virtual double solve() = 0; // Віртуальна функція для розв'язання завдання
    virtual double findDerivative(int a, int b, int h) = 0; // Функція для обчислення похідної
    virtual ~FunctionSolver() {} // Віртуальний деструктор
};

#endif