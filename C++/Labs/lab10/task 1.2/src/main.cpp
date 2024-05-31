#include "../inc/function_solver.h"
#include "../inc/specific_function_solver.h"

void inputData(int &a, int &b, int &h) 
{
    std::cout << "Введіть значення a(min): ";
    std::cin >> a;
    std::cout << "Введіть значення b(max): ";
    std::cin >> b;
    std::cout << "Введіть значення h: ";
    std::cin >> h;
}

int main() 
{
    int a, b, h;
    inputData(a, b, h);

    // Використовуємо базовий клас
    FunctionSolver solver;
    double result = solver.outputData(a, b, h);
    std::cout << "Результат для базового класу: " << result << std::endl;

    // Використовуємо похідний клас
    SpecificFunctionSolver specificSolver;
    result = specificSolver.outputData(a, b, h);
    std::cout << "Результат для похідного класу: " << result << std::endl;

    return 0;
}
